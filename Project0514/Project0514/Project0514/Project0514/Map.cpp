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
			GameMap[Row][Column] = '��';
		}
	}

	//�迭���ٰ� ĳ���� ��ġ �־��ֱ�
	GameMap[MapIndexInfo.PlayerPosition.x][MapIndexInfo.PlayerPosition.y] = '��';

	//��� ��ġ���ٰ� ���� �־��ֱ�
	GameMap[MapIndexInfo.FlagPosition.y][MapIndexInfo.FlagPosition.x] = '��';

	//����ġ
	GameMap[MapIndexInfo.BallPosition.y][MapIndexInfo.BallPosition.x] = '��';
}
