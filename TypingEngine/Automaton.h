#ifndef INCLUDE_TYPING_ENGINE_AUTOMATON_H
#define INCLUDE_TYPING_ENGINE_AUTOMATON_H

#include <vector>
#include <set>
#include <map>
#include <string>

#include "TransFunction.h"

namespace TypingEngine {
    class Automaton {
    private:
        std::set<std::wstring> m_stateSet;
        std::map<std::wstring, TransFunction> m_transitions;
        std::wstring m_initialState;
        std::vector<std::wstring> m_finalStates;
    public:
        Automaton(
            const std::set<std::wstring> &stateSet,
            const std::map<std::wstring, TransFunction> &functions,
            const std::wstring &startState,
            const std::vector<std::wstring> &endStates
        ) : m_stateSet(stateSet), m_transitions(functions), m_initialState(startState), m_finalStates(endStates) {}
        Automaton() = default;
        ~Automaton() = default;
    public:
        
        inline const std::set<std::wstring> &getStateSet() const { return m_stateSet; }
        inline const std::map<std::wstring, TransFunction> &getTransitions() const { return m_transitions; }
        inline const std::wstring &getInitialState() const { return m_initialState; }
        inline const std::vector<std::wstring> &getFinalStates() const { return m_finalStates; }
    public:
        std::wstring transitionByInput(const std::wstring &nowState, char input) const;
        std::string transitionToEnd() const;
        std::wstring toPlantUML() const;
    public:
        static const Automaton createEmpty();
    };
}

#endif // INCLUDE_TYPING_ENGINE_AUTOMATON_H
