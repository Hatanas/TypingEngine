#include "AutomatonCreator.h"
#include "KanaAutomaton.h"
#include "Edge.h"
#include "Node.h"

#include <memory>

namespace TypingEngine {

using namespace std;

KanaAutomaton AutomatonCreator::create(const u32string& word) {
    auto automaton = KanaAutomaton::empty();
    for (u32string str = word; str.size() > 0;) {
        auto selected = select(str);
        if (selected.first.isEmpty()) { break; }
        automaton = KanaAutomaton::connect(automaton, selected.first);
        str = selected.second;
    }
    return automaton;
}

std::pair<KanaAutomaton, std::u32string> AutomatonCreator::select(const std::u32string& word) {
    if (word.size() == 0) { return make_pair(KanaAutomaton::empty(), U""); }
    switch (word[0]) {
        case U'あ': return make_pair(createA(), word.substr(1));
        case U'い': return make_pair(createI(), word.substr(1));
        case U'う':
            return selectYouon(
                word, u32string(U"ぁぃぇぉ"),
                {createWHA, createWHI, createWHE, createWHO, createU});
        case U'え': return make_pair(createE(), word.substr(1));
        case U'お': return make_pair(createO(), word.substr(1));
        case U'ゔ':
            return selectYouon(
                word, u32string(U"ぁぃぅぇぉゃゅょ"),
                {createVA, createVI, createVU, createVE, createVO, createVYA, createVYU, createVYO, createVU});
        case U'か': return make_pair(createKA(), word.substr(1));
        case U'き':
            return selectYouon(
                word, u32string(U"ゃぃゅぇょ"),
                {createKYA, createKYI, createKYU, createKYE, createKYO, createKI});
        case U'く':
            return selectYouon(
                word, u32string(U"ぁぃぅぇぉ"),
                {createKWA, createKWI, createKWU, createKWE, createKWO, createKU});
        case U'け': return make_pair(createKE(), word.substr(1));
        case U'こ': return make_pair(createKO(), word.substr(1));
        case U'が': return make_pair(createGA(), word.substr(1));
        case U'ぎ':
            return selectYouon(
                word, u32string(U"ゃぃゅぇょ"),
                {createGYA, createGYI, createGYU, createGYE, createGYO, createGI});
        case U'ぐ':
            return selectYouon(
                word, u32string(U"ぁぃぅぇぉ"),
                {createGWA, createGWI, createGWU, createGWE, createGWO, createGU});
        case U'げ': return make_pair(createGE(), word.substr(1));
        case U'ご': return make_pair(createGO(), word.substr(1));
        case U'さ': return make_pair(createSA(), word.substr(1));
        case U'し':
            return selectYouon(
                word, u32string(U"ゃぃゅぇょ"),
                {createSYA, createSYI, createSYU, createSYE, createSYO, createSI});
        case U'す':
            return selectYouon(
                word, u32string(U"ぁぃぅぇぉ"),
                {createSWA, createSWI, createSWU, createSWE, createSWO, createSU});
        case U'せ': return make_pair(createSE(), word.substr(1));
        case U'そ': return make_pair(createSO(), word.substr(1));
        case U'ざ': return make_pair(createZA(), word.substr(1));
        case U'じ':
            return selectYouon(
                word, u32string(U"ゃぃゅぇょ"),
                {createZYA, createZYI, createZYU, createZYE, createZYO, createZI});
        case U'ず': return make_pair(createZU(), word.substr(1));
        case U'ぜ': return make_pair(createZE(), word.substr(1));
        case U'ぞ': return make_pair(createZO(), word.substr(1));
        case U'た': return make_pair(createTA(), word.substr(1));
        case U'ち':
            return selectYouon(
                word, u32string(U"ゃぃゅぇょ"),
                {createTYA, createTYI, createTYU, createTYE, createTYO, createTI});
        case U'つ':
            return selectYouon(
                word, u32string(U"ぁぃぇぉ"),
                {createTSA, createTSI, createTSE, createTSO, createTU});
        case U'て':
            return selectYouon(
                word, u32string(U"ゃぃゅぇょ"),
                {createTHA, createTHI, createTHU, createTHE, createTHO, createTE});
        case U'と':
            return selectYouon(
                word, u32string(U"ぁぃぅぇぉ"),
                {createTWA, createTWI, createTWU, createTWE, createTWO, createTO});
        case U'だ': return make_pair(createDA(), word.substr(1));
        case U'ぢ':
            return selectYouon(
                word, u32string(U"ゃぃゅぇょ"),
                {createDYA, createDYI, createDYU, createDYE, createDYO, createDI});
        case U'づ': return make_pair(createDU(), word.substr(1));
        case U'で':
            return selectYouon(
                word, u32string(U"ゃぃゅぇょ"),
                {createDHA, createDHI, createDHU, createDHE, createDHO, createDE});
        case U'ど':
            return selectYouon(
                word, u32string(U"ぁぃぅぇぉ"),
                {createDWA, createDWI, createDWU, createDWE, createDWO, createDO});
        case U'な': return make_pair(createNA(), word.substr(1));
        case U'に':
            return selectYouon(
                word, u32string(U"ゃぃゅぇょ"),
                {createNYA, createNYI, createNYU, createNYE, createNYO, createNI});
        case U'ぬ': return make_pair(createNU(), word.substr(1));
        case U'ね': return make_pair(createNE(), word.substr(1));
        case U'の': return make_pair(createNO(), word.substr(1));
        case U'は': return make_pair(createHA(), word.substr(1));
        case U'ひ':
            return selectYouon(
                word, u32string(U"ゃぃゅぇょ"),
                {createHYA, createHYI, createHYU, createHYE, createHYO, createHI});
        case U'ふ':
            return selectYouon(
                word, u32string(U"ぁぃぅぇぉゃゅょ"),
                {createFWA, createFWI, createFWU, createFWE, createFWO, createFYA, createFYU, createFYO, createHU});
        case U'へ': return make_pair(createHE(), word.substr(1));
        case U'ほ': return make_pair(createHO(), word.substr(1));
        case U'ば': return make_pair(createBA(), word.substr(1));
        case U'び':
            return selectYouon(
                word, u32string(U"ゃぃゅぇょ"),
                {createBYA, createBYI, createBYU, createBYE, createBYO, createBI});
        case U'ぶ': return make_pair(createBU(), word.substr(1));
        case U'べ': return make_pair(createBE(), word.substr(1));
        case U'ぼ': return make_pair(createBO(), word.substr(1));
        case U'ぱ': return make_pair(createPA(), word.substr(1));
        case U'ぴ':
            return selectYouon(
                word, u32string(U"ゃぃゅぇょ"),
                {createPYA, createPYI, createPYU, createPYE, createPYO, createPI});
        case U'ぷ': return make_pair(createPU(), word.substr(1));
        case U'ぺ': return make_pair(createPE(), word.substr(1));
        case U'ぽ': return make_pair(createPO(), word.substr(1));
        case U'ま': return make_pair(createMA(), word.substr(1));
        case U'み':
            return selectYouon(
                word, u32string(U"ゃぃゅぇょ"),
                {createMYA, createMYI, createMYU, createMYE, createMYO, createMI});
        case U'む': return make_pair(createMU(), word.substr(1));
        case U'め': return make_pair(createME(), word.substr(1));
        case U'も': return make_pair(createMO(), word.substr(1));
        case U'や': return make_pair(createYA(), word.substr(1));
        case U'ゆ': return make_pair(createYU(), word.substr(1));
        case U'よ': return make_pair(createYO(), word.substr(1));
        case U'ら': return make_pair(createRA(), word.substr(1));
        case U'り':
            return selectYouon(
                word, u32string(U"ゃぃゅぇょ"),
                {createRYA, createRYI, createRYU, createRYE, createRYO, createRI});
        case U'る': return make_pair(createRU(), word.substr(1));
        case U'れ': return make_pair(createRE(), word.substr(1));
        case U'ろ': return make_pair(createRO(), word.substr(1));
        case U'わ': return make_pair(createWA(), word.substr(1));
        case U'を': return make_pair(createWO(), word.substr(1));
        case U'ん':
        {
            if (
                word.size() > 1 &&
                u32string(U"あいうえおなにぬねのやゆよん").find(word[1]) == u32string::npos
            ) {
                return make_pair(createNN(), word.substr(1));
            }
            auto temp = createNN();
            return make_pair(KanaAutomaton(temp.getBegin(), temp.getEnd()), word.substr(1));
        }
        case U'ぁ': return make_pair(createXA(), word.substr(1));
        case U'ぃ': return make_pair(createXI(), word.substr(1));
        case U'ぅ': return make_pair(createXU(), word.substr(1));
        case U'ぇ': return make_pair(createXE(), word.substr(1));
        case U'ぉ': return make_pair(createXO(), word.substr(1));
        case U'ゃ': return make_pair(createXYA(), word.substr(1));
        case U'ゅ': return make_pair(createXYU(), word.substr(1));
        case U'ょ': return make_pair(createXYO(), word.substr(1));
        case U'っ':
        {
            // 再帰を使いたくないけどいい方法が思いつかない
            if (word.size() == 1) { return make_pair(createXTU(), word.substr(1)); }
            auto next = select(word.substr(1));
            auto begin = make_shared<Node>(vector<Edge<Node>>());
            // 次の文字の子音を重ねて入力するパターン
            for (auto& e : next.first.getBegin()->getEdges()) {
                auto node = make_shared<Node>(vector<Edge<Node>>({e}));
                begin->addEdges({Edge(e.getTypingChar(), e.isPriority(), node)});
            }
            // x or l を使って「っ」を直接入力するパターン
            auto xtu = createXTU();
            xtu.getEnd()->addEdges(next.first.getBegin()->getEdges());
            begin->addEdges(xtu.getBegin()->getEdges());
            // オートマトンを作成
            auto result = KanaAutomaton(begin, next.first.getEnds());
            return make_pair(result, next.second);
        }
        default: return make_pair(KanaAutomaton::empty(), U"");
    }
}

pair<KanaAutomaton, u32string> AutomatonCreator::selectYouon(
    const u32string& word, const u32string& youonList,
    const vector<function<KanaAutomaton(void)>>& funcList
) {
    // 次の文字がないときは拗音なしのオートマトンを生成する
    if (word.size() == 1) {
        return make_pair(funcList.back()(), word.substr(1));
    }
    // 対応する拗音があるときは、拗音付きのオートマトンを生成する
    auto pos = u32string(youonList).find(word[1]);
    if (pos == u32string::npos) {
        return make_pair(funcList.back()(), word.substr(1));
    }
    return make_pair(funcList[pos](), word.substr(2));
}

KanaAutomaton AutomatonCreator::createA() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, end)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createI() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, end)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createU() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto wh = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto w = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'u', true, end),
        Edge(U'h', false, wh)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'u', true, end),
        Edge(U'w', false, w)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createE() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, end)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createO() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, end)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createKA() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto k = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, end)}));
    auto c = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'k', true, k),
        Edge(U'c', false, c)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createKI() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto k = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'k', true, k)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createKU() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto k = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto c = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto q = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'k', true, k),
        Edge(U'c', false, c),
        Edge(U'q', false, q)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createKE() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto k = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'k', true, k)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createKO() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto k = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, end)}));
    auto c = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'k', true, k),
        Edge(U'c', false, c)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createSA() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto s = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U's', true, s)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createSI() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto c = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, end)}));
    auto sh = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, end)}));
    auto s = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'i', true, end),
        Edge(U'h', false, sh)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U's', true, s),
        Edge(U'c', false, c)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createSU() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto s = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U's', true, s)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createSE() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto s = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, end)}));
    auto c = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U's', true, s),
        Edge(U'c', false, c)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createSO() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto s = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U's', true, s)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createTA() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto t = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U't', true, t)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createTI() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto ch = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, end)}));
    auto c = make_shared<Node>(vector<Edge<Node>>({Edge(U'h', true, ch)}));
    auto t = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U't', true, t),
        Edge(U'c', false, c)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createTU() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto ts = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto t = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'u', true, end),
        Edge(U's', false, ts)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U't', true, t)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createTE() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto t = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U't', true, t)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createTO() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto t = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U't', true, t)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createNA() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto n = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'n', true, n)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createNI() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto n = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'n', true, n)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createNU() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto n = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'n', true, n)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createNE() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto n = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'n', true, n)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createNO() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto n = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'n', true, n)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createHA() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto h = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'h', true, h)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createHI() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto h = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'h', true, h)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createHU() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto f = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto h = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'h', true, h),
        Edge(U'f', false, f)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createHE() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto h = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'h', true, h)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createHO() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto h = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'h', true, h)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createMA() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto m = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'm', true, m)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createMI() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto m = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'm', true, m)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createMU() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto m = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'm', true, m)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createME() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto m = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'm', true, m)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createMO() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto m = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'm', true, m)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createYA() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto y = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'y', true, y)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createYU() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto y = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'y', true, y)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createYO() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto y = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'y', true, y)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createRA() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto r = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'r', true, r)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createRI() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto r = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'r', true, r)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createRU() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto r = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'r', true, r)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createRE() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto r = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'r', true, r)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createRO() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto r = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'r', true, r)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createWA() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto w = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'w', true, w)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createWO() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto w = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'w', true, w)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createGA() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto g = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'g', true, g)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createGI() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto g = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'g', true, g)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createGU() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto g = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'g', true, g)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createGE() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto g = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'g', true, g)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createGO() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto g = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'g', true, g)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createZA() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto z = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'z', true, z)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createZI() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto z = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, end)}));
    auto j = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'z', true, z),
        Edge(U'j', false, j)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createZU() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto z = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'z', true, z)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createZE() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto z = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'z', true, z)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createZO() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto z = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'z', true, z)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createDA() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto d = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'd', true, d)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createDI() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto d = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'd', true, d)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createDU() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto d = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'd', true, d)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createDE() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto d = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'd', true, d)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createDO() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto d = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'd', true, d)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createBA() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto b = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'b', true, b)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createBI() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto b = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'b', true, b)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createBU() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto b = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'b', true, b)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createBE() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto b = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'b', true, b)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createBO() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto b = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'b', true, b)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createPA() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto p = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'p', true, p)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createPI() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto p = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'p', true, p)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createPU() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto p = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'p', true, p)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createPE() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto p = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'p', true, p)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createPO() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto p = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'p', true, p)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createXA() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto x = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, end)}));
    auto l = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'x', true, x),
        Edge(U'l', false, l),}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createXI() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto x = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, end)}));
    auto l = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'x', true, x),
        Edge(U'l', false, l),}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createXU() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto x = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto l = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'x', true, x),
        Edge(U'l', false, l),}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createXE() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto x = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, end)}));
    auto l = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'x', true, x),
        Edge(U'l', false, l),}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createXO() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto x = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, end)}));
    auto l = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'x', true, x),
        Edge(U'l', false, l),}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createXYA() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto xy = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, end)}));
    auto ly = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, end)}));
    auto x = make_shared<Node>(vector<Edge<Node>>({Edge(U'y', true, xy)}));
    auto l = make_shared<Node>(vector<Edge<Node>>({Edge(U'y', true, ly)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'x', true, x),
        Edge(U'l', false, l),}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createXYU() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto xy = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto ly = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto x = make_shared<Node>(vector<Edge<Node>>({Edge(U'y', true, xy)}));
    auto l = make_shared<Node>(vector<Edge<Node>>({Edge(U'y', true, ly)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'x', true, x),
        Edge(U'l', false, l),}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createXYO() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto xy = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, end)}));
    auto ly = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, end)}));
    auto x = make_shared<Node>(vector<Edge<Node>>({Edge(U'y', true, xy)}));
    auto l = make_shared<Node>(vector<Edge<Node>>({Edge(U'y', true, ly)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'x', true, x),
        Edge(U'l', false, l),}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createXTU() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto xts = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto lts = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto xt = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'u', true, end),
        Edge(U's', false, xts)}));
    auto lt = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'u', true, end),
        Edge(U's', false, lts)}));
    auto x = make_shared<Node>(vector<Edge<Node>>({Edge(U't', true, xt)}));
    auto l = make_shared<Node>(vector<Edge<Node>>({Edge(U't', true, lt)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'x', true, x),
        Edge(U'l', false, l),}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createWHA() {
    auto xa = createXA();
    auto wh = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'a', true, xa.getEnd()),
        Edge(U'u', false, xa.getBegin())}));
    auto w = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'h', true, wh),
        Edge(U'u', false, xa.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, w),
        Edge(U'u', false, xa.getBegin())}));
    return KanaAutomaton(begin, xa.getEnd());
}

