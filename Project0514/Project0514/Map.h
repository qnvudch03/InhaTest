#pragma once
#include "Po"


#define MAP_SIZE 6

//extern int GameMap[MAP_SIZE][MAP_SIZE];
int GameMap[MAP_SIZE][MAP_SIZE];

struct MapInfo
{
	Position PlayerPosition;
	Position FlagPosition;
	Position BallPosition;
};

void PrintMap();

void SetMap(Position Player, Position Flag, Position Ball);