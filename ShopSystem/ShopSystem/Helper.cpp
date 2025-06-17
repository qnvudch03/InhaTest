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

bool GetKeyInput(KeyType key)
{
	if (GetAsyncKeyState((int)key) & 0x01) 
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

void SetCursorColor(Color color, Color bg)
{
	int code = (bg << 4) | color;
	//int code = color;
	// 색상코드: 배경색(4bit) + 글자색(4bit) 조합
	HANDLE hConsole = ::GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, code);
}

void ClearAfterCursorPosition(int x, int y)
{
	HANDLE hConsole = ::GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);

	COORD cursorPos;
	cursorPos.X = x;
	cursorPos.Y = y;
	DWORD cellsToClear = (csbi.dwSize.X * csbi.dwSize.Y) - (cursorPos.Y * csbi.dwSize.X + cursorPos.X);

	DWORD written;

	// 문자 지우기 (공백으로 채움)
	FillConsoleOutputCharacter(hConsole, ' ', cellsToClear, cursorPos, &written);

	// 속성도 지움 (기본 색으로 초기화)
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellsToClear, cursorPos, &written);

	// 커서 위치 되돌리기 (원래대로 유지)
	SetCursorPosition(x, y);
}

std::string Utf8ToAnsi(const std::string& utf8Str) 
{
	// UTF-8 → UTF-16 (wide string)
	int wideLen = MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, NULL, 0);
	if (wideLen == 0) return "";

	std::wstring wideStr(wideLen, 0);
	MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, &wideStr[0], wideLen);

	// UTF-16 → ANSI (CP949)
	int ansiLen = WideCharToMultiByte(949, 0, wideStr.c_str(), -1, NULL, 0, NULL, NULL);
	if (ansiLen == 0) return "";

	std::string ansiStr(ansiLen, 0);
	WideCharToMultiByte(949, 0, wideStr.c_str(), -1, &ansiStr[0], ansiLen, NULL, NULL);

	return ansiStr;
}

// 1 ~ 5
// ((5+1)-1) : rand() % 5 = (0~4)+1 = 1~4
int RandomRange(int min, int includeMax)
{
	if (min == 0 && includeMax == 0)
		return 0;

	return (rand() % ((includeMax +1) - min)) + min;
}
