#include "warrior.h"
#include <iostream>

using namespace std;

int SetClass(Player& Youser)
{
	int WoriarClasses = 0;

	cout << "\n-----------------------------\n";
	cout << "������ �����ϼ��� : \n";
	cout << "1. ����\n2. �ü�\n3. ������\n\n";
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
		Youser.ClassName = "����";
		//Youser.ClassNameString = "String����";
		cout << "\n����� ������ : '����' �Դϴ�.\n";
		break;

	case WorialClass::archor:
		Youser.Power = 45;
		Youser.CriticalRate = 0.7f;
		Youser.Acurate = 7;
		Youser.PlayerInformation.CurrentHP = 50;
		Youser.ClassName = "�ü�";
		//Youser.ClassNameString = "String�ü�";
		cout << "\n����� ������ : '�ü�' �Դϴ�.\n";
		break;

	case WorialClass::axe:
		Youser.Power = 70;
		Youser.CriticalRate = 0.2f;
		Youser.Acurate = 4;
		Youser.PlayerInformation.CurrentHP = 70;
		Youser.ClassName = "������";
		//Youser.ClassNameString = "String������";
		cout << "\n����� ������ : '������' �Դϴ�.\n";
		break;
	default:
		break;
	}

	return WoriarClasses;
}