#include "White.h"
#include "Board.h"
#include "Util.h"

extern int G_Chessboard[GAMESIZE][GAMESIZE];
bool Turn_White()
{
	//1. 같은 크기의 자기만의 배열을 생성
	//2. 글로벌 체스판에 등재
	//3. 업데이트

	Position InitPosition = {GAMESIZE / 2, GAMESIZE / 2};
	Position NextPosition = { 0, 0 };

	while (true)
	{
		NextPosition = HandleKeyInput(InitPosition);

		if (G_Chessboard[NextPosition.y][NextPosition.x] != Chess::None)

		PrintBoard();
		if (DetectSpaceBar())
			break;
	}

	return false;
}
