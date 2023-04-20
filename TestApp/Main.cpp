# include <Siv3D.hpp> // OpenSiv3D v0.6.6

#include "../TypingEngine/TypingEngine.h"
#include "../TypingEngine/UMLConverter.h"

char32_t inputKey() {
	const Array<Input> keys = Keyboard::GetAllInputs();
	for (const auto& key : keys) {
		if (key.down()) {
			auto str = key.name().lowercased();
			if (str.size() == 1) {
				return str.c_str()[0];
			}
		}
	}
	return U'\0';
}

void Main() {
	Scene::SetBackground(ColorF{ 0.8, 0.9, 1.0 });
	const Font font{ 40 };

	TextEditState teWord;

	int state = 0;

	String example = U"";
	auto engine = TypingEngine::TypingEngine::create(U"");

	while (System::Update()) {

		bool isVisibleEdit = true;
		switch (state) {
			case 0:
				// お題入力モード

				break;
			case 1:
				// タイピングモード
				if (engine.isFinished()) {
					example = U"";
					engine = TypingEngine::TypingEngine::create(U"");
					state = 0;
					break;
				}
				isVisibleEdit = false;
				char32_t input = inputKey();
				if (input != U'\0') {
					Print << U"put key: " << input;
					auto result = engine.type(input);
					engine = result.value_or(engine);
					example = engine.getAccumulatedInputChar() + engine.romanizedRemining();
					
				}
				break;
		}
		
		SimpleGUI::TextBox(teWord, Vec2{ 240, 80 }, 260, 30, isVisibleEdit);
		if (SimpleGUI::Button(U"Generate", Vec2{ 500, 80 }, unspecified, isVisibleEdit)) {
			engine = TypingEngine::TypingEngine::create(teWord.text.toUTF32());
			example = engine.romanized();
			state = 1;
			Logger << TypingEngine::UMLConverter::toPlantUML(engine);
		}

		auto pos = font(example).drawAt(Vec2{ 400, 200 }, Palette::Darkgray).pos;
		font(engine.getAccumulatedInputChar()).draw(pos, Palette::Black);
	}
}
