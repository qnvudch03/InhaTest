#include <iostream>
#include <Windows.h>
#include <random>

//���ӿ� ����ϴ� h
#include "warrior.h"
#include "Monster.h"
#include "Reword.h"

using namespace std;

#define YOUSER_NUMBER 3
#define CLEARHEAPARRAYPTR(x) delete[] x; x = nullptr;

//bool StartFight(Player& Youser, Monster& Enemy);
//int GoToBattleFiled();
//void MonsterApear(const Monster Enemy);
//bool CheckPartyAllDead(const Player* Party);
//void LostMoeny(Player& Youser);

bool StartFight(PlayerClass& Youser, Monster& Enemy);
int GoToBattleFiled();
void MonsterApear(const Monster Enemy);
bool CheckPartyAllDead(const PlayerClass* Party);
void LostMoeny(PlayerClass& Youser);

int main(void)
{
	/*
	1. ���� �����ϱ�
	2. ���� ü�� ���
	3. ���Ͱ� ���� ������ �����ϱ�
	4. �߸��� �� �Է� �� ����ó���ϱ�
	5. 3���� ���� ����
	*/

	//���� ���� ����
	//Player Youser;
	//SetPlayerClass(Youser);

	//���� ��ȯ �� �����÷��� ����

	//Player Yousers[YOUSER_NUMBER] = {};
	//MakePlayerClass(Yousers, sizeof(Yousers) / sizeof(Player));

	PlayerClass Yousers[YOUSER_NUMBER] = {};
	Yousers->MakePlayerClass(Yousers, sizeof(Yousers) / sizeof(PlayerClass));

	PlayerClass* Youser = Yousers;

	while (true)
	{
		//��Ƽ ���� ���� Ȯ��
		if (CheckPartyAllDead(Yousers))
		{
			cout << "\n\n[��Ƽ�� �����Ͽ����ϴ�]\n";
			break;
		}



		//������ ����
		cout << "\n---�޴�---\n";
		cout << "[ ����ĳ���� : " << Youser->ClassName << " ]\n";
		cout << "[ ������� - " << Youser->PlayerInformation.Deposit << "G ]\n\n";
		cout << "1. ���� ����\n2. ĳ���� ����\n3. ����\n";

		int InSelectMenu = 0;
		cout << ">>";
		cin >> InSelectMenu;

		if (InSelectMenu == 1)
		{
			if (Youser->PlayerInformation.CurrentHP != 0)
			{

				std::random_device rd;
				int RandomMonsterNum = (rd() % 5) + 1;
				Monster* RandomEnemyArray = new Monster[RandomMonsterNum];

				int bIsBattle = 0;
				int MonsterIndex = 0;

				while (true)
				{
					std::cout << "\n[���̵� : " << RandomMonsterNum << "]\n";

					RandomEnemyArray[MonsterIndex] = RandomEnemyArray->SpawnMonster();
					cout << "1. �ο��.\n2. ��������.\n";

					//bIsBattle = 0;
					cout << ">>";
					cin >> bIsBattle;

					if (bIsBattle == 1)
					{
						break;
					}
					else if (bIsBattle == 2)
					{
						RandomMonsterNum = (rd() % 5) + 1;
						CLEARHEAPARRAYPTR(RandomEnemyArray);
						RandomEnemyArray = new Monster[RandomMonsterNum];

					}

				}

				if (bIsBattle == 1)
				{

					bool bIsStageClear = true;
					//���� for ��
					for (int BattleCount = 0; BattleCount < RandomMonsterNum; BattleCount++)
					{
						//���� óġ�� ���� ����
						if (RandomEnemyArray[BattleCount].HP == 0)
						{
							RandomEnemyArray[BattleCount] = RandomEnemyArray->SpawnMonster();
						}

						//�������� ������ ����������
						if (StartFight(*Youser, RandomEnemyArray[BattleCount]))
						{
							//60%Ȯ���� ���� ���������� �� ������ �о��
							/*int LostMoneyRate = (rd() % 100) + 1;
							int RandomWorialIndex = (rd() % 3);

							if (LostMoneyRate > 60)
							{
								LostMoeny(Yousers[RandomWorialIndex]);
							}*/


							Sleep(2000);
						}

						//������ ����� ���� Ż��
						else
						{
							bIsStageClear = false;
							break;
						}
					}

					{
						int tempNum = 0;

						if (bIsStageClear)
						{
							cout << "\n\n---���� Ž�� Ŭ����---\n";
						}
						else
						{
							cout << "\n\n---���� Ž�� ����---\n";
						}

						cout << "\n\nPress Any Key To Continue --> (0)\n";
						CLEARHEAPARRAYPTR(RandomEnemyArray);
						cin >> tempNum;
						system("cls");
					}

				}

				else if (bIsBattle == 2)
				{
					CLEARHEAPARRAYPTR(RandomEnemyArray);
				}
			}

			else
			{
				cout << " ( ! ) ĳ���� [ " << Youser->ClassName << " ] �� ����Ͽ� �÷��� �� �� �����ϴ�.\n\n";
				continue;
			}
			

		}


		else if (InSelectMenu == 2)
		{
			//SetPlayerClass(Youser);
			Youser = Youser->SwitchPlayerClass(Yousers);
			system("cls");
		}


		else if (InSelectMenu == 3)
			break;

	}

	cout << "\n----------End Game----------";
}

