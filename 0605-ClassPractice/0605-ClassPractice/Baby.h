#pragma once

#include "Person.h"

class Baby : public Person
{
public:
	Baby(std::string Name, int Age) : Person(Name, Age) {}

	virtual void Action() override;
	virtual void PrintInfo() override;
};

