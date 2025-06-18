#pragma once
#include <vector>
#include <map>
#include <set>
#include <string>

constexpr int START_SHOP_PAGE_X = 0;
constexpr int MAX_SHOP_PAGE_X = 24;
constexpr int MAX_SHOP_PAGE_Y = 20;

constexpr int MIN_SHOP_ITEM_COUNT = 14;
constexpr int MAX_SHOP_ITEM_COUNT = 17;

class ShopItem;
class ItemData;
class SellingItem;

class Shop
{
public:
	void LoadShopItemData();
	void CreateRandomItem();

	void PrintShop();

	void RefreshAllItem();

	void RefreshItem();

	std::vector<SellingItem*> GetSellingItemData() { return _SellingItemData; }

private:
	std::map<int, ItemData*>	_shopData;	// json 에서 읽어온 원본 Item Data

	std::vector<int> ItemIdVec;
	std::vector<SellingItem*> _SellingItemData;
};

