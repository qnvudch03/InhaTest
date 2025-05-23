#include "White.h"
#include "Board.h"
#include "Util.h"

extern int G_Chessboard[GAMESIZE][GAMESIZE];
bool Turn_White()
{
	//1. ���� ũ���� �ڱ⸸�� �迭�� ����
	//2. �۷ι� ü���ǿ� ����
	//3. ������Ʈ

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
