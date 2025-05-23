#include "Helper.h"
#include <Windows.h>


Position HandleKeyInput(Position InPosition)
{
	if (InPosition.x >= GAMESIZE || InPosition.x < 0 || InPosition.y >= GAMESIZE || InPosition.y < 0)
		return InPosition;

	if (GetAsyncKeyState(VK_LEFT) & 0x01)
	{
		InPosition.x -= 1;
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x01)
	{
		InPosition.x += 1;
	}
	else if (GetAsyncKeyState(VK_UP) & 0x01)
	{
		InPosition.y -= 1;
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x01)
	{
		InPosition.y += 1;
	}

	return InPosition;
}

bool DetectSpaceBar()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x01)
	{
		return true;
	}
	return false;
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