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
		std::cout << "�Ǹ� ���� ��ǰ";
	else
		std::cout << "�Ǹ� �Ұ� ��ǰ";

	std::cout << " , ";

	if (ItemOption & ItemOption::CanInchant)
		std::cout << "��ȭ ���� ��ǰ";
	else
		std::cout << "��ȭ �Ұ� ��ǰ";

	std::cout << " , ";

	if (ItemOption & ItemOption::CanTrade)
		std::cout << "��ȯ ���� ��ǰ";
	else
		std::cout << "��ȯ �Ұ� ��ǰ";

	std::cout << " , ";

	if (ItemOption & ItemOption::CanDrop)
		std::cout << "��� ���� ��ǰ";
	else
		std::cout << "��� �Ұ� ��ǰ";

	std::cout << " ]\n";

}
