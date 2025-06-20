#include "pch.h"
#include "Helper.h"
#include <Windows.h>

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

	return (rand() % ((includeMax + 1) - min)) + min;
}
