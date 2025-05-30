#pragma once

struct Position
{
	int x = 0;
	int y = 0;

	bool operator== (Position b) { return x == b.x && y == b.y; }
};

struct MapInfo
{
	Position PlayerPosition{ 0,0 };
	Position FlagPosition{ 0, 0 };
	Position BallPosition{ 0, 0 };
	Position ClearPosition{ 0, 0 };
};
