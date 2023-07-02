#include "KanaAutomaton.h"
#include "Node.h"
#include "Edge.h"

#include <algorithm>
#include <string>

namespace TypingEngine {

using namespace std;

KanaAutomaton KanaAutomaton::transitByInput(std::u32string input) const {
    KanaAutomaton prev = *this;
    for (const auto& c : input) {
        KanaAutomaton next = prev.transitByInput(c);
        if (prev.m_now == next.m_now) { return prev; }
        prev = next;
    }
    return prev;
}

KanaAutomaton KanaAutomaton::transitByInput(char32_t inputChar) const {
    for (const auto& edge : m_now->getEdges()) {
        if (edge.getTypingChar() == inputChar) {
            u32string acc = m_accumulatedInput + edge.getTypingChar();
            return KanaAutomaton(m_begin, edge.getNext(), m_ends, acc);
        }
    }
    return *this;
}

KanaAutomaton KanaAutomaton::transitByPriority() const {
    KanaAutomaton prev = *this;
    while (!prev.isAccepted()) {
        KanaAutomaton next = prev;
        for (const auto& edge : prev.m_now->getEdges()) {
            if (edge.isPriority()) {
                u32string acc = prev.m_accumulatedInput + edge.getTypingChar();
                next = KanaAutomaton(prev.m_begin, edge.getNext(), prev.m_ends, acc);
                break;
            }
        }
        if (prev.m_now == next.m_now) { break; }
        prev = next;
    }
    return prev;
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