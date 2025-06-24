#include "pch.h"
#include <iostream>
#include "Helper.h"
#include "Windows.h"
#include "Board.h"
#include "Player.h"

int main()
{
	srand((unsigned int)time(0));

	SetCursorOnOff(false);

	Player player;

	Board board(&player);	// 플레이어의 주소를 넘겨준다.
	board.GenerateMap();

	player.SetBoard(&board);	// 맵정보를 알기위한 주소를 넘겨주자

	// 임시 path 설정
	//player._path.push_back(Pos(2, 1));
	//player._path.push_back(Pos(3, 1));
	//player._path.push_back(Pos(3, 2));
	//player._path.push_back(Pos(3, 3));
	//player._path.push_back(Pos(3, 4));

	//player.Calculate_RightHand();

	//임시 맵 그리기
	board.PrintMap();

	//player.Calculate_DFS();

	//player.Calculate_BFS();

	//player.Calculate_Dijkstra();
	//player.Calculate_Dijkstra2();
	player.Calculate_AStart();



	while (true)
	{
		if (player.Update()) // 한칸씩 (_path 따라서) 길찾기 수행 
		{
			break;
		}

		board.PrintMap();

		Sleep(100);
	}
}
