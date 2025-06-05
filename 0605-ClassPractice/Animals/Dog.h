#pragma once

#include "Animal.h"

class Dog : public Animal
{
public:
	Dog(std::string Name) : Animal(Name) {}
	virtual void Sound() override;
};

