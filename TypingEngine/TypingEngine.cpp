#include <memory>

#include "TypingEngine.h"
#include "KanaAutomaton.h"
#include "AutomatonCreator.h"
#include "Node.h"
#include "Edge.h"

namespace TypingEngine {

using namespace std;

TypingEngine TypingEngine::create(const u32string& word) {
    KanaAutomaton automaton = AutomatonCreator::create(word);
    return TypingEngine(automaton, U"");
}

optional<TypingEngine> TypingEngine::type(char32_t typingChar) const {
    auto transit = m_automaton.transitByTyping(typingChar);
    if (!transit.second) { return nullopt; }
    return TypingEngine(transit.first, m_accumulatedInputChar + typingChar);
}

u32string TypingEngine::romanized() const {
    return generateRomanizedString(m_automaton.getBegin());
}

u32string TypingEngine::romanizedRemining() const {
    return generateRomanizedString(m_automaton.getNow());
}

bool TypingEngine::isFinished() const {
    return m_automaton.getNow() == m_automaton.getEnd();
}

u32string TypingEngine::generateRomanizedString(std::shared_ptr<Node> start) const {
    KanaAutomaton automaton(m_automaton.getBegin(), start, m_automaton.getEnds());
    u32string roman = U"";
    while (true) {
        auto [a, c] = automaton.transitByPriority();
        if (c == '\0') { break; }
        roman += c;
        automaton = a;
    }
    return roman;
}
}