KanaAutomaton AutomatonCreator::createWHI() {
    auto xi = createXI();
    auto wh = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'i', true, xi.getEnd()),
        Edge(U'u', false, xi.getBegin())}));
    auto w = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'i', true, xi.getEnd()),
        Edge(U'h', false, wh),
        Edge(U'u', false, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, w),
        Edge(U'u', false, xi.getBegin())}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createWHE() {
    auto xe = createXE();
    auto wh = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'e', true, xe.getEnd()),
        Edge(U'u', false, xe.getBegin())}));
    auto w = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'e', true, xe.getEnd()),
        Edge(U'h', false, wh),
        Edge(U'u', false, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, w),
        Edge(U'u', false, xe.getBegin())}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createWHO() {
    auto xo = createXO();
    auto wh = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'o', true, xo.getEnd()),
        Edge(U'u', false, xo.getBegin())}));
    auto w = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'h', true, wh),
        Edge(U'u', false, xo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, w),
        Edge(U'u', false, xo.getBegin())}));
    return KanaAutomaton(begin, xo.getEnd());
}

KanaAutomaton AutomatonCreator::createKYA() {
    auto xya = createXYA();
    auto ky = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xya.getEnd())}));
    auto k = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, ky),
        Edge(U'i', false, xya.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'k', true, k)}));
    return KanaAutomaton(begin, xya.getEnd());
}

