#ifndef INCLUDE_TYPING_ENGINE_TRANS_FUNCTION_H
#define INCLUDE_TYPING_ENGINE_TRANS_FUNCTION_H

#include <map>
#include <string>

namespace TypingEngine {
    /// <summary>
    /// 遷移関数を表すクラス．
    /// ある状態（ノード）におけるすべての遷移関数を保持する．
    /// </summary>
    class TransFunction {
    private:
        /// <summary>
        /// 優先文字．
        /// 入力設定によって決まる遷移先の文字．
        /// </summary>
        char m_defaultKey;
        /// <summary>
        /// 遷移関数．
        /// </summary>
        std::map<char, std::wstring> m_transitions;
    public:
        /// <summary>
        /// コンストラクタ．
        /// </summary>
        /// <param name="defaultKey">優先文字</param>
        /// <param name="functions">遷移関数</param>
        /// <returns>生成したオブジェクト</returns>
        TransFunction(
            char defaultKey,
            const std::map<char, std::wstring> &functions
        ) : m_defaultKey(defaultKey), m_transitions(functions) {}
        /// <summary>
        /// コンストラクタ．
        /// </summary>
        /// <param name="function">遷移関数</param>
        /// <returns>生成したオブジェクト</returns>
        TransFunction(char key, const std::wstring &state)
            : m_defaultKey(key), m_transitions({std::make_pair(key, state)}) {}
        TransFunction() = default;
        ~TransFunction() = default;
    public:
        /// <summary>
        /// 次の状態を取得する．
        /// </summary>
        /// <param name="input">入力文字</param>
        /// <returns>次の状態</returns>
        std::wstring getNextState(char input) const;
        /// <summary>
        /// 入力設定による次の状態を取得する．
        /// </summary>
        /// <returns>次の状態</returns>
        std::pair<char, std::wstring> getNextStateBySetting() const;
        const TransFunction updateState(const std::wstring &prefix) const;
        const std::map<char, std::wstring> &getFunctions() const { return m_transitions; }
        char getDefaultKey() const { return m_defaultKey; }
    };
}

#endif // INCLUDE_TYPING_ENGINE_TRANS_FUNCTION_H