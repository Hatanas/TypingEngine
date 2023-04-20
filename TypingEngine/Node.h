#pragma once

#include <vector>

#include "Edge.h"

namespace TypingEngine {

/// <summary>
/// オートマトンのノード
/// </summary>
class Node {

private:
    /// <summary>
    /// エッジのリスト
    /// </summary>
    std::vector<Edge> m_edges;

public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="edges">エッジリスト</param>
    Node(std::vector<Edge> edges) : m_edges(edges) {}

    /// <summary>
    /// コンストラクタ
    /// </summary>
    Node() : Node(std::vector<Edge>()) {}

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Node() = default;

    /// <summary>
    /// エッジのリストを取得
    /// </summary>
    /// <returns>エッジリスト</returns>
    std::vector<Edge> getEdges() const { return m_edges; }

    /// <summary>
    /// エッジを追加
    /// </summary>
    /// <param name="edges">エッジリスト</param>
    void addEdges(std::vector<Edge> edges) { m_edges.insert(m_edges.end(), edges.begin(), edges.end()); }
};
}


