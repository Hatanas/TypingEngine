#include "AutomatonGenerator.h"

#include <vector>
#include <functional>
#include <stdexcept>

#include "Automaton.h"
#include "AutomatonConnector.h"

namespace TypingEngine {

    using namespace std::string_literals;
    using std::wstring;
    using std::map;
    using std::pair;
    using std::function;

    Automaton AutomatonGenerator::generate(const wstring &str) const {
        Automaton automaton = Automaton::createEmpty();
        wstring remaining = str;
        for (int i = 0; i < str.size(); ++i) {
            pair<Automaton, wstring> result;
            switch (str[i]) {
                case L'‚ ': result = ‚ (remaining); break;
                case L'‚¢': result = ‚¢(remaining); break;
                case L'‚¤': result = ‚¤(remaining); break;
                case L'‚¦': result = ‚¦(remaining); break;
                case L'‚¨': result = ‚¨(remaining); break;
                case L'‚©': result = ‚©(remaining); break;
                case L'‚«': result = ‚«(remaining); break;
                case L'‚­': result = ‚­(remaining); break;
                case L'‚¯': result = ‚¯(remaining); break;
                case L'‚±': result = ‚±(remaining); break;
                case L'‚³': result = ‚³(remaining); break;
                case L'‚µ': result = ‚µ(remaining); break;
                case L'‚·': result = ‚·(remaining); break;
                case L'‚¹': result = ‚¹(remaining); break;
                case L'‚»': result = ‚»(remaining); break;
                case L'‚½': result = ‚½(remaining); break;
                case L'‚¿': result = ‚¿(remaining); break;
                case L'‚Â': result = ‚Â(remaining); break;
                case L'‚Ä': result = ‚Ä(remaining); break;
                case L'‚Æ': result = ‚Æ(remaining); break;
                case L'‚È': result = ‚È(remaining); break;
                case L'‚É': result = ‚É(remaining); break;
                case L'‚Ê': result = ‚Ê(remaining); break;
                case L'‚Ë': result = ‚Ë(remaining); break;
                case L'‚Ì': result = ‚Ì(remaining); break;
                case L'‚Í': result = ‚Í(remaining); break;
                case L'‚Ð': result = ‚Ð(remaining); break;
                case L'‚Ó': result = ‚Ó(remaining); break;
                case L'‚Ö': result = ‚Ö(remaining); break;
                case L'‚Ù': result = ‚Ù(remaining); break;
                case L'‚Ü': result = ‚Ü(remaining); break;
                case L'‚Ý': result = ‚Ý(remaining); break;
                case L'‚Þ': result = ‚Þ(remaining); break;
                case L'‚ß': result = ‚ß(remaining); break;
                case L'‚à': result = ‚à(remaining); break;
                case L'‚â': result = ‚â(remaining); break;
                case L'‚ä': result = ‚ä(remaining); break;
                case L'‚æ': result = ‚æ(remaining); break;
                case L'‚ç': result = ‚ç(remaining); break;
                case L'‚è': result = ‚è(remaining); break;
                case L'‚é': result = ‚é(remaining); break;
                case L'‚ê': result = ‚ê(remaining); break;
                case L'‚ë': result = ‚ë(remaining); break;
                case L'‚í': result = ‚í(remaining); break;
                case L'‚ð': result = ‚ð(remaining); break;
                case L'‚ñ': result = ‚ñ(remaining); break;
                default: throw std::invalid_argument("The string contains unsupported characters."); break;
            }
            if (i > 0 && str[i - 1] == L'‚ñ') {
                automaton = AutomatonConnector::connectHatsuonToKana(automaton, result.first);
            }
            else {
                automaton = AutomatonConnector::connectKanaToKana(automaton, result.first);
            }
            remaining = result.second;
        }
        return automaton;
    }

