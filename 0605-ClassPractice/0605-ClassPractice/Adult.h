#pragma once

#include "Person.h"

class Adult : public Person
{
public:
	Adult(std::string Name, int Age, std::string CompanyName) : Person(Name, Age), _CompanyName(CompanyName) {}

	virtual void Action() override;
	virtual void PrintInfo() override;

private:
	std::string _CompanyName = "";
};

