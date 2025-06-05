#include "Adult.h"

void Adult::Action()
{
	std::cout << "Action : Work\n";
}

void Adult::PrintInfo()
{
	std::cout << "이름 : " << GetName() << '\n';
	std::cout << "나이 : " << GetAge() << '\n';
	std::cout << "직장 : " << _CompanyName << '\n';
}
