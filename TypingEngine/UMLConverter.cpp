#include "UMLConverter.h"
#include "TypingEngine.h"
#include "Node.h"

#include <queue>
#include <memory>
#include <set>
#include <map>
#include <numeric>

namespace TypingEngine {

using namespace std;

u32string UMLConverter::toPlantUML(const TypingEngine& engine) {
    auto automaton = engine.getAutomaton();
    // Automatonを幅優先で全探索してNode間の隣接情報を取得する
    queue<tuple<shared_ptr<Node>, shared_ptr<Node>, char32_t>> adjacencies;
    deque<shared_ptr<Node>> searches;
    auto nowNode = automaton.getBegin();
    while (true) {
        for (auto& e : nowNode->getEdges()) {
            adjacencies.push({nowNode, e.getNext(), e.getTypingChar()});
            // 計算量削減のためにQueueにないものだけEnqueueする
            // 重複して探索するコストよりも、検索コストのほうが小さいはず
            if (find(searches.begin(), searches.end(), e.getNext()) == searches.end()) {
                searches.push_back(e.getNext());
            }
        }
        if (searches.empty()) { break; }
        nowNode = searches.front();
        searches.pop_front();
    }
    // 隣接情報からNodeの名前を決定してPlantUML文を作成
    map<shared_ptr<Node>, u32string> names;
    set<u32string> umlDoc;
    while (!adjacencies.empty()) {
        auto& [prev, next, c] = adjacencies.front();
        adjacencies.pop();
        u32string cPrev = names.contains(prev) ? names[prev] : U"[*]";
        u32string cNext =
            next == automaton.getEnd() ? U"[*]" :
            names.contains(next) ? names[next] :
            names.contains(prev) ? names[prev] + c :
            u32string() + c;
        names.insert(make_pair(next, cNext));
        umlDoc.insert(cPrev + U" --> " + cNext + U" : " + c);
    }
    // PlantUMLの状態遷移図生成文を作成
    u32string result = accumulate(
        umlDoc.begin(),
        umlDoc.end(),
        u32string(U"@startuml\nhide empty description\n"),
        [](const u32string& acc, const u32string& uml) { return acc + uml + U'\n'; });
    return result + U"@enduml\n";
}
}