#include <iostream>
#include <Windows.h>
#include <random>

//���ӿ� ����ϴ� h
#include "warrior.h"
#include "Monster.h"
#include "Reword.h"

using namespace std;



void StartFight(Player& Youser, Monster& Enemy);
int GoToBattleFiled();

int main(void)
{
	/*
	1. ���� �����ϱ�
	2. ���� ü�� ���
	3. ���Ͱ� ���� ������ �����ϱ�
	4. �߸��� �� �Է� �� ����ó���ϱ�
	5. 3���� ���� ����
	*/


	Player Youser;

	SetClass(Youser);

	while (true)
	{
		cout << "\n---�޴�---\n";
		cout << "1. ���� ����\n2. ĳ���� ����\n3. ����\n";

		int InSelectMenu = 0;
		cout << ">>";
		cin >> InSelectMenu;

		if (InSelectMenu == 1)
		{
			Monster Enemy;
			int bIsBattle = 0;
			while (true)
			{
				Enemy = SpawnMonster();
				cout << "1. �ο��.\n2. ��������.\n3. ������ ����\n";

				bIsBattle = 0;
				cout << ">>";
				cin >> bIsBattle;

				if (bIsBattle == 1 || bIsBattle == 3)
					break;

			}

			if (bIsBattle == 1)
			{
				StartFight(Youser, Enemy);

				{
					int tempNum = 0;
					cout << "Press Any Key To Continue --> (0)\n";
					cin >> tempNum;
					system("cls");
				}
			}

			else if (bIsBattle == 3)
			{
				continue;
			}
			
		}
			

		else if (InSelectMenu == 2)
			SetClass(Youser);

		else if (InSelectMenu == 3)
			break;

	}

	cout << "\n----------End Game----------";	
}

void StartFight(Player& Youser, Monster& Enemy)
{
	int ChanceCount = 3;
	int MosterHP = Enemy.HP;
	int PlayerHP = Youser.HP;
	int UseItem = 1;

	while (ChanceCount > 0)
	{
		//ChanceCount--;

		cout << "\n���� : ";

		Sleep(1000);

		std::random_device rd;

		//���ݿ� �������� ��!
		if ((rd() % 10) + 1 < Youser.Acurate)
		{
			int Damage = 0;
			float CriticlaChance = (rd() & 100) / 100.0f;

			if (CriticlaChance < Youser.CriticalRate)
			{
				cout << "ũ��Ƽ�� ����!\n";

				Damage = Youser.Power * 2 - 0.5*(Enemy.DEF);

				MosterHP = MosterHP - Damage;
			}

			else
			{
				cout << "���� ����!\n";

				Damage = Youser.Power - Enemy.DEF;
				MosterHP = MosterHP - Damage;
			}

			MosterHP = (MosterHP < 0) ? 0 : MosterHP;
			cout << "[ ���� HP : " << MosterHP << " ]\n";

		}
		else
		{
			PlayerHP -= Enemy.ATK;

			if (PlayerHP < 0)
				PlayerHP = 0;

			cout << "����!\n";
			cout << "������ ���� : " << "- "<<Enemy.ATK << '\n';
			cout << "[ �뺴 HP : " << PlayerHP << " ]\n";
			cout << "[ ���� HP : " << MosterHP << " ]\n";
		}

		if (ChanceCount == 0 || MosterHP <= 0 || PlayerHP <= 0)
		{
			if (MosterHP > 0)
			{
				cout << "\n��� ���� : [ �ܿ� ���� HP  " << MosterHP << "]" << "\n";

				/*if (UseItem != 0)
				{
					cout << "�������� ����Ͻðڽ��ϱ�??  <Yes : 1> / <No : 0>\n";
					cout << ">>";
					cin >> UseItem;

					switch (UseItem)
					{
					case 1:
						ChanceCount = 1;
						UseItem--;
						continue;

					case 0:
						cout << "������ �����ƴ�...\n\n";
						break;
					default:
						break;
					}
				}*/

				break;
			}

			else
			{
				cout << "�١���� ����!!�ڡ�\n\n";
				cout << "[����]\n";

				int ReWord = GetHuntReword();
				PrintItemOption(ReWord);

				break;
			}

		}
	}
}



int GoToBattleFiled()
{
	cout << "1. �ο��.\n2. ��������.\n";

	int bIsBattle = 0;
	cout << ">>";
	cin >> bIsBattle;

	return bIsBattle;
}


