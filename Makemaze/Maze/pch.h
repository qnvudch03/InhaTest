#pragma once


#include <iostream>
#include <Windows.h>
#include <vector>
#include <queue>
#include <stack>



enum class MoveDir
{
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_MAX,
};


struct Pos
{
	int x = 0;
	int y = 0;

	Pos() {}
	Pos(int x, int y) : x(x), y(y) {}

	// 연산자 오버로딩 작업. 편의를 위해
	// Pos(1,2) + Pos(3,4) = Pos(4,6)
	Pos operator+(const Pos& other)
	{
		Pos result;
		result.x = x + other.x;
		result.y = y + other.y;
		return result;
	}
	Pos operator-(const Pos& other)
	{
		Pos result;
		result.x = x - other.x;
		result.y = y - other.y;
		return result;
	}

	// Pos(1,2) += Pos(3,4)
	Pos& operator+=(const Pos& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	// Pos(1,2) == Pos(3,4)
	bool operator==(const Pos& other)
	{
		return x == other.x && y == other.y;
	}

	// Pos(1,2) != Pos(3,4)
	bool operator!=(const Pos& other)
	{
		return !(*this == other);
	}
};

#include "Helper.h"
using namespace std;