KanaAutomaton AutomatonCreator::createKYI() {
    auto xi = createXI();
    auto ky = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto k = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, ky),
        Edge(U'i', false, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'k', true, k)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createKYU() {
    auto xyu = createXYU();
    auto ky = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xyu.getEnd())}));
    auto k = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, ky),
        Edge(U'i', false, xyu.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'k', true, k)}));
    return KanaAutomaton(begin, xyu.getEnd());
}

KanaAutomaton AutomatonCreator::createKYE() {
    auto xe = createXE();
    auto ky = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto k = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, ky),
        Edge(U'i', false, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'k', true, k)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createKYO() {
    auto xyo = createXYO();
    auto ky = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xyo.getEnd())}));
    auto k = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, ky),
        Edge(U'i', false, xyo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'k', true, k)}));
    return KanaAutomaton(begin, xyo.getEnd());
}

KanaAutomaton AutomatonCreator::createKWA() {
    auto xa = createXA();
    auto kw = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xa.getEnd())}));
    auto k = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, kw),
        Edge(U'u', false, xa.getBegin())}));
    auto q = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'a', true, xa.getEnd()),
        Edge(U'u', false, xa.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'k', false, k),
        Edge(U'q', true, q)}));
    return KanaAutomaton(begin, xa.getEnd());
}

