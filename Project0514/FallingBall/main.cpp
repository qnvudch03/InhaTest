#include "pch.h"
#include "Helper.h"
#include "BallMap.h"
#include "PlayerBall.h"

#include <Windows.h>
#include <random>

//const char* Map[MAP_WIDTH][MAP_HEIGHT];

int Score = 0;
int Life = 3;

void ClearMap();
Position* MakeNewBall();

Position* BallManagerArray[MAX_ARRAYBALL];
Position* REDBallManagerArray[MAX_ARRAYBALL];
Position* HeallingBallManagerArray[MAX_ARRAYBALL];

Position** BallManager[BallType::BallMax] = { BallManagerArray , REDBallManagerArray , HeallingBallManagerArray };

int main()
{
	//입력

	//로직

	//출력

	SetCursorOnOff(false);

	Position PlayerPosition = { MAP_WIDTH / 2, MAP_HEIGHT - 1 };

	int FrameCount = 3;

	int YellowFramdCount = 2;

	int HealFrameCount = 3;

	std::random_device rd;

	while (true)
	{
		int CurrentLevel = (Score / 100) + 1;
		FrameCount--;

		if (FrameCount == 0)
		{
			//스코어가 100점이 오를 때 마다, 레벨을 오르고 공을 추가로 생성
			for (int LevelAdd = 0; LevelAdd < CurrentLevel; LevelAdd++)
			{
				int WitchBallToSpawn = 100 - (rd() % 100);

				//87% 확율로 노란공 생성
				if (WitchBallToSpawn > 13)
				{
					//nullPtr을 가르키는 요소를 찾아 공 포인터를 할당
					for (int BallIndex = 0; BallIndex < MAX_ARRAYBALL; BallIndex++)
					{
						//if (BallManagerArray[BallIndex] != nullptr)
						if (BallManager[BallType::BallYellow][BallIndex] != nullptr)
							continue;

						Position* NewBall = MakeNewBall();
						//BallManagerArray[BallIndex] = NewBall;
						BallManager[BallType::BallYellow][BallIndex] = NewBall;
						break;
					}
				}

				//10% 확율로 노란공 생성
				else if (WitchBallToSpawn > 3)
				{
					//nullPtr을 가르키는 요소를 찾아 공 포인터를 할당
					for (int BallIndex = 0; BallIndex < MAX_ARRAYBALL; BallIndex++)
					{
						//if (REDBallManagerArray[BallIndex] != nullptr)
						if (BallManager[BallType::BallBlue][BallIndex] != nullptr)
							continue;

						Position* NewBall = MakeNewBall();
						//REDBallManagerArray[BallIndex] = NewBall;
						BallManager[BallType::BallBlue][BallIndex] = NewBall;
						break;
					}
				}

				//3% 확율로 힐링공 생성
				else
				{
					for (int BallIndex = 0; BallIndex < MAX_ARRAYBALL; BallIndex++)
					{
						//if (HeallingBallManagerArray[BallIndex] != nullptr)
						if (BallManager[BallType::BallHeal][BallIndex] != nullptr)
							continue;

						Position* NewBall = MakeNewBall();
						BallManager[BallType::BallHeal][BallIndex] = NewBall;
						break;
					}
				}
			}

			FrameCount = 3;
		}

		ClearMap();

		MoveDir PlayerInput = HandleKeyInput();

		BallMap::UpdateYellowBall();
		//BallMap::UpdateBall(BallType::BallYellow);

		if (YellowFramdCount == 0)
		{
			BallMap::UpdateRedBall();
			//BallMap::UpdateBall(BallType::BallBlue);
			YellowFramdCount = 2; //2
		}

		if (HealFrameCount == 0)
		{
			BallMap::UpdateHealBall();
			//BallMap::UpdateBall(BallType::BallHeal);
			HealFrameCount = 3; //3
		}



		UpdatePlayer(&PlayerPosition, PlayerInput);

		//BallMap::Test();

		BallMap::PrintMap(&PlayerPosition);


		//Life가 바닥나면 게임 종료
		if (BallMap::CheckCollision(&PlayerPosition))
		{
			Life--;
		}
		else
		{
			//Life 충전!!
		}

		if (Life == 0)
		{
			//하트 지우기
			SetCursorPosition(0, MAP_HEIGHT + 1);
			std::cout << "  ";
			SetCursorPosition(0, MAP_HEIGHT + 3);

			break;
		}

		Sleep(50);

		YellowFramdCount--;
		HealFrameCount--;

	}

	for (int i = 0; i < MAX_ARRAYBALL; i++)
	{
		if (BallManagerArray[i] != nullptr)
		{
			delete BallManagerArray[i];
			BallManagerArray[i] = nullptr;
		}
			

		if (REDBallManagerArray[i] != nullptr)
		{
			delete REDBallManagerArray[i];
			REDBallManagerArray[i] = nullptr;
		}
			

		if (HeallingBallManagerArray[i] != nullptr)
		{
			delete HeallingBallManagerArray[i];
			HeallingBallManagerArray[i] = nullptr;
		}
	}

}

void ClearMap()
{
	SetCursorPosition(0, 0);

	//Clear Game Map Image
	for (int horizon = 0; horizon < MAP_HEIGHT; horizon++)
	{
		for (int vertical = 0; vertical < MAP_WIDTH; vertical++)
		{
			std::cout << "□";
		}
		std::cout << '\n';
	}

	//Clear Life Image
	SetCursorPosition(0, MAP_HEIGHT + 1);
	for (int index = 0; index < MAX_LIFE * 2; index++)
	{
		std::cout << "  ";
	}


	SetCursorPosition(0, 0);
}

Position* MakeNewBall()
{
	Position* NewPosition = new Position;

	std::random_device rd;
	int RandomIndex = (rd() % MAP_WIDTH);

	NewPosition->x = RandomIndex;
	NewPosition->y = 0;

	return NewPosition;
}
