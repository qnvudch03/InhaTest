#include "pch.h"
#include "Helper.h"
#include <Windows.h>


// 한프레임마다 키보드의 입력에 대한 상태값을 저장한다. 왜?
// 이전 프레임의 키 상태 vs 현재 프레임의 키 상태 비교해서,
// 방금 눌렀는지? or 계속 눌러진 상태인지? or 방금 릴리즈?
//0 or 1
bool pressed[MoveDir::MOVE_MAX] = { 0 };	// 이전 상태에 대한 값을 저장하고 있는 변수
int vkMapping[MoveDir::MOVE_MAX] = { VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN };

// 방금 키가 눌렀느냐? 상태를 리턴하는 입력 함수
bool IsKeyDown(MoveDir dir)
{
	// 0x01 키 입력이 들어온순간 한번만 체크하는 용도?
	// 0x8000 프레스드 상태 체크하는 용도.
	bool now = GetAsyncKeyState(vkMapping[dir]) & 0x8000;
	bool prev = pressed[dir];
	
	pressed[dir] = now;

	// 지금은 키가 눌러져있는데, 이전에는 안눌러져있었어.
	// -> 지금 막 눌렀다!
	return (now && !prev);
}

// 어떤 키가 눌러져있느냐? 이런 역할만 할것이다.
MoveDir HandleKeyInput()
{
	// 왼쪽 키가 눌렸는냐
	if (GetAsyncKeyState(VK_LEFT) & 0x01) // 키보드로만 변경될 일은 없어요. 하지만, inputcheck 들어간다면? 콘솔 패드?? 
	{
		// 플레이어 이동 로직
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