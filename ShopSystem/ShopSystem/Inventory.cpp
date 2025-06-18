#include "Inventory.h"
#include <iostream>
#include <iomanip>
#include "Helper.h"
#include "MyHelper.h"

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
		SetCursorPosition((START_INVEN_PAGE_X * 2) + 4, InventoryIndex);
		ChangItemGradFromGrad(CurrentItem.second->ItemData);
		std::cout << "[ " << InventoryIndex << " ]" << CurrentItem.second->ItemData->name;

		SetCursorPosition((START_INVEN_PAGE_X * 2) + 30, InventoryIndex);
		std::cout<< CurrentItem.second->ItemCount;

		SetCursorColor(Color::White);
		SetCursorPosition((START_INVEN_PAGE_X * 2) + 40, InventoryIndex);

		std::cout << CurrentItem.second->ItemData->price << "(" << CurrentItem.second->ItemSpeck << ")";
		InventoryIndex++;

	}
}

void Inventory::BuyItem(ItemData* Item)
{

	//Myinvectory.push_back(new ItemData(*Item));

	//Key 값을 아이템 이름으로 받아서, 아이템 이름 기반 그로써리 카운트 늘리기
	//근데 동일 아이템 이 들어오면 어떻하지??
	//그럼 key 값이 ItemData이고, 매핑된 값이 카운트라면?

	if (Item->type == ItemType::Grocery)
	{
		//이미 존재하는 물품인지 확인
		if (MyInventory.find(Item->name) != MyInventory.end())
		{
			//있는거라면
			MyInventory.find(Item->name)->second->ItemCount += 1;
			_totalGold -= Item->price;
			return;
		}
	}
	//장비이거나, 새로운 그로써리 일 경우
	MyInventory.insert(make_pair(Item->name, new MyOwningItem(Item, RandomRange(Item->minValue, Item->maxValue))));

	_totalGold -= Item->price;
	
}

void Inventory::SellAllItem()
{
	for (auto& CurrentItem : MyInventory)
	{
		while (CurrentItem.second->ItemCount != 0)
		{
			_totalGold += CurrentItem.second->ItemData->price;
			CurrentItem.second->ItemCount -= 1;
		}

		//메몰;?
		//delete &CurrentItem;
		delete CurrentItem.second;
	}
	MyInventory.clear();
}

void Inventory::SellItem(int Index)
{

	if (Index > MyInventory.size())
		return;

	auto Iter = MyInventory.begin();

	for (int i = 1; i < Index; i++)
		Iter++;

	while (Iter->second->ItemCount != 0)
	{
		_totalGold += Iter->second->ItemData->price;
		Iter->second->ItemCount--;
	}

	delete Iter->second;
	MyInventory.erase(Iter);
}

void Inventory::SellItemByGrade(ItemGrade Type)
{
	auto Iter = MyInventory.begin();
	for (Iter; Iter != MyInventory.end();)
	{
		if (Iter->second->ItemData->grade != Type)
		{
			Iter++;
			continue;
		}

		while (Iter->second->ItemCount != 0)
		{
			_totalGold += Iter->second->ItemData->price;
			Iter->second->ItemCount -= 1;
		}

		delete Iter->second;
		Iter = MyInventory.erase(Iter);
	}
}
