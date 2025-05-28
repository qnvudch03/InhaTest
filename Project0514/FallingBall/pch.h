#pragma once

#include <iostream>

#define MAP_HEIGHT 25
#define MAP_WIDTH 8

#define MAX_ARRAYBALL 20

struct Position
{
	int x = -1;
	int y = -1;

	Position operator+(Position b)
	{
		Position Sum;
		Sum.x = x + b.x;
		Sum.y = y + b.y;

		return Sum;
	}

	//bool operator!=(Position b) { return (x != b.x && y != b.y) ? true : false; }
	bool operator==(Position b) { return (x == b.x && y == b.y) ? true : false; }
};

extern Position NullPosition;

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)

#endif
