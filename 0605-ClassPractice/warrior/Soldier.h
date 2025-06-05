#pragma once

#include "PlayerClass.h"

class Soldier : PlayerClass
{
public:

	Soldier(int HP, int Attack) : PlayerClass(HP, Attack) {}

	virtual void Attack() override;
};

