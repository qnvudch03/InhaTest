#include "pch.h"
#include "Logic.h"
#include <random>

extern int Score;

extern MoveDir CurrentMoveDir;

extern Position MovingOffset[4];

Position** SpawnNewFood(Position* HeadPosition, Position** FoodArray)
{
	int currentFoodCount = 0;

	while (true)
	{
		if (FoodArray[currentFoodCount] != nullptr)
		{
			currentFoodCount++;
		}

		else
			break;
	}

	Position** NewFoodArray = new Position * [currentFoodCount + 2];

	//기존포인터에 있던 food값 index를 받아옴
	for (int i = 0; i < currentFoodCount; i++)
	{
		NewFoodArray[i] = new Position;
		NewFoodArray[i]->x = FoodArray[i]->x;
		NewFoodArray[i]->y = FoodArray[i]->y;
	}


	Position SnailHead = *HeadPosition;

	std::random_device rd;

	Position* RandomFoodPosition = new Position;

	//지렁이 머리와 겹쳐져 있는지는 않은지 확인
	while (true)
	{
		int RandomX = (rd() % (MAP_WIDTH - 2)) + 1;
		int RandomY = (rd() % (MAP_HEIGHT - 2)) + 1;

		if (RandomX == HeadPosition->x && RandomY == HeadPosition->y)
		{
			continue;
		}

		else
		{
			bool bIsNoneOverlab = true;
			//현재 음식 배열과 중복이 되지는 않는지 확인
			for (int FoodIndex = 0; FoodIndex < currentFoodCount; FoodIndex++)
			{
				if (FoodArray[FoodIndex]->x == RandomX && FoodArray[FoodIndex]->y == RandomY)
				{
					bIsNoneOverlab = false;
				}
			}

			if (bIsNoneOverlab)
			{
				RandomFoodPosition->x = RandomX;
				RandomFoodPosition->y = RandomY;
				break;
			}

		}


	}

	NewFoodArray[currentFoodCount] = RandomFoodPosition;
	NewFoodArray[currentFoodCount + 1] = nullptr;

	delete[] * FoodArray;
	*FoodArray = nullptr;

	return NewFoodArray;
}

void UpdateSnail(Position** SnailArray, MoveDir PlayerInput)
{
	if (PlayerInput != MoveDir::MOVE_MAX || PlayerInput == CurrentMoveDir)
	{
		CurrentMoveDir = PlayerInput;
	}

	if (CurrentMoveDir == MoveDir::MOVE_MAX)
		return;

	//머리 이동
	{
		Position pastPostiion = *SnailArray[0];
		SnailArray[0]->past_x = SnailArray[0]->x;
		SnailArray[0]->past_y = SnailArray[0]->y;
		*SnailArray[0] = *SnailArray[0] + MovingOffset[(int)CurrentMoveDir];
	}


	//과거와 현재를 잇는 코드
	int SnailIndex = 1;
	while (true)
	{
		if (SnailArray[SnailIndex] == nullptr || (SnailArray[SnailIndex]->x == 0 && SnailArray[SnailIndex]->y == 0))
			break;

		int past1 = SnailArray[SnailIndex - 1]->past_x;
		int past2 = SnailArray[SnailIndex - 1]->past_y;

		SnailArray[SnailIndex]->past_x = SnailArray[SnailIndex]->x;
		SnailArray[SnailIndex]->past_y = SnailArray[SnailIndex]->y;

		SnailArray[SnailIndex]->x = SnailArray[SnailIndex - 1]->past_x;
		SnailArray[SnailIndex]->y = SnailArray[SnailIndex - 1]->past_y;



		SnailIndex++;
	}

	//CurrentMoveDir에 따라 SnailArray의 배열의 값을 지속 한칸씩 증가
}

bool CheckEatFood(Position* SnialHead, Position** FoodArray)
{
	int FoodIndex = 0;
	Position SnailHeadPosition = *SnialHead;

	bool bIsEatFood = false;

	while (true)
	{
		if (FoodArray[FoodIndex] == nullptr)
			break;

		if (*FoodArray[FoodIndex] == SnailHeadPosition)
		{
			Position Test = *FoodArray[FoodIndex];
			bIsEatFood = true;
			FoodArray[FoodIndex]->x = -1;
			FoodArray[FoodIndex]->y = -1;
			Score++;
		}


		FoodIndex++;
	}

	return bIsEatFood;
}

bool CheckEatDietFood(Position* SnialHead, Position** DieteFoodArray)
{
	int FoodIndex = 0;
	Position SnailHeadPosition = *SnialHead;

	bool bIsEatFood = false;

	while (true)
	{
		if (DieteFoodArray[FoodIndex] == nullptr)
			break;

		if (*DieteFoodArray[FoodIndex] == SnailHeadPosition)
		{
			Position Test = *DieteFoodArray[FoodIndex];
			bIsEatFood = true;
			DieteFoodArray[FoodIndex]->x = -1;
			DieteFoodArray[FoodIndex]->y = -1;
			Score++;
		}


		FoodIndex++;
	}

	return bIsEatFood;
}

bool CheckCollision(Position** SnailArray)
{
	Position HeadPosition = *(*SnailArray);

	//벽에 충돌했는지 체크
	if (HeadPosition.x == MAP_WIDTH - 1 || HeadPosition.y == MAP_HEIGHT-1 || HeadPosition.x == 0 || HeadPosition.y == 0)
	{
		return true;
	}

	//자기들 끼리 겹쳤는지 체크
	int snailCount = 1;
	while (true)
	{
		if (SnailArray[snailCount] == nullptr)
			break;


		if (SnailArray[snailCount]->x == HeadPosition.x && SnailArray[snailCount]->y == HeadPosition.y)
		{
			return true;
		}
		snailCount++;
	}


	return false;
}
