#pragma once

#include <string>
#include <optional>

#include "KanaAutomaton.h"

namespace TypingEngine {

class Node;

/// <summary>
/// タイピングエンジン本体
/// </summary>
class TypingEngine {
private:
    KanaAutomaton m_automaton;
    std::u32string m_accumulatedInputChar;

public:
    TypingEngine(const KanaAutomaton& automaton, std::u32string accInputChar)
        : m_automaton(automaton), m_accumulatedInputChar(accInputChar) {}

public:
    /// <summary>
    /// これまでに入力した文字列を取得
    /// </summary>
    /// <returns>入力済み文字列</returns>
    inline std::u32string getAccumulatedInputChar() const { return m_accumulatedInputChar; }

    /// <summary>
    /// かな入力オートマトンを取得
    /// </summary>
    /// <returns>オートマトンオブジェクト</returns>
    inline KanaAutomaton getAutomaton() const { return m_automaton; }

    /// <summary>
    /// 文字を入力する
    /// </summary>
    /// <param name="inputChar"></param>
    /// <returns>入力後のエンジン</returns>
    std::optional<TypingEngine> type(char32_t typingChar) const;

    /// <summary>
    /// 入力文字列を生成する
    /// </summary>
    /// <returns></returns>
    std::u32string romanized() const;

    /// <summary>
    /// 入力文字列を生成する
    /// </summary>
    /// <param name="config"></param>
    /// <returns></returns>
    std::u32string romanizedRemining() const;

    bool isFinished() const;

public:
    /// <summary>
    /// 入力エンジンを生成する
    /// </summary>
    /// <param name="str"></param>
    /// <returns></returns>
    static TypingEngine create(const std::u32string& word);

private:
    std::u32string generateRomanizedString(std::shared_ptr<Node> start) const;
};
}

