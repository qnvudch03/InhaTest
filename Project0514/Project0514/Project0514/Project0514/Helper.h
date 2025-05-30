#pragma once

// 키보드 입력
void HandleKeyInput();

enum Color
{
	Red = 12,
	Black = 0,
	Yellow = 14,
};

void SetCursorPosition(int x, int y);
void SetCursorOnOff(bool visible);
void SetCursorColor(Color color, Color bg = Color::Black);

//SetCursorColor(Color::Yellow, Color::Red);
//SetCursorColor(Color::Yellow);