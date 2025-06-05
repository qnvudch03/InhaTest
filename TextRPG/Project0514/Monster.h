#pragma once

enum MonsterClass
{
	Slime = 1,
	Ork,
	Skeleton,
	Dragon
};

class Monster
{
public:
	int HP = 0;
	int DEF = 0;
	int ATK = 0;
	int Deposit = 0;
	const char* MonsterName = nullptr;

public:
	Monster SpawnMonster();
	void ShowMonsterStat(Monster Enemy);
};

//struct Monster
//{
//	int HP = 0;
//	int DEF = 0;
//	int ATK = 0;
//	int Deposit = 0;
//	const char* MonsterName = nullptr;
//};

//Monster SpawnMonster();
//void ShowMonsterStat(Monster Enemy);



