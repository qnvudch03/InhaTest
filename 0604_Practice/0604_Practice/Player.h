#pragma once
class Player
{
public:
	Player(int MaxHP = 0, int level = 0) : Max_HP(MaxHP), Level(level) { Current_HP = Max_HP; }

	Player(int MaxHP) : Max_HP(MaxHP) {}

public:
	int Max_HP = 0;
	int Level = 0;

	int Current_HP = 0;


	const char* Name = "ภüป็";


public:

	void Attack()
	{

	}

	void HealMe()
	{
		Current_HP += 50;
		Current_HP = (Current_HP > Max_HP) ? Max_HP : Current_HP;
	}
};

