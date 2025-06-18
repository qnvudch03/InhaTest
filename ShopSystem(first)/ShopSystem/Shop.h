#pragma once
#include <vector>
#include <map>
#include <string>
#include <set>

class ShopItem;
class ItemData;

constexpr int START_SHOP_PAGE_X = 0;
constexpr int MAX_SHOP_PAGE_X = 24;
constexpr int MAX_SHOP_PAGE_Y = 20; //아이템 종류 개수

constexpr int MIN_SHOP_ITEM_COUNT = 14;
constexpr int MAX_SHOP_ITEM_COUNT = 17;

class Shop
{
public:
	void LoadShopItemData();
	void CreateRandomItem();

	void CheckItemGrad(std::pair<const int, ItemData*> iter);

	void PrintShop();

	std::map<int, ItemData*>& GetSellData() { return _SellData; }
	//std::set<int>& GetAvaliableKeyData() { return ItemKeyAvailable; }

	std::set<int> ItemKeyAvailable;

private:
	std::map<int, ItemData*>	_shopData;	// json 에서 읽어온 원본 Item Data
	std::map<int, ItemData*>	_TempData;
	std::map<int, ItemData*>	_SellData;
};

