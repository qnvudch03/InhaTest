#include "Student.h"

void Student::Action()
{
	std::cout << "Action : Study" << std::endl;
}

void Student::PrintInfo()
{
	std::cout << "�̸� : " << GetName() << '\n';
	std::cout << "���� : " << GetAge() << '\n';
	std::cout << "�б� : " << this->_SchoolName << '\n';
}