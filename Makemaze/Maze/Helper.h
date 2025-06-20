#pragma once

#include <string>
#include <Windows.h>

enum Color
{
	Black = 0,
	Blue = 1,
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