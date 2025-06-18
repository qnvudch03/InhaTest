#include "Shop.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <random>
#include "Helper.h"
#include "Item.h"

// C++ 20
#include <format>
#include <filesystem>
namespace fs = std::filesystem;

// Json
#include <fstream>
#include "Json/nlohmann/json.hpp" // nlohmann/json 헤더 파일
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
	}
}

void Shop::CreateRandomItem()
{
	//@TODO 내용 채우기
	int RandomItemNumCount = RandomRange(MIN_SHOP_ITEM_COUNT, MAX_SHOP_ITEM_COUNT);

	ItemKeyAvailable.clear();

	_TempData = _shopData;

	random_device rd;

	//직접 접근이 불가능 하다. iteraor로써 접근해야 한다
	for (int i = 0; i < RandomItemNumCount; i++)
	{
		auto iter = _TempData.begin();
		int randomIndex = (rd() % _TempData.size());

		for (int i = 0; i < randomIndex; i++)
			iter++;

		_SellData.insert(*iter);
		ItemKeyAvailable.insert(iter->first);

		_TempData.erase(iter);
	}
	_TempData.clear();
}

void Shop::CheckItemGrad(std::pair<const int, ItemData*> iter)
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

void Shop::PrintShop()
{
	SetCursorColor(Color::SkyBlue);

	for (int y = 0; y < MAX_SHOP_PAGE_Y; ++y)
	{
		SetCursorPosition(START_SHOP_PAGE_X * 2, y);

		for (int x = 0; x < MAX_SHOP_PAGE_X; ++x)
		{
			if (x == 0 || x == MAX_SHOP_PAGE_X - 1 || y == 0 || y == MAX_SHOP_PAGE_Y - 1)
				cout << "■";
			else
				cout << "  ";
		}

		cout << endl;
	}

	//@TODO 아이템 목록 출력
	int Linevertex = 1;
	int Grad = -1;
	for (auto iter : _SellData)
	{
		SetCursorPosition(2, Linevertex);

		//색 바꿔줌
		CheckItemGrad(iter);

		std::cout << "[ " << Linevertex << " ]" << iter.second->name;
		
		SetCursorPosition(MAX_SHOP_PAGE_X, Linevertex);

		if (ItemKeyAvailable.find(iter.first) != ItemKeyAvailable.end())
			std::cout << "1";
		else
			std::cout << "품절";


		SetCursorColor(Color::White);
		SetCursorPosition(MAX_SHOP_PAGE_X + 5, Linevertex);
		std::cout << iter.second->price << "(" << iter.second->minValue << " ~ " << iter.second->maxValue << ")";
		Linevertex++;
	}
	SetCursorColor(Color::White);
}
