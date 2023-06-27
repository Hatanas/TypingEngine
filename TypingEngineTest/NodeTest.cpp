#include "pch.h"
#include "Matcher.h"
#include "Edge.h"
#include "Node.h"

namespace TypingEngineTest {

using namespace TypingEngine;
using namespace std;
using namespace testing;

TEST(NodeTest, GetEdges) {
    vector<Edge<Node>> edges({Edge<Node>(L'a', true, make_shared<Node>())});
    Node node(edges);
    EXPECT_THAT(node.getEdges(), ElementsAre(IsEqualEdge(edges[0])));
}

TEST(NodeTest, AddEdges) {
    vector<Edge<Node>> edges1({Edge<Node>(L'a', true, make_shared<Node>())});
    vector<Edge<Node>> edges2({Edge<Node>(L'b', true, make_shared<Node>())});
    Node node(edges1);
    node.addEdges(edges2);
    edges1.insert(edges1.end(), edges2.begin(), edges2.end());
    EXPECT_THAT(node.getEdges(), ElementsAre(IsEqualEdge(edges1[0]), IsEqualEdge(edges1[1])));
}
}