#include "pch.h"
#include "BallMap.h"
#include "Helper.h"

int Score = 0;

void BallMap::PrintMap(Position* PlayerPosition)
{
	//��, �÷��̾ �ִ� ��ġ�� setcursor���ؼ� ������ �׷��ֱ�

	//��Ʈ ���
	{
		SetCursorColor(Color::Red);
		SetCursorPosition(PlayerPosition->x * 2, PlayerPosition->y);
		std::cout << "��";
		SetCursorColor(Color::White);
	}

	//���׶�� ���
	{
		for (int index = 0; index < MAX_ARRAYBALL; index++)
		{
			if (BallManagerArray[index] == nullptr)
			{
				continue;
			}

			SetCursorColor(Color::Yellow);
			SetCursorPosition(BallManagerArray[index]->x * 2, BallManagerArray[index]->y);
			std::cout << "��";
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
			std::cout << "��";
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
		//�Ŵ����迭�� ������ index�� nullPosition �̸� �ǳʶٱ�
		if (BallManagerArray[index] == nullptr)
		{
			continue;
		}

		//�ٴڿ� �̹� ���� ���̶�� ����
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