KanaAutomaton AutomatonCreator::createKWI() {
    auto xi = createXI();
    auto kw = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto k = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, kw),
        Edge(U'u', false, xi.getBegin())}));
    auto q = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'i', true, xi.getEnd()),
        Edge(U'u', false, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'k', false, k),
        Edge(U'q', true, q)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createKWU() {
    auto xu = createXU();
    auto kw = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xu.getEnd())}));
    auto k = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, kw),
        Edge(U'u', false, xu.getBegin())}));
    auto q = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', false, xu.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'k', true, k),
        Edge(U'q', false, q)}));
    return KanaAutomaton(begin, xu.getEnd());
}

KanaAutomaton AutomatonCreator::createKWE() {
    auto xe = createXE();
    auto kw = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto k = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, kw),
        Edge(U'u', false, xe.getBegin())}));
    auto q = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'e', true, xe.getEnd()),
        Edge(U'u', false, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'k', false, k),
        Edge(U'q', true, q)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createKWO() {
    auto xo = createXO();
    auto kw = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xo.getEnd())}));
    auto k = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, kw),
        Edge(U'u', false, xo.getBegin())}));
    auto q = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'o', true, xo.getEnd()),
        Edge(U'u', false, xo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'k', false, k),
        Edge(U'q', true, q)}));
    return KanaAutomaton(begin, xo.getEnd());
}

KanaAutomaton AutomatonCreator::createGYA() {
    auto xya = createXYA();
    auto gy = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xya.getEnd())}));
    auto g = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, gy),
        Edge(U'i', false, xya.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'g', true, g)}));
    return KanaAutomaton(begin, xya.getEnd());
}

KanaAutomaton AutomatonCreator::createGYI() {
    auto xi = createXI();
    auto gy = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto g = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, gy),
        Edge(U'i', false, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'g', true, g)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createGYU() {
    auto xyu = createXYU();
    auto gy = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xyu.getEnd())}));
    auto g = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, gy),
        Edge(U'i', false, xyu.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'g', true, g)}));
    return KanaAutomaton(begin, xyu.getEnd());
}

KanaAutomaton AutomatonCreator::createGYE() {
    auto xe = createXE();
    auto gy = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto g = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, gy),
        Edge(U'i', false, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'g', true, g)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createGYO() {
    auto xyo = createXYO();
    auto gy = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xyo.getEnd())}));
    auto g = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, gy),
        Edge(U'i', false, xyo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'g', true, g)}));
    return KanaAutomaton(begin, xyo.getEnd());
}

KanaAutomaton AutomatonCreator::createGWA() {
    auto xa = createXA();
    auto gw = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xa.getEnd())}));
    auto g = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, gw),
        Edge(U'u', false, xa.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'g', true, g)}));
    return KanaAutomaton(begin, xa.getEnd());
}

KanaAutomaton AutomatonCreator::createGWI() {
    auto xi = createXI();
    auto gw = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto g = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, gw),
        Edge(U'u', false, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'g', true, g)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createGWU() {
    auto xu = createXU();
    auto gw = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xu.getEnd())}));
    auto g = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, gw),
        Edge(U'u', false, xu.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'g', true, g)}));
    return KanaAutomaton(begin, xu.getEnd());
}

KanaAutomaton AutomatonCreator::createGWE() {
    auto xe = createXE();
    auto gw = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto g = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, gw),
        Edge(U'u', false, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'g', true, g)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createGWO() {
    auto xo = createXO();
    auto gw = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xo.getEnd())}));
    auto g = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, gw),
        Edge(U'u', false, xo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'g', true, g)}));
    return KanaAutomaton(begin, xo.getEnd());
}

KanaAutomaton AutomatonCreator::createSYA() {
    auto xya = createXYA();
    auto sy = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xya.getEnd())}));
    auto sh = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'a', true, xya.getEnd()),
        Edge(U'i', false, xya.getBegin())}));
    auto s = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, sy),
        Edge(U'h', false, sh),
        Edge(U'i', false, xya.getBegin())}));
    auto c = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xya.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U's', true, s),
        Edge(U'c', false, c)}));
    return KanaAutomaton(begin, xya.getEnd());
}

KanaAutomaton AutomatonCreator::createSYI() {
    auto xi = createXI();
    auto sy = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto sh = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getBegin())}));
    auto s = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, sy),
        Edge(U'h', false, sh),
        Edge(U'i', false, xi.getBegin())}));
    auto c = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U's', true, s),
        Edge(U'c', false, c)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createSYU() {
    auto xyu = createXYU();
    auto sy = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xyu.getEnd())}));
    auto sh = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'u', true, xyu.getEnd()),
        Edge(U'i', false, xyu.getBegin())}));
    auto s = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, sy),
        Edge(U'h', false, sh),
        Edge(U'i', false, xyu.getBegin())}));
    auto c = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xyu.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U's', true, s),
        Edge(U'c', false, c)}));
    return KanaAutomaton(begin, xyu.getEnd());
}

KanaAutomaton AutomatonCreator::createSYE() {
    auto xe = createXE();
    auto sy = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto sh = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'e', true, xe.getEnd()),
        Edge(U'i', false, xe.getBegin())}));
    auto s = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, sy),
        Edge(U'h', false, sh),
        Edge(U'i', false, xe.getBegin())}));
    auto c = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U's', true, s),
        Edge(U'c', false, c)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createSYO() {
    auto xyo = createXYO();
    auto sy = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xyo.getEnd())}));
    auto sh = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'o', true, xyo.getEnd()),
        Edge(U'i', false, xyo.getBegin())}));
    auto s = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, sy),
        Edge(U'h', false, sh),
        Edge(U'i', false, xyo.getBegin())}));
    auto c = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xyo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U's', true, s),
        Edge(U'c', false, c)}));
    return KanaAutomaton(begin, xyo.getEnd());
}

KanaAutomaton AutomatonCreator::createSWA() {
    auto xa = createXA();
    auto sw = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xa.getEnd())}));
    auto s = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, sw),
        Edge(U'u', false, xa.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U's', true, s)}));
    return KanaAutomaton(begin, xa.getEnd());
}

