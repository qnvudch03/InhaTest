#include "pch.h"
#include "Helper.h"
#include <Windows.h>


// �������Ӹ��� Ű������ �Է¿� ���� ���°��� �����Ѵ�. ��?
// ���� �������� Ű ���� vs ���� �������� Ű ���� ���ؼ�,
// ��� ��������? or ��� ������ ��������? or ��� ������?
//0 or 1
bool pressed[MoveDir::MOVE_MAX] = { 0 };	// ���� ���¿� ���� ���� �����ϰ� �ִ� ����
int vkMapping[MoveDir::MOVE_MAX] = { VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN };

// ��� Ű�� ��������? ���¸� �����ϴ� �Է� �Լ�
bool IsKeyDown(MoveDir dir)
{
	// 0x01 Ű �Է��� ���¼��� �ѹ��� üũ�ϴ� �뵵?
	// 0x8000 �������� ���� üũ�ϴ� �뵵.
	bool now = GetAsyncKeyState(vkMapping[dir]) & 0x8000;
	bool prev = pressed[dir];
	
	pressed[dir] = now;

	// ������ Ű�� �������ִµ�, �������� �ȴ������־���.
	// -> ���� �� ������!
	return (now && !prev);
}

// � Ű�� �������ִ���? �̷� ���Ҹ� �Ұ��̴�.
MoveDir HandleKeyInput()
{
	// ���� Ű�� ���ȴ³�
	if (GetAsyncKeyState(VK_LEFT) & 0x01) // Ű����θ� ����� ���� �����. ������, inputcheck ���ٸ�? �ܼ� �е�?? 
	{
		// �÷��̾� �̵� ����
		return MoveDir::MOVE_LEFT;
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x01)
	{
		return MoveDir::MOVE_RIGHT;
	}
	else if (GetAsyncKeyState(VK_UP) & 0x01)
	{
		return MoveDir::MOVE_UP;
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x01)
	{
		return MoveDir::MOVE_DOWN;
	}

	return MOVE_MAX;
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