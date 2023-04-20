#pragma once

#include <memory>
#include <vector>

#include "Node.h"

namespace TypingEngine {

/// <summary>
/// かな入力オートマトン
/// </summary>
class KanaAutomaton {

private:
    /// <summary>
    /// 始点
    /// </summary>
    std::shared_ptr<Node> m_begin;

    /// <summary>
    /// 現在地点
    /// </summary>
    std::shared_ptr<Node> m_now;

    /// <summary>
    /// 終点
    /// </summary>
    std::vector<std::shared_ptr<Node>> m_ends;

public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="begin">始点</param>
    /// <param name="now">現在地点</param>
    /// <param name="ends">終点リスト</param>
    KanaAutomaton(std::shared_ptr<Node> begin, std::shared_ptr<Node> now, std::vector<std::shared_ptr<Node>> ends)
        : m_begin(begin), m_now(now), m_ends(ends) {}

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="begin">始点</param>
    /// <param name="ends">終点リスト</param>
    KanaAutomaton(std::shared_ptr<Node> begin, std::vector<std::shared_ptr<Node>> ends)
        : KanaAutomaton(begin, begin, ends) {}

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="begin">始点</param>
    /// <param name="ends">終点</param>
    KanaAutomaton(std::shared_ptr<Node> begin, std::shared_ptr<Node> end)
        : KanaAutomaton(begin, begin, {end}) {}

    /// <summary>
    /// コンストラクタ
    /// </summary>
    KanaAutomaton() {
        auto node = std::make_shared<Node>();
        m_begin = node;
        m_now = node;
        m_ends = {node};
    }

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~KanaAutomaton() = default;

    /// <summary>
    /// 始点ノードを取得
    /// </summary>
    /// <returns>始点ノード</returns>
    inline std::shared_ptr<Node> getBegin() const { return m_begin; }

    /// <summary>
    /// 現在地点ノードを取得
    /// </summary>
    /// <returns>現在地点ノード</returns>
    inline std::shared_ptr<Node> getNow() const { return m_now; }

    /// <summary>
    /// 終点ノードを取得
    /// </summary>
    /// <returns>終点ノード</returns>
    inline std::shared_ptr<Node> getEnd() const { return m_ends.front(); }

    /// <summary>
    /// 終点ノードリストを取得
    /// </summary>
    /// <returns>終点ノードリスト</returns>
    inline std::vector<std::shared_ptr<Node>> getEnds() const { return m_ends; }

    /// <summary>
    /// 空のオートマトンかを判定
    /// </summary>
    /// <remarks>始点と終点が同じノードかどうかで判定する。</remarks>
    /// <returns>空のオートマトンか</returns>
    inline bool isEmpty() const { return m_ends.size() == 1 && m_begin == m_ends[0]; }

    /// <summary>
    /// 文字入力による遷移
    /// </summary>
    /// <param name="typingChar">入力した文字</param>
    /// <returns>遷移後のオートマトンと遷移できたかのフラグ</returns>
    std::pair<KanaAutomaton, bool> transitByTyping(char32_t typingChar) const;

    /// <summary>
    /// Edgeに設定された優先度による遷移
    /// </summary>
    /// <returns>遷移後のオートマトンと遷移できたかのフラグ</returns>
    std::pair<KanaAutomaton, char32_t> transitByPriority() const;

public:
    /// <summary>
    /// オートマトンを接続
    /// </summary>
    /// <param name="first">前方側</param>
    /// <param name="second">後方側</param>
    /// <returns>接続したオートマトン</returns>
    static KanaAutomaton connect(const KanaAutomaton& first, const KanaAutomaton& second);

    /// <summary>
    /// オートマトンが空であるかを判定
    /// </summary>
    /// <returns>空かどうか</returns>
    static KanaAutomaton empty();
};
}

