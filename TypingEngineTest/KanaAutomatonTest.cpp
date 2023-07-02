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


TEST(KanaAutomatonTest, GetAccumulatedInput) {
    auto begin = make_shared<Node>();
    auto now = make_shared<Node>();
    auto end = make_shared<Node>();
    KanaAutomaton automaton(begin, now, {end}, U"input");
    EXPECT_EQ(U"input", automaton.getAccumulatedInput());
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

TEST(KanaAutomatonTest, IsAccepted) {
    auto begin = make_shared<Node>();
    auto end1 = make_shared<Node>();
    auto end2 = make_shared<Node>();
    KanaAutomaton a1(begin, end2, {end1, end2});
    KanaAutomaton a2(begin, begin, {end1});
    EXPECT_TRUE(a1.isAccepted());
    EXPECT_FALSE(a2.isAccepted());
}

TEST(KanaAutomatonTest, TransitByInputString) {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto ch = make_shared<Node>(vector<Edge<Node>>({Edge<Node>(U'i', true, end)}));
    auto c = make_shared<Node>(vector<Edge<Node>>({Edge<Node>(U'h', true, ch)}));
    auto t = make_shared<Node>(vector<Edge<Node>>({Edge<Node>(U'i', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge<Node>(U't', true, t),
        Edge<Node>(U'c', false, c)}));
    KanaAutomaton automaton(begin, end);
    EXPECT_THAT(
        automaton.transitByInput(U"chi"),
        IsEqualKanaAutomaton(KanaAutomaton(begin, end, {end})));
    EXPECT_THAT(
        automaton.transitByInput(U"shi"),
        IsEqualKanaAutomaton(automaton));
}

TEST(KanaAutomatonTest, TransitByInputChar) {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto ch = make_shared<Node>(vector<Edge<Node>>({Edge<Node>(U'i', true, end)}));
    auto c = make_shared<Node>(vector<Edge<Node>>({Edge<Node>(U'h', true, ch)}));
    auto t = make_shared<Node>(vector<Edge<Node>>({Edge<Node>(U'i', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge<Node>(U't', true, t),
        Edge<Node>(U'c', false, c)}));
    KanaAutomaton automaton(begin, end);
    EXPECT_THAT(
        automaton.transitByInput(U't'),
        IsEqualKanaAutomaton(KanaAutomaton(begin, t, {end})));
    EXPECT_THAT(
        automaton.transitByInput(U'a'),
        IsEqualKanaAutomaton(automaton));
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
        IsEqualKanaAutomaton(KanaAutomaton(begin, b, {end})));
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
        connect.transitByInput(U"nnk"),
        IsEqualKanaAutomaton(KanaAutomaton(begin1, end2, {end2})));
    EXPECT_THAT(
        connect.transitByInput(U"nk"),
        IsEqualKanaAutomaton(KanaAutomaton(begin1, end2, {end2})));
}

TEST(KanaAutomatonTest, Empty) {
    auto a = KanaAutomaton::empty();
    EXPECT_TRUE(a.isEmpty());
}
}