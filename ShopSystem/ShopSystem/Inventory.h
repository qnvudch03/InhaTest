#pragma once

#include <vector>
#include <set>
#include <map>
#include "Item.h"

constexpr int START_INVEN_PAGE_X = 26;
constexpr int MAX_INVEN_PAGE_X = 26;
constexpr int MAX_INVEN_PAGE_Y = 20;

class Inventory
{
public:
	void PrintInventory();
	int GetTotalGold() const { return _totalGold; }
	void BuyItem(ItemData* Item);

	void SellAllItem();
	void SellItem(int Index);
	void SellItemByGrade(ItemGrade Type);
	
private:

	//std::set<SellingItem> Myinvectory;
	std::multimap<std::string, MyOwningItem*> MyInventory;
	int _totalGold = 2000;
};

