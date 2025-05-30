#include "Map.h"
#include "Helper.h"
#include <iostream>

const char* GameMap[MAP_SIZE+2][MAP_SIZE+2];

void PrintMap()
{
	for (int Row = 0; Row < MAP_SIZE + 2; Row++)
	{
		for (int Column = 0; Column < MAP_SIZE + 2; Column++)
		{
			std::cout << GameMap[Row][Column];
		}
		std::cout << "\n";
	}
	
}

void SetMap(Position& PlayerPosition, MapInfo* MapArray)
{
	Position& Player = PlayerPosition;

	//Set Basic
	for (int Row = 1; Row < MAP_SIZE + 1; Row++)
	{
		for (int Column = 1; Column < MAP_SIZE + 1; Column++)
		{
			GameMap[Row][Column] = "□";
		}
	}

	for (int MapIndex = 0; MapIndex < GollNum; MapIndex++)
	{
		MapInfo CurrentMap = MapArray[MapIndex];

		Position& Flag = CurrentMap.FlagPosition;
		Position& Ball = CurrentMap.BallPosition;
		Position& Clear = CurrentMap.ClearPosition;

		//골대 위치에다가 정보 넣어주기
		GameMap[Flag.y][Flag.x] = "☆";

		//공위치
		if (Ball.x != -1 && Ball.y != -1)
		{
			GameMap[Ball.y][Ball.x] = "♬";
		}

		//공이 들어간 클리어 위치에 넣어주기
		if (Clear.x != 0 && Clear.y != 0)
			GameMap[Clear.y][Clear.x] = "♨";
	}

	//배열에다가 캐릭터 위치 넣어주기
	GameMap[Player.y][Player.x] = "♧";

	
}
