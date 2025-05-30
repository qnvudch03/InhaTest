#pragma once

#include "Util.h"
#define GAMESIZE 10

// 키보드 입력
 Position HandleKeyInput(Position InValue);
 bool DetectSpaceBar();

enum Chess
{
	None = 0,
	White,
	Black,
	Max_Size
};

void SetCursorPosition(int x, int y);
void SetCursorOnOff(bool visible);

//SetCursorColor(Color::Yellow, Color::Red);
//SetCursorColor(Color::Yellow);