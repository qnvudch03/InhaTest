#include "pch.h"

#include"Helper.h"
#include "Map.h"

void ClearMap()
{
	SetCursorPosition(0, 0);
	for (int vertic = 0; vertic < MAP_HEIGHT; vertic++)
	{
		for (int horizon = 0; horizon < MAP_WIDTH; horizon++)
		{
			std::cout << "��";
		}
		std::cout << '\n';
	}
	SetCursorPosition(0, 0);
}

void PrintMap(Position** SnilArray, Position** FoodArray)
{
	//������ �׸���
	SetCursorPosition(2, 1);
	for (int vertic = 0; vertic < MAP_HEIGHT - 2; vertic++)
	{
		for (int horizon = 0; horizon < MAP_WIDTH - 2; horizon++)
		{
			std::cout << "  ";
		}
		SetCursorPosition(2, 2 + vertic);
	}

	//�����̸� �׸���.
	int SnailIndex = 0;
	while (true)
	{
		if (SnilArray[SnailIndex] == nullptr)
			break;

		SetCursorColor(Color::RightGreen);
		SetCursorPosition(SnilArray[SnailIndex]->x * 2, SnilArray[SnailIndex]->y);
		if (SnailIndex == 0)
			std::cout << "��";
		else
			std::cout << "��";
		
		SnailIndex++;
	}

	//������ �׸���.
	int FoodIndex = 0;
	while (true)
	{
		if (FoodArray[FoodIndex] == nullptr)
			break;

		if (FoodArray[FoodIndex]->x == -1 || FoodArray[FoodIndex]->y == -1)
		{
			FoodIndex++;
			continue;
		}

		SetCursorColor(Color::Yellow);
		SetCursorPosition(FoodArray[FoodIndex]->x * 2, FoodArray[FoodIndex]->y);
		std::cout << "��";
		FoodIndex++;
	}

	//���� ǥ�� â�� �׸���.
	{
		SetCursorColor(Color::White);
		SetCursorPosition(MAP_WIDTH * 2 + 1, 0);
		std::cout << " ���� SCORE : " << Score;

		SetCursorPosition(MAP_WIDTH * 2 + 1, 1);
		std::cout << " ������ ���� : " << SnailIndex << '\n';

		SetCursorPosition(MAP_WIDTH * 2 + 1, 2);
		std::cout << " ���� ���� ���� :   [ " << FoodIndex << " / 100 ]";
	}


	SetCursorColor(Color::White);
	SetCursorPosition(0, 0);
}

void PrintMap(Position** SnilArray, Position** FoodArray, Position** DieteFoodArray)
{
	//������ �׸���
	SetCursorPosition(2, 1);
	for (int vertic = 0; vertic < MAP_HEIGHT - 2; vertic++)
	{
		for (int horizon = 0; horizon < MAP_WIDTH - 2; horizon++)
		{
			std::cout << "  ";
		}
		SetCursorPosition(2, 2 + vertic);
	}

	//�����̸� �׸���.
	int SnailIndex = 0;
	while (true)
	{
		if (SnilArray[SnailIndex] == nullptr || (SnilArray[SnailIndex]->x == -1&& SnilArray[SnailIndex]->y))
			break;

		if (SnilArray[SnailIndex]->x != 0 && SnilArray[SnailIndex]->y != 0 && SnilArray[SnailIndex]->x <= MAP_WIDTH - 2 && SnilArray[SnailIndex]->y <= MAP_HEIGHT - 2)
		{
			SetCursorColor(Color::RightGreen);
			SetCursorPosition(SnilArray[SnailIndex]->x * 2, SnilArray[SnailIndex]->y);
			if (SnailIndex == 0)
				std::cout << "��";
			else
				std::cout << "��";

			SnailIndex++;
		}

		else
		{
			SnailIndex++;
		}
		
	}

	//������ �׸���.
	int FoodIndex = 0;
	while (true)
	{
		if (FoodArray[FoodIndex] == nullptr)
			break;

		if (FoodArray[FoodIndex]->x == -1 || FoodArray[FoodIndex]->y == -1)
		{
			FoodIndex++;
			continue;
		}

		SetCursorColor(Color::Yellow);
		SetCursorPosition(FoodArray[FoodIndex]->x * 2, FoodArray[FoodIndex]->y);
		std::cout << "��";
		FoodIndex++;
	}

	int DietFoodIndex = 0;
	while (true)
	{
		if (DieteFoodArray[DietFoodIndex] == nullptr)
			break;

		if (DieteFoodArray[DietFoodIndex]->x == -1 || DieteFoodArray[DietFoodIndex]->y == -1)
		{
			DietFoodIndex++;
			continue;
		}

		SetCursorColor(Color::SkyBlue);
		SetCursorPosition(DieteFoodArray[DietFoodIndex]->x * 2, DieteFoodArray[DietFoodIndex]->y);
		std::cout << "��";
		DietFoodIndex++;
	}

	//���� ǥ�� â�� �׸���.
	{
		/*SetCursorColor(Color::White);
		SetCursorPosition(MAP_WIDTH*2 + 1, MAP_HEIGHT + 2);
		std::cout << " ���� SCORE : " << Score;

		SetCursorPosition(MAP_WIDTH * 2 + 1, MAP_HEIGHT + 3);
		std::cout << " ������ ���� : " << SnailIndex;

		SetCursorPosition(MAP_WIDTH * 2 + 1, MAP_HEIGHT + 4);
		std::cout << " ���� ���� ���� :   [ " << FoodIndex << " / 100 ]";*/

		SetCursorColor(Color::White);
		SetCursorPosition(MAP_WIDTH * 2 + 1, 0);
		std::cout << "SCORE : " << Score;

		SetCursorPosition(MAP_WIDTH * 2 + 1, 1);
		std::cout << "Snail: Length " << SnailIndex;

		SetCursorPosition(MAP_WIDTH * 2 + 1, 2);
		std::cout << "Food Num :   [ " << FoodIndex << " / 100 ]";
	}


	SetCursorColor(Color::White);
}
