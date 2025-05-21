#include <iostream>
#include <bitset>
#include <Windows.h>

enum ItemOption
{
	Sell = 1<<16,
	Drop = 1 <<8, 
	Upgrade = 1
};

int main(void)
{
	unsigned char Property = 0; //1����Ʈ

	unsigned char bIsSell = 0;

	unsigned char bIsDroped = 0;

	unsigned char bIsUpgrade = 1;

	//std::cin >> bIsSell >> bIsDroped >> bIsUpgrade;

	int Result = 0;

	/*Property = bIsSell << 2 | bIsDroped << 1 | bIsUpgrade;

	if ((Property & 0b00000100) >= 0b00000100)
		std::cout << "�Ǹ� ������ ��ǰ\n";
	else
		std::cout << "�Ǹ� �Ұ� ��ǰ\n";

	if ((Property & 0b00000010) >= 0b00000010)
		std::cout << "��� ������ ��ǰ\n";
	else
		std::cout << "��� �Ұ� ��ǰ\n";

	if ((Property & 0b00000001) >= 0b00000001)
		std::cout << "��ȭ ������ ��ǰ\n";
	else
		std::cout << "��ȭ �Ұ� ��ǰ\n";*/


	Result = bIsSell << 16 | bIsDroped << 8 | bIsUpgrade;

	////0b00000000000000010000000100000001
	//if ( (Result & 0b00000000000000010000000000000000) >= 0b00000000000000010000000000000000)
	//	std::cout << "�Ǹ� ������ ��ǰ\n";
	//else
	//	std::cout << "�Ǹ� �Ұ� ��ǰ\n";

	//if ((Result & 0b00000000000000000000000100000001) >= 0b00000000000000000000000100000001)
	//	std::cout << "��� ������ ��ǰ\n";
	//else
	//	std::cout << "��� �Ұ� ��ǰ\n";

	//if ((Result & 0b00000000000000000000000000000001) >= 0b00000000000000000000000000000001)
	//	std::cout << "��ȭ ������ ��ǰ\n";
	//else
	//	std::cout << "��ȭ �Ұ� ��ǰ\n";


	if ((Result & ItemOption::Sell))
		std::cout << "�Ǹ� ������ ��ǰ\n";
	else
		std::cout << "�Ǹ� �Ұ� ��ǰ\n";

	if ((Result & 256))
		std::cout << "��� ������ ��ǰ\n";
	else
		std::cout << "��� �Ұ� ��ǰ\n";

	if ((Result & 1))
		std::cout << "��ȭ ������ ��ǰ\n";
	else
		std::cout << "��ȭ �Ұ� ��ǰ\n";


	return 0;
}