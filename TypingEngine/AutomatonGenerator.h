#pragma once

#include "Automaton.h"

#include <memory>
#include <string>

namespace TypingEngine
{
    class AutomatonGenerator
    {
    public:
        AutomatonGenerator() = default;
        ~AutomatonGenerator() = default;
    public:
        Automaton generate(const std::wstring& str) const;
    public:
        // あ行
        std::pair<Automaton, std::wstring> あ(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> い(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> う(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> え(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> お(const std::wstring& remaining) const;
        // か行
        std::pair<Automaton, std::wstring> か(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> き(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> く(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> け(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> こ(const std::wstring& remaining) const;
        // さ行
        std::pair<Automaton, std::wstring> さ(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> し(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> す(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> せ(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> そ(const std::wstring& remaining) const;
        // た行
        std::pair<Automaton, std::wstring> た(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> ち(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> つ(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> て(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> と(const std::wstring& remaining) const;
        // な行
        std::pair<Automaton, std::wstring> な(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> に(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> ぬ(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> ね(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> の(const std::wstring& remaining) const;
        // は行
        std::pair<Automaton, std::wstring> は(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> ひ(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> ふ(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> へ(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> ほ(const std::wstring& remaining) const;
        // ま行
        std::pair<Automaton, std::wstring> ま(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> み(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> む(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> め(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> も(const std::wstring& remaining) const;
        // や行
        std::pair<Automaton, std::wstring> や(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> ゐ(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> ゆ(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> ゑ(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> よ(const std::wstring& remaining) const;
        // ら行
        std::pair<Automaton, std::wstring> ら(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> り(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> る(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> れ(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> ろ(const std::wstring& remaining) const;
        // わ行
        std::pair<Automaton, std::wstring> わ(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> を(const std::wstring& remaining) const;
        std::pair<Automaton, std::wstring> ん(const std::wstring& remaining) const;

        // が行
        std::pair<Automaton, std::wstring> が(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> ぎ(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> ぐ(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> げ(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> ご(const std::wstring &remaining) const;
        // ざ行
        std::pair<Automaton, std::wstring> ざ(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> じ(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> ず(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> ぜ(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> ぞ(const std::wstring &remaining) const;
        // だ行
        std::pair<Automaton, std::wstring> だ(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> ぢ(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> づ(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> で(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> ど(const std::wstring &remaining) const;
        // ば行
        std::pair<Automaton, std::wstring> ば(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> び(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> ぶ(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> べ(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> ぼ(const std::wstring &remaining) const;
        // ぱ行
        std::pair<Automaton, std::wstring> ぱ(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> ぴ(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> ぷ(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> ぺ(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> ぽ(const std::wstring &remaining) const;

        // ぁ行
        std::pair<Automaton, std::wstring> ぁ(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> ぃ(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> ぅ(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> ぇ(const std::wstring &remaining) const;
        std::pair<Automaton, std::wstring> ぉ(const std::wstring &remaining) const;
        // ゃ行
        std::pair<Automaton, std::wstring> ゃ(const std::wstring & remaining) const;
        std::pair<Automaton, std::wstring> ゅ(const std::wstring & remaining) const;
        std::pair<Automaton, std::wstring> ょ(const std::wstring & remaining) const;

        // っ
        std::pair<Automaton, std::wstring> っ(const std::wstring &remaining) const;
    };
}
