#pragma once

#include <string>
#include <Windows.h>

enum Color
{
	Black = 0,
	Blue = 1,
	SkyBlue = 3,
	Red = 4,
	Default = 7, // 기본 회색
	Yellow = 6,
	RightGreen = 10,
	RightBlue = 9,
	RightRed = 12,
	White = 15,
};

// 출력될 커서의 위치를 옮긴다. SetCursorPosition(0,0) 으로 호출하면, 콘솔창의 첫 시작점으로 이동해서 글자를 출력한다
void SetCursorPosition(int x, int y);

// 커서의 모양을 켜고/끈다.
void SetCursorOnOff(bool visible);

// 출력창에 찍힐 글자의 색상 + 배경색을 변경한다.
// Color는 enum 정의된 값으로 원하는 Color 값을 추가하고 맞은 KeyCode를 입력한다.(KeyCode는 디코에 공유되어있습니다)
void SetCursorColor(Color color, Color bg = Color::Black);

void ClearAfterCursorPosition(int x, int y);

std::string Utf8ToAnsi(const std::string& utf8Str);

int RandomRange(int min, int max);