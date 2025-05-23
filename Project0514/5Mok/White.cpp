#include "White.h"
#include "Board.h"
#include "Util.h"

extern int G_Chessboard[GAMESIZE][GAMESIZE];
bool Turn_White()
{
	//1. 같은 크기의 자기만의 배열을 생성
	//2. 글로벌 체스판에 등재
	//3. 업데이트

	Position CurrentStone = {GAMESIZE / 2, GAMESIZE / 2};

	while (true)
	{
		CurrentStone = HandleKeyInput(CurrentStone);
		G_Chessboard[CurrentStone.y][CurrentStone.x] = Chess::White;

		PrintBoard();
		if (DetectSpaceBar())
			break;
	}

	return false;
}
