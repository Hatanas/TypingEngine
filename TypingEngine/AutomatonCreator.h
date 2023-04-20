#pragma once

#include <string>
#include <vector>
#include <functional>

namespace TypingEngine {

class KanaAutomaton;

class AutomatonCreator {
public:
    static KanaAutomaton create(const std::u32string& word);
private:
    /// <summary>
    /// 入力した文字に対応したオートマトンを返す
    /// </summary>
    /// <param name="word">オートマトンを生成する文字列</param>
    /// <returns>オートマトンと余った文字列</returns>
    static std::pair<KanaAutomaton, std::u32string> select(const std::u32string& word);

    /// <summary>
    /// 拗音付き文字に対応したオートマトンを返す
    /// </summary>
    /// <param name="word">オートマトンを生成する文字列</param>
    /// <returns>オートマトンと余った文字列</returns>
    static std::pair<KanaAutomaton, std::u32string> selectYouon(const std::u32string& word, const std::u32string& youonList, const std::vector<std::function<KanaAutomaton(void)>>& funcList);

    static KanaAutomaton createA();
    static KanaAutomaton createI();
    static KanaAutomaton createU();
    static KanaAutomaton createE();
    static KanaAutomaton createO();
    static KanaAutomaton createWHA();
    static KanaAutomaton createWHI();
    static KanaAutomaton createWHE();
    static KanaAutomaton createWHO();
    static KanaAutomaton createKA();
    static KanaAutomaton createKI();
    static KanaAutomaton createKU();
    static KanaAutomaton createKE();
    static KanaAutomaton createKO();
    static KanaAutomaton createKYA();
    static KanaAutomaton createKYI();
    static KanaAutomaton createKYU();
    static KanaAutomaton createKYE();
    static KanaAutomaton createKYO();
    static KanaAutomaton createKWA();
    static KanaAutomaton createKWI();
    static KanaAutomaton createKWU();
    static KanaAutomaton createKWE();
    static KanaAutomaton createKWO();
    static KanaAutomaton createSA();
    static KanaAutomaton createSI();
    static KanaAutomaton createSU();
    static KanaAutomaton createSE();
    static KanaAutomaton createSO();
    static KanaAutomaton createSYA();
    static KanaAutomaton createSYI();
    static KanaAutomaton createSYU();
    static KanaAutomaton createSYE();
    static KanaAutomaton createSYO();
    static KanaAutomaton createSWA();
    static KanaAutomaton createSWI();
    static KanaAutomaton createSWU();
    static KanaAutomaton createSWE();
    static KanaAutomaton createSWO();
    static KanaAutomaton createTA();
    static KanaAutomaton createTI();
    static KanaAutomaton createTU();
    static KanaAutomaton createTE();
    static KanaAutomaton createTO();
    static KanaAutomaton createTYA();
    static KanaAutomaton createTYI();
    static KanaAutomaton createTYU();
    static KanaAutomaton createTYE();
    static KanaAutomaton createTYO();
    static KanaAutomaton createTSA();
    static KanaAutomaton createTSI();
    static KanaAutomaton createTSE();
    static KanaAutomaton createTSO();
    static KanaAutomaton createTHA();
    static KanaAutomaton createTHI();
    static KanaAutomaton createTHU();
    static KanaAutomaton createTHE();
    static KanaAutomaton createTHO();
    static KanaAutomaton createTWA();
    static KanaAutomaton createTWI();
    static KanaAutomaton createTWU();
    static KanaAutomaton createTWE();
    static KanaAutomaton createTWO();
    static KanaAutomaton createNA();
    static KanaAutomaton createNI();
    static KanaAutomaton createNU();
    static KanaAutomaton createNE();
    static KanaAutomaton createNO();
    static KanaAutomaton createNYA();
    static KanaAutomaton createNYI();
    static KanaAutomaton createNYU();
    static KanaAutomaton createNYE();
    static KanaAutomaton createNYO();
    static KanaAutomaton createHA();
    static KanaAutomaton createHI();
    static KanaAutomaton createHU();
    static KanaAutomaton createHE();
    static KanaAutomaton createHO();
    static KanaAutomaton createHYA();
    static KanaAutomaton createHYI();
    static KanaAutomaton createHYU();
    static KanaAutomaton createHYE();
    static KanaAutomaton createHYO();
    static KanaAutomaton createFWA();
    static KanaAutomaton createFWI();
    static KanaAutomaton createFWU();
    static KanaAutomaton createFWE();
    static KanaAutomaton createFWO();
    static KanaAutomaton createFYA();
    static KanaAutomaton createFYU();
    static KanaAutomaton createFYO();
    static KanaAutomaton createMA();
    static KanaAutomaton createMI();
    static KanaAutomaton createMU();
    static KanaAutomaton createME();
    static KanaAutomaton createMO();
    static KanaAutomaton createMYA();
    static KanaAutomaton createMYI();
    static KanaAutomaton createMYU();
    static KanaAutomaton createMYE();
    static KanaAutomaton createMYO();
    static KanaAutomaton createYA();
    static KanaAutomaton createYU();
    static KanaAutomaton createYO();
    static KanaAutomaton createRA();
    static KanaAutomaton createRI();
    static KanaAutomaton createRU();
    static KanaAutomaton createRE();
    static KanaAutomaton createRO();
    static KanaAutomaton createRYA();
    static KanaAutomaton createRYI();
    static KanaAutomaton createRYU();
    static KanaAutomaton createRYE();
    static KanaAutomaton createRYO();
    static KanaAutomaton createWA();
    static KanaAutomaton createWO();
    static KanaAutomaton createNN();
    static KanaAutomaton createGA();
    static KanaAutomaton createGI();
    static KanaAutomaton createGU();
    static KanaAutomaton createGE();
    static KanaAutomaton createGO();
    static KanaAutomaton createGYA();
    static KanaAutomaton createGYI();
    static KanaAutomaton createGYU();
    static KanaAutomaton createGYE();
    static KanaAutomaton createGYO();
    static KanaAutomaton createGWA();
    static KanaAutomaton createGWI();
    static KanaAutomaton createGWU();
    static KanaAutomaton createGWE();
    static KanaAutomaton createGWO();
    static KanaAutomaton createZA();
    static KanaAutomaton createZI();
    static KanaAutomaton createZU();
    static KanaAutomaton createZE();
    static KanaAutomaton createZO();
    static KanaAutomaton createZYA();
    static KanaAutomaton createZYI();
    static KanaAutomaton createZYU();
    static KanaAutomaton createZYE();
    static KanaAutomaton createZYO();
    static KanaAutomaton createDA();
    static KanaAutomaton createDI();
    static KanaAutomaton createDU();
    static KanaAutomaton createDE();
    static KanaAutomaton createDO();
    static KanaAutomaton createDYA();
    static KanaAutomaton createDYI();
    static KanaAutomaton createDYU();
    static KanaAutomaton createDYE();
    static KanaAutomaton createDYO();
    static KanaAutomaton createDHA();
    static KanaAutomaton createDHI();
    static KanaAutomaton createDHU();
    static KanaAutomaton createDHE();
    static KanaAutomaton createDHO();
    static KanaAutomaton createDWA();
    static KanaAutomaton createDWI();
    static KanaAutomaton createDWU();
    static KanaAutomaton createDWE();
    static KanaAutomaton createDWO();
    static KanaAutomaton createBA();
    static KanaAutomaton createBI();
    static KanaAutomaton createBU();
    static KanaAutomaton createBE();
    static KanaAutomaton createBO();
    static KanaAutomaton createBYA();
    static KanaAutomaton createBYI();
    static KanaAutomaton createBYU();
    static KanaAutomaton createBYE();
    static KanaAutomaton createBYO();
    static KanaAutomaton createPA();
    static KanaAutomaton createPI();
    static KanaAutomaton createPU();
    static KanaAutomaton createPE();
    static KanaAutomaton createPO();
    static KanaAutomaton createPYA();
    static KanaAutomaton createPYI();
    static KanaAutomaton createPYU();
    static KanaAutomaton createPYE();
    static KanaAutomaton createPYO();
    static KanaAutomaton createVA();
    static KanaAutomaton createVI();
    static KanaAutomaton createVU();
    static KanaAutomaton createVE();
    static KanaAutomaton createVO();
    static KanaAutomaton createVYA();
    static KanaAutomaton createVYU();
    static KanaAutomaton createVYO();
    static KanaAutomaton createXA();
    static KanaAutomaton createXI();
    static KanaAutomaton createXU();
    static KanaAutomaton createXE();
    static KanaAutomaton createXO();
    static KanaAutomaton createXYA();
    static KanaAutomaton createXYU();
    static KanaAutomaton createXYO();
    static KanaAutomaton createXTU();
};
}