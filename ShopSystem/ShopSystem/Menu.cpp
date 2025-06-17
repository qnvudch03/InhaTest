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
	cout << "  + ������ : " << _inventory->GetTotalGold() << endl;

	SetCursorColor(Color::White);
	cout << "  �Ϲ� : 1, ";
	SetCursorColor(Color::RightBlue);
	cout << "��� : 2, ";
	SetCursorColor(Color::RightRed);
	cout << "���� : 3" << endl << endl;

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

	cin.clear(); // ���� ����
	cin.ignore(1000, '\n'); // ���� �Է� ����
}

void Menu::printShopMode()
{
    SetCursorColor(Color::SkyBlue);

    cout << "[ ���� ]" << endl;
    cout << "1. ����" << endl;
    cout << "2. ǰ��->����ǰ ��ü" << endl;
	cout << "3. ���ΰ�ħ" << endl;
	cout << "4. �κ��丮 �̵�" << endl;
}

void Menu::printInvenMode()
{
    SetCursorColor(Color::RightGreen);

    cout << "[ �κ��丮 ]" << endl;
    cout << "1. �Ǹ�" << endl;
    cout << "2. ��� �Ǹ�" << endl;
	cout << "3. (���� ���)��� �Ǹ�" << endl;
	cout << "4. ���� �̵�" << endl;
}

void Menu::handleError(const std::string& msg)
{
	cout << msg << endl;
	cout << "����Ϸ��� �ƹ� Ű�� ��������..." << endl;
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
		cout << "������ �������� ��ȣ�� �Է��ϼ���. " << endl;
		cout << ">>> " << endl;
		cin >> selectIndex;

		//@TODO ���� ä���

		//���� �������� Ȯ��

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
		cout << "ǰ�� ����� ���ο� ���������� ä��ϴ�. " << endl;
		
		//@TODO ���� ä���
	}
		break;
	case MENU_SHOP::RefreshItem:
	{
		cout << "���� ����� ���ΰ�ħ �մϴ�. " << endl;
		
		//@TODO ���� ä���
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
		cout << "�Ǹ��� �������� ���̵� �Է��ϼ���. " << endl;
		cout << ">>> " << endl;
		cin >> selectId;

		//@TODO ���� ä���
	}break;
	case MENU_INVEN::AllSellItem:
	{
		//@TODO ���� ä���
	}break;
	case MENU_INVEN::SellItemByGrade:
	{
		int selectGrade;
		cout << "�Ǹ��� �������� ����� �Է��ϼ���. " << endl;
		cout << ">>> " << endl;
		cin >> selectGrade;

		//@TODO ���� ä���
	}break;
	case MENU_INVEN::Exit:
	{
		_mode = MENU_MODE::SHOP;
	}break;
	}
}