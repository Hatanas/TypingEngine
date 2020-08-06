#pragma once

#include <memory>

namespace TypingEngine
{
    class CharNode;

    class CharEdge
    {
    private:
        const bool m_isAutomaticTransition;
        const wchar_t m_inputChar;
        const std::shared_ptr<CharNode> m_next;
    public:
        CharEdge(const bool shouldTransitionPrior, const wchar_t transitionChar, const std::shared_ptr<CharNode> next);
        ~CharEdge() = default;
    public:
        inline bool isAutomaticTransition() const { return m_isAutomaticTransition; }
        inline wchar_t getInputChar() const { return m_inputChar; }
        inline std::shared_ptr<CharNode> getNext() const { return m_next; }
    };
}
