#pragma once

#include <string>
#include <Windows.h>

enum MoveDir
{
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_MAX,
};

enum class KeyType
{
	Left = VK_LEFT,
	Right = VK_RIGHT,
};

struct Pos
{
	int x = 0;
	int y = 0;
};

// Ű���� �Է�
bool IsKeyDown(MoveDir dir);
MoveDir HandleKeyInput();
bool GetKeyInput(KeyType key);

enum Color
{
	Black = 0,
	SkyBlue = 3,
	Red = 4,
	Default = 7, // �⺻ ȸ��
	Yellow = 6,
	RightGreen = 10,
	RightBlue = 9,
	RightRed = 12,
	White = 15,
};

// ��µ� Ŀ���� ��ġ�� �ű��. SetCursorPosition(0,0) ���� ȣ���ϸ�, �ܼ�â�� ù ���������� �̵��ؼ� ���ڸ� ����Ѵ�
void SetCursorPosition(int x, int y);

// Ŀ���� ����� �Ѱ�/����.
void SetCursorOnOff(bool visible);

// ���â�� ���� ������ ���� + ������ �����Ѵ�.
// Color�� enum ���ǵ� ������ ���ϴ� Color ���� �߰��ϰ� ���� KeyCode�� �Է��Ѵ�.(KeyCode�� ���ڿ� �����Ǿ��ֽ��ϴ�)
void SetCursorColor(Color color, Color bg = Color::Black);

void ClearAfterCursorPosition(int x, int y);

std::string Utf8ToAnsi(const std::string& utf8Str);

int RandomRange(int min, int max);