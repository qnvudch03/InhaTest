#pragma once

#include "Player.h"

struct PlayerInfo
{
	int CurrentHP = 0;
	int Deposit = 0;
};

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
	axe,
	WorialMax
};

int SetPlayerClass(Player& Youser);
void MakePlayerClass(Player* Youser, int YouserNumber);
Player* SwitchPlayerClass(Player* YouserArray);