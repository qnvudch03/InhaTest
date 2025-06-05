#pragma once

#include <iostream>

class PlayerClass
{
public:
	PlayerClass(int HP, int Attack) : _HP(HP), _Attack(Attack) {}

	virtual void Attack() {}

private:
	int _HP = 0;
	int _Attack = 0;
};

