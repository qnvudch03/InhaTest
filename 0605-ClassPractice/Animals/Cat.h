#pragma once

#include "Animal.h"

class Cat : public Animal
{
public:
	Cat(std::string Name) : Animal(Name) {}
	virtual void Sound() override;
};

