#include <iostream>
#include <Windows.h>
#include <random>

//게임에 사용하는 h
#include "warrior.h"
#include "Monster.h"
#include "Reword.h"

using namespace std;



void StartFight(Player& Youser, Monster& Enemy);
int GoToBattleFiled();

int main(void)
{
	/*
	1. 직업 선택하기
	2. 몬스터 체력 깎기
	3. 몬스터가 죽을 때까지 공격하기
	4. 잘못된 값 입려 시 예외처리하기
	5. 3번만 공격 가능
	*/


	Player Youser;

	SetClass(Youser);

	while (true)
	{
		cout << "\n---메뉴---\n";
		cout << "1. 던전 입장\n2. 캐릭터 선택\n3. 종료\n";

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
				cout << "1. 싸운다.\n2. 도망간다.\n3. 마을로 복귀\n";

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

				Damage = Youser.Power * 2 - 0.5*(Enemy.DEF);

				MosterHP = MosterHP - Damage;
			}

			else
			{
				cout << "보통 공격!\n";

				Damage = Youser.Power - Enemy.DEF;
				MosterHP = MosterHP - Damage;
			}

			MosterHP = (MosterHP < 0) ? 0 : MosterHP;
			cout << "[ 몬스터 HP : " << MosterHP << " ]\n";

		}
		else
		{
			PlayerHP -= Enemy.ATK;

			if (PlayerHP < 0)
				PlayerHP = 0;

			cout << "실패!\n";
			cout << "몬스터의 공격 : " << "- "<<Enemy.ATK << '\n';
			cout << "[ 용병 HP : " << PlayerHP << " ]\n";
			cout << "[ 몬스터 HP : " << MosterHP << " ]\n";
		}

		if (ChanceCount == 0 || MosterHP <= 0 || PlayerHP <= 0)
		{
			if (MosterHP > 0)
			{
				cout << "\n토벌 실패 : [ 잔여 몬스터 HP  " << MosterHP << "]" << "\n";

				/*if (UseItem != 0)
				{
					cout << "아이템을 사용하시겠습니까??  <Yes : 1> / <No : 0>\n";
					cout << ">>";
					cin >> UseItem;

					switch (UseItem)
					{
					case 1:
						ChanceCount = 1;
						UseItem--;
						continue;

					case 0:
						cout << "마을로 도망쳤다...\n\n";
						break;
					default:
						break;
					}
				}*/

				break;
			}

			else
			{
				cout << "☆★토벌 성공!!★☆\n\n";
				cout << "[보상]\n";

				int ReWord = GetHuntReword();
				PrintItemOption(ReWord);

				break;
			}

		}
	}
}



int GoToBattleFiled()
{
	cout << "1. 싸운다.\n2. 도망간다.\n";

	int bIsBattle = 0;
	cout << ">>";
	cin >> bIsBattle;

	return bIsBattle;
}


