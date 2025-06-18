#pragma once

#include <string>
#include "Helper.h"

enum class ItemGrade
{
	None,
	Normal,	
	Rare,
	Legendary,
};

enum class ItemType
{
	None,
	Equipment,
	Grocery,
};

class ItemData
{
public:
	int id;
	std::string name;
	ItemGrade grade;
	ItemType type;
	int price;
	int minValue;
	int maxValue;

	Color GetColor() const;
};