KanaAutomaton AutomatonCreator::createSWI() {
    auto xi = createXI();
    auto sw = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto s = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, sw),
        Edge(U'u', false, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U's', true, s)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createSWU() {
    auto xu = createXU();
    auto sw = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xu.getEnd())}));
    auto s = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, sw),
        Edge(U'u', false, xu.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U's', true, s)}));
    return KanaAutomaton(begin, xu.getEnd());
}

KanaAutomaton AutomatonCreator::createSWE() {
    auto xe = createXE();
    auto sw = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto s = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, sw),
        Edge(U'u', false, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U's', true, s)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createSWO() {
    auto xo = createXO();
    auto sw = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xo.getEnd())}));
    auto s = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, sw),
        Edge(U'u', false, xo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U's', true, s)}));
    return KanaAutomaton(begin, xo.getEnd());
}

KanaAutomaton AutomatonCreator::createZYA() {
    auto xya = createXYA();
    auto zy = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xya.getEnd())}));
    auto jy = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xya.getEnd())}));
    auto z = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, zy),
        Edge(U'i', false, xya.getBegin())}));
    auto j = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'a', true, xya.getEnd()),
        Edge(U'y', false, jy),
        Edge(U'i', false, xya.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'z', true, z),
        Edge(U'j', false, j)}));
    return KanaAutomaton(begin, xya.getEnd());
}

KanaAutomaton AutomatonCreator::createZYI() {
    auto xi = createXI();
    auto zy = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto jy = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto z = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, zy),
        Edge(U'i', false, xi.getBegin())}));
    auto j = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, jy),
        Edge(U'i', false, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'z', true, z),
        Edge(U'j', false, j)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createZYU() {
    auto xyu = createXYU();
    auto zy = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xyu.getEnd())}));
    auto jy = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xyu.getEnd())}));
    auto z = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, zy),
        Edge(U'i', false, xyu.getBegin())}));
    auto j = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'u', true, xyu.getEnd()),
        Edge(U'y', false, jy),
        Edge(U'i', false, xyu.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'z', true, z),
        Edge(U'j', false, j)}));
    return KanaAutomaton(begin, xyu.getEnd());
}

KanaAutomaton AutomatonCreator::createZYE() {
    auto xe = createXE();
    auto zy = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto jy = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto z = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, zy),
        Edge(U'i', false, xe.getBegin())}));
    auto j = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'e', true, xe.getEnd()),
        Edge(U'y', false, jy),
        Edge(U'i', false, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'z', true, z),
        Edge(U'j', false, j)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createZYO() {
    auto xyo = createXYO();
    auto zy = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xyo.getEnd())}));
    auto jy = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xyo.getEnd())}));
    auto z = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, zy),
        Edge(U'i', false, xyo.getBegin())}));
    auto j = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'o', true, xyo.getEnd()),
        Edge(U'y', false, jy),
        Edge(U'i', false, xyo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'z', true, z),
        Edge(U'j', false, j)}));
    return KanaAutomaton(begin, xyo.getEnd());
}

KanaAutomaton AutomatonCreator::createTYA() {
    auto xya = createXYA();
    auto ty = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xya.getEnd())}));
    auto ch = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'a', true, xya.getEnd()),
        Edge(U'i', false, xya.getBegin())}));
    auto cy = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xya.getEnd())}));
    auto t = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, ty),
        Edge(U'i', false, xya.getBegin())}));
    auto c = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'h', false, ch),
        Edge(U'y', true, cy)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U't', true, t),
        Edge(U'c', false, c)}));
    return KanaAutomaton(begin, xya.getEnd());
}

KanaAutomaton AutomatonCreator::createTYI() {
    auto xi = createXI();
    auto ty = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto ch = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getBegin())}));
    auto cy = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto t = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, ty),
        Edge(U'i', false, xi.getBegin())}));
    auto c = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'h', false, ch),
        Edge(U'y', true, cy)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U't', true, t),
        Edge(U'c', false, c)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createTYU() {
    auto xyu = createXYU();
    auto ty = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xyu.getEnd())}));
    auto ch = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'u', true, xyu.getEnd()),
        Edge(U'i', false, xyu.getBegin())}));
    auto cy = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xyu.getEnd())}));
    auto t = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, ty),
        Edge(U'i', false, xyu.getBegin())}));
    auto c = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'h', false, ch),
        Edge(U'y', true, cy)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U't', true, t),
        Edge(U'c', false, c)}));
    return KanaAutomaton(begin, xyu.getEnd());
}

KanaAutomaton AutomatonCreator::createTYE() {
    auto xe = createXE();
    auto ty = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto ch = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'e', true, xe.getEnd()),
        Edge(U'i', false, xe.getBegin())}));
    auto cy = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto t = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, ty),
        Edge(U'i', false, xe.getBegin())}));
    auto c = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'h', false, ch),
        Edge(U'y', true, cy)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U't', true, t),
        Edge(U'c', false, c)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createTYO() {
    auto xyo = createXYO();
    auto ty = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xyo.getEnd())}));
    auto ch = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'o', true, xyo.getEnd()),
        Edge(U'i', false, xyo.getBegin())}));
    auto cy = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xyo.getEnd())}));
    auto t = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, ty),
        Edge(U'i', false, xyo.getBegin())}));
    auto c = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'h', false, ch),
        Edge(U'y', true, cy)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U't', true, t),
        Edge(U'c', false, c)}));
    return KanaAutomaton(begin, xyo.getEnd());
}

KanaAutomaton AutomatonCreator::createTSA() {
    auto xa = createXA();
    auto ts = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'a', true, xa.getEnd()),
        Edge(U'u', false, xa.getBegin())}));
    auto t = make_shared<Node>(vector<Edge<Node>>({
        Edge(U's', true, ts),
        Edge(U'u', false, xa.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U't', true, t)}));
    return KanaAutomaton(begin, xa.getEnd());
}

