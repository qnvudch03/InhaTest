#include <iostream>
#include <random>

#define ArrayNumber 7

int GameCount = 1;

int main(void)
{
	//배열 순회하면서 값 출력하기
	/*int array[3][3] =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	};

	for(int hang = 0; hang < 3; hang++)
	{
		for (int yul = 0; yul < 3; yul++)
		{
			std::cout << array[hang][yul]<<' ';
		}
		std::cout << '\n';
	}*/

	//5*5 인벤토리에 랜덤값 대입 후 총합과 최대값 최소 값 찾기
	//int inventory[5][5] = {};
	//int Sum = 0;
	//int MaxPrice = 0;
	//int MinPrice = INT32_MAX;
	//std::random_device rd;

	//for (int hang = 0; hang < 5; hang++)
	//{
	//	for (int yul = 0; yul < 5; yul++)
	//	{
	//		int randomNumber = (rd() % 99) + 1;

	//		if (randomNumber > MaxPrice)
	//			MaxPrice = randomNumber;

	//		if (randomNumber < MinPrice)
	//			MinPrice = randomNumber;

	//		//자간 보정
	//		if (randomNumber < 10)
	//			std::cout << ' ';

	//		std::cout << randomNumber << ' ';
	//		inventory[hang][yul] = randomNumber;
	//		Sum += randomNumber;
	//	}
	//	std::cout << '\n';
	//}

	//std::cout << "\n\n총 합 : " << Sum;
	//std::cout << "\n최소값 : " << MinPrice << "  최대값 : " << MaxPrice;



	/*int inventory[5][5] = {};
	int Number = 1;
	std::random_device rd;

	for (int hang = 0; hang < 5; hang++)
	{
		for (int yul = 0; yul < 5; yul++)
		{
			inventory[hang][yul] = Number;
			Number++;
		}
	}
	int TempInventory[5][5] = {};*/


	//좌우 반전 스왑
	/*for (int i = 0; i < 5; i++)
	{
		int Tempindex = 0;
		for (int a = 4; a >= 0; a--)
		{
			std::swap(TempInventory[i][Tempindex], inventory[i][a]);
			Tempindex++;
		}
	}*/


	//상하 반전 스왑
	/*for (int i = 0; i < 5; i++)
	{
		int Tempindex = 0;
		for (int a = 4; a >= 0; a--)
		{
			std::swap(TempInventory[Tempindex][i], inventory[a][i]);
			Tempindex++;
		}
	}*/


	//o x

	unsigned char OXArray[ArrayNumber][ArrayNumber] = {};

	std::random_device rd;

	for (int hang = 0; hang < ArrayNumber; hang++)
	{
		for (int yul = 0; yul < ArrayNumber; yul++)
		{
			OXArray[hang][yul] = (rd() & 1) ? 'X' : 'O';
			std::cout << OXArray[hang][yul] << ' ';
		}
		std::cout << '\n';
	}

	int ResultBingo = 0;

	for (int i = 0; i < ArrayNumber; i++)
	{
		int Rowcount = 0;
		int Columcount = 0;
		for (int hang = 0; hang < ArrayNumber; hang++)
		{
			char what = OXArray[hang][i];
			if (OXArray[hang][i] == 'O')
				Rowcount++;

			if (OXArray[i][hang] == 'O')
				Columcount++;
		}

		if (Rowcount == ArrayNumber)
			ResultBingo++;

		if (Columcount == ArrayNumber)
			ResultBingo++;

	}

	//for (int i = 0; i < ArrayNumber; i++)
	//{
	//	int count = 0;
	//	for (int yul = 0; yul < ArrayNumber; yul++)
	//	{

	//		if (OXArray[i][yul] == 'O')
	//			count++;
	//	}
	//	if (count == ArrayNumber)
	//		ResultBingo++;
	//}

	//대각선

	int leftBingoOffset = 0;
	int count = 0;
	for (int leftvertex = 0; leftvertex < ArrayNumber; leftvertex++)
	{
		if (OXArray[leftvertex][leftvertex] == 'O')
			count++;

		if (count == ArrayNumber)
			leftBingoOffset++;
	}

	int RightBingoOffset = 0;
	count = 0;
	for (int Rightvertex = 0; Rightvertex < ArrayNumber; Rightvertex++)
	{
		if (OXArray[Rightvertex][(ArrayNumber - 1) - Rightvertex] == 'O')
			count++;

		if (count == ArrayNumber)
			RightBingoOffset++;
	}

	int Result = ResultBingo + leftBingoOffset + RightBingoOffset;

	if (Result > 1)
	{
		std::cout << "[ " << GameCount << " ]" << "회차 게임\n";
		std::cout << "\n연속적인 0 배열의 개수 : " << Result;
		return 0;
	}

	else
	{
		std::cout << "\n\n\n빙고실패!!\n\n\n";
		GameCount++;
		main();
	}

}
