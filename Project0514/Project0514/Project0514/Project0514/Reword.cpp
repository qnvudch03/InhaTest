#include "Reword.h"
#include <random>
#include <iostream>

enum ItemOption
{
	CanSell = 1 << 0,
	CanInchant = 1 << 1,
	CanTrade = 1 << 2,
	CanDrop = 1 << 3,
	ItemEraseBit = 15
};

int GetHuntReword()
{
	std::random_device rd;
	unsigned int randomNum = rd() & ItemOption::ItemEraseBit;

	return randomNum;
}

void PrintItemOption(int ItemOption)
{
	std::cout << "[ ";

	if (ItemOption & ItemOption::CanSell)
		std::cout << "판매 가능 상품";
	else
		std::cout << "판매 불가 상품";

	std::cout << " , ";

	if (ItemOption & ItemOption::CanInchant)
		std::cout << "강화 가능 상품";
	else
		std::cout << "강화 불가 상품";

	std::cout << " , ";

	if (ItemOption & ItemOption::CanTrade)
		std::cout << "교환 가능 상품";
	else
		std::cout << "교환 불가 상품";

	std::cout << " , ";

	if (ItemOption & ItemOption::CanDrop)
		std::cout << "폐기 가능 상품";
	else
		std::cout << "폐기 불가 상품";

	std::cout << " ]\n";

}
