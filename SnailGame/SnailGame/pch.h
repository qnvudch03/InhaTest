#pragma once

#include <iostream>

#define MAP_WIDTH 35
#define MAP_HEIGHT 20

struct Position
{
	int x = -1;
	int y = -1;

	int past_x = 0;
	int past_y = 0;

	Position operator+(Position b)
	{
		Position Sum;
		Sum.x = x + b.x;
		Sum.y = y + b.y;

		Sum.past_x = past_x + b.past_x;
		Sum.past_y = past_y + b.past_y;
		return Sum;
	}

	Position operator-(Position b)
	{
		Position Diff;
		Diff.x = x - b.x;
		Diff.y = y - b.y;

		Diff.past_x = past_x - b.past_x;
		Diff.past_y = past_y - b.past_y;

		return Diff;
	}

	bool operator!=(Position b) { return (x != b.x && y != b.y) ? true : false; }
	bool operator==(Position b) { return (x == b.x && y == b.y) ? true : false; }
};

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)

#endif