KanaAutomaton AutomatonCreator::createTSI() {
    auto xi = createXI();
    auto ts = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'i', true, xi.getEnd()),
        Edge(U'u', false, xi.getBegin())}));
    auto t = make_shared<Node>(vector<Edge<Node>>({
        Edge(U's', true, ts),
        Edge(U'u', false, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U't', true, t)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createTSE() {
    auto xe = createXE();
    auto ts = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'e', true, xe.getEnd()),
        Edge(U'u', false, xe.getBegin())}));
    auto t = make_shared<Node>(vector<Edge<Node>>({
        Edge(U's', true, ts),
        Edge(U'u', false, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U't', true, t)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createTSO() {
    auto xo = createXO();
    auto ts = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'o', true, xo.getEnd()),
        Edge(U'u', false, xo.getBegin())}));
    auto t = make_shared<Node>(vector<Edge<Node>>({
        Edge(U's', true, ts),
        Edge(U'u', false, xo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U't', true, t)}));
    return KanaAutomaton(begin, xo.getEnd());
}

KanaAutomaton AutomatonCreator::createTHA() {
    auto xya = createXYA();
    auto th = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xya.getEnd())}));
    auto t = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'h', true, th),
        Edge(U'e', false, xya.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U't', true, t)}));
    return KanaAutomaton(begin, xya.getEnd());
}

KanaAutomaton AutomatonCreator::createTHI() {
    auto xi = createXI();
    auto th = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto t = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'h', true, th),
        Edge(U'e', false, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U't', true, t)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createTHU() {
    auto xyu = createXYU();
    auto th = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xyu.getEnd())}));
    auto t = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'h', true, th),
        Edge(U'e', false, xyu.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U't', true, t)}));
    return KanaAutomaton(begin, xyu.getEnd());
}

KanaAutomaton AutomatonCreator::createTHE() {
    auto xe = createXE();
    auto th = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto t = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'h', true, th),
        Edge(U'e', false, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U't', true, t)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createTHO() {
    auto xyo = createXYO();
    auto th = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xyo.getEnd())}));
    auto t = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'h', true, th),
        Edge(U'e', false, xyo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U't', true, t)}));
    return KanaAutomaton(begin, xyo.getEnd());
}

KanaAutomaton AutomatonCreator::createTWA() {
    auto xa = createXA();
    auto tw = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xa.getEnd())}));
    auto t = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, tw),
        Edge(U'o', false, xa.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U't', true, t)}));
    return KanaAutomaton(begin, xa.getEnd());
}

KanaAutomaton AutomatonCreator::createTWI() {
    auto xi = createXI();
    auto tw = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto t = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, tw),
        Edge(U'o', false, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U't', true, t)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createTWU() {
    auto xu = createXU();
    auto tw = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xu.getEnd())}));
    auto t = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, tw),
        Edge(U'o', false, xu.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U't', true, t)}));
    return KanaAutomaton(begin, xu.getEnd());
}

KanaAutomaton AutomatonCreator::createTWE() {
    auto xe = createXE();
    auto tw = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto t = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, tw),
        Edge(U'o', false, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U't', true, t)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createTWO() {
    auto xo = createXO();
    auto tw = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xo.getEnd())}));
    auto t = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, tw),
        Edge(U'o', false, xo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U't', true, t)}));
    return KanaAutomaton(begin, xo.getEnd());
}

KanaAutomaton AutomatonCreator::createDYA() {
    auto xya = createXYA();
    auto dy = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xya.getEnd())}));
    auto d = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, dy),
        Edge(U'i', false, xya.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'd', true, d)}));
    return KanaAutomaton(begin, xya.getEnd());
}

KanaAutomaton AutomatonCreator::createDYI() {
    auto xi = createXI();
    auto dy = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto d = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, dy),
        Edge(U'i', false, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'd', true, d)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createDYU() {
    auto xyu = createXYU();
    auto dy = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xyu.getEnd())}));
    auto d = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, dy),
        Edge(U'i', false, xyu.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'd', true, d)}));
    return KanaAutomaton(begin, xyu.getEnd());
}

KanaAutomaton AutomatonCreator::createDYE() {
    auto xe = createXE();
    auto dy = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto d = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, dy),
        Edge(U'i', false, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'd', true, d)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createDYO() {
    auto xyo = createXYO();
    auto dy = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xyo.getEnd())}));
    auto d = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, dy),
        Edge(U'i', false, xyo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'd', true, d)}));
    return KanaAutomaton(begin, xyo.getEnd());
}

KanaAutomaton AutomatonCreator::createDHA() {
    auto xya = createXYA();
    auto dh = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xya.getEnd())}));
    auto d = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'h', true, dh),
        Edge(U'e', false, xya.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'd', true, d)}));
    return KanaAutomaton(begin, xya.getEnd());
}

KanaAutomaton AutomatonCreator::createDHI() {
    auto xi = createXI();
    auto dh = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto d = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'h', true, dh),
        Edge(U'e', false, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'd', true, d)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createDHU() {
    auto xyu = createXYU();
    auto dh = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xyu.getEnd())}));
    auto d = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'h', true, dh),
        Edge(U'e', false, xyu.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'd', true, d)}));
    return KanaAutomaton(begin, xyu.getEnd());
}

KanaAutomaton AutomatonCreator::createDHE() {
    auto xe = createXE();
    auto dh = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto d = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'h', true, dh),
        Edge(U'e', false, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'd', true, d)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createDHO() {
    auto xyo = createXYO();
    auto dh = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xyo.getEnd())}));
    auto d = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'h', true, dh),
        Edge(U'e', false, xyo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'd', true, d)}));
    return KanaAutomaton(begin, xyo.getEnd());
}

KanaAutomaton AutomatonCreator::createDWA() {
    auto xa = createXA();
    auto dw = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xa.getEnd())}));
    auto d = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, dw),
        Edge(U'o', false, xa.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'd', true, d)}));
    return KanaAutomaton(begin, xa.getEnd());
}

KanaAutomaton AutomatonCreator::createDWI() {
    auto xi = createXI();
    auto dw = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto d = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, dw),
        Edge(U'o', false, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'd', true, d)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createDWU() {
    auto xu = createXU();
    auto dw = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xu.getEnd())}));
    auto d = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, dw),
        Edge(U'o', false, xu.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'd', true, d)}));
    return KanaAutomaton(begin, xu.getEnd());
}

KanaAutomaton AutomatonCreator::createDWE() {
    auto xe = createXE();
    auto dw = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto d = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, dw),
        Edge(U'o', false, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'd', true, d)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createDWO() {
    auto xo = createXO();
    auto dw = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xo.getEnd())}));
    auto d = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, dw),
        Edge(U'o', false, xo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'd', true, d)}));
    return KanaAutomaton(begin, xo.getEnd());
}

