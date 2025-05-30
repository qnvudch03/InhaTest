#include <iostream>
#include <Windows.h>
#include "Helper.h"
#include "Player.h"
#include "Map.h"

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

	//함수

	/*
	
	*/

	//Draw BackGround
	for (int Row = 0; Row < MAP_SIZE + 2; Row++)
	{
		for (int Column = 0; Column < MAP_SIZE + 2; Column++)
		{
			std::cout << "■";
		}
		std::cout << '\n';
	}

	while (true)
	{

		SetCursorPosition(1, 1);

		// 입력
		HandleKeyInput();
		
		SetMap();
		int A = GameMap[2][2];

		// 로직 (Update)
		HandleMove();


		// 출력 (렌더링)
		PrintMap();
	}
}

