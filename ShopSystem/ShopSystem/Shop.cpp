#include "Shop.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <random>
#include "Helper.h"
#include "Item.h"
#include "MyHelper.h"

// C++ 20
#include <format>
#include <filesystem>
namespace fs = std::filesystem;

// Json
#include <fstream>
#include "Json/nlohmann/json.hpp" // nlohmann/json ��� ����
using json = nlohmann::json;

// magic_enum
#include "magic_enum/magic_enum.hpp"

using namespace std;

void Shop::LoadShopItemData()
{

	std::filesystem::path executablePath = std::filesystem::current_path();
	fs::path path = executablePath / L"shopItemList.json";
	
	std::ifstream file(path.c_str());
	if (!file.is_open())
	{
		MessageBox(nullptr, L"Failed to open JSON file", L"Error", MB_OK);
		return;
	}

	json data = json::parse(file);

	for (json::iterator it = data.begin(); it != data.end(); ++it) 
	{
		auto key = it.key();	// 1000
		auto value = it.value(); // { }

		ItemData* shopData = new ItemData();
		shopData->id = std::stoi(it.key());
		shopData->name = Utf8ToAnsi(value["name"]);
		shopData->price = value["price"];
		if(value.contains("minValue"))
			shopData->minValue = value["minValue"];
		if (value.contains("maxValue"))
		shopData->maxValue = value["maxValue"];
		
		// magic_enum
		string grade_name = value["grade"];
		auto grade_enum = magic_enum::enum_cast<ItemGrade>(grade_name);
		if (grade_enum.has_value())
		{
			shopData->grade = grade_enum.value();
		}

		string type_name = value["type"];
		auto type_enum = magic_enum::enum_cast<ItemType>(type_name);
		if (type_enum.has_value())
		{
			shopData->type = type_enum.value();
		}
		
		_shopData.insert(make_pair(shopData->id, shopData));

		ItemIdVec.push_back(shopData->id);
	}
}

void Shop::CreateRandomItem()
{
	//@TODO ���� ä���
	random_device rd;

	int RandomCount = RandomRange(MIN_SHOP_ITEM_COUNT, MAX_SHOP_ITEM_COUNT);

	for (int i = 0; i < RandomCount; i++)
	{
		int RandomIndex = (rd() % ItemIdVec.size());
		int randomKeyvalue = ItemIdVec[RandomIndex];

		//SellingItem SellItem =  SellingItem(_shopData[randomKeyvalue]);
		//�޸� ����???
		SellingItem* SellItem = new SellingItem(_shopData[randomKeyvalue]);
		_SellingItemData.push_back(SellItem);

		ItemIdVec.erase(ItemIdVec.begin() + RandomIndex);
	}

}


void Shop::PrintShop()
{
	SetCursorColor(Color::SkyBlue);

	for (int y = 0; y < MAX_SHOP_PAGE_Y; ++y)
	{
		SetCursorPosition(START_SHOP_PAGE_X * 2, y);

		for (int x = 0; x < MAX_SHOP_PAGE_X; ++x)
		{
			if (x == 0 || x == MAX_SHOP_PAGE_X - 1 || y == 0 || y == MAX_SHOP_PAGE_Y - 1)
				cout << "��";
			else
				cout << "  ";
		}

		cout << endl;
	}

	//@TODO ������ ��� ���
	int Linevertex = 1;
	int Grad = -1;
	for (auto iter : _SellingItemData)
	{
		SetCursorPosition(2, Linevertex);

		//�� �ٲ���
		ChangItemGradFromGrad(iter->ItemData);
		_SellingItemData;

		std::cout << "[ " << Linevertex << " ]" << iter->ItemData->name;

		SetCursorPosition(MAX_SHOP_PAGE_X + 2, Linevertex);

		if (iter->ItemCount != 0)
			std::cout << iter->ItemCount;
		else
			std::cout << "ǰ��";


		SetCursorColor(Color::White);
		SetCursorPosition(MAX_SHOP_PAGE_X + 7, Linevertex);
		std::cout << iter->ItemData->price << "(" << iter->ItemData->minValue << " ~ " << iter->ItemData->maxValue << ")";
		Linevertex++;
	}
	SetCursorColor(Color::White);
}

void Shop::RefreshAllItem()
{
	ItemIdVec.clear();

	for (auto DeletedDat : _SellingItemData)
	{
		//delete DeletedDat->ItemData;
		//DeletedDat->ItemData = nullptr;
	}

	_SellingItemData.clear();

	//���̵� ���� �� �Ҵ�
	for (auto& CurrentItemData : _shopData)
	{
		ItemIdVec.push_back(CurrentItemData.second->id);
	}

	CreateRandomItem();
}

void Shop::RefreshItem()
{
	//���� ������ ����Ʈ �� �ƹ��ų� �ϳ� ��� �־�����
	random_device rd;
	int indexCount = 0;

	//if (ItemIdVec.size() == 0)
	//{
	//	return;
	//}


	for (auto& SelledItem : _SellingItemData)
	{
		if (SelledItem->ItemCount != 0) {}

		else
		{
			if (ItemIdVec.size() == 0)
				break;

			int RandomIndex = (rd() % ItemIdVec.size());
			ItemData* NewRandomItem = _shopData.find(ItemIdVec[RandomIndex])->second;

			SelledItem = new SellingItem(NewRandomItem);

			//�����ε�, key ���� ���ؼ� ���� �����ؾ� �Ѵ�.
			for (int i = 0; i < ItemIdVec.size(); i++)
			{
				if (ItemIdVec[i] != SelledItem->ItemData->id)
					continue;

				ItemIdVec.erase(ItemIdVec.begin() + i);
				break;
			}
		}

		indexCount++;
		
	}
}
