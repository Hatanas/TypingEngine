// TypingEngine.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <cstdio>
#include <Windows.h>

#include "AutomatonGenerator.h"
#include "Automaton.h"
#include "TransFunction.h"

using namespace std;
using namespace TypingEngine;

int main()
{
    setlocale(LC_CTYPE, "");

    // QueryPerformanceCounter関数の1秒当たりのカウント数を取得する
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    LARGE_INTEGER start, end;
    QueryPerformanceCounter(&start);

    Automaton m = AutomatonGenerator().generate(L"");

    QueryPerformanceCounter(&end);

    double time = static_cast< double >(end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
    printf("time %lf[ms]\n", time);
    
    wstring str = m.toPlantUML();
    //あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほまみむめもやゆよらりるれろわをん
    wcout << str << endl;
    return 0;
}
