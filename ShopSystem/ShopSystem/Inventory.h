#pragma once

#include <vector>
#include <map>
#include "Item.h"

constexpr int START_INVEN_PAGE_X = 26;
constexpr int MAX_INVEN_PAGE_X = 26;
constexpr int MAX_INVEN_PAGE_Y = 20;

class NumCountItemData
{
public:

	NumCountItemData(ItemData* InItem) : Item(InItem), NumItem(1) {}
	ItemData* Item = nullptr;
	int NumItem = 0;
};

class Inventory
{
public:
	void PrintInventory();
	int GetTotalGold() const { return _totalGold; }

	void BuyItem(ItemData* Item);
	void SellItem(ItemData* Item);

	void CheckItemGrad2(std::pair<const int, ItemData*> iter);

	//std::map<int, ItemData*> MyInventory;
	std::vector<NumCountItemData> MyInventory;

private:

	
	int _totalGold = 2000;
};



