#include "KanaAutomaton.h"
#include "Node.h"
#include "Edge.h"

#include <algorithm>

namespace TypingEngine {

using namespace std;

pair<KanaAutomaton, bool> KanaAutomaton::transitByTyping(char32_t typingChar) const {
    for (const auto& edge : m_now->getEdges()) {
        if (edge.getTypingChar() == typingChar) {
            KanaAutomaton automaton(m_begin, edge.getNext(), m_ends);
            return make_pair(automaton, true);
        }
    }
    return make_pair(*this, false);
}

pair<KanaAutomaton, char32_t> KanaAutomaton::transitByPriority() const {
    for (const auto& edge : m_now->getEdges()) {
        if (edge.isPriority()) {
            KanaAutomaton automaton(m_begin, edge.getNext(), m_ends);
            return make_pair(automaton, edge.getTypingChar());
        }
    }
    // 遷移先がなかった場合は適当に先頭のNodeに遷移する
    if (m_now->getEdges().size() > 0) {
        auto edge = m_now->getEdges().front();
        KanaAutomaton automaton(m_begin, edge.getNext(), m_ends);
        return make_pair(automaton, edge.getTypingChar());
    }
    return make_pair(*this, U'\0');
}

KanaAutomaton KanaAutomaton::connect(const KanaAutomaton& first, const KanaAutomaton& second) {
    auto ends = first.getEnds();
    for_each(ends.begin(), ends.end(), [second](auto& node) { node->addEdges(second.getBegin()->getEdges()); });
    return KanaAutomaton(first.getBegin(), second.getEnds());
}

KanaAutomaton KanaAutomaton::empty() {
    auto node = make_shared<Node>(vector<Edge<Node>>());
    return KanaAutomaton(node, node);
}
}