    pair<Automaton, wstring> AutomatonGenerator::‚ (const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"‚ "},
            map<wstring, TransFunction>({{L"", TransFunction('a', L"‚ ")}}),
            L"",
            {L"‚ "}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚¢(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"‚¢"},
            map<wstring, TransFunction>({{L"", TransFunction('i', L"‚¢")}}),
            L"",
            {L"‚¢"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚¤(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"w", L"wh", L"‚¤"},
            map<wstring, TransFunction>({
                {L"",   TransFunction('u', {{'u', L"‚¤"}, {'w', L"w"}})},
                {L"w",  TransFunction('u', {{'u', L"‚¤"}, {'h', L"wh"}})},
                {L"wh", TransFunction('u', L"‚¤")}}),
                L"",
            {L"‚¤"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚¦(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"‚¦"},
            map<wstring, TransFunction>({{L"", TransFunction('e', L"‚¦")}}),
            L"",
            {L"‚¦"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚¨(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"‚¨"},
            map<wstring, TransFunction>({{L"", TransFunction('o', L"‚¨")}}),
            wstring(),
            {L"‚¨"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚©(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"k", L"c", L"‚©"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('k', {{'k', L"k"}, {'c', L"c"}})},
                {L"k", TransFunction('a', L"‚©")},
                {L"c", TransFunction('a', L"‚©")}}),
                L"",
            {L"‚©"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚«(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"‚«"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('k', L"k")},
                {L"k", TransFunction('i', L"‚«")}}),
                L"",
            {L"‚«"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚­(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"k", L"c", L"q", L"‚­"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('k', {{'k', L"k"}, {'c', L"c"}, {'q', L"q"}})},
                {L"k", TransFunction('u', L"‚­")},
                {L"c", TransFunction('u', L"‚­")},
                {L"q", TransFunction('u', L"‚­")}}),
                L"",
            {L"‚­"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚¯(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"‚¯"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('k', L"k")},
                {L"k", TransFunction('e', L"‚¯")},
                }),
                L"",
            {L"‚¯"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚±(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"k", L"c", L"‚±"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('k', {{'k', L"k"}, {'c', L"c"}})},
                {L"k", TransFunction('o', L"‚±")},
                {L"c", TransFunction('o', L"‚±")}}),
                L"",
            {L"‚±"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚³(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"s", L"‚³"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('s', L"s")},
                {L"s", TransFunction('a', L"‚³")}}),
                L"",
            {L"‚³"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚µ(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"s", L"c", L"sh", L"‚µ"},
            map<wstring, TransFunction>({
                {L"",   TransFunction('s', {{'s', L"s"}, {'c', L"c"}})},
                {L"s",  TransFunction('i', {{'i', L"‚µ"}, {'h', L"sh"}})},
                {L"sh", TransFunction('i', L"‚µ")},
                {L"c",  TransFunction('i', L"‚µ")}}),
                L"",
            {L"‚µ"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚·(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"s", L"‚·"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('s', L"s")},
                {L"s", TransFunction('u', L"‚·")}}),
                L"",
            {L"‚·"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚¹(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"s", L"c", L"‚¹"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('s', {{'s', L"s"}, {'c', L"c"}})},
                {L"s", TransFunction('i', L"‚¹")},
                {L"c", TransFunction('i', L"‚¹")}}),
                L"",
            {L"‚¹"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚»(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"s", L"‚»"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('s', L"s")},
                {L"s", TransFunction('o', L"‚»")}}),
                L"",
            {L"‚»"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚½(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"t", L"‚½"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('t', L"t")},
                {L"t", TransFunction('a', L"‚½")}}),
                L"",
            {L"‚½"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚¿(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"t", L"c", L"ch", L"‚¿"},
            map<wstring, TransFunction>({
                {L"",   TransFunction('t', {{'t', L"t"}, {'c', L"c"}})},
                {L"t",  TransFunction('i', L"‚¿")},
                {L"c",  TransFunction('h', L"ch")},
                {L"ch", TransFunction('i', L"‚¿")}}),
                L"",
            {L"‚¿"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚Â(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"t", L"ts", L"‚Â"},
            map<wstring, TransFunction>({
                {L"",   TransFunction('t', L"t")},
                {L"t",  TransFunction('u', {{'u', L"‚Â"}, {'s', L"ts"}})},
                {L"ts", TransFunction('u', L"‚Â")}}),
                L"",
            {L"‚Â"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚Ä(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"t", L"‚Ä"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('t', L"t")},
                {L"t", TransFunction('e', L"‚Ä")}}),
                L"",
            {L"‚Ä"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚Æ(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"t", L"‚Æ"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('t', L"t")},
                {L"t", TransFunction('o', L"‚Æ")}}),
                L"",
            {L"‚Æ"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚È(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"n", L"‚È"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('n', L"n")},
                {L"n", TransFunction('a', L"‚È")}}),
                L"",
            {L"‚È"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚É(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"n", L"‚É"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('n', L"n")},
                {L"n", TransFunction('i', L"‚É")}}),
                L"",
            {L"‚É"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚Ê(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"n", L"‚Ê"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('n', L"n")},
                {L"n", TransFunction('u', L"‚Ê")}}),
                L"",
            {L"‚Ê"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚Ë(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"n", L"‚Ë"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('n', L"n")},
                {L"n", TransFunction('e', L"‚Ë")}}),
                L"",
            {L"‚Ë"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚Ì(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"n", L"‚Ì"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('n', L"n")},
                {L"n", TransFunction('o', L"‚Ì")}}),
                L"",
            {L"‚Ì"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚Í(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"h", L"‚Í"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('h', L"h")},
                {L"h", TransFunction('a', L"‚Í")}}),
                L"",
            {L"‚Í"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚Ð(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"h", L"‚Ð"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('h', L"h")},
                {L"h", TransFunction('i', L"‚Ð")}}),
                L"",
            {L"‚Ð"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚Ó(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"h", L"f", L"‚Ó"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('h', {{'h', L"h"}, {'f', L"f"}})},
                {L"h", TransFunction('u', L"‚Ó")},
                {L"f", TransFunction('u', L"‚Ó")}}),
                L"",
            {L"‚Ó"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚Ö(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"h", L"‚Ö"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('h', L"h")},
                {L"h", TransFunction('e', L"‚Ö")}}),
                L"",
            {L"‚Ö"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚Ù(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"h", L"‚Ù"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('h', L"h")},
                {L"h", TransFunction('o', L"‚Ù")}}),
                L"",
            {L"‚Ù"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚Ü(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"m", L"‚Ü"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('m', L"m")},
                {L"m", TransFunction('a', L"‚Ü")}}),
                L"",
            {L"‚Ü"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚Ý(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"m", L"‚Ý"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('m', L"m")},
                {L"m", TransFunction('i', L"‚Ý")}}),
                L"",
            {L"‚Ý"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚Þ(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"m", L"‚Þ"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('m', L"m")},
                {L"m", TransFunction('u', L"‚Þ")}}),
                L"",
            {L"‚Þ"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚ß(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"m", L"‚ß"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('m', L"m")},
                {L"m", TransFunction('e', L"‚ß")}}),
                L"",
            {L"‚ß"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚à(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"m", L"‚à"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('m', L"m")},
                {L"m", TransFunction('o', L"‚à")}}),
                L"",
            {L"‚à"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚â(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"y", L"‚â"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('y', L"y")},
                {L"y", TransFunction('a', L"‚â")}}),
                L"",
            {L"‚â"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚ä(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"y", L"‚ä"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('y', L"y")},
                {L"y", TransFunction('u', L"‚ä")}}),
                L"",
            {L"‚ä"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚æ(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"y", L"‚æ"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('y', L"y")},
                {L"y", TransFunction('o', L"‚æ")}}),
                L"",
            {L"‚æ"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚ç(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"r", L"‚ç"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('r', L"r")},
                {L"r", TransFunction('a', L"‚ç")}}),
                L"",
            {L"‚ç"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚è(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"r", L"‚è"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('r', L"r")},
                {L"r", TransFunction('i', L"‚è")}}),
                L"",
            {L"‚è"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚é(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"r", L"‚é"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('r', L"r")},
                {L"r", TransFunction('u', L"‚é")}}),
                L"",
            {L"‚é"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚ê(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"r", L"‚ê"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('r', L"r")},
                {L"r", TransFunction('e', L"‚ê")}}),
                L"",
            {L"‚ê"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚ë(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"r", L"‚ë"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('r', L"r")},
                {L"r", TransFunction('o', L"‚ë")}}),
                L"",
            {L"‚ë"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚í(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"w", L"‚í"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('w', L"w")},
                {L"w", TransFunction('a', L"‚í")}}),
                L"",
            {L"‚í"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚ð(const wstring &remaining) const {
        auto automaton = Automaton(
            {L"", L"w", L"‚ð"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('w', L"w")},
                {L"w", TransFunction('o', L"‚ð")}}),
                L"",
            {L"‚ð"}
        );
        return make_pair(automaton, remaining.substr(1));
    }

    pair<Automaton, wstring> AutomatonGenerator::‚ñ(const wstring &remaining) const {
        std::vector<wstring> finalStates;
        if (remaining.size() == 1 ||
            L"‚ ‚¢‚¤‚¦‚¨‚È‚É‚Ê‚Ë‚Ì"s.find(remaining[1]) < wstring::npos
            ) {
            finalStates = {L"‚ñ"};
        }
        else {
            finalStates = {L"‚ñ", L"n"};
        }
        auto automaton = Automaton(
            {L"", L"n", L"x", L"‚ñ"},
            map<wstring, TransFunction>({
                {L"",  TransFunction('n', {{'n', L"n"}, {'x', L"x"}})},
                {L"n", TransFunction('n', {{'n', L"‚ñ"}, {'\'', L"‚ñ"}})},
                {L"x", TransFunction('n', L"‚ñ")}}),
                L"",
                finalStates
                );
        return make_pair(automaton, remaining.substr(1));
    }
}