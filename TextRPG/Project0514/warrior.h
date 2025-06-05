#pragma once

#include "Player.h"


enum WorialClass
{
	warrior = 1,
	archor,
	axe,
	WorialMax
};

class PlayerClass
{
public:
	int SetPlayerClass(PlayerClass& Youser);
	void MakePlayerClass(PlayerClass* Youser, int YouserNumber);
	PlayerClass* SwitchPlayerClass(PlayerClass* YouserArray);

public:
	PlayerInfo PlayerInformation;
	int Power = 0;
	float CriticalRate = 0.0f;
	const char* ClassName = nullptr;
	int Acurate = 0;
};



//struct Player
//{
//	PlayerInfo PlayerInformation;
//	int Power = 0;
//	float CriticalRate = 0.0f;
//	const char* ClassName = nullptr;
//	int Acurate = 0;
//};



//int SetPlayerClass(Player& Youser);
//void MakePlayerClass(Player* Youser, int YouserNumber);
//Player* SwitchPlayerClass(Player* YouserArray);