//bool StartFight(Player& Youser, Monster& Enemy)
//{
//	int ChanceCount = 3;
//	int MosterHP = Enemy.HP;
//	int PlayerHP = Youser.PlayerInformation.CurrentHP;
//	int UseItem = 1;
//
//	while (ChanceCount > 0)
//	{
//		//ChanceCount--;
//
//		cout << "\n���� : ";
//
//		Sleep(1000);
//
//		std::random_device rd;
//
//		//���ݿ� �������� ��!
//		if ((rd() % 10) + 1 < Youser.Acurate)
//		{
//			int Damage = 0;
//			float CriticlaChance = (rd() & 100) / 100.0f;
//
//			if (CriticlaChance < Youser.CriticalRate)
//			{
//				cout << "ũ��Ƽ�� ����!\n";
//
//				Damage = Youser.Power * 2 - 0.5 * (Enemy.DEF);
//
//				MosterHP = MosterHP - Damage;
//			}
//
//			else
//			{
//				cout << "���� ����!\n";
//
//				Damage = Youser.Power - Enemy.DEF;
//				MosterHP = MosterHP - Damage;
//			}
//
//			MosterHP = (MosterHP < 0) ? 0 : MosterHP;
//			cout << "[ " << Enemy.MonsterName << " HP : " << MosterHP << " ]\n";
//
//		}
//		else
//		{
//			PlayerHP -= Enemy.ATK;
//
//			if (PlayerHP < 0)
//				PlayerHP = 0;
//
//			cout << "����!\n";
//			cout << Enemy.MonsterName << "(��) ���� : " << "- " << Enemy.ATK << '\n';
//			cout << "[ " << Youser.ClassName << " HP : " << PlayerHP << " ]\n";
//			cout << "[ " << Enemy.MonsterName << " HP : " << MosterHP << " ]\n";
//		}
//
//		if (ChanceCount == 0 || MosterHP <= 0 || PlayerHP <= 0)
//		{
//			if (MosterHP > 0)
//			{
//				int OriginGold = Youser.PlayerInformation.Deposit;
//				int CurrentGold = (OriginGold - Enemy.Deposit < 0) ? 0 : OriginGold - Enemy.Deposit;
//				cout << "\n��� ���� : [ �ܿ� ���� HP  " << MosterHP << "]" << "\n";
//				cout << "[ ������  " << OriginGold << "  ->  " << CurrentGold << " ]\n";
//				Youser.PlayerInformation.Deposit = CurrentGold;
//				Youser.PlayerInformation.CurrentHP = 0;
//				return false;
//
//				break;
//			}
//
//			else
//			{
//				cout << "�١���� ����!!�ڡ�\n\n";
//				cout << "[����]\n";
//				cout << "[��ɰ��] : " << Enemy.Deposit << " G\n";
//				Youser.PlayerInformation.Deposit += Enemy.Deposit;
//
//				const int ReWord = GetHuntReword();
//				PrintItemOption(ReWord);
//
//				break;
//			}
//
//		}
//	}
//
//	return true;
//}
//
//
bool StartFight(PlayerClass& Youser, Monster& Enemy)
{
	int ChanceCount = 3;
	int MosterHP = Enemy.HP;
	int PlayerHP = Youser.PlayerInformation.CurrentHP;
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

				Damage = Youser.Power * 2 - 0.5 * (Enemy.DEF);

				MosterHP = MosterHP - Damage;
			}

			else
			{
				cout << "���� ����!\n";

				Damage = Youser.Power - Enemy.DEF;
				MosterHP = MosterHP - Damage;
			}

			MosterHP = (MosterHP < 0) ? 0 : MosterHP;
			cout << "[ " << Enemy.MonsterName << " HP : " << MosterHP << " ]\n";

		}
		else
		{
			PlayerHP -= Enemy.ATK;

			if (PlayerHP < 0)
				PlayerHP = 0;

			cout << "����!\n";
			cout << Enemy.MonsterName << "(��) ���� : " << "- " << Enemy.ATK << '\n';
			cout << "[ " << Youser.ClassName << " HP : " << PlayerHP << " ]\n";
			cout << "[ " << Enemy.MonsterName << " HP : " << MosterHP << " ]\n";
		}

		if (ChanceCount == 0 || MosterHP <= 0 || PlayerHP <= 0)
		{
			if (MosterHP > 0)
			{
				int OriginGold = Youser.PlayerInformation.Deposit;
				int CurrentGold = (OriginGold - Enemy.Deposit < 0) ? 0 : OriginGold - Enemy.Deposit;
				cout << "\n��� ���� : [ �ܿ� ���� HP  " << MosterHP << "]" << "\n";
				cout << "[ ������  " << OriginGold << "  ->  " << CurrentGold << " ]\n";
				Youser.PlayerInformation.Deposit = CurrentGold;
				Youser.PlayerInformation.CurrentHP = 0;
				return false;

				break;
			}

			else
			{
				cout << "�١���� ����!!�ڡ�\n\n";
				cout << "[����]\n";
				cout << "[��ɰ��] : " << Enemy.Deposit << " G\n";
				Youser.PlayerInformation.Deposit += Enemy.Deposit;

				const int ReWord = GetHuntReword();
				PrintItemOption(ReWord);

				break;
			}

		}
	}

	return true;
}

