#include "Adult.h"

void Adult::Action()
{
	std::cout << "Action : Work\n";
}

void Adult::PrintInfo()
{
	std::cout << "�̸� : " << GetName() << '\n';
	std::cout << "���� : " << GetAge() << '\n';
	std::cout << "���� : " << _CompanyName << '\n';
}
