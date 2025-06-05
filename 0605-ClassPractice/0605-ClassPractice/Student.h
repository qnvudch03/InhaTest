#pragma once

#include "Person.h"

class Student : public Person
{
public:

	Student(std::string Name, int Age, std::string SchoolName) : Person(Name, Age), _SchoolName(SchoolName) {}

	virtual void Action() override;
	virtual void PrintInfo() override;

private:
	std::string _SchoolName = "";
};

