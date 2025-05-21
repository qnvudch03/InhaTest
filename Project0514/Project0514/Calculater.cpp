#include <iostream>

int main(void)
{
	double FirstNumber = 0;
	double SecondeNumber = 0;
	char Operator = 0;

	std::cout << "----계산기 프로그램----\n\n";

	std::cout << "첫번쨰 숫자를 입력하세요 : ";
	std::cin >> FirstNumber;

	std::cout << "두번쨰 숫자를 입력하세요 : ";
	std::cin >> SecondeNumber;

	std::cout << "적용할 연산을 입력하세요 : ";
	std::cin >> Operator;

	std::cout << "\n\n";

	switch (Operator)
	{
	case '+':
		std::cout << "연살 결과 : "<< FirstNumber + SecondeNumber << '\n';
		break;

	case '-':
		std::cout << "연살 결과 : " << FirstNumber - SecondeNumber << '\n';
		break;

	case '/':
		if (SecondeNumber == 0)
		{
			std::cout << "Numberick Error!!\n";
			break;
		}

		std::cout << "연살 결과 : " << FirstNumber / SecondeNumber << '\n';
		break;

	case '*':
		std::cout << "연살 결과 : " << FirstNumber * SecondeNumber << '\n';
		break;

	default:
		std::cout << "Wrong Operator Inputted !! \n";
		break;
	}
	
	int TempInputAction = 0;
	std::cin >> TempInputAction;
	return 0;
}