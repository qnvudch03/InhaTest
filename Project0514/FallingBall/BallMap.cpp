#include "pch.h"
#include "BallMap.h"
#include "Helper.h"

extern int Score;
extern int Life;

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

	//�ʷϵ��׶�� ���
	{
		for (int index = 0; index < MAX_ARRAYBALL; index++)
		{
			if (HeallingBallManagerArray[index] == nullptr)
			{
				continue;
			}

			SetCursorColor(Color::RightGreen);
			SetCursorPosition(HeallingBallManagerArray[index]->x * 2, HeallingBallManagerArray[index]->y);
			std::cout << "��";
			SetCursorColor(Color::White);
		}
	}

	//������׶�� ���
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

	//�������׶�� ���
	{
		for (int index = 0; index < MAX_ARRAYBALL; index++)
		{
			if (REDBallManagerArray[index] == nullptr)
			{
				continue;
			}

			SetCursorColor(Color::RightBlue);
			SetCursorPosition(REDBallManagerArray[index]->x * 2, REDBallManagerArray[index]->y);
			std::cout << "��";
			SetCursorColor(Color::White);
		}
	}

	SetCursorColor(Color::Red);
	SetCursorPosition(0, MAP_HEIGHT + 1);
	for (int life = 0; life < Life; life++)
	{
		std::cout << "��";
	}


	SetCursorColor(Color::White);

	SetCursorColor(Color::SkyBlue);
	SetCursorPosition(0, MAP_HEIGHT + 2);
	std::cout << "SCORE : " << Score;
	SetCursorColor(Color::White);
}

bool BallMap::CheckCollision(Position* PlayerPosition)
{
	//Check Yellow
	for (int index = 0; index < MAX_ARRAYBALL; index++)
	{
		if (BallManagerArray[index] == nullptr)
			continue;

		if (*BallManagerArray[index] == *PlayerPosition)
		{
			SetCursorColor(Color::Red);
			SetCursorPosition(PlayerPosition->x * 2, PlayerPosition->y);
			std::cout << "��";
			SetCursorColor(Color::White);

			//1������ ������ ���·�, Collison�� �������� �´� ������ �־� �𸮼ǿ����� ����� ���� �߰�
			delete BallManagerArray[index];
			BallManagerArray[index] = nullptr;

			return true;
		}
	}

	//Check Red
	for (int index = 0; index < MAX_ARRAYBALL; index++)
	{
		if (REDBallManagerArray[index] == nullptr)
			continue;

		if (*REDBallManagerArray[index] == *PlayerPosition)
		{
			SetCursorColor(Color::Red);
			SetCursorPosition(PlayerPosition->x * 2, PlayerPosition->y);
			std::cout << "��";
			SetCursorColor(Color::White);

			//1������ ������ ���·�, Collison�� �������� �´� ������ �־� �𸮼ǿ����� ����� ���� �߰�
			delete REDBallManagerArray[index];
			REDBallManagerArray[index] = nullptr;

			return true;
		}
	}

	//Check Heal
	for (int index = 0; index < MAX_ARRAYBALL; index++)
	{
		if (HeallingBallManagerArray[index] == nullptr)
			continue;

		if (*HeallingBallManagerArray[index] == *PlayerPosition)
		{
			Life++;

			//1������ ������ ���·�, Collison�� �������� �´� ������ �־� �𸮼ǿ����� ����� ���� �߰�
			delete HeallingBallManagerArray[index];
			HeallingBallManagerArray[index] = nullptr;

			return false;
		}
	}

	return false;
}

void BallMap::UpdateYellowBall()
{
	//Update Yellow Ball
	for (int Yellowindex = 0; Yellowindex < MAX_ARRAYBALL; Yellowindex++)
	{

		{
			//�Ŵ����迭�� ������ index�� nullPosition �̸� �ǳʶٱ�
			if (BallManagerArray[Yellowindex] == nullptr)
			{
				continue;
			}

			//�ٴڿ� �̹� ���� ����� ����
			else if (BallManagerArray[Yellowindex]->y == MAP_HEIGHT - 1)
			{
				delete BallManagerArray[Yellowindex];
				BallManagerArray[Yellowindex] = nullptr;
				Score++;
			}

			else
			{
				BallManagerArray[Yellowindex]->y += 1;
			}
		}

	}

}

void BallMap::UpdateRedBall()
{
	//Update
	for (int REDindex = 0; REDindex < MAX_ARRAYBALL; REDindex++)
	{

		{
			//�Ŵ����迭�� ������ index�� nullPosition �̸� �ǳʶٱ�
			if (REDBallManagerArray[REDindex] == nullptr)
			{
				continue;
			}

			//�ٴڿ� ���� ������ ����
			else if (REDBallManagerArray[REDindex]->y == MAP_HEIGHT - 1)
			{
				delete REDBallManagerArray[REDindex];
				REDBallManagerArray[REDindex] = nullptr;
				Score++;
			}

			else
			{
				REDBallManagerArray[REDindex]->y += 1;
			}
		}
	}
}

void BallMap::UpdateHealBall()
{
	//Update
	for (int Healindex = 0; Healindex < MAX_ARRAYBALL; Healindex++)
	{

		{
			//�Ŵ����迭�� ������ index�� nullPosition �̸� �ǳʶٱ�
			if (HeallingBallManagerArray[Healindex] == nullptr)
			{
				continue;
			}

			//�ٴڿ� ���� ���� �� ����
			else if (HeallingBallManagerArray[Healindex]->y == MAP_HEIGHT - 1)
			{
				delete HeallingBallManagerArray[Healindex];
				HeallingBallManagerArray[Healindex] = nullptr;
			}

			else
			{
				HeallingBallManagerArray[Healindex]->y += 1;
			}
		}

	}
}

void BallMap::UpdateBall(BallType Balltype)
{
	//Position* SelectedBallType = nullptr;

	//switch (Balltype)
	//{
	//case Yellow:
	//	SelectedBallType = BallManagerArray;
	//	break;
	//case Blue:
	//	SelectedBallType = *REDBallManagerArray;
	//	break;
	//case Heal:
	//	SelectedBallType = *HeallingBallManagerArray;
	//	break;
	//default:
	//	break;
	//}



	////�� ������ �ȵǴ°ž�
	//for (int Index = 0; Index < MAX_ARRAYBALL; Index++)
	//{

	//	{
	//		//�Ŵ����迭�� ������ index�� nullPosition �̸� �ǳʶٱ�
	//		if (&SelectedBallType[Index] == nullptr)
	//		{
	//			continue;
	//		}

	//		//�ٴڿ� �̹� ���� ����� ����
	//		else if (&SelectedBallType[Index]->y == MAP_HEIGHT - 1)
	//		{
	//			delete BallManagerArray[Index];
	//			BallManagerArray[Index] = nullptr;
	//			Score++;
	//		}

	//		else
	//		{
	//			BallManagerArray[Index]->y += 1;
	//		}
	//	}

	//}



}

void BallMap::Test()
{
	
}