KanaAutomaton AutomatonCreator::createNYA() {
    auto xya = createXYA();
    auto ny = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xya.getEnd())}));
    auto n = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, ny),
        Edge(U'i', false, xya.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'n', true, n)}));
    return KanaAutomaton(begin, xya.getEnd());
}

KanaAutomaton AutomatonCreator::createNYI() {
    auto xi = createXI();
    auto ny = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto n = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, ny),
        Edge(U'i', false, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'n', true, n)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createNYU() {
    auto xyu = createXYU();
    auto ny = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xyu.getEnd())}));
    auto n = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, ny),
        Edge(U'i', false, xyu.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'n', true, n)}));
    return KanaAutomaton(begin, xyu.getEnd());
}

KanaAutomaton AutomatonCreator::createNYE() {
    auto xe = createXE();
    auto ny = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto n = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, ny),
        Edge(U'i', false, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'n', true, n)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createNYO() {
    auto xyo = createXYO();
    auto ny = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xyo.getEnd())}));
    auto n = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, ny),
        Edge(U'i', false, xyo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'n', true, n)}));
    return KanaAutomaton(begin, xyo.getEnd());
}

KanaAutomaton AutomatonCreator::createHYA() {
    auto xya = createXYA();
    auto hy = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xya.getEnd())}));
    auto h = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, hy),
        Edge(U'i', false, xya.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'h', true, h)}));
    return KanaAutomaton(begin, xya.getEnd());
}

KanaAutomaton AutomatonCreator::createHYI() {
    auto xi = createXI();
    auto hy = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto h = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, hy),
        Edge(U'i', false, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'h', true, h)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createHYU() {
    auto xyu = createXYU();
    auto hy = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xyu.getEnd())}));
    auto h = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, hy),
        Edge(U'i', false, xyu.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'h', true, h)}));
    return KanaAutomaton(begin, xyu.getEnd());
}

KanaAutomaton AutomatonCreator::createHYE() {
    auto xe = createXE();
    auto hy = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto h = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, hy),
        Edge(U'i', false, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'h', true, h)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createHYO() {
    auto xyo = createXYO();
    auto hy = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xyo.getEnd())}));
    auto h = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, hy),
        Edge(U'i', false, xyo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'h', true, h)}));
    return KanaAutomaton(begin, xyo.getEnd());
}

KanaAutomaton AutomatonCreator::createFWA() {
    auto xa = createXA();
    auto fw = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xa.getEnd())}));
    auto f = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'a', true, xa.getEnd()),
        Edge(U'w', false, fw),
        Edge(U'u', false, xa.getBegin())}));
    auto h = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xa.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'f', true, f),
        Edge(U'h', false, h)}));
    return KanaAutomaton(begin, xa.getEnd());
}

KanaAutomaton AutomatonCreator::createFWI() {
    auto xi = createXI();
    auto fw = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto f = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'i', true, xi.getEnd()),
        Edge(U'w', false, fw),
        Edge(U'u', false, xi.getBegin())}));
    auto h = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'f', true, f),
        Edge(U'h', false, h)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createFWU() {
    auto xu = createXU();
    auto fw = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xu.getEnd())}));
    auto f = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'w', true, fw),
        Edge(U'u', false, xu.getBegin())}));
    auto h = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xu.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'f', true, f),
        Edge(U'h', false, h)}));
    return KanaAutomaton(begin, xu.getEnd());
}

KanaAutomaton AutomatonCreator::createFWE() {
    auto xe = createXE();
    auto fw = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto f = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'e', true, xe.getEnd()),
        Edge(U'w', false, fw),
        Edge(U'u', false, xe.getBegin())}));
    auto h = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'f', true, f),
        Edge(U'h', false, h)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createFWO() {
    auto xo = createXO();
    auto fw = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xo.getEnd())}));
    auto f = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'o', true, xo.getEnd()),
        Edge(U'w', false, fw),
        Edge(U'u', false, xo.getBegin())}));
    auto h = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'f', true, f),
        Edge(U'h', false, h)}));
    return KanaAutomaton(begin, xo.getEnd());
}

KanaAutomaton AutomatonCreator::createFYA() {
    auto xya = createXYA();
    auto fy = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xya.getEnd())}));
    auto f = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, fy),
        Edge(U'u', false, xya.getBegin())}));
    auto h = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xya.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'f', true, f),
        Edge(U'h', false, h)}));
    return KanaAutomaton(begin, xya.getEnd());
}

KanaAutomaton AutomatonCreator::createFYU() {
    auto xyu = createXYU();
    auto fy = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xyu.getEnd())}));
    auto f = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, fy),
        Edge(U'u', false, xyu.getBegin())}));
    auto h = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xyu.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'f', true, f),
        Edge(U'h', false, h)}));
    return KanaAutomaton(begin, xyu.getEnd());
}

KanaAutomaton AutomatonCreator::createFYO() {
    auto xyo = createXYO();
    auto fy = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xyo.getEnd())}));
    auto f = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, fy),
        Edge(U'u', false, xyo.getBegin())}));
    auto h = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xyo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'f', true, f),
        Edge(U'h', false, h)}));
    return KanaAutomaton(begin, xyo.getEnd());
}

KanaAutomaton AutomatonCreator::createBYA() {
    auto xya = createXYA();
    auto by = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xya.getEnd())}));
    auto b = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, by),
        Edge(U'i', false, xya.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'b', true, b)}));
    return KanaAutomaton(begin, xya.getEnd());
}

KanaAutomaton AutomatonCreator::createBYI() {
    auto xi = createXI();
    auto by = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto b = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, by),
        Edge(U'i', false, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'b', true, b)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createBYU() {
    auto xyu = createXYU();
    auto by = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xyu.getEnd())}));
    auto b = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, by),
        Edge(U'i', false, xyu.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'b', true, b)}));
    return KanaAutomaton(begin, xyu.getEnd());
}

KanaAutomaton AutomatonCreator::createBYE() {
    auto xe = createXE();
    auto by = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto b = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, by),
        Edge(U'i', false, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'b', true, b)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createBYO() {
    auto xyo = createXYO();
    auto by = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xyo.getEnd())}));
    auto b = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, by),
        Edge(U'i', false, xyo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'b', true, b)}));
    return KanaAutomaton(begin, xyo.getEnd());
}

KanaAutomaton AutomatonCreator::createPYA() {
    auto xya = createXYA();
    auto py = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xya.getEnd())}));
    auto p = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, py),
        Edge(U'i', false, xya.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'p', true, p)}));
    return KanaAutomaton(begin, xya.getEnd());
}

