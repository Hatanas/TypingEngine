#pragma once

#include <string>
#include <vector>
#include <set>
#include <map>

namespace TypingEngine
{
    struct TransitionCondition
    {
        bool isDefaultDestination;
        wchar_t transitionChar;
    };

    class KanaInputAutomaton
    {
    private:
        std::set<std::wstring> m_stateSet;
        std::map<std::wstring, std::map<wchar_t, std::wstring>> m_transitionFunction;
        std::wstring m_initialState;
        std::vector<std::wstring> m_acceptStates;
    };
}
