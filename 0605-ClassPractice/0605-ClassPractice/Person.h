#pragma once

#include <iostream>

class Person
{
public:
	Person(std::string Name, int Age) : _Name(Name), _Age(Age) {}

	virtual void Action() = 0;
	virtual void PrintInfo() = 0;

	std::string GetName() { return _Name; }
	int GetAge() { return _Age; }

private:
	std::string _Name = "";
	int _Age = 0;
};