KanaAutomaton AutomatonCreator::createPYI() {
    auto xi = createXI();
    auto py = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto p = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, py),
        Edge(U'i', false, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'p', true, p)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createPYU() {
    auto xyu = createXYU();
    auto py = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xyu.getEnd())}));
    auto p = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, py),
        Edge(U'i', false, xyu.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'p', true, p)}));
    return KanaAutomaton(begin, xyu.getEnd());
}

KanaAutomaton AutomatonCreator::createPYE() {
    auto xe = createXE();
    auto py = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto p = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, py),
        Edge(U'i', false, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'p', true, p)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createPYO() {
    auto xyo = createXYO();
    auto py = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xyo.getEnd())}));
    auto p = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, py),
        Edge(U'i', false, xyo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'p', true, p)}));
    return KanaAutomaton(begin, xyo.getEnd());
}

KanaAutomaton AutomatonCreator::createMYA() {
    auto xya = createXYA();
    auto my = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xya.getEnd())}));
    auto m = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, my),
        Edge(U'i', false, xya.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'm', true, m)}));
    return KanaAutomaton(begin, xya.getEnd());
}

KanaAutomaton AutomatonCreator::createMYI() {
    auto xi = createXI();
    auto my = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto m = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, my),
        Edge(U'i', false, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'm', true, m)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createMYU() {
    auto xyu = createXYU();
    auto my = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xyu.getEnd())}));
    auto m = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, my),
        Edge(U'i', false, xyu.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'm', true, m)}));
    return KanaAutomaton(begin, xyu.getEnd());
}

KanaAutomaton AutomatonCreator::createMYE() {
    auto xe = createXE();
    auto my = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto m = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, my),
        Edge(U'i', false, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'm', true, m)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createMYO() {
    auto xyo = createXYO();
    auto my = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xyo.getEnd())}));
    auto m = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, my),
        Edge(U'i', false, xyo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'm', true, m)}));
    return KanaAutomaton(begin, xyo.getEnd());
}

KanaAutomaton AutomatonCreator::createRYA() {
    auto xya = createXYA();
    auto ry = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xya.getEnd())}));
    auto r = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, ry),
        Edge(U'i', false, xya.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'r', true, r)}));
    return KanaAutomaton(begin, xya.getEnd());
}

KanaAutomaton AutomatonCreator::createRYI() {
    auto xi = createXI();
    auto ry = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto r = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, ry),
        Edge(U'i', false, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'r', true, r)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createRYU() {
    auto xyu = createXYU();
    auto ry = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xyu.getEnd())}));
    auto r = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, ry),
        Edge(U'i', false, xyu.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'r', true, r)}));
    return KanaAutomaton(begin, xyu.getEnd());
}

KanaAutomaton AutomatonCreator::createRYE() {
    auto xe = createXE();
    auto ry = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto r = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, ry),
        Edge(U'i', false, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'r', true, r)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createRYO() {
    auto xyo = createXYO();
    auto ry = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xyo.getEnd())}));
    auto r = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, ry),
        Edge(U'i', false, xyo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'r', true, r)}));
    return KanaAutomaton(begin, xyo.getEnd());
}

KanaAutomaton AutomatonCreator::createVA() {
    auto xa = createXA();
    auto v = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'a', true, xa.getEnd()),
        Edge(U'u', false, xa.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'v', true, v)}));
    return KanaAutomaton(begin, xa.getEnd());
}

KanaAutomaton AutomatonCreator::createVI() {
    auto xi = createXI();
    auto vy = make_shared<Node>(vector<Edge<Node>>({Edge(U'i', true, xi.getEnd())}));
    auto v = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'i', true, xi.getEnd()),
        Edge(U'y', false, vy),
        Edge(U'u', false, xi.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'v', true, v)}));
    return KanaAutomaton(begin, xi.getEnd());
}

KanaAutomaton AutomatonCreator::createVU() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto v = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'v', true, v)}));
    return KanaAutomaton(begin, end);
}

KanaAutomaton AutomatonCreator::createVE() {
    auto xe = createXE();
    auto vy = make_shared<Node>(vector<Edge<Node>>({Edge(U'e', true, xe.getEnd())}));
    auto v = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'e', true, xe.getEnd()),
        Edge(U'y', false, vy),
        Edge(U'u', false, xe.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'v', true, v)}));
    return KanaAutomaton(begin, xe.getEnd());
}

KanaAutomaton AutomatonCreator::createVO() {
    auto xo = createXO();
    auto v = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'o', true, xo.getEnd()),
        Edge(U'u', false, xo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'v', true, v)}));
    return KanaAutomaton(begin, xo.getEnd());
}

KanaAutomaton AutomatonCreator::createVYA() {
    auto xya = createXYA();
    auto vy = make_shared<Node>(vector<Edge<Node>>({Edge(U'a', true, xya.getEnd())}));
    auto v = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, vy),
        Edge(U'u', false, xya.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'v', true, v)}));
    return KanaAutomaton(begin, xya.getEnd());
}

KanaAutomaton AutomatonCreator::createVYU() {
    auto xyu = createXYU();
    auto vy = make_shared<Node>(vector<Edge<Node>>({Edge(U'u', true, xyu.getEnd())}));
    auto v = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, vy),
        Edge(U'u', false, xyu.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'v', true, v)}));
    return KanaAutomaton(begin, xyu.getEnd());
}

KanaAutomaton AutomatonCreator::createVYO() {
    auto xyo = createXYO();
    auto vy = make_shared<Node>(vector<Edge<Node>>({Edge(U'o', true, xyo.getEnd())}));
    auto v = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'y', true, vy),
        Edge(U'u', false, xyo.getBegin())}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({Edge(U'v', true, v)}));
    return KanaAutomaton(begin, xyo.getEnd());
}

KanaAutomaton AutomatonCreator::createNN() {
    auto end = make_shared<Node>(vector<Edge<Node>>());
    auto n = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'n', true, end),
        Edge(U'\'', false, end)}));
    auto x = make_shared<Node>(vector<Edge<Node>>({Edge(U'n', true, end)}));
    auto begin = make_shared<Node>(vector<Edge<Node>>({
        Edge(U'n', true, n),
        Edge(U'x', false, x)}));
    return KanaAutomaton(begin, begin, {end, n});
}
}