#pragma once

// #define 
constexpr int BOARD_SIZE = 49;	// 미로 크기. 반드시 홀수 개수여야함.

// 벽 or 빈 공간 타입
enum class TileType
{
	NONE,
	EMPTY,	// 비어있다.
	WALL,	// 벽
};

class Player;

// 미로를 관리하는 클래스
class Board
{
public:
	Board(Player* player)
	{
		_player = player;
	}

	// 미로를 생성하는 함수
	void GenerateMap();

	void PrintMap();

	TileType GetTileType(Pos pos);
	Color GetTileColor(Pos pos);
	
	// 목표지점을 반환하는 함수
	Pos GetDest() { return _dest; }

private:
	TileType _tile[BOARD_SIZE][BOARD_SIZE] = {};

	// 길찾기 할때 목표지점
	Pos _dest;

	Player* _player = nullptr;
};

