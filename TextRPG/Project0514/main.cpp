#include <iostream>
#include <Windows.h>
#include <random>

//게임에 사용하는 h
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
	1. 직업 선택하기
	2. 몬스터 체력 깎기
	3. 몬스터가 죽을 때까지 공격하기
	4. 잘못된 값 입려 시 예외처리하기
	5. 3번만 공격 가능
	*/

	//단일 선택 버젼
	//Player Youser;
	//SetPlayerClass(Youser);

	//다중 소환 후 게임플레이 버젼

	//Player Yousers[YOUSER_NUMBER] = {};
	//MakePlayerClass(Yousers, sizeof(Yousers) / sizeof(Player));

	PlayerClass Yousers[YOUSER_NUMBER] = {};
	Yousers->MakePlayerClass(Yousers, sizeof(Yousers) / sizeof(PlayerClass));

	PlayerClass* Youser = Yousers;

	while (true)
	{
		//파티 전멸 여부 확인
		if (CheckPartyAllDead(Yousers))
		{
			cout << "\n\n[파티가 전멸하였습니다]\n";
			break;
		}



		//본게임 시작
		cout << "\n---메뉴---\n";
		cout << "[ 현재캐릭터 : " << Youser->ClassName << " ]\n";
		cout << "[ 보유골드 - " << Youser->PlayerInformation.Deposit << "G ]\n\n";
		cout << "1. 던전 입장\n2. 캐릭터 선택\n3. 종료\n";

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
					std::cout << "\n[난이도 : " << RandomMonsterNum << "]\n";

					RandomEnemyArray[MonsterIndex] = RandomEnemyArray->SpawnMonster();
					cout << "1. 싸운다.\n2. 도망간다.\n";

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
					//전투 for 문
					for (int BattleCount = 0; BattleCount < RandomMonsterNum; BattleCount++)
					{
						//다음 처치할 몬스터 생성
						if (RandomEnemyArray[BattleCount].HP == 0)
						{
							RandomEnemyArray[BattleCount] = RandomEnemyArray->SpawnMonster();
						}

						//전투에서 생존시 다음전투로
						if (StartFight(*Youser, RandomEnemyArray[BattleCount]))
						{
							//60%확율로 돈의 랜덤직업의 돈 절반을 털어간다
							/*int LostMoneyRate = (rd() % 100) + 1;
							int RandomWorialIndex = (rd() % 3);

							if (LostMoneyRate > 60)
							{
								LostMoeny(Yousers[RandomWorialIndex]);
							}*/


							Sleep(2000);
						}

						//전투중 사망시 전투 탈출
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
							cout << "\n\n---던젼 탐험 클리어---\n";
						}
						else
						{
							cout << "\n\n---던젼 탐헝 실패---\n";
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
				cout << " ( ! ) 캐릭터 [ " << Youser->ClassName << " ] 는 사망하여 플레이 할 수 없습니다.\n\n";
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
//		cout << "\n공격 : ";
//
//		Sleep(1000);
//
//		std::random_device rd;
//
//		//공격에 성공했을 때!
//		if ((rd() % 10) + 1 < Youser.Acurate)
//		{
//			int Damage = 0;
//			float CriticlaChance = (rd() & 100) / 100.0f;
//
//			if (CriticlaChance < Youser.CriticalRate)
//			{
//				cout << "크리티컬 공격!\n";
//
//				Damage = Youser.Power * 2 - 0.5 * (Enemy.DEF);
//
//				MosterHP = MosterHP - Damage;
//			}
//
//			else
//			{
//				cout << "보통 공격!\n";
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
//			cout << "실패!\n";
//			cout << Enemy.MonsterName << "(의) 공격 : " << "- " << Enemy.ATK << '\n';
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
//				cout << "\n토벌 실패 : [ 잔여 몬스터 HP  " << MosterHP << "]" << "\n";
//				cout << "[ 소지금  " << OriginGold << "  ->  " << CurrentGold << " ]\n";
//				Youser.PlayerInformation.Deposit = CurrentGold;
//				Youser.PlayerInformation.CurrentHP = 0;
//				return false;
//
//				break;
//			}
//
//			else
//			{
//				cout << "☆★토벌 성공!!★☆\n\n";
//				cout << "[보상]\n";
//				cout << "[사냥골드] : " << Enemy.Deposit << " G\n";
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

		cout << "\n공격 : ";

		Sleep(1000);

		std::random_device rd;

		//공격에 성공했을 때!
		if ((rd() % 10) + 1 < Youser.Acurate)
		{
			int Damage = 0;
			float CriticlaChance = (rd() & 100) / 100.0f;

			if (CriticlaChance < Youser.CriticalRate)
			{
				cout << "크리티컬 공격!\n";

				Damage = Youser.Power * 2 - 0.5 * (Enemy.DEF);

				MosterHP = MosterHP - Damage;
			}

			else
			{
				cout << "보통 공격!\n";

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

			cout << "실패!\n";
			cout << Enemy.MonsterName << "(의) 공격 : " << "- " << Enemy.ATK << '\n';
			cout << "[ " << Youser.ClassName << " HP : " << PlayerHP << " ]\n";
			cout << "[ " << Enemy.MonsterName << " HP : " << MosterHP << " ]\n";
		}

		if (ChanceCount == 0 || MosterHP <= 0 || PlayerHP <= 0)
		{
			if (MosterHP > 0)
			{
				int OriginGold = Youser.PlayerInformation.Deposit;
				int CurrentGold = (OriginGold - Enemy.Deposit < 0) ? 0 : OriginGold - Enemy.Deposit;
				cout << "\n토벌 실패 : [ 잔여 몬스터 HP  " << MosterHP << "]" << "\n";
				cout << "[ 소지금  " << OriginGold << "  ->  " << CurrentGold << " ]\n";
				Youser.PlayerInformation.Deposit = CurrentGold;
				Youser.PlayerInformation.CurrentHP = 0;
				return false;

				break;
			}

			else
			{
				cout << "☆★토벌 성공!!★☆\n\n";
				cout << "[보상]\n";
				cout << "[사냥골드] : " << Enemy.Deposit << " G\n";
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
	cout << "1. 싸운다.\n2. 도망간다.\n";

	int bIsBattle = 0;
	cout << ">>";
	cin >> bIsBattle;

	return bIsBattle;
}

void MonsterApear(const Monster Enemy)
{
	std::cout << "\n-----[" << Enemy.MonsterName << "]이(가) 출현하였습니다-----\n";
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
//	std::cout << "[ " << Youser.ClassName << " ] 골드 소실!!\n";
//}
void LostMoeny(PlayerClass& Youser)
{
	Youser.PlayerInformation.Deposit /= 2;
	std::cout << "[ " << Youser.ClassName << " ] 골드 소실!!\n";
}

//

