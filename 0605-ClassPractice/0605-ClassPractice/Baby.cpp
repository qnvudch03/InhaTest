#include "Baby.h"

void Baby::Action()
{
	std::cout << "Action : Cry" << std::endl;
}

void Baby::PrintInfo()
{
	std::cout << "�̸� : " << GetName() << '\n';
	std::cout << "���� : " << GetAge() << '\n';
}
