#include <iostream>
#include <random>

#define ArrayNumber 7

int GameCount = 1;

int main(void)
{
	//�迭 ��ȸ�ϸ鼭 �� ����ϱ�
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

	//5*5 �κ��丮�� ������ ���� �� ���հ� �ִ밪 �ּ� �� ã��
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

	//		//�ڰ� ����
	//		if (randomNumber < 10)
	//			std::cout << ' ';

	//		std::cout << randomNumber << ' ';
	//		inventory[hang][yul] = randomNumber;
	//		Sum += randomNumber;
	//	}
	//	std::cout << '\n';
	//}

	//std::cout << "\n\n�� �� : " << Sum;
	//std::cout << "\n�ּҰ� : " << MinPrice << "  �ִ밪 : " << MaxPrice;



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


	//�¿� ���� ����
	/*for (int i = 0; i < 5; i++)
	{
		int Tempindex = 0;
		for (int a = 4; a >= 0; a--)
		{
			std::swap(TempInventory[i][Tempindex], inventory[i][a]);
			Tempindex++;
		}
	}*/


	//���� ���� ����
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

	//�밢��

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
		std::cout << "[ " << GameCount << " ]" << "ȸ�� ����\n";
		std::cout << "\n�������� 0 �迭�� ���� : " << Result;
		return 0;
	}

	else
	{
		std::cout << "\n\n\n�������!!\n\n\n";
		GameCount++;
		main();
	}

}
