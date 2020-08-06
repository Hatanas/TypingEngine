#ifndef INCLUDE_TYPING_ENGINE_AUTOMATON_CONNECTOR
#define INCLUDE_TYPING_ENGINE_AUTOMATON_CONNECTOR

namespace TypingEngine {
    class Automaton;
    class AutomatonConnector {
    public:
        static Automaton connectKanaToKana(const Automaton& a, const Automaton& b);
        static Automaton connectSokuonToKana(const Automaton& a, const Automaton& b);
        static Automaton connectHatsuonToKana(const Automaton& a, const Automaton& b);
    };
}

#endif // INCLUDE_TYPING_ENGINE_AUTOMATON_CONNECTOR