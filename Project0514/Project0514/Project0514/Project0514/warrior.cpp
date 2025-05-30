#include "warrior.h"
#include <iostream>

using namespace std;

int SetPlayerClass(Player& Youser)
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

void MakePlayerClass(Player* Youser, int YouserNumber)
{
	for (int PlayerClass = 1; PlayerClass <= YouserNumber; PlayerClass++)
	{
		if (PlayerClass == WorialClass::warrior)
		{
			Youser->Power = 55;
			Youser->CriticalRate = 0.25f;
			Youser->Acurate = 9;
			Youser->PlayerInformation.CurrentHP = 150;
			Youser->ClassName = "����";
		}

		else if (PlayerClass == WorialClass::archor)
		{
			Youser->Power = 45;
			Youser->CriticalRate = 0.7f;
			Youser->Acurate = 7;
			Youser->PlayerInformation.CurrentHP = 50;
			Youser->ClassName = "�ü�";
		}

		else if (PlayerClass == WorialClass::axe)
		{
			Youser->Power = 70;
			Youser->CriticalRate = 0.2f;
			Youser->Acurate = 4;
			Youser->PlayerInformation.CurrentHP = 70;
			Youser->ClassName = "������";
		}

		//�ڵ����� ���� �迭�� �ִ� Youser Index ����
		Youser++;
	}
}

Player* SwitchPlayerClass(Player* YouserArray)
{
	int choicePlayer = -1;
	Player* SellectedPlayer = nullptr;

	while (true)
	{
		cout << "\n--�뺴 ����--\n";
		cout << "1. ����\n2. �ü�\n3. ������\n\n";
		cin >> choicePlayer;

		if (YouserArray[choicePlayer - 1].PlayerInformation.CurrentHP >= 0)
		{
			SellectedPlayer = &YouserArray[choicePlayer - 1];
			break;
		}

		else
		{
			cout << "\n �̹� ����� ĳ���� �Դϴ�\n";
		}
	}

	return SellectedPlayer;
}
