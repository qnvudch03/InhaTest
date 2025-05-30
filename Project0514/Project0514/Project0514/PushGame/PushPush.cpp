#include <iostream>
#include <Windows.h>
#include "Helper.h"
#include "Player.h"
#include "Map.h"
#include "Position.h"
#include <random>

void InitializePosition(MapInfo& PositionInfo);
bool GollCheck(MapInfo* MapInfoArray);

extern const char* GameMap[MAP_SIZE + 2][MAP_SIZE + 2];

int main()
{
	//기본적으로 흰색 네모를 다 그린 다음에, Map에서 보정된 위쳉서 네모를 그리게 하자
	//변수
	/*
	--Player--
		1. 현재 본인의 위치 값


	--Map--
		1. 스테이지 맵에 대한 정보
			맵의 크기 정보
			골대의 위치 정보
			공의 위치 정보
	*/

	Position PlayerPosition;
	MapInfo PositionInfo;

	MapInfo MapInfoArray[GollNum];

	for (MapInfo& CurrentMapInfo : MapInfoArray)
	{
		InitializePosition(CurrentMapInfo);
		
		//Player Position을 따로 뽑아서 넣자니, Init함수에서 번거로우니 마지막 쎄트의 위치값을 가져가도록 임시 적용
		PlayerPosition = CurrentMapInfo.PlayerPosition;
	}
		

	//InitializePosition(PositionInfo);

	SetCursorColor(Color::Yellow, Color::Black);
	SetCursorOnOff(false);

	////Set BackGround
	for (int Row = 0; Row < MAP_SIZE + 2; Row++)
	{
		for (int Column = 0; Column < MAP_SIZE + 2; Column++)
		{
			GameMap[Row][Column] = "■";
		}
	}


	while (true)
	{

		SetCursorPosition(0, 0);

		// 입력
		HandleKeyInput(PlayerPosition, MapInfoArray);

		SetMap(PlayerPosition, MapInfoArray);

		// 로직 (Update)
		HandleMove();

		// 출력 (렌더링)
		PrintMap();

		if (GollCheck(MapInfoArray))
		{
			system("cls");
			SetCursorColor(Color::Yellow, Color::Red);
			PrintMap();

			std::cout << "\n\n--게임클리어--\n";
			return 0;
		}
	}
}

void InitializePosition(MapInfo& PositionInfo)
{
	Position& Player = PositionInfo.PlayerPosition;
	Position& Flag = PositionInfo.FlagPosition;
	Position& Ball = PositionInfo.BallPosition;

	std::random_device rd;

	//Player Position
	{
		Player.x = (rd() % MAP_SIZE) + 1;
		Player.y = (rd() % MAP_SIZE) + 1;
	}

	//Flag Position
	{
		Flag.x = (rd() % MAP_SIZE) + 1;
		Flag.y = (rd() % MAP_SIZE) + 1;
	}

	//Ball Position
	{
		Ball.x = (rd() % MAP_SIZE);
		Ball.y = (rd() % MAP_SIZE);

		Ball.x = (Ball.x <= 1) ? 2 : Ball.x;
		Ball.y = (Ball.y <= 1) ? 2 : Ball.y;
		Ball.x = (Ball.x >= MAP_SIZE) ? MAP_SIZE - 1 : Ball.x;
		Ball.y = (Ball.y >= MAP_SIZE) ? MAP_SIZE - 1 : Ball.y;
	}
}

bool GollCheck(MapInfo* MapArray)
{
	int ClearCount = 0;

	for (int BallCount = 0; BallCount < GollNum; BallCount++)
	{
		Position BallPosition = MapArray[BallCount].BallPosition;

		for (int FlagCount = 0; FlagCount < GollNum; FlagCount++)
		{
			if (BallPosition == MapArray[FlagCount].FlagPosition)
			{
				MapArray[FlagCount].ClearPosition = BallPosition;
				MapArray[BallCount].BallPosition = { -1, -1 };
			}
				
		}

		if (BallPosition.x == -1 && BallPosition.y == -1)
			ClearCount++;
	}

	if (ClearCount == GollNum)
		return true;

	else
		return false;
}
