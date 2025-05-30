#include "Helper.h"
#include <Windows.h>

void HandleKeyInput()
{
	// ���� Ű�� ���ȴ³�
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


// �ϳ��� �����? �����Լ�.
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
	// �����ڵ�: ����(4bit) + ���ڻ�(4bit) ����
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, code);
}