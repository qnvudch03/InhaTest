#include <iostream>

int main(void)
{
	double FirstNumber = 0;
	double SecondeNumber = 0;
	char Operator = 0;

	std::cout << "----���� ���α׷�----\n\n";

	std::cout << "ù���� ���ڸ� �Է��ϼ��� : ";
	std::cin >> FirstNumber;

	std::cout << "�ι��� ���ڸ� �Է��ϼ��� : ";
	std::cin >> SecondeNumber;

	std::cout << "������ ������ �Է��ϼ��� : ";
	std::cin >> Operator;

	std::cout << "\n\n";

	switch (Operator)
	{
	case '+':
		std::cout << "���� ��� : "<< FirstNumber + SecondeNumber << '\n';
		break;

	case '-':
		std::cout << "���� ��� : " << FirstNumber - SecondeNumber << '\n';
		break;

	case '/':
		if (SecondeNumber == 0)
		{
			std::cout << "Numberick Error!!\n";
			break;
		}

		std::cout << "���� ��� : " << FirstNumber / SecondeNumber << '\n';
		break;

	case '*':
		std::cout << "���� ��� : " << FirstNumber * SecondeNumber << '\n';
		break;

	default:
		std::cout << "Wrong Operator Inputted !! \n";
		break;
	}
	
	int TempInputAction = 0;
	std::cin >> TempInputAction;
	return 0;
}