int GoToBattleFiled()
{
	cout << "1. �ο��.\n2. ��������.\n";

	int bIsBattle = 0;
	cout << ">>";
	cin >> bIsBattle;

	return bIsBattle;
}

void MonsterApear(const Monster Enemy)
{
	std::cout << "\n-----[" << Enemy.MonsterName << "]��(��) �����Ͽ����ϴ�-----\n";
}

//bool CheckPartyAllDead(const Player* Party)
//{
//	int DeadWorial = 0;
//	
//	for (int WorialIndex = 0; WorialIndex < YOUSER_NUMBER; WorialIndex++)
//	{
//		if (Party->PlayerInformation.CurrentHP == 0)
//		{
//			DeadWorial++;
//		}
//
//		Party++;
//	}
//
//	return (DeadWorial == YOUSER_NUMBER) ? true : false;
//}
bool CheckPartyAllDead(const PlayerClass* Party)
{
	int DeadWorial = 0;

	for (int WorialIndex = 0; WorialIndex < YOUSER_NUMBER; WorialIndex++)
	{
		if (Party->PlayerInformation.CurrentHP == 0)
		{
			DeadWorial++;
		}

		Party++;
	}

	return (DeadWorial == YOUSER_NUMBER) ? true : false;
}

//void LostMoeny(Player& Youser)
//{
//	Youser.PlayerInformation.Deposit /= 2;
//	std::cout << "[ " << Youser.ClassName << " ] ��� �ҽ�!!\n";
//}
void LostMoeny(PlayerClass& Youser)
{
	Youser.PlayerInformation.Deposit /= 2;
	std::cout << "[ " << Youser.ClassName << " ] ��� �ҽ�!!\n";
}

//

