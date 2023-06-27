#include "pch.h"
#include "Edge.h"

namespace TypingEngineTest {

using namespace TypingEngine;
using namespace std;

TEST(EdgeTest, GetTypingChar) {
    Edge<int> edge(U'a', true, make_shared<int>(1));
    EXPECT_EQ(U'a', edge.getTypingChar());
}

TEST(EdgeTest, IsPriority) {
    Edge<int> edge(U'a', true, make_shared<int>(1));
    EXPECT_EQ(true, edge.isPriority());
}

TEST(EdgeTest, GetNext) {
    auto next = make_shared<int>(1);
    Edge<int> edge(U'a', true, next);
    EXPECT_EQ(next, edge.getNext());
}
}