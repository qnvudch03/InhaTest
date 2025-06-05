#include "Student.h"

void Student::Action()
{
	std::cout << "Action : Study" << std::endl;
}

void Student::PrintInfo()
{
	std::cout << "이름 : " << GetName() << '\n';
	std::cout << "나이 : " << GetAge() << '\n';
	std::cout << "학교 : " << this->_SchoolName << '\n';
}