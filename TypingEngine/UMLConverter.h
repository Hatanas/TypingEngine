#pragma once

#include <string>

namespace TypingEngine {

class TypingEngine;

class UMLConverter {
public:
    static std::u32string toPlantUML(const TypingEngine& engine);
};
}
