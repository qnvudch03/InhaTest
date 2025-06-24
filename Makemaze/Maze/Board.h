#pragma once

// #define 
constexpr int BOARD_SIZE = 49;	// �̷� ũ��. �ݵ�� Ȧ�� ����������.

// �� or �� ���� Ÿ��
enum class TileType
{
	NONE,
	EMPTY,	// ����ִ�.
	WALL,	// ��
};

class Player;

// �̷θ� �����ϴ� Ŭ����
class Board
{
public:
	Board(Player* player)
	{
		_player = player;
	}

	// �̷θ� �����ϴ� �Լ�
	void GenerateMap();

	void PrintMap();

	TileType GetTileType(Pos pos);
	Color GetTileColor(Pos pos);
	
	// ��ǥ������ ��ȯ�ϴ� �Լ�
	Pos GetDest() { return _dest; }

private:
	TileType _tile[BOARD_SIZE][BOARD_SIZE] = {};

	// ��ã�� �Ҷ� ��ǥ����
	Pos _dest;

	Player* _player = nullptr;
};

