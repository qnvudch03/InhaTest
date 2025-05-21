#pragma once

#include "Player.h"

struct Player
{
	PlayerInfo PlayerInformation;
	int Power = 0;
	float CriticalRate = 0.0f;
	const char* ClassName = nullptr;
	//std::string ClassNameString;
	int Acurate = 0;
};

enum WorialClass
{
	warrior = 1,
	archor,
	axe
};

int SetClass(Player& Youser);