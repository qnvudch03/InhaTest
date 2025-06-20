#include "pch.h"
#include "Board.h"
#include "Player.h"

void Board::GenerateMap()
{
	_dest.x = BOARD_SIZE - 2;
	_dest.y = BOARD_SIZE - 2;

	// y, x ��ȸ �� or ������� �����.
	for (int y = 0; y < BOARD_SIZE; ++y)
	{
		for (int x = 0; x < BOARD_SIZE; ++x)
		{
			// 1�ܰ�. ¦����°�� ������ �����Ѵ�.
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
	// ����, �����ϰ� ������ or �Ʒ������� ���� �����.(TileType::WALL -> TileType::EMPTY)
	// ��ü�� ��ȸ�ϸ鼭 
	for (int y = 1; y < BOARD_SIZE-1; ++y)
	{
		for (int x = 1; x < BOARD_SIZE-1; ++x)
		{
			// ������
			if (x == BOARD_SIZE - 2 && y == BOARD_SIZE - 2)
			{
				continue;
			}

			// 1) ¦���� ����
			if (x % 2 == 0 || y % 2 == 0)
			{
				// �̹� ���̶� ��ŵ
				continue;
			}

			// 2) ���� ������ X �̸� �Ʒ��� ���� �մ´�.
			if (x == BOARD_SIZE - 2) // �������� ������ ���̶� �ɷ����.
			{
				_tile[y + 1][x] = TileType::EMPTY;
				continue;
			}

			// 3) ���� ������ Y �̸�, ���������� ���� �մ´�.
			if (y == BOARD_SIZE - 2) // �������� ������ ���̶� �ɷ����.
			{
				_tile[y][x + 1] = TileType::EMPTY;
				continue;
			}

			// 4) �����ϰ� ������ or �Ʒ����� ���� �մ´�.
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
			cout << "��";
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

	// �÷��̾��� ��ġ�� ���ٸ� ������
	if (_player->_pos == pos)
	{
		return Color::Red;
	}

	// ��ǥ������ ��ġ�� ���ٸ� �Ͼ��
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