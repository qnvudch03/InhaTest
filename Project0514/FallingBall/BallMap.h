#pragma once

extern const char* Map[MAP_WIDTH][MAP_HEIGHT];

extern Position* BallManagerArray[MAX_ARRAYBALL];

namespace BallMap
{
	void PrintMap(Position* PlayerPosition);

	bool CheckCollision(Position* PlayerPosition);

	void UpdateBall();
}

