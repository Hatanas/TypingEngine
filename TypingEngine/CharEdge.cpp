#include "CharEdge.h"

using namespace std;

namespace TypingEngine
{
    CharEdge::CharEdge(const bool shouldTransitionPrior, const wchar_t transitionChar, shared_ptr<CharNode> next) :
        m_isAutomaticTransition(shouldTransitionPrior),
        m_inputChar(transitionChar),
        m_next(next)
    {
    }
}
