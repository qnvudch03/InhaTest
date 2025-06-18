#pragma once
#include <string>

enum MENU_MODE_2
{
	SHOP2,	// 0
	INVEN2  // 1
};


enum class MENU_MODE
{
	SHOP,
	INVEN,
};

enum class MENU_SHOP
{
	BuyItem = 1,
	NewItem,
	RefreshItem,
	Exit,
};

enum class MENU_INVEN
{
	SellItem = 1,
	AllSellItem,
	SellItemByGrade,
	Exit,
};

class Inventory;
class Shop;

class Menu
{
public:
	Menu();
	~Menu();

	void Init();
	void UpdateMenu();

private:
	void printShopMode();
	void printInvenMode();
	
	void handleError(const std::string& msg);
	void handleShopMode(int input);
	void handleInvenMode(int input);

private:
	MENU_MODE _mode = MENU_MODE::SHOP;

	Inventory*	_inventory = nullptr;
	Shop*		_shop = nullptr;
};

