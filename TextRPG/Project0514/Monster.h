#pragma once

struct Monster
{
	int HP = 0;
	int DEF = 0;
	int ATK = 0;
	int Deposit = 0;
	const char* MonsterName = nullptr;
};



enum MonsterClass
{
	Slime = 1,
	Ork,
	Skeleton,
	Dragon
};

Monster SpawnMonster();
void ShowMonsterStat(Monster Enemy);