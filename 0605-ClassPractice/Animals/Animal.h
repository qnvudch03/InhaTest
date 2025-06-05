#pragma once

#include <iostream>

class Animal
{
public:
	Animal(std::string Name) : _Name(Name) {}
	virtual void Sound() = 0;

	std::string GetName() { return _Name; }

public:
	std::string _Name = "";
};

