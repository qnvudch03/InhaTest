#include "pch.h"
#include "Board.h"
#include "Player.h"

void Board::GenerateMap()
{
	_dest.x = BOARD_SIZE - 2;
	_dest.y = BOARD_SIZE - 2;

	// y, x 순회 벽 or 빈공간을 만든다.
	for (int y = 0; y < BOARD_SIZE; ++y)
	{
		for (int x = 0; x < BOARD_SIZE; ++x)
		{
			// 1단계. 짝수번째는 벽으로 설정한다.
			if (x % 2 == 0 || y % 2 == 0)
			{
				_tile[y][x] = TileType::WALL;
			}
			else
			{
				_tile[y][x] = TileType::EMPTY;
			}
		}
	}

	// Binary Tree Maze
	// 이제, 랜덤하게 오른쪽 or 아래쪽으로 길을 만든다.(TileType::WALL -> TileType::EMPTY)
	// 전체를 순회하면서 
	for (int y = 1; y < BOARD_SIZE-1; ++y)
	{
		for (int x = 1; x < BOARD_SIZE-1; ++x)
		{
			// 마지막
			if (x == BOARD_SIZE - 2 && y == BOARD_SIZE - 2)
			{
				continue;
			}

			// 1) 짝수는 제외
			if (x % 2 == 0 || y % 2 == 0)
			{
				// 이미 벽이라서 스킵
				continue;
			}

			// 2) 제일 마지막 X 이면 아래로 길을 뚫는다.
			if (x == BOARD_SIZE - 2) // 마지막은 무조건 벽이라서 걸렀어요.
			{
				_tile[y + 1][x] = TileType::EMPTY;
				continue;
			}

			// 3) 제일 마지막 Y 이면, 오른쪽으로 길을 뚫는다.
			if (y == BOARD_SIZE - 2) // 마지막은 무조건 벽이라서 걸렀어요.
			{
				_tile[y][x + 1] = TileType::EMPTY;
				continue;
			}

			// 4) 랜덤하게 오른쪽 or 아래쪽을 길을 뚫는다.
			if (rand() % 2 == 0)
			{
				_tile[y][x + 1] = TileType::EMPTY;
			}
			else
			{
				_tile[y + 1][x] = TileType::EMPTY;
			}
		}
	}

}

void Board::PrintMap()
{
	SetCursorPosition(0, 0);

	for (int y = 0; y < BOARD_SIZE; ++y)
	{
		for (int x = 0; x < BOARD_SIZE; ++x)
		{
			Color color = GetTileColor(Pos(x, y));
			SetCursorColor(color);
			cout << "■";
		}

		cout << endl;
	}
}

TileType Board::GetTileType(Pos pos)
{
	if (pos.x < 0 || pos.x >= BOARD_SIZE)
		return TileType::NONE;
	if (pos.y < 0 || pos.y >= BOARD_SIZE)
		return TileType::NONE;

	return _tile[pos.y][pos.x];
}

Color Board::GetTileColor(Pos pos)
{
	TileType tileType = GetTileType(pos);

	// 플레이어의 위치와 같다면 빨간색
	if (_player->_pos == pos)
	{
		return Color::Red;
	}

	// 목표지점의 위치와 같다면 하얀색
	if (pos == _dest)
	{
		return Color::White;
	}

	if (tileType == TileType::WALL)
	{
		return Color::Blue;
	}

	if (tileType == TileType::EMPTY)
	{
		return Color::RightGreen;
	}

	return Color::Default;
}