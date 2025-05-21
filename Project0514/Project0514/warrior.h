#pragma once

struct Player
{
	int Power = 0;
	int HP = 0;
	float CriticalRate = 0.0f;
	int Acurate = 0;
};

enum WorialClass
{
	warrior = 1,
	archor,
	axe
};

int SetClass(Player& Youser);