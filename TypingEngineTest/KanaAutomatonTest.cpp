#include "pch.h"
#include "Matcher.h"
#include "KanaAutomaton.h"
#include "Edge.h"

namespace TypingEngineTest {

using namespace TypingEngine;
using namespace std;
using namespace testing;

TEST(KanaAutomatonTest, GetBegin) {
    auto begin = make_shared<Node>();
    auto now = make_shared<Node>();
    auto end = make_shared<Node>();
    KanaAutomaton automaton(begin, now, {end});
    EXPECT_EQ(begin, automaton.getBegin());
}

TEST(KanaAutomatonTest, GetNow) {
    auto begin = make_shared<Node>();
    auto now = make_shared<Node>();
    auto end = make_shared<Node>();
    KanaAutomaton automaton(begin, now, {end});
    EXPECT_EQ(now, automaton.getNow());
}

TEST(KanaAutomatonTest, GetEnd) {
    auto begin = make_shared<Node>();
    auto now = make_shared<Node>();
    auto end = make_shared<Node>();
    KanaAutomaton automaton(begin, now, {end});
    EXPECT_EQ(end, automaton.getEnd());
}

TEST(KanaAutomatonTest, GetEnds) {
    auto begin = make_shared<Node>();
    auto now = make_shared<Node>();
    auto end = make_shared<Node>();
    KanaAutomaton automaton(begin, now, {end});
    vector<shared_ptr<Node>> ends({end});
    EXPECT_EQ(ends, automaton.getEnds());
}

TEST(KanaAutomatonTest, Constructor2Arg) {
    auto begin = make_shared<Node>();
    auto end = make_shared<Node>();
    KanaAutomaton automaton(begin, end);
    EXPECT_EQ(begin, automaton.getBegin());
    EXPECT_EQ(begin, automaton.getNow());
    EXPECT_EQ(end, automaton.getEnd());
}

TEST(KanaAutomatonTest, Constructor2ArgVec) {
    auto begin = make_shared<Node>();
    auto end = make_shared<Node>();
    KanaAutomaton automaton(begin, {end});
    EXPECT_EQ(begin, automaton.getBegin());
    EXPECT_EQ(begin, automaton.getNow());
    EXPECT_EQ(end, automaton.getEnd());
}

TEST(KanaAutomatonTest, IsEmptyTrue) {
    auto node = make_shared<Node>();
    KanaAutomaton automaton(node, node);
    EXPECT_TRUE(automaton.isEmpty());
}

TEST(KanaAutomatonTest, IsEmptyFalse) {
    auto begin = make_shared<Node>();
    auto end = make_shared<Node>();
    KanaAutomaton automaton(begin, end);
    EXPECT_FALSE(automaton.isEmpty());
}

TEST(KanaAutomatonTest, TransitByTyping) {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto ch = make_shared<Node>(vector<Edge<Node>>({Edge<Node>(U'i', true, end)}));
    auto c = make_shared<Node>(vector<Edge<Node>>({Edge<Node>(U'h', true, ch)}));
    auto t = make_shared<Node>(vector<Edge<Node>>({Edge<Node>(U'i', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge<Node>(U't', true, t),
        Edge<Node>(U'c', false, c)}));
    KanaAutomaton automaton(begin, end);
    EXPECT_THAT(
        automaton.transitByTyping(U't'),
        Pair(IsEqualKanaAutomaton(KanaAutomaton(begin, t, {end})), Eq(true)));
    EXPECT_THAT(
        automaton.transitByTyping(U'a'),
        Pair(IsEqualKanaAutomaton(automaton), Eq(false)));
}
}