#include "White.h"
#include "Board.h"
#include "Util.h"

extern int G_Chessboard[GAMESIZE][GAMESIZE];
bool Turn_White()
{
	//1. ���� ũ���� �ڱ⸸�� �迭�� ����
	//2. �۷ι� ü���ǿ� ����
	//3. ������Ʈ

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
