#include "Helper.h"
#include <Windows.h>


void HandleKeyInput(Position& PlayerPosition, MapInfo* MapInfoArray)
{
	int WitchPressed = 0;

	// ���� Ű�� ���ȴ³�
	if (GetAsyncKeyState(VK_LEFT) & 0x01)
	{
		WitchPressed = KeyBoard::LEFT;

		if (PlayerPosition.x > 1)
		{
			PlayerPosition.x -= 1;
		}

		for (int MapInfoIndex = 0; MapInfoIndex < GollNum; MapInfoIndex++)
		{
			Position& BallPosition = MapInfoArray[MapInfoIndex].BallPosition;

			//�̵��� ��ġ��, ���� �ߺ��� �� ��
			if (PlayerPosition == BallPosition)
			{
				if (BallPosition.x != 1)
				{
					BallPosition.x -= 1;
				}
				else
					PlayerPosition.x += 1;
			}
		}

		
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x01)
	{
		WitchPressed = KeyBoard::RIGHT;

		if (PlayerPosition.x < MAP_SIZE)
		{
			PlayerPosition.x += 1;
		}

		for (int MapInfoIndex = 0; MapInfoIndex < GollNum; MapInfoIndex++)
		{
			Position& BallPosition = MapInfoArray[MapInfoIndex].BallPosition;

			if (PlayerPosition == BallPosition)
			{
				if (BallPosition.x != MAP_SIZE)
				{
					BallPosition.x += 1;
				}
				else
					PlayerPosition.x -= 1;
			}
		}

	}
	else if (GetAsyncKeyState(VK_UP) & 0x01)
	{

		WitchPressed = KeyBoard::UP;

		if (PlayerPosition.y > 1)
		{
			PlayerPosition.y -= 1;
		}

		for (int MapInfoIndex = 0; MapInfoIndex < GollNum; MapInfoIndex++)
		{
			Position& BallPosition = MapInfoArray[MapInfoIndex].BallPosition;

			if (PlayerPosition == BallPosition)
			{
				if (BallPosition.y != 1)
				{
					BallPosition.y -= 1;
				}
				else
					PlayerPosition.y += 1;
			}
		}

	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x01)
	{
		WitchPressed = KeyBoard::DOWN;

		if (PlayerPosition.y < MAP_SIZE)
		{
			PlayerPosition.y += 1;
		}

		for (int MapInfoIndex = 0; MapInfoIndex < GollNum; MapInfoIndex++)
		{
			Position& BallPosition = MapInfoArray[MapInfoIndex].BallPosition;

			if (PlayerPosition == BallPosition)
			{
				if (BallPosition.y != MAP_SIZE)
				{
					BallPosition.y += 1;
				}
				else
					PlayerPosition.y -= 1;
			}
		}

		
	}

	for (int i = 0; i < GollNum; i++)
	{
		//��߷� �̵� ����
		Position& FlagPosition = MapInfoArray[i].FlagPosition;
		if (PlayerPosition == FlagPosition)
		{
			switch (WitchPressed)
			{
			case KeyBoard::UP:
				PlayerPosition.y += 1;
				break;

			case KeyBoard::DOWN:
				PlayerPosition.y -= 1;
				break;

			case KeyBoard::RIGHT:
				PlayerPosition.x -= 1;
				break;

			case KeyBoard::LEFT:
				PlayerPosition.x += 1;
				break;
			default:
				break;
			}
		}
	}

	CheckBoxOverrlap(WitchPressed, MapInfoArray);
	
}

void CheckBoxOverrlap(int KeyboardInput, MapInfo* MapInfoArray)
{
	Position* OverallapedBox = nullptr;
	bool Overlapped = false;

	for (int i = 0; i < GollNum; i++)
	{
		if (i == GollNum - 1)
			continue;

		for (int a = 1; a < GollNum; a++)
		{
			if (MapInfoArray[i].BallPosition == MapInfoArray[a + i].BallPosition)
			{
				OverallapedBox = &MapInfoArray[a].BallPosition;
				Overlapped = true;
			}
		}
		
	}

	if (Overlapped && OverallapedBox != nullptr)
	{
		//����ó���� �Ҵ��ϴ� ��ġ �� -1�� �ߺ��Ǿ� ������ ��찡 ����
		if (OverallapedBox->x == -1 || OverallapedBox->y == -1)
			return;

		switch (KeyboardInput)
		{
		case KeyBoard::UP:
			OverallapedBox->y -= 1;
			break;

		case KeyBoard::DOWN:
			OverallapedBox->y += 1;
			break;

		case KeyBoard::RIGHT:
			OverallapedBox->x += 1;
			break;

		case KeyBoard::LEFT:
			OverallapedBox->x -= 1;
			break;
		default:
			break;
		}
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