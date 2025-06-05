#include "Baby.h"

void Baby::Action()
{
	std::cout << "Action : Cry" << std::endl;
}

void Baby::PrintInfo()
{
	std::cout << "이름 : " << GetName() << '\n';
	std::cout << "나이 : " << GetAge() << '\n';
}
