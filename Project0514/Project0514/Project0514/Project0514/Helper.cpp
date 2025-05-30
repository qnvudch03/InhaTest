#include "Helper.h"
#include <Windows.h>

void HandleKeyInput()
{
	// 왼쪽 키가 눌렸는냐
	if (GetAsyncKeyState(VK_LEFT) & 0x01)
	{

	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x01)
	{

	}
	else if (GetAsyncKeyState(VK_UP) & 0x01)
	{

	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x01)
	{

	}
}


// 하나의 포장용? 래핑함수.
void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { (SHORT)x, (SHORT)y };
	::SetConsoleCursorPosition(output, pos);
}

void SetCursorOnOff(bool visible)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	::GetConsoleCursorInfo(output, &cursorInfo);
	cursorInfo.bVisible = visible;
	::SetConsoleCursorInfo(output, &cursorInfo);
}

void SetCursorColor(Color color, Color bg)
{
	int code = (bg << 4) | color;
	//int code = color;
	// 색상코드: 배경색(4bit) + 글자색(4bit) 조합
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, code);
}