#include "AutomatonConnector.h"
#include "Automaton.h"

#include <stdexcept>
#include <algorithm>

namespace TypingEngine {
    using std::vector;
    using std::set;
    using std::map;
    using std::wstring;
    using std::invalid_argument;

    set<wstring> mergeStates(const Automaton &a, const Automaton &b) {
        wstring prefix = a.getFinalStates().front();
        set<wstring> states(a.getStateSet());
        for (auto state : b.getStateSet()) {
            states.insert(prefix + state);
        }
        return states;
    }

    map<wstring, TransFunction> mergeTransitions(const Automaton &a, const Automaton &b) {
        wstring prefix = a.getFinalStates().front();
        map<wstring, TransFunction> transitions(a.getTransitions());
        for (auto transition : b.getTransitions()) {
            wstring key = prefix + transition.first;
            TransFunction value = transition.second.updateState(prefix);
            transitions.emplace(key, value);
        }
        return transitions;
    }

    vector<wstring> mergeFinalStates(const Automaton &a, const Automaton &b) {
        wstring prefix = a.getFinalStates().front();
        vector<wstring> finalStates;
        for (auto state : b.getFinalStates()) {
            finalStates.push_back(prefix + state);
        }
        return finalStates;
    }

    Automaton AutomatonConnector::connectKanaToKana(const Automaton &a, const Automaton &b) {
        if (a.getFinalStates().size() != 1) { throw invalid_argument("a is not KanaAutomaton"); }
        //if (b.getFinalStates().size() != 1) { throw invalid_argument("b is not KanaAutomaton"); }
        auto states = mergeStates(a, b);
        auto transitions = mergeTransitions(a, b);
        auto finalStates = mergeFinalStates(a, b);
        return Automaton(states, transitions, a.getInitialState(), finalStates);
    }

    Automaton AutomatonConnector::connectSokuonToKana(const Automaton &a, const Automaton &b) {
        if (a.getFinalStates().front().back() != L'ВЅ') { throw invalid_argument("a is not SokuonAutomaton"); }
        //if (b.getFinalStates().size() != 1) { throw invalid_argument("b is not KanaAutomaton"); }
        auto states = mergeStates(a, b);
        auto transitions = mergeTransitions(a, b);
        auto finalStates = mergeFinalStates(a, b);
        if (a.getFinalStates().size() > 1) {
            auto otherStates(a.getFinalStates());
            otherStates.erase(otherStates.begin());
            for (auto key : otherStates) {
                wchar_t suffix = key.back();
                auto searchMap = transitions.at(a.getFinalStates().front()).getFunctions();
                auto func = std::find_if(searchMap.begin(), searchMap.end(), [=](const auto s) { return s.second.back() == suffix; });
                transitions.emplace(key, TransFunction(func->first, func->second));
            }
        }
        return Automaton(states, transitions, a.getInitialState(), finalStates);
    }

    Automaton AutomatonConnector::connectHatsuonToKana(const Automaton &a, const Automaton &b) {
        if (a.getFinalStates().front().back() != L'Вс' || a.getFinalStates().size() > 2) { throw invalid_argument("a is not HatsuonAutomaton"); }
        //if (b.getFinalStates().size() != 1) { throw invalid_argument("b is not KanaAutomaton"); }
        auto states = mergeStates(a, b);
        auto transitions = mergeTransitions(a, b);
        auto finalStates = mergeFinalStates(a, b);
        if (a.getFinalStates().size() == 2) {
            wstring cState = a.getFinalStates()[0];
            auto cFunc = transitions.at(cState).getFunctions();
            wstring n = a.getFinalStates()[1];
            auto nTrans = transitions.at(n);
            auto nFunc = nTrans.getFunctions();
            for (auto f : cFunc) {
                nFunc.emplace(f.first, f.second);
            }
            transitions[n] = TransFunction(nTrans.getDefaultKey(), nFunc);
        }
        return Automaton(states, transitions, a.getInitialState(), finalStates);
    }
}
