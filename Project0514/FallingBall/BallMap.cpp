#include "pch.h"
#include "BallMap.h"
#include "Helper.h"

int Score = 0;

void BallMap::PrintMap(Position* PlayerPosition)
{
	//공, 플레이어가 있는 위치로 setcursor를해서 아이콘 그려주기

	//하트 찍기
	{
		SetCursorColor(Color::Red);
		SetCursorPosition(PlayerPosition->x * 2, PlayerPosition->y);
		std::cout << "♥";
		SetCursorColor(Color::White);
	}

	//동그라미 찍기
	{
		for (int index = 0; index < MAX_ARRAYBALL; index++)
		{
			if (BallManagerArray[index] == nullptr)
			{
				continue;
			}

			SetCursorColor(Color::Yellow);
			SetCursorPosition(BallManagerArray[index]->x * 2, BallManagerArray[index]->y);
			std::cout << "▼";
			SetCursorColor(Color::White);
		}
	}

	SetCursorColor(Color::SkyBlue);
	SetCursorPosition(0, MAP_HEIGHT + 1);
	std::cout << "SCORE : " << Score;
	SetCursorColor(Color::White);
}

bool BallMap::CheckCollision(Position* PlayerPosition)
{
	for (int index = 0; index < MAX_ARRAYBALL; index++)
	{
		if (BallManagerArray[index] == nullptr)
			continue;

		if (*BallManagerArray[index] == *PlayerPosition)
		{
			/*SetCursorColor(Color::Red);
			SetCursorPosition(PlayerPosition->x * 2, PlayerPosition->y * 2);
			std::cout << "☆";
			SetCursorColor(Color::White);*/

			return true;
		}
	}

	return false;
}

void BallMap::UpdateBall()
{
	for (int index = 0; index < MAX_ARRAYBALL; index++)
	{
		//매니저배열에 접근한 index가 nullPosition 이면 건너뛰기
		if (BallManagerArray[index] == nullptr)
		{
			continue;
		}

		//바닥에 이미 닿은 놈이라면 삭제
		else if (BallManagerArray[index]->y == MAP_HEIGHT - 1)
		{
			delete BallManagerArray[index];
			BallManagerArray[index] = nullptr;
			Score++;
		}

		else
		{
			BallManagerArray[index]->y += 1;
		}
	}
}
