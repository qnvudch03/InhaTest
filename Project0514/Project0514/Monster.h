#pragma once

struct Monster
{
	int HP = 0;
	int DEF = 0;
	int ATK = 0;
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