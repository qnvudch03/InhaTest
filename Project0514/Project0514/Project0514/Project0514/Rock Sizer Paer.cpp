#include <iostream>

int main(void)
{
	//��� ���� �Ǻ��ϱ�
	/*int InputValue = 0;
	std::cout << "���ڸ� �Է� �� �ּ���. : " << '\n';
	std::cin >> InputValue;

	std::cout << '\n';

	if (InputValue > 0)
	{
		std::cout << "�Է��� ���� ��� �Դϴ�. \n";
	}

	else
	{
		std::cout << "�Է��� ���� ���� �Դϴ�. \n";
	}*/


	//¦�� Ȧ�� �Ǻ�
	/*int InputValue = 0;
	std::cout << "���ڸ� �Է� �� �ּ���. : " << '\n';
	std::cin >> InputValue;

	std::cout << '\n';

	if (InputValue %2  == 0)
	{
		std::cout << "�Է��� ���� ¦�� �Դϴ�. \n";
	}

	else
	{
		std::cout << "�Է��� ���� Ȧ�� �Դϴ�. \n";
	}
	return 0;*/

	//���� ���� ���
	/*int InputValue = 0;
	std::cout << "������ �Է� �� �ּ���. : " << '\n';
	std::cin >> InputValue;

	std::cout << '\n';

	std::cout << "���� : ";
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
	std::cout << "-----�ٰ��� ���� �� ���ӡ�-----\n\n";

	while (true)
	{
		std::cout << "1. ����\n2. ����\n3. ��\n\n�����Է� : ";
		std::cin >> MySelect;

		if (MySelect != 1 && MySelect != 2 && MySelect != 3)
			break;


		srand(time(0));
		int ComputerSelect = (rand() % 3) + 1;
		int GameResult = -1;

		switch (ComputerSelect)
		{
		case 1:
			std::cout << "��ǻ���� ���� : ����\n";

			if (MySelect == 1)
				GameResult = 0;

			else if (MySelect == 2)
				GameResult = -1;

			else if (MySelect == 3)
				GameResult = 1;

			break;

		case 2:
			std::cout << "��ǻ���� ���� :����\n";

			if (MySelect == 2)
				GameResult = 0;

			else if (MySelect == 3)
				GameResult = -1;

			else if (MySelect == 1)
				GameResult = 1;

			break;

		case 3:
			std::cout << "��ǻ���� ���� :��\n";

			if (MySelect == 3)
				GameResult = 0;

			else if (MySelect == 1)
				GameResult = -1;

			else if (MySelect == 2)
				GameResult = 1;

			break;

		default:
			std::cout << "����!!";
			break;
		}

		std::cout << "\n���Ӱ�� : ";

		switch (GameResult)
		{
		case 1:
			std::cout << "�¸�!!\n\n";
			break;

		case -1:
			std::cout << "�й�\n\n";
			break;

		case 0:
			std::cout << "���º�\n\n";
			break;
		default:
			break;
		}

	}

	std::cout << "\n\n��������";

}