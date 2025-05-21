#include "Monster.h"
#include <iostream>
#include <random>

Monster SpawnMonster()
{
	Monster SpawnedMonster;
	std::random_device rd;

	int RandomMosterIncounter = (rd() % 4) + 1;

	switch (RandomMosterIncounter)
	{
	case Ork:
		SpawnedMonster.HP = 70;
		SpawnedMonster.DEF = 10;
		SpawnedMonster.ATK = 10;
		std::cout << "\n-----[오크]이(가) 출현하였습니다-----";
		break;
	case Slime:
		SpawnedMonster.HP = 30;
		SpawnedMonster.DEF = 5;
		SpawnedMonster.ATK = 5;
		std::cout << "\n-----[슬라임]이(가) 출현하였습니다-----";
		break;
	case Dragon:
		SpawnedMonster.HP = 120;
		SpawnedMonster.DEF = 30;
		SpawnedMonster.ATK = 30;
		std::cout << "\n-----[드래곤]이(가) 출현하였습니다-----";
		break;
	case Skeleton:
		SpawnedMonster.HP = 100;
		SpawnedMonster.DEF = 0;
		SpawnedMonster.ATK = 13;
		std::cout << "\n-----[스켈레톤]이(가) 출현하였습니다-----";
		break;
	default:
		break;
	}
	ShowMonsterStat(SpawnedMonster);
	return SpawnedMonster;
}

void ShowMonsterStat(Monster Enemy)
{
	std::cout << "[ HP : " << Enemy.HP << ' ' << " ATK : " << Enemy.ATK << ' ' << "DEF : " << Enemy.DEF << " ]" << "\n\n";
}