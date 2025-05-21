#include "warrior.h"
#include <iostream>

using namespace std;

int SetClass(Player& Youser)
{
	int WoriarClasses = 0;

	cout << "\n-----------------------------\n";
	cout << "직업을 선택하세요 : \n";
	cout << "1. 전사\n2. 궁수\n3. 광전사\n\n";
	cout << "-----------------------------\n";
	cout << ">>";
	cin >> WoriarClasses;

	system("cls");

	switch (WoriarClasses)
	{
	case WorialClass::warrior:
		Youser.Power = 55;
		Youser.CriticalRate = 0.25f;
		Youser.Acurate = 9;
		Youser.PlayerInformation.CurrentHP = 150;
		Youser.ClassName = "전사";
		//Youser.ClassNameString = "String전사";
		cout << "\n당신의 직업은 : '전사' 입니다.\n";
		break;

	case WorialClass::archor:
		Youser.Power = 45;
		Youser.CriticalRate = 0.7f;
		Youser.Acurate = 7;
		Youser.PlayerInformation.CurrentHP = 50;
		Youser.ClassName = "궁수";
		//Youser.ClassNameString = "String궁수";
		cout << "\n당신의 직업은 : '궁수' 입니다.\n";
		break;

	case WorialClass::axe:
		Youser.Power = 70;
		Youser.CriticalRate = 0.2f;
		Youser.Acurate = 4;
		Youser.PlayerInformation.CurrentHP = 70;
		Youser.ClassName = "광전사";
		//Youser.ClassNameString = "String광전사";
		cout << "\n당신의 직업은 : '광전사' 입니다.\n";
		break;
	default:
		break;
	}

	return WoriarClasses;
}