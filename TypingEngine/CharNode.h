#pragma once

#include <vector>
#include <memory>

namespace TypingEngine
{
    class CharEdge;

    class CharNode
    {
    private:
        std::vector<CharEdge> m_edges;
    public:
        CharNode();
        explicit CharNode(std::vector<CharEdge> targets);
        ~CharNode() = default;
    public:
        inline std::vector<CharEdge> getEdges() const { return m_edges; }
        void addEdge(const CharEdge edge);
    };
}
