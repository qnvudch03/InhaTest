#include "Board.h"

extern int G_Chessboard[GAMESIZE][GAMESIZE];

void UpdateChess()
{
	SetCursorPosition(0,0);
	SetCursorOnOff(false);
}

void PrintBoard()
{
	SetCursorPosition(0, 0);
	for (int Row = 0; Row < GAMESIZE; Row++)
	{
		for (int column = 0; column < GAMESIZE; column++)
		{
			switch (G_Chessboard[Row][column])
			{
			case Chess::White :
				std::cout << "��";
				break;
			case Chess::Black:
				std::cout << "��";
				break;
			case Chess::None:
				std::cout << "��";
				break;
			default:
				break;
			}

		}
		std::cout << '\n';
	}
}
