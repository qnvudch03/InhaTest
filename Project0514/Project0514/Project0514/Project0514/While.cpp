#include <iostream>

int main(void)
{
	while (true)
	{
		int TargetNumber = 0;
		std::cout << "-----구구단을 외자-----\n";
		std::cout << "단수 입력 : ";
		std::cin >> TargetNumber;

		if (TargetNumber == 0) { break; }

		for (int i = 1; i <= 9; i++)
		{
			std::cout << TargetNumber << " * " << i << " = " << TargetNumber * i << '\n';
		}

		std::cout << "\n\n";
	}

	std::cout << "\n프로그램 종료, 아무키나 누르세요.\n";
	system("pause");
}