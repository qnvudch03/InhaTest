#pragma once


enum MoveDir
{
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_MAX,
};

struct Pos
{
	int x = 0;
	int y = 0;
};

// Ű���� �Է�
bool IsKeyDown(MoveDir dir);
MoveDir HandleKeyInput();

enum Color
{
	Black = 0,
	SkyBlue = 3,
	Red = 4,
	Default = 7, // �⺻ ȸ��
	Yellow = 6,
	RightGreen = 10,
	RightBlue = 9,
	White = 15,
};

// ��µ� Ŀ���� ��ġ�� �ű��. SetCursorPosition(0,0) ���� ȣ���ϸ�, �ܼ�â�� ù ���������� �̵��ؼ� ���ڸ� ����Ѵ�
void SetCursorPosition(int x, int y);

// Ŀ���� ����� �Ѱ�/����.
void SetCursorOnOff(bool visible);

// ���â�� ���� ������ ���� + ������ �����Ѵ�.
// Color�� enum ���ǵ� ������ ���ϴ� Color ���� �߰��ϰ� ���� KeyCode�� �Է��Ѵ�.(KeyCode�� ���ڿ� �����Ǿ��ֽ��ϴ�)
void SetCursorColor(Color color, Color bg = Color::Black);

//SetCursorColor(Color::Yellow, Color::Red);
//SetCursorColor(Color::Yellow);