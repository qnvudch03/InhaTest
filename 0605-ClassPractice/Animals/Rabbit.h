#pragma once

#include "Animal.h"

class Rabbit : public Animal
{
public:
	Rabbit(std::string Name) : Animal(Name) {}
	virtual void Sound() override;
};

