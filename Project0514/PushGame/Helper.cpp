#include "Helper.h"
#include <Windows.h>


void HandleKeyInput(Position& PlayerPosition, MapInfo* MapInfoArray)
{
	int WitchPressed = 0;

	// 왼쪽 키가 눌렸는냐
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

			//이동한 위치가, 공과 중복이 될 때
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
		//깃발로 이동 막기
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
		//골인처리시 할당하는 위치 값 -1이 중복되어 들어오는 경우가 있음
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