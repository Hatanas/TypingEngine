#include <iostream>
#include <algorithm>

#include "Automaton.h"

using namespace std;

namespace TypingEngine {
    using std::vector;
    using std::set;
    using std::map;
    using std::string;
    using std::wstring;

    wstring Automaton::transitionByInput(const wstring& nowState, char input) const {
        if (m_transitions.find(nowState) == m_transitions.end()) {
            std::cout << "Automaton: Œ»Ý‚Ìó‘Ô‚ª•s³‚Å‚·" << std::endl;
            return L"";
        }
        wstring next = m_transitions.at(nowState).getNextState(input);
        if (next.empty()) {
            std::cout << "Automaton: ‘JˆÚ‚Å‚«‚Ü‚¹‚ñ‚Å‚µ‚½" << std::endl;
            return nowState;
        }
        return next;
    }

    string Automaton::transitionToEnd() const {
        wstring nowState = m_initialState;
        string inputString = "";
        while (true) {
            auto p = m_transitions.at(nowState).getNextStateBySetting();
            if (p.first == '\0') {
                return inputString;
            }
            inputString += p.first;
            nowState = p.second;
            if (p.second == m_finalStates[0]) {
                return inputString;
            }
        }
    }

    wstring Automaton::toPlantUML() const {
        wstring uml = L"";
        uml += L"@startuml\n";
        uml += L"hide empty description\n";
        for (auto trans : m_transitions) {
            wstring state = trans.first == m_initialState ? L"[*]" : trans.first;
            for (auto func : trans.second.getFunctions()) {
                const char src[2] = {func.first, '\0'};
                size_t len = 0;
                wchar_t key[10] = {L"\0"};
                mbstowcs_s(&len, key, src, _TRUNCATE);
                uml += state + L" --> " + func.second + L" : " + key + L"\n";
            }
        }
        for (auto state : m_finalStates) {
            uml += state + L" --> " + L"[*]\n";
        }
        uml += L"@enduml\n";
        return uml;
    }

    const Automaton Automaton::createEmpty() {
        return Automaton({L""}, {{L"", TransFunction('\0', L"")}}, L"", {L""});
    }
}