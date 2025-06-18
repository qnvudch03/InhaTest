#include "Inventory.h"
#include <iostream>
#include <iomanip>
#include "Helper.h"

using namespace std;

void Inventory::PrintInventory()
{
	SetCursorColor(Color::RightGreen);
	for (int y = 0; y < MAX_INVEN_PAGE_Y; ++y)
	{
		SetCursorPosition(START_INVEN_PAGE_X * 2, y);

		for (int x = 0; x < MAX_INVEN_PAGE_X; ++x)
		{
			if (x == 0 || x == MAX_INVEN_PAGE_X - 1 || y == 0 || y == MAX_INVEN_PAGE_Y - 1)
				cout << "■";
			else
				cout << "  ";
		}

		cout << endl;
	}

	//@TODO 아이템 목록 출력
	int InventoryIndex = 1;
	for (auto& CurrentItem : MyInventory)
	{
		SetCursorPosition((START_INVEN_PAGE_X * 2)+4, InventoryIndex);
		//CheckItemGrad2(CurrentItem);
		std::cout << "[ " << InventoryIndex << " ]" << CurrentItem.Item->name;
		InventoryIndex++;
	}
}

void Inventory::BuyItem(ItemData* Item)
{
	MyInventory.push_back(Item);
	_totalGold -= Item->price;
}

void Inventory::SellItem(ItemData* Item)
{
}

void Inventory::CheckItemGrad2(std::pair<const int, ItemData*> iter)
{
	if (iter.second->grade == ItemGrade::Normal)
	{
		SetCursorColor(Color::White);
	}

	else if (iter.second->grade == ItemGrade::Rare)
	{
		SetCursorColor(Color::SkyBlue);
	}

	else if (iter.second->grade == ItemGrade::Legendary)
	{
		SetCursorColor(Color::Red);
	}
}
