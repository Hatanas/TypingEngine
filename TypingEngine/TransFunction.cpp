#include <iostream>
#include <algorithm>

#include "TransFunction.h"

namespace TypingEngine
{
    using std::map;
    using std::wstring;
    using std::pair;

    wstring TransFunction::getNextState(char input) const
    {
        if (m_transitions.find(input) == m_transitions.end()) {
            std::cout << "TransFunction: ‘JˆÚæ‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½D" << std::endl;
            return L"";
        }
        return m_transitions.at(input);
    }

    pair<char, wstring> TransFunction::getNextStateBySetting() const
    {
        if (m_transitions.find(m_defaultKey) == m_transitions.end()) {
            std::cout << "TransFunction: “ü—ÍÝ’è‚É‚æ‚é‘JˆÚæ‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½D" << std::endl;
            return make_pair('\0', wstring());
        }
        return make_pair(m_defaultKey, m_transitions.at(m_defaultKey));
    }
    const TransFunction TransFunction::updateState(const wstring& prefix) const
    {
        auto retFunc = map<char, wstring>();
        std::for_each(
            m_transitions.begin(),
            m_transitions.end(),
            [&](const auto& func) { retFunc.insert(make_pair(func.first, prefix + func.second)); });
        return TransFunction(m_defaultKey, retFunc);
    }
}
