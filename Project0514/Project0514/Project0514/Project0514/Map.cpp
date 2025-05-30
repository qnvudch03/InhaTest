#include "Map.h"
#include <iostream>

void PrintMap()
{

	
}

void SetMap(Position Player, Position Flag, Position Ball)
{
	MapInfo MapIndexInfo;

	//GameMap[MAP_SIZE][MAP_SIZE];

	//Set Basic
	for (int Row = 1; Row < MAP_SIZE; Row++)
	{
		for (int Column = 1; Column < MAP_SIZE; Column++)
		{
			GameMap[Row][Column] = '□';
		}
	}

	//배열에다가 캐릭터 위치 넣어주기
	GameMap[MapIndexInfo.PlayerPosition.x][MapIndexInfo.PlayerPosition.y] = '♧';

	//골대 위치에다가 정보 넣어주기
	GameMap[MapIndexInfo.FlagPosition.y][MapIndexInfo.FlagPosition.x] = '☆';

	//공위치
	GameMap[MapIndexInfo.BallPosition.y][MapIndexInfo.BallPosition.x] = '♡';
}
