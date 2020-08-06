#include "CharNode.h"
#include "CharEdge.h"

using namespace std;

namespace TypingEngine
{
    CharNode::CharNode() : m_edges()
    {
    }

    CharNode::CharNode(vector<CharEdge> targets) : m_edges(targets)
    {
    }

    void CharNode::addEdge(const CharEdge edge)
    {
        m_edges.push_back(edge);
    }
}