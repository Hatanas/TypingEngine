#include "pch.h"
#include "Matcher.h"
#include "KanaAutomaton.h"
#include "AutomatonCreator.h"

namespace TypingEngineTest {

using namespace TypingEngine;
using namespace std;
using namespace testing;

TEST(AutomatonCreatorTest, CreateA) {
    auto automaton = AutomatonCreator::create(U"あ");
    EXPECT_TRUE(automaton.transitByInput(U"a").isAccepted());
    EXPECT_EQ(U"a", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateI) {
    auto automaton = AutomatonCreator::create(U"い");
    EXPECT_TRUE(automaton.transitByInput(U"i").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"yi").isAccepted());
    EXPECT_EQ(U"i", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"yi", automaton.transitByInput(U"y").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateU) {
    auto automaton = AutomatonCreator::create(U"う");
    EXPECT_TRUE(automaton.transitByInput(U"u").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"wu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"whu").isAccepted());
    EXPECT_EQ(U"u", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"wu", automaton.transitByInput(U"w").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"whu", automaton.transitByInput(U"wh").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateE) {
    auto automaton = AutomatonCreator::create(U"え");
    EXPECT_TRUE(automaton.transitByInput(U"e").isAccepted());
    EXPECT_EQ(U"e", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateO) {
    auto automaton = AutomatonCreator::create(U"お");
    EXPECT_TRUE(automaton.transitByInput(U"o").isAccepted());
    EXPECT_EQ(U"o", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateYE) {
    auto automaton = AutomatonCreator::create(U"いぇ");
    EXPECT_TRUE(automaton.transitByInput(U"ye").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"yixe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"yile").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"ixe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"ile").isAccepted());
    EXPECT_EQ(U"ye", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"ye", automaton.transitByInput(U"y").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"yixe", automaton.transitByInput(U"yi").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"yixe", automaton.transitByInput(U"yix").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"yile", automaton.transitByInput(U"yil").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"ixe", automaton.transitByInput(U"i").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"ixe", automaton.transitByInput(U"ix").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"ile", automaton.transitByInput(U"il").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateWHA) {
    auto automaton = AutomatonCreator::create(U"うぁ");
    EXPECT_TRUE(automaton.transitByInput(U"wha").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"wuxa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"wula").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"whuxa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"whula").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"uxa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"ula").isAccepted());
    EXPECT_EQ(U"wha", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"wha", automaton.transitByInput(U"w").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"wha", automaton.transitByInput(U"wh").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"whuxa", automaton.transitByInput(U"whu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"whuxa", automaton.transitByInput(U"whux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"whula", automaton.transitByInput(U"whul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"wuxa", automaton.transitByInput(U"wu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"wuxa", automaton.transitByInput(U"wux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"wula", automaton.transitByInput(U"wul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"uxa", automaton.transitByInput(U"u").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"uxa", automaton.transitByInput(U"ux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"ula", automaton.transitByInput(U"ul").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateWHI) {
    auto automaton = AutomatonCreator::create(U"うぃ");
    EXPECT_TRUE(automaton.transitByInput(U"wi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"whi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"wuxi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"wuli").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"whuxi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"whuli").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"uxi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"uli").isAccepted());
    EXPECT_EQ(U"wi", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"wi", automaton.transitByInput(U"w").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"whi", automaton.transitByInput(U"wh").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"whuxi", automaton.transitByInput(U"whu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"whuxi", automaton.transitByInput(U"whux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"whuli", automaton.transitByInput(U"whul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"wuxi", automaton.transitByInput(U"wu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"wuxi", automaton.transitByInput(U"wux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"wuli", automaton.transitByInput(U"wul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"uxi", automaton.transitByInput(U"u").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"uxi", automaton.transitByInput(U"ux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"uli", automaton.transitByInput(U"ul").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateWHE) {
    auto automaton = AutomatonCreator::create(U"うぇ");
    EXPECT_TRUE(automaton.transitByInput(U"we").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"whe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"wuxe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"wule").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"whuxe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"whule").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"uxe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"ule").isAccepted());
    EXPECT_EQ(U"we", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"we", automaton.transitByInput(U"w").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"whe", automaton.transitByInput(U"wh").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"whuxe", automaton.transitByInput(U"whu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"whuxe", automaton.transitByInput(U"whux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"whule", automaton.transitByInput(U"whul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"wuxe", automaton.transitByInput(U"wu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"wuxe", automaton.transitByInput(U"wux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"wule", automaton.transitByInput(U"wul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"uxe", automaton.transitByInput(U"u").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"uxe", automaton.transitByInput(U"ux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"ule", automaton.transitByInput(U"ul").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateWHO) {
    auto automaton = AutomatonCreator::create(U"うぉ");
    EXPECT_TRUE(automaton.transitByInput(U"who").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"wuxo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"wulo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"whuxo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"whulo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"uxo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"ulo").isAccepted());
    EXPECT_EQ(U"who", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"who", automaton.transitByInput(U"w").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"who", automaton.transitByInput(U"wh").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"whuxo", automaton.transitByInput(U"whu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"whuxo", automaton.transitByInput(U"whux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"whulo", automaton.transitByInput(U"whul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"wuxo", automaton.transitByInput(U"wu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"wuxo", automaton.transitByInput(U"wux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"wulo", automaton.transitByInput(U"wul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"uxo", automaton.transitByInput(U"u").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"uxo", automaton.transitByInput(U"ux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"ulo", automaton.transitByInput(U"ul").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateKA) {
    auto automaton = AutomatonCreator::create(U"か");
    EXPECT_TRUE(automaton.transitByInput(U"ka").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"ca").isAccepted());
    EXPECT_EQ(U"ka", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"ka", automaton.transitByInput(U"k").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"ca", automaton.transitByInput(U"c").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateKI) {
    auto automaton = AutomatonCreator::create(U"き");
    EXPECT_TRUE(automaton.transitByInput(U"ki").isAccepted());
    EXPECT_EQ(U"ki", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"ki", automaton.transitByInput(U"k").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateKU) {
    auto automaton = AutomatonCreator::create(U"く");
    EXPECT_TRUE(automaton.transitByInput(U"ku").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"qu").isAccepted());
    EXPECT_EQ(U"ku", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"ku", automaton.transitByInput(U"k").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cu", automaton.transitByInput(U"c").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qu", automaton.transitByInput(U"q").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateKE) {
    auto automaton = AutomatonCreator::create(U"け");
    EXPECT_TRUE(automaton.transitByInput(U"ke").isAccepted());
    EXPECT_EQ(U"ke", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"ke", automaton.transitByInput(U"k").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateKO) {
    auto automaton = AutomatonCreator::create(U"こ");
    EXPECT_TRUE(automaton.transitByInput(U"ko").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"co").isAccepted());
    EXPECT_EQ(U"ko", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"ko", automaton.transitByInput(U"k").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"co", automaton.transitByInput(U"c").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateKYA) {
    auto automaton = AutomatonCreator::create(U"きゃ");
    EXPECT_TRUE(automaton.transitByInput(U"kya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kixya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kilya").isAccepted());
    EXPECT_EQ(U"kya", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kya", automaton.transitByInput(U"k").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kya", automaton.transitByInput(U"ky").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kixya", automaton.transitByInput(U"ki").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kixya", automaton.transitByInput(U"kix").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kilya", automaton.transitByInput(U"kil").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateKYI) {
    auto automaton = AutomatonCreator::create(U"きぃ");
    EXPECT_TRUE(automaton.transitByInput(U"kyi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kixi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kili").isAccepted());
    EXPECT_EQ(U"kyi", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kyi", automaton.transitByInput(U"k").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kyi", automaton.transitByInput(U"ky").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kixi", automaton.transitByInput(U"ki").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kixi", automaton.transitByInput(U"kix").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kili", automaton.transitByInput(U"kil").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateKYU) {
    auto automaton = AutomatonCreator::create(U"きゅ");
    EXPECT_TRUE(automaton.transitByInput(U"kyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kixyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kilyu").isAccepted());
    EXPECT_EQ(U"kyu", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kyu", automaton.transitByInput(U"k").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kyu", automaton.transitByInput(U"ky").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kixyu", automaton.transitByInput(U"ki").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kixyu", automaton.transitByInput(U"kix").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kilyu", automaton.transitByInput(U"kil").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateKYE) {
    auto automaton = AutomatonCreator::create(U"きぇ");
    EXPECT_TRUE(automaton.transitByInput(U"kye").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kixe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kile").isAccepted());
    EXPECT_EQ(U"kye", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kye", automaton.transitByInput(U"k").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kye", automaton.transitByInput(U"ky").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kixe", automaton.transitByInput(U"ki").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kixe", automaton.transitByInput(U"kix").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kile", automaton.transitByInput(U"kil").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateKYO) {
    auto automaton = AutomatonCreator::create(U"きょ");
    EXPECT_TRUE(automaton.transitByInput(U"kyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kixyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kilyo").isAccepted());
    EXPECT_EQ(U"kyo", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kyo", automaton.transitByInput(U"k").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kyo", automaton.transitByInput(U"ky").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kixyo", automaton.transitByInput(U"ki").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kixyo", automaton.transitByInput(U"kix").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kilyo", automaton.transitByInput(U"kil").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateKWA) {
    auto automaton = AutomatonCreator::create(U"くぁ");
    EXPECT_TRUE(automaton.transitByInput(U"qa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"qwa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"quxa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"qula").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kwa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kuxa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kula").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cuxa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cula").isAccepted());
    EXPECT_EQ(U"qa", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qa", automaton.transitByInput(U"q").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qwa", automaton.transitByInput(U"qw").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"quxa", automaton.transitByInput(U"qu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"quxa", automaton.transitByInput(U"qux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qula", automaton.transitByInput(U"qul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kwa", automaton.transitByInput(U"k").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kwa", automaton.transitByInput(U"kw").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kuxa", automaton.transitByInput(U"ku").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kuxa", automaton.transitByInput(U"kux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kula", automaton.transitByInput(U"kul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxa", automaton.transitByInput(U"c").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxa", automaton.transitByInput(U"cu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxa", automaton.transitByInput(U"cux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cula", automaton.transitByInput(U"cul").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateKWI) {
    auto automaton = AutomatonCreator::create(U"くぃ");
    EXPECT_TRUE(automaton.transitByInput(U"qi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"qwi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"qyi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"quxi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"quli").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kwi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kuxi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kuli").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cuxi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"culi").isAccepted());
    EXPECT_EQ(U"qi", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qi", automaton.transitByInput(U"q").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qwi", automaton.transitByInput(U"qw").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qyi", automaton.transitByInput(U"qy").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"quxi", automaton.transitByInput(U"qu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"quxi", automaton.transitByInput(U"qux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"quli", automaton.transitByInput(U"qul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kwi", automaton.transitByInput(U"k").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kwi", automaton.transitByInput(U"kw").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kuxi", automaton.transitByInput(U"ku").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kuxi", automaton.transitByInput(U"kux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kuli", automaton.transitByInput(U"kul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxi", automaton.transitByInput(U"c").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxi", automaton.transitByInput(U"cu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxi", automaton.transitByInput(U"cux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"culi", automaton.transitByInput(U"cul").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateKWU) {
    auto automaton = AutomatonCreator::create(U"くぅ");
    EXPECT_TRUE(automaton.transitByInput(U"kwu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kuxu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kulu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"qwu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"quxu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"qulu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cuxu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"culu").isAccepted());
    EXPECT_EQ(U"kwu", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kwu", automaton.transitByInput(U"k").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kwu", automaton.transitByInput(U"kw").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kuxu", automaton.transitByInput(U"ku").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kuxu", automaton.transitByInput(U"kux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kulu", automaton.transitByInput(U"kul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qwu", automaton.transitByInput(U"q").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qwu", automaton.transitByInput(U"qw").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"quxu", automaton.transitByInput(U"qu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"quxu", automaton.transitByInput(U"qux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qulu", automaton.transitByInput(U"qul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxu", automaton.transitByInput(U"c").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxu", automaton.transitByInput(U"cu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxu", automaton.transitByInput(U"cux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"culu", automaton.transitByInput(U"cul").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateKWE) {
    auto automaton = AutomatonCreator::create(U"くぇ");
    EXPECT_TRUE(automaton.transitByInput(U"qe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"qwe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"qye").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"quxe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"qule").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kwe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kuxe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kule").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cuxe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cule").isAccepted());
    EXPECT_EQ(U"qe", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qe", automaton.transitByInput(U"q").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qwe", automaton.transitByInput(U"qw").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qye", automaton.transitByInput(U"qy").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"quxe", automaton.transitByInput(U"qu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"quxe", automaton.transitByInput(U"qux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qule", automaton.transitByInput(U"qul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kwe", automaton.transitByInput(U"k").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kwe", automaton.transitByInput(U"kw").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kuxe", automaton.transitByInput(U"ku").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kuxe", automaton.transitByInput(U"kux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kule", automaton.transitByInput(U"kul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxe", automaton.transitByInput(U"c").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxe", automaton.transitByInput(U"cu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxe", automaton.transitByInput(U"cux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cule", automaton.transitByInput(U"cul").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateKWO) {
    auto automaton = AutomatonCreator::create(U"くぉ");
    EXPECT_TRUE(automaton.transitByInput(U"qo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"qwo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"quxo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"qulo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kwo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kuxo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kulo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cuxo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"culo").isAccepted());
    EXPECT_EQ(U"qo", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qo", automaton.transitByInput(U"q").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qwo", automaton.transitByInput(U"qw").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"quxo", automaton.transitByInput(U"qu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"quxo", automaton.transitByInput(U"qux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qulo", automaton.transitByInput(U"qul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kwo", automaton.transitByInput(U"k").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kwo", automaton.transitByInput(U"kw").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kuxo", automaton.transitByInput(U"ku").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kuxo", automaton.transitByInput(U"kux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kulo", automaton.transitByInput(U"kul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxo", automaton.transitByInput(U"c").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxo", automaton.transitByInput(U"cu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxo", automaton.transitByInput(U"cux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"culo", automaton.transitByInput(U"cul").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateQYA) {
    auto automaton = AutomatonCreator::create(U"くゃ");
    EXPECT_TRUE(automaton.transitByInput(U"qya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"quxya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"qulya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kuxya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kulya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cuxya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"culya").isAccepted());
    EXPECT_EQ(U"qya", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qya", automaton.transitByInput(U"q").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qya", automaton.transitByInput(U"qy").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"quxya", automaton.transitByInput(U"qu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"quxya", automaton.transitByInput(U"qux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qulya", automaton.transitByInput(U"qul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kuxya", automaton.transitByInput(U"k").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kuxya", automaton.transitByInput(U"ku").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kuxya", automaton.transitByInput(U"kux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kulya", automaton.transitByInput(U"kul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxya", automaton.transitByInput(U"c").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxya", automaton.transitByInput(U"cu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxya", automaton.transitByInput(U"cux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"culya", automaton.transitByInput(U"cul").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateQYU) {
    auto automaton = AutomatonCreator::create(U"くゅ");
    EXPECT_TRUE(automaton.transitByInput(U"qyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"quxyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"qulyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kuxyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kulyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cuxyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"culyu").isAccepted());
    EXPECT_EQ(U"qyu", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qyu", automaton.transitByInput(U"q").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qyu", automaton.transitByInput(U"qy").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"quxyu", automaton.transitByInput(U"qu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"quxyu", automaton.transitByInput(U"qux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qulyu", automaton.transitByInput(U"qul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kuxyu", automaton.transitByInput(U"k").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kuxyu", automaton.transitByInput(U"ku").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kuxyu", automaton.transitByInput(U"kux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kulyu", automaton.transitByInput(U"kul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxyu", automaton.transitByInput(U"c").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxyu", automaton.transitByInput(U"cu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxyu", automaton.transitByInput(U"cux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"culyu", automaton.transitByInput(U"cul").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateQYO) {
    auto automaton = AutomatonCreator::create(U"くょ");
    EXPECT_TRUE(automaton.transitByInput(U"qyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"quxyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"qulyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kuxyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"kulyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cuxyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"culyo").isAccepted());
    EXPECT_EQ(U"qyo", automaton.transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qyo", automaton.transitByInput(U"q").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qyo", automaton.transitByInput(U"qy").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"quxyo", automaton.transitByInput(U"qu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"quxyo", automaton.transitByInput(U"qux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"qulyo", automaton.transitByInput(U"qul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kuxyo", automaton.transitByInput(U"k").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kuxyo", automaton.transitByInput(U"ku").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kuxyo", automaton.transitByInput(U"kux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"kulyo", automaton.transitByInput(U"kul").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxyo", automaton.transitByInput(U"c").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxyo", automaton.transitByInput(U"cu").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"cuxyo", automaton.transitByInput(U"cux").transitByPriority().getAccumulatedInput());
    EXPECT_EQ(U"culyo", automaton.transitByInput(U"cul").transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateSA) {
    auto automaton = AutomatonCreator::create(U"さ");
    EXPECT_TRUE(automaton.transitByInput(U"sa").isAccepted());
    EXPECT_EQ(U"sa", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateSI) {
    auto automaton = AutomatonCreator::create(U"し");
    EXPECT_TRUE(automaton.transitByInput(U"si").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"shi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"ci").isAccepted());
    EXPECT_EQ(U"si", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateSU) {
    auto automaton = AutomatonCreator::create(U"す");
    EXPECT_TRUE(automaton.transitByInput(U"su").isAccepted());
    EXPECT_EQ(U"su", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateSE) {
    auto automaton = AutomatonCreator::create(U"せ");
    EXPECT_TRUE(automaton.transitByInput(U"se").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"ce").isAccepted());
    EXPECT_EQ(U"se", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateSO) {
    auto automaton = AutomatonCreator::create(U"そ");
    EXPECT_TRUE(automaton.transitByInput(U"so").isAccepted());
    EXPECT_EQ(U"so", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTA) {
    auto automaton = AutomatonCreator::create(U"た");
    EXPECT_TRUE(automaton.transitByInput(U"ta").isAccepted());
    EXPECT_EQ(U"ta", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTI) {
    auto automaton = AutomatonCreator::create(U"ち");
    EXPECT_TRUE(automaton.transitByInput(U"ti").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"chi").isAccepted());
    EXPECT_EQ(U"ti", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTU) {
    auto automaton = AutomatonCreator::create(U"つ");
    EXPECT_TRUE(automaton.transitByInput(U"tu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tsu").isAccepted());
    EXPECT_EQ(U"tu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTE) {
    auto automaton = AutomatonCreator::create(U"て");
    EXPECT_TRUE(automaton.transitByInput(U"te").isAccepted());
    EXPECT_EQ(U"te", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTO) {
    auto automaton = AutomatonCreator::create(U"と");
    EXPECT_TRUE(automaton.transitByInput(U"to").isAccepted());
    EXPECT_EQ(U"to", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateNA) {
    auto automaton = AutomatonCreator::create(U"な");
    EXPECT_TRUE(automaton.transitByInput(U"na").isAccepted());
    EXPECT_EQ(U"na", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateNI) {
    auto automaton = AutomatonCreator::create(U"に");
    EXPECT_TRUE(automaton.transitByInput(U"ni").isAccepted());
    EXPECT_EQ(U"ni", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateNU) {
    auto automaton = AutomatonCreator::create(U"ぬ");
    EXPECT_TRUE(automaton.transitByInput(U"nu").isAccepted());
    EXPECT_EQ(U"nu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateNE) {
    auto automaton = AutomatonCreator::create(U"ね");
    EXPECT_TRUE(automaton.transitByInput(U"ne").isAccepted());
    EXPECT_EQ(U"ne", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateNO) {
    auto automaton = AutomatonCreator::create(U"の");
    EXPECT_TRUE(automaton.transitByInput(U"no").isAccepted());
    EXPECT_EQ(U"no", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateHA) {
    auto automaton = AutomatonCreator::create(U"は");
    EXPECT_TRUE(automaton.transitByInput(U"ha").isAccepted());
    EXPECT_EQ(U"ha", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateHI) {
    auto automaton = AutomatonCreator::create(U"ひ");
    EXPECT_TRUE(automaton.transitByInput(U"hi").isAccepted());
    EXPECT_EQ(U"hi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateHU) {
    auto automaton = AutomatonCreator::create(U"ふ");
    EXPECT_TRUE(automaton.transitByInput(U"hu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"fu").isAccepted());
    EXPECT_EQ(U"hu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateHE) {
    auto automaton = AutomatonCreator::create(U"へ");
    EXPECT_TRUE(automaton.transitByInput(U"he").isAccepted());
    EXPECT_EQ(U"he", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateHO) {
    auto automaton = AutomatonCreator::create(U"ほ");
    EXPECT_TRUE(automaton.transitByInput(U"ho").isAccepted());
    EXPECT_EQ(U"ho", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateMA) {
    auto automaton = AutomatonCreator::create(U"ま");
    EXPECT_TRUE(automaton.transitByInput(U"ma").isAccepted());
    EXPECT_EQ(U"ma", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateMI) {
    auto automaton = AutomatonCreator::create(U"み");
    EXPECT_TRUE(automaton.transitByInput(U"mi").isAccepted());
    EXPECT_EQ(U"mi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateMU) {
    auto automaton = AutomatonCreator::create(U"む");
    EXPECT_TRUE(automaton.transitByInput(U"mu").isAccepted());
    EXPECT_EQ(U"mu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateME) {
    auto automaton = AutomatonCreator::create(U"め");
    EXPECT_TRUE(automaton.transitByInput(U"me").isAccepted());
    EXPECT_EQ(U"me", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateMO) {
    auto automaton = AutomatonCreator::create(U"も");
    EXPECT_TRUE(automaton.transitByInput(U"mo").isAccepted());
    EXPECT_EQ(U"mo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateYA) {
    auto automaton = AutomatonCreator::create(U"や");
    EXPECT_TRUE(automaton.transitByInput(U"ya").isAccepted());
    EXPECT_EQ(U"ya", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateYU) {
    auto automaton = AutomatonCreator::create(U"ゆ");
    EXPECT_TRUE(automaton.transitByInput(U"yu").isAccepted());
    EXPECT_EQ(U"yu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateYO) {
    auto automaton = AutomatonCreator::create(U"よ");
    EXPECT_TRUE(automaton.transitByInput(U"yo").isAccepted());
    EXPECT_EQ(U"yo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateRA) {
    auto automaton = AutomatonCreator::create(U"ら");
    EXPECT_TRUE(automaton.transitByInput(U"ra").isAccepted());
    EXPECT_EQ(U"ra", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateRI) {
    auto automaton = AutomatonCreator::create(U"り");
    EXPECT_TRUE(automaton.transitByInput(U"ri").isAccepted());
    EXPECT_EQ(U"ri", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateRU) {
    auto automaton = AutomatonCreator::create(U"る");
    EXPECT_TRUE(automaton.transitByInput(U"ru").isAccepted());
    EXPECT_EQ(U"ru", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateRE) {
    auto automaton = AutomatonCreator::create(U"れ");
    EXPECT_TRUE(automaton.transitByInput(U"re").isAccepted());
    EXPECT_EQ(U"re", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateRO) {
    auto automaton = AutomatonCreator::create(U"ろ");
    EXPECT_TRUE(automaton.transitByInput(U"ro").isAccepted());
    EXPECT_EQ(U"ro", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateWA) {
    auto automaton = AutomatonCreator::create(U"わ");
    EXPECT_TRUE(automaton.transitByInput(U"wa").isAccepted());
    EXPECT_EQ(U"wa", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateWO) {
    auto automaton = AutomatonCreator::create(U"を");
    EXPECT_TRUE(automaton.transitByInput(U"wo").isAccepted());
    EXPECT_EQ(U"wo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateGA) {
    auto automaton = AutomatonCreator::create(U"が");
    EXPECT_TRUE(automaton.transitByInput(U"ga").isAccepted());
    EXPECT_EQ(U"ga", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateGI) {
    auto automaton = AutomatonCreator::create(U"ぎ");
    EXPECT_TRUE(automaton.transitByInput(U"gi").isAccepted());
    EXPECT_EQ(U"gi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateGU) {
    auto automaton = AutomatonCreator::create(U"ぐ");
    EXPECT_TRUE(automaton.transitByInput(U"gu").isAccepted());
    EXPECT_EQ(U"gu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateGE) {
    auto automaton = AutomatonCreator::create(U"げ");
    EXPECT_TRUE(automaton.transitByInput(U"ge").isAccepted());
    EXPECT_EQ(U"ge", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateGO) {
    auto automaton = AutomatonCreator::create(U"ご");
    EXPECT_TRUE(automaton.transitByInput(U"go").isAccepted());
    EXPECT_EQ(U"go", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateZA) {
    auto automaton = AutomatonCreator::create(U"ざ");
    EXPECT_TRUE(automaton.transitByInput(U"za").isAccepted());
    EXPECT_EQ(U"za", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateZI) {
    auto automaton = AutomatonCreator::create(U"じ");
    EXPECT_TRUE(automaton.transitByInput(U"zi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"ji").isAccepted());
    EXPECT_EQ(U"zi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateZU) {
    auto automaton = AutomatonCreator::create(U"ず");
    EXPECT_TRUE(automaton.transitByInput(U"zu").isAccepted());
    EXPECT_EQ(U"zu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateZE) {
    auto automaton = AutomatonCreator::create(U"ぜ");
    EXPECT_TRUE(automaton.transitByInput(U"ze").isAccepted());
    EXPECT_EQ(U"ze", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateZO) {
    auto automaton = AutomatonCreator::create(U"ぞ");
    EXPECT_TRUE(automaton.transitByInput(U"zo").isAccepted());
    EXPECT_EQ(U"zo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateDA) {
    auto automaton = AutomatonCreator::create(U"だ");
    EXPECT_TRUE(automaton.transitByInput(U"da").isAccepted());
    EXPECT_EQ(U"da", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateDI) {
    auto automaton = AutomatonCreator::create(U"ぢ");
    EXPECT_TRUE(automaton.transitByInput(U"di").isAccepted());
    EXPECT_EQ(U"di", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateDU) {
    auto automaton = AutomatonCreator::create(U"づ");
    EXPECT_TRUE(automaton.transitByInput(U"du").isAccepted());
    EXPECT_EQ(U"du", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateDE) {
    auto automaton = AutomatonCreator::create(U"で");
    EXPECT_TRUE(automaton.transitByInput(U"de").isAccepted());
    EXPECT_EQ(U"de", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateDO) {
    auto automaton = AutomatonCreator::create(U"ど");
    EXPECT_TRUE(automaton.transitByInput(U"do").isAccepted());
    EXPECT_EQ(U"do", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateBA) {
    auto automaton = AutomatonCreator::create(U"ば");
    EXPECT_TRUE(automaton.transitByInput(U"ba").isAccepted());
    EXPECT_EQ(U"ba", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateBI) {
    auto automaton = AutomatonCreator::create(U"び");
    EXPECT_TRUE(automaton.transitByInput(U"bi").isAccepted());
    EXPECT_EQ(U"bi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateBU) {
    auto automaton = AutomatonCreator::create(U"ぶ");
    EXPECT_TRUE(automaton.transitByInput(U"bu").isAccepted());
    EXPECT_EQ(U"bu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateBE) {
    auto automaton = AutomatonCreator::create(U"べ");
    EXPECT_TRUE(automaton.transitByInput(U"be").isAccepted());
    EXPECT_EQ(U"be", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateBO) {
    auto automaton = AutomatonCreator::create(U"ぼ");
    EXPECT_TRUE(automaton.transitByInput(U"bo").isAccepted());
    EXPECT_EQ(U"bo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreatePA) {
    auto automaton = AutomatonCreator::create(U"ぱ");
    EXPECT_TRUE(automaton.transitByInput(U"pa").isAccepted());
    EXPECT_EQ(U"pa", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreatePI) {
    auto automaton = AutomatonCreator::create(U"ぴ");
    EXPECT_TRUE(automaton.transitByInput(U"pi").isAccepted());
    EXPECT_EQ(U"pi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreatePU) {
    auto automaton = AutomatonCreator::create(U"ぷ");
    EXPECT_TRUE(automaton.transitByInput(U"pu").isAccepted());
    EXPECT_EQ(U"pu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreatePE) {
    auto automaton = AutomatonCreator::create(U"ぺ");
    EXPECT_TRUE(automaton.transitByInput(U"pe").isAccepted());
    EXPECT_EQ(U"pe", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreatePO) {
    auto automaton = AutomatonCreator::create(U"ぽ");
    EXPECT_TRUE(automaton.transitByInput(U"po").isAccepted());
    EXPECT_EQ(U"po", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateXA) {
    auto automaton = AutomatonCreator::create(U"ぁ");
    EXPECT_TRUE(automaton.transitByInput(U"xa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"la").isAccepted());
    EXPECT_EQ(U"xa", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateXI) {
    auto automaton = AutomatonCreator::create(U"ぃ");
    EXPECT_TRUE(automaton.transitByInput(U"xi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"li").isAccepted());
    EXPECT_EQ(U"xi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateXU) {
    auto automaton = AutomatonCreator::create(U"ぅ");
    EXPECT_TRUE(automaton.transitByInput(U"xu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"lu").isAccepted());
    EXPECT_EQ(U"xu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateXE) {
    auto automaton = AutomatonCreator::create(U"ぇ");
    EXPECT_TRUE(automaton.transitByInput(U"xe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"le").isAccepted());
    EXPECT_EQ(U"xe", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateXO) {
    auto automaton = AutomatonCreator::create(U"ぉ");
    EXPECT_TRUE(automaton.transitByInput(U"xo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"lo").isAccepted());
    EXPECT_EQ(U"xo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateXYA) {
    auto automaton = AutomatonCreator::create(U"ゃ");
    EXPECT_TRUE(automaton.transitByInput(U"xya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"lya").isAccepted());
    EXPECT_EQ(U"xya", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateXYU) {
    auto automaton = AutomatonCreator::create(U"ゅ");
    EXPECT_TRUE(automaton.transitByInput(U"xyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"lyu").isAccepted());
    EXPECT_EQ(U"xyu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateXYO) {
    auto automaton = AutomatonCreator::create(U"ょ");
    EXPECT_TRUE(automaton.transitByInput(U"xyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"lyo").isAccepted());
    EXPECT_EQ(U"xyo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateXTU) {
    auto automaton = AutomatonCreator::create(U"っ");
    EXPECT_TRUE(automaton.transitByInput(U"xtu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"ltu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"xtsu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"ltsu").isAccepted());
    EXPECT_EQ(U"xtu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateGYA) {
    auto automaton = AutomatonCreator::create(U"ぎゃ");
    EXPECT_TRUE(automaton.transitByInput(U"gya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"gixya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"gilya").isAccepted());
    EXPECT_EQ(U"gya", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateGYI) {
    auto automaton = AutomatonCreator::create(U"ぎぃ");
    EXPECT_TRUE(automaton.transitByInput(U"gyi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"gixi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"gili").isAccepted());
    EXPECT_EQ(U"gyi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateGYU) {
    auto automaton = AutomatonCreator::create(U"ぎゅ");
    EXPECT_TRUE(automaton.transitByInput(U"gyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"gixyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"gilyu").isAccepted());
    EXPECT_EQ(U"gyu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateGYE) {
    auto automaton = AutomatonCreator::create(U"ぎぇ");
    EXPECT_TRUE(automaton.transitByInput(U"gye").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"gixe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"gile").isAccepted());
    EXPECT_EQ(U"gye", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateGYO) {
    auto automaton = AutomatonCreator::create(U"ぎょ");
    EXPECT_TRUE(automaton.transitByInput(U"gyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"gixyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"gilyo").isAccepted());
    EXPECT_EQ(U"gyo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateGWA) {
    auto automaton = AutomatonCreator::create(U"ぐぁ");
    EXPECT_TRUE(automaton.transitByInput(U"gwa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"guxa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"gula").isAccepted());
    EXPECT_EQ(U"gwa", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateGWI) {
    auto automaton = AutomatonCreator::create(U"ぐぃ");
    EXPECT_TRUE(automaton.transitByInput(U"gwi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"guxi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"guli").isAccepted());
    EXPECT_EQ(U"gwi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateGWU) {
    auto automaton = AutomatonCreator::create(U"ぐぅ");
    EXPECT_TRUE(automaton.transitByInput(U"gwu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"guxu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"gulu").isAccepted());
    EXPECT_EQ(U"gwu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateGWE) {
    auto automaton = AutomatonCreator::create(U"ぐぇ");
    EXPECT_TRUE(automaton.transitByInput(U"gwe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"guxe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"gule").isAccepted());
    EXPECT_EQ(U"gwe", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateGWO) {
    auto automaton = AutomatonCreator::create(U"ぐぉ");
    EXPECT_TRUE(automaton.transitByInput(U"gwo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"guxo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"gulo").isAccepted());
    EXPECT_EQ(U"gwo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateSYA) {
    auto automaton = AutomatonCreator::create(U"しゃ");
    EXPECT_TRUE(automaton.transitByInput(U"sya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"sha").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"sixya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"silya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cixya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cilya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"shixya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"shilya").isAccepted());
    EXPECT_EQ(U"sya", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateSYI) {
    auto automaton = AutomatonCreator::create(U"しぃ");
    EXPECT_TRUE(automaton.transitByInput(U"syi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"sixi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"sili").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cixi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cili").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"shixi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"shili").isAccepted());
    EXPECT_EQ(U"syi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateSYU) {
    auto automaton = AutomatonCreator::create(U"しゅ");
    EXPECT_TRUE(automaton.transitByInput(U"syu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"shu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"sixyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"silyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cixyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cilyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"shixyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"shilyu").isAccepted());
    EXPECT_EQ(U"syu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateSYE) {
    auto automaton = AutomatonCreator::create(U"しぇ");
    EXPECT_TRUE(automaton.transitByInput(U"sye").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"she").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"sixe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"sile").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cixe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cile").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"shixe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"shile").isAccepted());
    EXPECT_EQ(U"sye", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateSYO) {
    auto automaton = AutomatonCreator::create(U"しょ");
    EXPECT_TRUE(automaton.transitByInput(U"syo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"sho").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"sixyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"silyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cixyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cilyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"shixyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"shilyo").isAccepted());
    EXPECT_EQ(U"syo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateSWA) {
    auto automaton = AutomatonCreator::create(U"すぁ");
    EXPECT_TRUE(automaton.transitByInput(U"swa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"suxa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"sula").isAccepted());
    EXPECT_EQ(U"swa", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateSWI) {
    auto automaton = AutomatonCreator::create(U"すぃ");
    EXPECT_TRUE(automaton.transitByInput(U"swi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"suxi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"suli").isAccepted());
    EXPECT_EQ(U"swi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateSWU) {
    auto automaton = AutomatonCreator::create(U"すぅ");
    EXPECT_TRUE(automaton.transitByInput(U"swu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"suxu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"sulu").isAccepted());
    EXPECT_EQ(U"swu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateSWE) {
    auto automaton = AutomatonCreator::create(U"すぇ");
    EXPECT_TRUE(automaton.transitByInput(U"swe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"suxe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"sule").isAccepted());
    EXPECT_EQ(U"swe", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateSWO) {
    auto automaton = AutomatonCreator::create(U"すぉ");
    EXPECT_TRUE(automaton.transitByInput(U"swo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"suxo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"sulo").isAccepted());
    EXPECT_EQ(U"swo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateZYA) {
    auto automaton = AutomatonCreator::create(U"じゃ");
    EXPECT_TRUE(automaton.transitByInput(U"ja").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"zya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"jya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"zixya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"zilya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"jixya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"jilya").isAccepted());
    EXPECT_EQ(U"zya", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateZYI) {
    auto automaton = AutomatonCreator::create(U"じぃ");
    EXPECT_TRUE(automaton.transitByInput(U"zyi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"jyi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"zixi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"zili").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"jixi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"jili").isAccepted());
    EXPECT_EQ(U"zyi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateZYU) {
    auto automaton = AutomatonCreator::create(U"じゅ");
    EXPECT_TRUE(automaton.transitByInput(U"ju").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"zyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"jyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"zixyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"zilyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"jixyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"jilyu").isAccepted());
    EXPECT_EQ(U"zyu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateZYE) {
    auto automaton = AutomatonCreator::create(U"じぇ");
    EXPECT_TRUE(automaton.transitByInput(U"je").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"zye").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"jye").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"zixe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"zile").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"jixe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"jile").isAccepted());
    EXPECT_EQ(U"zye", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateZYO) {
    auto automaton = AutomatonCreator::create(U"じょ");
    EXPECT_TRUE(automaton.transitByInput(U"jo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"zyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"jyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"zixyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"zilyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"jixyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"jilyo").isAccepted());
    EXPECT_EQ(U"zyo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTYA) {
    auto automaton = AutomatonCreator::create(U"ちゃ");
    EXPECT_TRUE(automaton.transitByInput(U"tya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cha").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tixya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tilya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"chixya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"chilya").isAccepted());
    EXPECT_EQ(U"tya", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTYI) {
    auto automaton = AutomatonCreator::create(U"ちぃ");
    EXPECT_TRUE(automaton.transitByInput(U"tyi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cyi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tixi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tili").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"chixi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"chili").isAccepted());
    EXPECT_EQ(U"tyi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTYU) {
    auto automaton = AutomatonCreator::create(U"ちゅ");
    EXPECT_TRUE(automaton.transitByInput(U"tyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"chu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tixyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tilyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"chixyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"chilyu").isAccepted());
    EXPECT_EQ(U"tyu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTYE) {
    auto automaton = AutomatonCreator::create(U"ちぇ");
    EXPECT_TRUE(automaton.transitByInput(U"tye").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cye").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"che").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tixe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tile").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"chixe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"chile").isAccepted());
    EXPECT_EQ(U"tye", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTYO) {
    auto automaton = AutomatonCreator::create(U"ちょ");
    EXPECT_TRUE(automaton.transitByInput(U"tyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"cho").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tixyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tilyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"chixyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"chilyo").isAccepted());
    EXPECT_EQ(U"tyo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTSA) {
    auto automaton = AutomatonCreator::create(U"つぁ");
    EXPECT_TRUE(automaton.transitByInput(U"tsa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tuxa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tula").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tsuxa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tsula").isAccepted());
    EXPECT_EQ(U"tsa", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTSI) {
    auto automaton = AutomatonCreator::create(U"つぃ");
    EXPECT_TRUE(automaton.transitByInput(U"tsi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tuxi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tuli").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tsuxi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tsuli").isAccepted());
    EXPECT_EQ(U"tsi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTSE) {
    auto automaton = AutomatonCreator::create(U"つぇ");
    EXPECT_TRUE(automaton.transitByInput(U"tse").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tuxe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tule").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tsuxe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tsule").isAccepted());
    EXPECT_EQ(U"tse", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTSO) {
    auto automaton = AutomatonCreator::create(U"つぉ");
    EXPECT_TRUE(automaton.transitByInput(U"tso").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tuxo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tulo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tsuxo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tsulo").isAccepted());
    EXPECT_EQ(U"tso", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTHA) {
    auto automaton = AutomatonCreator::create(U"てゃ");
    EXPECT_TRUE(automaton.transitByInput(U"tha").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"texya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"telya").isAccepted());
    EXPECT_EQ(U"tha", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTHI) {
    auto automaton = AutomatonCreator::create(U"てぃ");
    EXPECT_TRUE(automaton.transitByInput(U"thi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"texi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"teli").isAccepted());
    EXPECT_EQ(U"thi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTHU) {
    auto automaton = AutomatonCreator::create(U"てゅ");
    EXPECT_TRUE(automaton.transitByInput(U"thu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"texyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"telyu").isAccepted());
    EXPECT_EQ(U"thu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTHE) {
    auto automaton = AutomatonCreator::create(U"てぇ");
    EXPECT_TRUE(automaton.transitByInput(U"the").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"texe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tele").isAccepted());
    EXPECT_EQ(U"the", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTHO) {
    auto automaton = AutomatonCreator::create(U"てょ");
    EXPECT_TRUE(automaton.transitByInput(U"tho").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"texyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"telyo").isAccepted());
    EXPECT_EQ(U"tho", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTWA) {
    auto automaton = AutomatonCreator::create(U"とぁ");
    EXPECT_TRUE(automaton.transitByInput(U"twa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"toxa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tola").isAccepted());
    EXPECT_EQ(U"twa", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTWI) {
    auto automaton = AutomatonCreator::create(U"とぃ");
    EXPECT_TRUE(automaton.transitByInput(U"twi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"toxi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"toli").isAccepted());
    EXPECT_EQ(U"twi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTWU) {
    auto automaton = AutomatonCreator::create(U"とぅ");
    EXPECT_TRUE(automaton.transitByInput(U"twu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"toxu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tolu").isAccepted());
    EXPECT_EQ(U"twu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTWE) {
    auto automaton = AutomatonCreator::create(U"とぇ");
    EXPECT_TRUE(automaton.transitByInput(U"twe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"toxe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tole").isAccepted());
    EXPECT_EQ(U"twe", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateTWO) {
    auto automaton = AutomatonCreator::create(U"とぉ");
    EXPECT_TRUE(automaton.transitByInput(U"two").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"toxo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"tolo").isAccepted());
    EXPECT_EQ(U"two", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateDYA) {
    auto automaton = AutomatonCreator::create(U"ぢゃ");
    EXPECT_TRUE(automaton.transitByInput(U"dya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"dixya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"dilya").isAccepted());
    EXPECT_EQ(U"dya", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateDYI) {
    auto automaton = AutomatonCreator::create(U"ぢぃ");
    EXPECT_TRUE(automaton.transitByInput(U"dyi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"dixi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"dili").isAccepted());
    EXPECT_EQ(U"dyi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateDYU) {
    auto automaton = AutomatonCreator::create(U"ぢゅ");
    EXPECT_TRUE(automaton.transitByInput(U"dyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"dixyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"dilyu").isAccepted());
    EXPECT_EQ(U"dyu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateDYE) {
    auto automaton = AutomatonCreator::create(U"ぢぇ");
    EXPECT_TRUE(automaton.transitByInput(U"dye").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"dixe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"dile").isAccepted());
    EXPECT_EQ(U"dye", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateDYO) {
    auto automaton = AutomatonCreator::create(U"ぢょ");
    EXPECT_TRUE(automaton.transitByInput(U"dyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"dixyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"dilyo").isAccepted());
    EXPECT_EQ(U"dyo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateDHA) {
    auto automaton = AutomatonCreator::create(U"でゃ");
    EXPECT_TRUE(automaton.transitByInput(U"dha").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"dexya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"delya").isAccepted());
    EXPECT_EQ(U"dha", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateDHI) {
    auto automaton = AutomatonCreator::create(U"でぃ");
    EXPECT_TRUE(automaton.transitByInput(U"dhi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"dexi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"deli").isAccepted());
    EXPECT_EQ(U"dhi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateDHU) {
    auto automaton = AutomatonCreator::create(U"でゅ");
    EXPECT_TRUE(automaton.transitByInput(U"dhu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"dexyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"delyu").isAccepted());
    EXPECT_EQ(U"dhu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateDHE) {
    auto automaton = AutomatonCreator::create(U"でぇ");
    EXPECT_TRUE(automaton.transitByInput(U"dhe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"dexe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"dele").isAccepted());
    EXPECT_EQ(U"dhe", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateDHO) {
    auto automaton = AutomatonCreator::create(U"でょ");
    EXPECT_TRUE(automaton.transitByInput(U"dho").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"dexyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"delyo").isAccepted());
    EXPECT_EQ(U"dho", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateDWA) {
    auto automaton = AutomatonCreator::create(U"どぁ");
    EXPECT_TRUE(automaton.transitByInput(U"dwa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"doxa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"dola").isAccepted());
    EXPECT_EQ(U"dwa", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateDWI) {
    auto automaton = AutomatonCreator::create(U"どぃ");
    EXPECT_TRUE(automaton.transitByInput(U"dwi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"doxi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"doli").isAccepted());
    EXPECT_EQ(U"dwi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateDWU) {
    auto automaton = AutomatonCreator::create(U"どぅ");
    EXPECT_TRUE(automaton.transitByInput(U"dwu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"doxu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"dolu").isAccepted());
    EXPECT_EQ(U"dwu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateDWE) {
    auto automaton = AutomatonCreator::create(U"どぇ");
    EXPECT_TRUE(automaton.transitByInput(U"dwe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"doxe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"dole").isAccepted());
    EXPECT_EQ(U"dwe", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateDWO) {
    auto automaton = AutomatonCreator::create(U"どぉ");
    EXPECT_TRUE(automaton.transitByInput(U"dwo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"doxo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"dolo").isAccepted());
    EXPECT_EQ(U"dwo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateNYA) {
    auto automaton = AutomatonCreator::create(U"にゃ");
    EXPECT_TRUE(automaton.transitByInput(U"nya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"nixya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"nilya").isAccepted());
    EXPECT_EQ(U"nya", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateNYI) {
    auto automaton = AutomatonCreator::create(U"にぃ");
    EXPECT_TRUE(automaton.transitByInput(U"nyi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"nixi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"nili").isAccepted());
    EXPECT_EQ(U"nyi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateNYU) {
    auto automaton = AutomatonCreator::create(U"にゅ");
    EXPECT_TRUE(automaton.transitByInput(U"nyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"nixyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"nilyu").isAccepted());
    EXPECT_EQ(U"nyu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateNYE) {
    auto automaton = AutomatonCreator::create(U"にぇ");
    EXPECT_TRUE(automaton.transitByInput(U"nye").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"nixe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"nile").isAccepted());
    EXPECT_EQ(U"nye", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateNYO) {
    auto automaton = AutomatonCreator::create(U"にょ");
    EXPECT_TRUE(automaton.transitByInput(U"nyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"nixyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"nilyo").isAccepted());
    EXPECT_EQ(U"nyo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateHYA) {
    auto automaton = AutomatonCreator::create(U"ひゃ");
    EXPECT_TRUE(automaton.transitByInput(U"hya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"hixya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"hilya").isAccepted());
    EXPECT_EQ(U"hya", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateHYI) {
    auto automaton = AutomatonCreator::create(U"ひぃ");
    EXPECT_TRUE(automaton.transitByInput(U"hyi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"hixi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"hili").isAccepted());
    EXPECT_EQ(U"hyi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateHYU) {
    auto automaton = AutomatonCreator::create(U"ひゅ");
    EXPECT_TRUE(automaton.transitByInput(U"hyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"hixyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"hilyu").isAccepted());
    EXPECT_EQ(U"hyu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateHYE) {
    auto automaton = AutomatonCreator::create(U"ひぇ");
    EXPECT_TRUE(automaton.transitByInput(U"hye").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"hixe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"hile").isAccepted());
    EXPECT_EQ(U"hye", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateHYO) {
    auto automaton = AutomatonCreator::create(U"ひょ");
    EXPECT_TRUE(automaton.transitByInput(U"hyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"hixyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"hilyo").isAccepted());
    EXPECT_EQ(U"hyo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateFWA) {
    auto automaton = AutomatonCreator::create(U"ふぁ");
    EXPECT_TRUE(automaton.transitByInput(U"fa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"fwa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"fuxa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"fula").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"huxa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"hula").isAccepted());
    EXPECT_EQ(U"fa", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateFWI) {
    auto automaton = AutomatonCreator::create(U"ふぃ");
    EXPECT_TRUE(automaton.transitByInput(U"fi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"fwi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"fuxi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"fuli").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"huxi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"huli").isAccepted());
    EXPECT_EQ(U"fi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateFWU) {
    auto automaton = AutomatonCreator::create(U"ふぅ");
    EXPECT_TRUE(automaton.transitByInput(U"fwu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"fuxu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"fulu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"huxu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"hulu").isAccepted());
    EXPECT_EQ(U"fwu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateFWE) {
    auto automaton = AutomatonCreator::create(U"ふぇ");
    EXPECT_TRUE(automaton.transitByInput(U"fe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"fwe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"fuxe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"fule").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"huxe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"hule").isAccepted());
    EXPECT_EQ(U"fe", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateFWO) {
    auto automaton = AutomatonCreator::create(U"ふぉ");
    EXPECT_TRUE(automaton.transitByInput(U"fo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"fwo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"fuxo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"fulo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"huxo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"hulo").isAccepted());
    EXPECT_EQ(U"fo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateFYA) {
    auto automaton = AutomatonCreator::create(U"ふゃ");
    EXPECT_TRUE(automaton.transitByInput(U"fya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"fuxya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"fulya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"huxya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"hulya").isAccepted());
    EXPECT_EQ(U"fya", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateFYU) {
    auto automaton = AutomatonCreator::create(U"ふゅ");
    EXPECT_TRUE(automaton.transitByInput(U"fyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"fuxyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"fulyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"huxyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"hulyu").isAccepted());
    EXPECT_EQ(U"fyu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateFYO) {
    auto automaton = AutomatonCreator::create(U"ふょ");
    EXPECT_TRUE(automaton.transitByInput(U"fyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"fuxyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"fulyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"huxyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"hulyo").isAccepted());
    EXPECT_EQ(U"fyo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateBYA) {
    auto automaton = AutomatonCreator::create(U"びゃ");
    EXPECT_TRUE(automaton.transitByInput(U"bya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"bixya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"bilya").isAccepted());
    EXPECT_EQ(U"bya", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateBYI) {
    auto automaton = AutomatonCreator::create(U"びぃ");
    EXPECT_TRUE(automaton.transitByInput(U"byi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"bixi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"bili").isAccepted());
    EXPECT_EQ(U"byi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateBYU) {
    auto automaton = AutomatonCreator::create(U"びゅ");
    EXPECT_TRUE(automaton.transitByInput(U"byu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"bixyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"bilyu").isAccepted());
    EXPECT_EQ(U"byu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateBYE) {
    auto automaton = AutomatonCreator::create(U"びぇ");
    EXPECT_TRUE(automaton.transitByInput(U"bye").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"bixe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"bile").isAccepted());
    EXPECT_EQ(U"bye", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateBYO) {
    auto automaton = AutomatonCreator::create(U"びょ");
    EXPECT_TRUE(automaton.transitByInput(U"byo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"bixyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"bilyo").isAccepted());
    EXPECT_EQ(U"byo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreatePYA) {
    auto automaton = AutomatonCreator::create(U"ぴゃ");
    EXPECT_TRUE(automaton.transitByInput(U"pya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"pixya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"pilya").isAccepted());
    EXPECT_EQ(U"pya", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreatePYI) {
    auto automaton = AutomatonCreator::create(U"ぴぃ");
    EXPECT_TRUE(automaton.transitByInput(U"pyi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"pixi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"pili").isAccepted());
    EXPECT_EQ(U"pyi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreatePYU) {
    auto automaton = AutomatonCreator::create(U"ぴゅ");
    EXPECT_TRUE(automaton.transitByInput(U"pyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"pixyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"pilyu").isAccepted());
    EXPECT_EQ(U"pyu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreatePYE) {
    auto automaton = AutomatonCreator::create(U"ぴぇ");
    EXPECT_TRUE(automaton.transitByInput(U"pye").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"pixe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"pile").isAccepted());
    EXPECT_EQ(U"pye", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreatePYO) {
    auto automaton = AutomatonCreator::create(U"ぴょ");
    EXPECT_TRUE(automaton.transitByInput(U"pyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"pixyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"pilyo").isAccepted());
    EXPECT_EQ(U"pyo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateMYA) {
    auto automaton = AutomatonCreator::create(U"みゃ");
    EXPECT_TRUE(automaton.transitByInput(U"mya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"mixya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"milya").isAccepted());
    EXPECT_EQ(U"mya", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateMYI) {
    auto automaton = AutomatonCreator::create(U"みぃ");
    EXPECT_TRUE(automaton.transitByInput(U"myi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"mixi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"mili").isAccepted());
    EXPECT_EQ(U"myi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateMYU) {
    auto automaton = AutomatonCreator::create(U"みゅ");
    EXPECT_TRUE(automaton.transitByInput(U"myu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"mixyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"milyu").isAccepted());
    EXPECT_EQ(U"myu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateMYE) {
    auto automaton = AutomatonCreator::create(U"みぇ");
    EXPECT_TRUE(automaton.transitByInput(U"mye").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"mixe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"mile").isAccepted());
    EXPECT_EQ(U"mye", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateMYO) {
    auto automaton = AutomatonCreator::create(U"みょ");
    EXPECT_TRUE(automaton.transitByInput(U"myo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"mixyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"milyo").isAccepted());
    EXPECT_EQ(U"myo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateRYA) {
    auto automaton = AutomatonCreator::create(U"りゃ");
    EXPECT_TRUE(automaton.transitByInput(U"rya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"rixya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"rilya").isAccepted());
    EXPECT_EQ(U"rya", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateRYI) {
    auto automaton = AutomatonCreator::create(U"りぃ");
    EXPECT_TRUE(automaton.transitByInput(U"ryi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"rixi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"rili").isAccepted());
    EXPECT_EQ(U"ryi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateRYU) {
    auto automaton = AutomatonCreator::create(U"りゅ");
    EXPECT_TRUE(automaton.transitByInput(U"ryu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"rixyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"rilyu").isAccepted());
    EXPECT_EQ(U"ryu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateRYE) {
    auto automaton = AutomatonCreator::create(U"りぇ");
    EXPECT_TRUE(automaton.transitByInput(U"rye").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"rixe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"rile").isAccepted());
    EXPECT_EQ(U"rye", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateRYO) {
    auto automaton = AutomatonCreator::create(U"りょ");
    EXPECT_TRUE(automaton.transitByInput(U"ryo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"rixyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"rilyo").isAccepted());
    EXPECT_EQ(U"ryo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateVA) {
    auto automaton = AutomatonCreator::create(U"ゔぁ");
    EXPECT_TRUE(automaton.transitByInput(U"va").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"vuxa").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"vula").isAccepted());
    EXPECT_EQ(U"va", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateVI) {
    auto automaton = AutomatonCreator::create(U"ゔぃ");
    EXPECT_TRUE(automaton.transitByInput(U"vi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"vyi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"vuxi").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"vuli").isAccepted());
    EXPECT_EQ(U"vi", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateVU) {
    auto automaton = AutomatonCreator::create(U"ゔ");
    EXPECT_TRUE(automaton.transitByInput(U"vu").isAccepted());
    EXPECT_EQ(U"vu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateVE) {
    auto automaton = AutomatonCreator::create(U"ゔぇ");
    EXPECT_TRUE(automaton.transitByInput(U"ve").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"vye").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"vuxe").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"vule").isAccepted());
    EXPECT_EQ(U"ve", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateVO) {
    auto automaton = AutomatonCreator::create(U"ゔぉ");
    EXPECT_TRUE(automaton.transitByInput(U"vo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"vuxo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"vulo").isAccepted());
    EXPECT_EQ(U"vo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateVYA) {
    auto automaton = AutomatonCreator::create(U"ゔゃ");
    EXPECT_TRUE(automaton.transitByInput(U"vya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"vuxya").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"vulya").isAccepted());
    EXPECT_EQ(U"vya", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateVYU) {
    auto automaton = AutomatonCreator::create(U"ゔゅ");
    EXPECT_TRUE(automaton.transitByInput(U"vyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"vuxyu").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"vulyu").isAccepted());
    EXPECT_EQ(U"vyu", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateVYO) {
    auto automaton = AutomatonCreator::create(U"ゔょ");
    EXPECT_TRUE(automaton.transitByInput(U"vyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"vuxyo").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"vulyo").isAccepted());
    EXPECT_EQ(U"vyo", automaton.transitByPriority().getAccumulatedInput());
}

TEST(AutomatonCreatorTest, CreateNN1) {
    auto automaton = AutomatonCreator::create(U"ん");
    EXPECT_TRUE(automaton.transitByInput(U"nn").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"xn").isAccepted());
    EXPECT_TRUE(automaton.transitByInput(U"n\'").isAccepted());
    EXPECT_FALSE(automaton.transitByInput(U"n").isAccepted());
    EXPECT_EQ(U"nn", automaton.transitByPriority().getAccumulatedInput());
}
}