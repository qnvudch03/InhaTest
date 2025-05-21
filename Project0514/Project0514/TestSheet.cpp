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
	unsigned char Property = 0; //1바이트

	unsigned char bIsSell = 0;

	unsigned char bIsDroped = 0;

	unsigned char bIsUpgrade = 1;

	//std::cin >> bIsSell >> bIsDroped >> bIsUpgrade;

	int Result = 0;

	/*Property = bIsSell << 2 | bIsDroped << 1 | bIsUpgrade;

	if ((Property & 0b00000100) >= 0b00000100)
		std::cout << "판매 가능한 상품\n";
	else
		std::cout << "판매 불가 상품\n";

	if ((Property & 0b00000010) >= 0b00000010)
		std::cout << "드랍 가능한 상품\n";
	else
		std::cout << "드랍 불가 상품\n";

	if ((Property & 0b00000001) >= 0b00000001)
		std::cout << "강화 가능한 상품\n";
	else
		std::cout << "강화 불가 상품\n";*/


	Result = bIsSell << 16 | bIsDroped << 8 | bIsUpgrade;

	////0b00000000000000010000000100000001
	//if ( (Result & 0b00000000000000010000000000000000) >= 0b00000000000000010000000000000000)
	//	std::cout << "판매 가능한 상품\n";
	//else
	//	std::cout << "판매 불가 상품\n";

	//if ((Result & 0b00000000000000000000000100000001) >= 0b00000000000000000000000100000001)
	//	std::cout << "드랍 가능한 상품\n";
	//else
	//	std::cout << "드랍 불가 상품\n";

	//if ((Result & 0b00000000000000000000000000000001) >= 0b00000000000000000000000000000001)
	//	std::cout << "강화 가능한 상품\n";
	//else
	//	std::cout << "강화 불가 상품\n";


	if ((Result & ItemOption::Sell))
		std::cout << "판매 가능한 상품\n";
	else
		std::cout << "판매 불가 상품\n";

	if ((Result & 256))
		std::cout << "드랍 가능한 상품\n";
	else
		std::cout << "드랍 불가 상품\n";

	if ((Result & 1))
		std::cout << "강화 가능한 상품\n";
	else
		std::cout << "강화 불가 상품\n";


	return 0;
}