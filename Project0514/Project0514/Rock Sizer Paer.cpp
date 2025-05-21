#include <iostream>

int main(void)
{
	//양수 음수 판별하기
	/*int InputValue = 0;
	std::cout << "숫자를 입력 해 주세요. : " << '\n';
	std::cin >> InputValue;

	std::cout << '\n';

	if (InputValue > 0)
	{
		std::cout << "입력한 수는 양수 입니다. \n";
	}

	else
	{
		std::cout << "입력한 수는 음수 입니다. \n";
	}*/


	//짝수 홀수 판별
	/*int InputValue = 0;
	std::cout << "숫자를 입력 해 주세요. : " << '\n';
	std::cin >> InputValue;

	std::cout << '\n';

	if (InputValue %2  == 0)
	{
		std::cout << "입력한 수는 짝수 입니다. \n";
	}

	else
	{
		std::cout << "입력한 수는 홀수 입니다. \n";
	}
	return 0;*/

	//시험 점수 등급
	/*int InputValue = 0;
	std::cout << "점수를 입력 해 주세요. : " << '\n';
	std::cin >> InputValue;

	std::cout << '\n';

	std::cout << "학점 : ";
	if (InputValue > 90)
	{
		std::cout << "A\n";
	}

	else if (InputValue > 80)
	{
		std::cout << "B\n";
	}

	else if (InputValue > 70)
	{
		std::cout << "C\n";
	}

	else if (InputValue > 60)
	{
		std::cout << "D\n";
	}

	else
	{
		std::cout << "F\n";
	}

	return 0;*/


	int MySelect = -1;
	std::cout << "-----☆가위 바위 보 게임☆-----\n\n";

	while (true)
	{
		std::cout << "1. 바위\n2. 가위\n3. 보\n\n선택입력 : ";
		std::cin >> MySelect;

		if (MySelect != 1 && MySelect != 2 && MySelect != 3)
			break;


		srand(time(0));
		int ComputerSelect = (rand() % 3) + 1;
		int GameResult = -1;

		switch (ComputerSelect)
		{
		case 1:
			std::cout << "컴퓨터의 선택 : 바위\n";

			if (MySelect == 1)
				GameResult = 0;

			else if (MySelect == 2)
				GameResult = -1;

			else if (MySelect == 3)
				GameResult = 1;

			break;

		case 2:
			std::cout << "컴퓨터의 선택 :가위\n";

			if (MySelect == 2)
				GameResult = 0;

			else if (MySelect == 3)
				GameResult = -1;

			else if (MySelect == 1)
				GameResult = 1;

			break;

		case 3:
			std::cout << "컴퓨터의 선택 :보\n";

			if (MySelect == 3)
				GameResult = 0;

			else if (MySelect == 1)
				GameResult = -1;

			else if (MySelect == 2)
				GameResult = 1;

			break;

		default:
			std::cout << "에러!!";
			break;
		}

		std::cout << "\n게임결과 : ";

		switch (GameResult)
		{
		case 1:
			std::cout << "승리!!\n\n";
			break;

		case -1:
			std::cout << "패배\n\n";
			break;

		case 0:
			std::cout << "무승부\n\n";
			break;
		default:
			break;
		}

	}

	std::cout << "\n\n게임종료";

}