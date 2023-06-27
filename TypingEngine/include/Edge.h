#pragma once

#include <memory>

namespace TypingEngine {

/// <summary>
/// オートマトンのエッジ
/// </summary>
template <typename T>
class Edge {

private:
    /// <summary>
    /// 遷移条件の文字
    /// </summary>
    /// <remarks>この文字が入力されたときに遷移する。</remarks>
    char32_t m_typingChar;

    /// <summary>
    /// 優先的に遷移すべきか
    /// </summary>
    /// <remarks>このフラグが有効なときに遷移する。</remarks>
    bool m_isPriority;

    /// <summary>
    /// 遷移先のノード
    /// </summary>
    std::shared_ptr<T> m_next;

public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="typingChar">遷移条件の文字</param>
    /// <param name="isPriority">優先的に遷移すべきか</param>
    /// <param name="next">遷移先のノード</param>
    Edge(char32_t typingChar, bool isPriority, std::shared_ptr<T> next) :
        m_typingChar(typingChar), m_isPriority(isPriority), m_next(next) { }

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Edge() = default;

    /// <summary>
    /// 遷移条件の文字を取得
    /// </summary>
    char32_t getTypingChar() const { return m_typingChar; }

    /// <summary>
    /// 優先的に遷移すべきか
    /// </summary>
    bool isPriority() const { return m_isPriority; }

    /// <summary>
    /// 遷移先のノードを取得
    /// </summary>
    std::shared_ptr<T> getNext() const { return m_next; }
};
}