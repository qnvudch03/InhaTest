#include <iostream>

int main(void)
{
	while (true)
	{
		int TargetNumber = 0;
		std::cout << "-----�������� ����-----\n";
		std::cout << "�ܼ� �Է� : ";
		std::cin >> TargetNumber;

		if (TargetNumber == 0) { break; }

		for (int i = 1; i <= 9; i++)
		{
			std::cout << TargetNumber << " * " << i << " = " << TargetNumber * i << '\n';
		}

		std::cout << "\n\n";
	}

	std::cout << "\n���α׷� ����, �ƹ�Ű�� ��������.\n";
	system("pause");
}