#include <iostream>

int SelectMenu()
{
	int InputValue = 0;

	std::cout << "1. ���� ����\n"
		<< "2. ����\n"
		<< "3. ����\n";

	std::cin >> InputValue;

	return InputValue;
}

int main(void)
{
	std::cout << "�޴��� �����ϼ���.\n";

	int SelectIndex = SelectMenu();

	switch (SelectIndex)
	{
	case 1:
		std::cout << "���� ����\n";
		break;
	case 2:
		std::cout << "���� ����\n";
		break;
	case 3:
		std::cout << "���� ����\n";
		break;
	default:
		break;
	}

	return 0;
}
