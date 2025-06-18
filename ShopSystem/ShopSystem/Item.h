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

class SellingItem
{
public:

	SellingItem(ItemData* InItemData) : ItemData(InItemData), ItemCount(1) {}

	ItemData* ItemData;
	int ItemCount;
};

class MyOwningItem
{
public:
	MyOwningItem(ItemData* InItemData, int Speck) : ItemData(InItemData), ItemCount(1), ItemSpeck(Speck){}

	ItemData* ItemData;
	int ItemCount;
	int ItemSpeck;
};
