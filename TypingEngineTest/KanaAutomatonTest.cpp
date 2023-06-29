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

TEST(KanaAutomatonTest, TransitByPriority) {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto a = make_shared<Node>(vector<Edge<Node>>({Edge<Node>(U'c', true, end)}));
    auto b = make_shared<Node>(vector<Edge<Node>>({Edge<Node>(U'd', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge<Node>(U'a', false, a),
        Edge<Node>(U'b', true, b)}));
    KanaAutomaton automaton(begin, end);
    EXPECT_THAT(
        automaton.transitByPriority(),
        Pair(IsEqualKanaAutomaton(KanaAutomaton(begin, b, {end})), Eq(U'b')));
}

TEST(KanaAutomatonTest, Connect) {
    auto end1 = make_shared<Node>(vector<Edge<Node>>());
    auto n1 = make_shared<Node>(vector<Edge<Node>>({Edge(U'n', true, end1)}));
    auto begin1 = make_shared<Node>(vector<Edge<Node>>({Edge(U'n', true, n1)}));
    KanaAutomaton a1(begin1, begin1, {end1, n1});
    auto end2 = make_shared<Node>(vector<Edge<Node>>());
    auto begin2 = make_shared<Node>(vector<Edge<Node>>({Edge(U'k', true, end2)}));
    KanaAutomaton a2(begin2, begin2, {end2});
    auto connect = KanaAutomaton::connect(a1, a2);
    EXPECT_EQ(begin1, connect.getBegin());
    EXPECT_EQ(end2, connect.getEnd());
    EXPECT_THAT(
        connect.transitByTyping(U'n').first.transitByTyping(U'n').first.transitByTyping(U'k'),
        Pair(IsEqualKanaAutomaton(KanaAutomaton(begin1, end2, {end2})), Eq(true)));
    EXPECT_THAT(
        connect.transitByTyping(U'n').first.transitByTyping(U'k'),
        Pair(IsEqualKanaAutomaton(KanaAutomaton(begin1, end2, {end2})), Eq(true)));
}

TEST(KanaAutomatonTest, Empty) {
    auto a = KanaAutomaton::empty();
    EXPECT_TRUE(a.empty());
}
}