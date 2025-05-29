#pragma once

extern const char* Map[MAP_WIDTH][MAP_HEIGHT];

extern Position* BallManagerArray[MAX_ARRAYBALL];

extern Position* REDBallManagerArray[MAX_ARRAYBALL];

extern Position* HeallingBallManagerArray[MAX_ARRAYBALL];

namespace BallMap
{
	void PrintMap(Position* PlayerPosition);

	bool CheckCollision(Position* PlayerPosition);

	void UpdateYellowBall();

	void UpdateRedBall();

	void UpdateHealBall();

	//TestFuntion
	void UpdateBall(BallType Balltype);

	//TestFunction
	void Test();
}

