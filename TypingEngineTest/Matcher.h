#pragma once

#include "pch.h"

namespace TypingEngineTest {

MATCHER_P(IsEqualEdge, e, "") {
    bool eqTypingChar = arg.getTypingChar() == e.getTypingChar();
    bool eqIsPrioriity = arg.isPriority() == e.isPriority();
    bool eqNext = arg.getNext() == e.getNext();
    return eqTypingChar && eqIsPrioriity && eqNext;
}

MATCHER_P(IsEqualNode, n, "") {
    for (int i = 0; i < arg.size(); ++i) {
        if (!testing::Value(arg[i], IsEqualEdge(n[i]))) { return false; }
    }
    return true;
}

MATCHER_P(IsEqualKanaAutomaton, a, "") {
    bool eqBegin = arg.getBegin() == a.getBegin();
    bool eqNow = arg.getNow() == a.getNow();
    bool eqEnds = arg.getEnds() == a.getEnds();
    return eqBegin && eqNow && eqEnds;
}
}