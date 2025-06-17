#include "Menu.h"
#include <iostream>
#include <conio.h>
#include "Helper.h"
#include "Shop.h"
#include "Inventory.h"

using namespace std;

Menu::Menu()
{
	_shop = new Shop();
	_inventory = new Inventory();
}

Menu::~Menu()
{
	if (_shop) delete _shop;
	if (_inventory) delete _inventory;
}

void Menu::Init()
{
	if (_shop)
	{
		_shop->LoadShopItemData();
		_shop->CreateRandomItem();
	}
}

void Menu::UpdateMenu()
{
	if (_shop == nullptr || _inventory == nullptr)
		return;

	_shop->PrintShop();
	_inventory->PrintInventory();

	SetCursorColor(Color::Yellow);
	ClearAfterCursorPosition(0, MAX_SHOP_PAGE_Y);
	cout << "  + 소지금 : " << _inventory->GetTotalGold() << endl;

	SetCursorColor(Color::White);
	cout << "  일반 : 1, ";
	SetCursorColor(Color::RightBlue);
	cout << "희귀 : 2, ";
	SetCursorColor(Color::RightRed);
	cout << "전설 : 3" << endl << endl;

	switch (_mode)
	{
	case MENU_MODE::SHOP:
		printShopMode();
		break;
	case MENU_MODE::INVEN:
		printInvenMode();
		break;
	}

	int inputType;
	cout << ">>> " << endl;
	cin >> inputType;

	switch ((MENU_MODE)_mode)
	{
	case MENU_MODE::SHOP:
		handleShopMode(inputType);
		break;
	case MENU_MODE::INVEN:
		handleInvenMode(inputType);
		break;
	}

	cin.clear(); // 상태 복구
	cin.ignore(1000, '\n'); // 남은 입력 무시
}

void Menu::printShopMode()
{
    SetCursorColor(Color::SkyBlue);

    cout << "[ 상점 ]" << endl;
    cout << "1. 구매" << endl;
    cout << "2. 품절->새상품 대체" << endl;
	cout << "3. 새로고침" << endl;
	cout << "4. 인벤토리 이동" << endl;
}

void Menu::printInvenMode()
{
    SetCursorColor(Color::RightGreen);

    cout << "[ 인벤토리 ]" << endl;
    cout << "1. 판매" << endl;
    cout << "2. 모두 판매" << endl;
	cout << "3. (같은 등급)모두 판매" << endl;
	cout << "4. 상점 이동" << endl;
}

void Menu::handleError(const std::string& msg)
{
	cout << msg << endl;
	cout << "계속하려면 아무 키나 누르세요..." << endl;
	int result = _getch();
}

void Menu::handleShopMode(int input)
{

	auto iter = _shop->GetSellData().begin();

	switch ((MENU_SHOP)input)
	{
	case MENU_SHOP::BuyItem:
	{
		int selectIndex;
		cout << "구매할 아이템의 번호를 입력하세요. " << endl;
		cout << ">>> " << endl;
		cin >> selectIndex;

		//@TODO 내용 채우기

		//구매 가능한지 확인

		for (int i = 1; i < selectIndex; i++)
			iter++;

		if (_shop->ItemKeyAvailable.find(iter->first) != _shop->ItemKeyAvailable.end() && _inventory->GetTotalGold() >= iter->second->price)
		{
			_inventory->BuyItem(iter->second);
			_shop->ItemKeyAvailable.erase(iter->first);
		}

	}break;
	case MENU_SHOP::NewItem:
	{
		cout << "품절 목록을 새로운 아이템으로 채웁니다. " << endl;
		
		//@TODO 내용 채우기
	}
		break;
	case MENU_SHOP::RefreshItem:
	{
		cout << "상점 목록을 새로고침 합니다. " << endl;
		
		//@TODO 내용 채우기
	}break;
	case MENU_SHOP::Exit:
	{
		_mode = MENU_MODE::INVEN;
	}break;
	}
}

void Menu::handleInvenMode(int input)
{
	switch ((MENU_INVEN)input)
	{
	case MENU_INVEN::SellItem:
	{
		int selectId;
		cout << "판매할 아이템의 아이디를 입력하세요. " << endl;
		cout << ">>> " << endl;
		cin >> selectId;

		//@TODO 내용 채우기
	}break;
	case MENU_INVEN::AllSellItem:
	{
		//@TODO 내용 채우기
	}break;
	case MENU_INVEN::SellItemByGrade:
	{
		int selectGrade;
		cout << "판매할 아이템의 등급을 입력하세요. " << endl;
		cout << ">>> " << endl;
		cin >> selectGrade;

		//@TODO 내용 채우기
	}break;
	case MENU_INVEN::Exit:
	{
		_mode = MENU_MODE::SHOP;
	}break;
	}
}