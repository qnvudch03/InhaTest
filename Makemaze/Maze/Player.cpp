#include "pch.h"
#include "Player.h"
#include "Board.h"

int Player::Update()
{
	// _path : 전체 경로를 저장하고 있다. 
	// _pathIndex : 현재 어느 지점을 지나고 있는지
	if (_pathIndex < _path.size())
	{
		// {0,0} -> {0,1} -> {0,2} -> {1,2}
		//							  index
		_pos = _path[_pathIndex];	// Path중에서 어느지점인지 현재 위치 갱신
		_pathIndex++; // 다음 칸 이동

		return 0;
	}

	return 1;
}

void Player::Calculate_RightHand()
{
	// 기존 패스정보는 싹 날리고, 처음부터 길찾기 시작
	_path.clear();

	// 시작 위치부터 길찾기 시작
	_path.push_back(_pos);

	// 목표지점을 알아야 길을 찾을수있다.
	Pos dest = _board->GetDest();

	// 무한으로 검색하느냐? _pos == dest/ 목표지점에 도착할떄까지 무한으로 1,2,3 체크
	// 1. 현재 바라보는 방향을 기준으로, 오른쪽으로 갈수있는지(벽인지or뚫려있는지) 확인
	// 오른쪽이 뚫려있어서 갈수있다? 나의 방향을 회전
	// 한칸 앞으로 이동
	// _path 좌표 기록.

	// 2. 오른쪽이 벽이어서 막혀있다.
	// 현재방향 기준으로 앞으로 갈수있나? 
	// 한칸 앞으로 이동
	// _path 좌표를 기록

	// 3. (1)오른쪽 벽도 막혔고, (2) 앞도 갈수 없다. 반대 방향(왼쪽)으로 회전한다

	while (_pos != dest)
	{
		Pos RightHandPos = GetMyRightHandPos();

		if (_board->GetTileType(RightHandPos) == TileType::EMPTY)
		{
			LotateToRight();
			MoveToDir();
		}

		else if (_board->GetTileType(RightHandPos) == TileType::WALL)
		{
			Pos NextPosition = _pos + delta[(int)_dir];

			if (_board->GetTileType(NextPosition) == TileType::EMPTY)
			{
				MoveToDir();
			}
			else
			{
				LotateToLeft();
			}
		}
	}

}

Pos Player::GetMyRightHandPos()
{
	Pos RightHandPos;

	switch (_dir)
	{
	case MoveDir::MOVE_LEFT:
		RightHandPos = _pos + delta[(int)MoveDir::MOVE_UP];
		break;
	case MoveDir::MOVE_RIGHT:
		RightHandPos = _pos + delta[(int)MoveDir::MOVE_DOWN];
		break;
	case MoveDir::MOVE_UP:
		RightHandPos = _pos + delta[(int)MoveDir::MOVE_RIGHT];
		break;
	case MoveDir::MOVE_DOWN:
		RightHandPos = _pos + delta[(int)MoveDir::MOVE_LEFT];
		break;
	case MoveDir::MOVE_MAX:
		break;
	default:
		break;
	}

	return RightHandPos;
}

void Player::LotateToRight()
{
	switch (_dir)
	{
	case MoveDir::MOVE_LEFT:
		_dir = MoveDir::MOVE_UP;
		break;
	case MoveDir::MOVE_RIGHT:
		_dir = MoveDir::MOVE_DOWN;
		break;
	case MoveDir::MOVE_UP:
		_dir = MoveDir::MOVE_RIGHT;
		break;
	case MoveDir::MOVE_DOWN:
		_dir = MoveDir::MOVE_LEFT;
		break;
	case MoveDir::MOVE_MAX:
		break;
	default:
		break;
	}
}

void Player::LotateToLeft()
{
	switch (_dir)
	{
	case MoveDir::MOVE_LEFT:
		_dir = MoveDir::MOVE_DOWN;
		break;
	case MoveDir::MOVE_RIGHT:
		_dir = MoveDir::MOVE_UP;
		break;
	case MoveDir::MOVE_UP:
		_dir = MoveDir::MOVE_LEFT;
		break;
	case MoveDir::MOVE_DOWN:
		_dir = MoveDir::MOVE_RIGHT;
		break;
	case MoveDir::MOVE_MAX:
		break;
	default:
		break;
	}
}

void Player::Calculate_DFS()
{
	//현 자기위치에서,
	// 4방향의 true를 확인하고, true인 곳으로 들어가서 계속 true true 확인
	// true를 탈 떄 마다, _path에 좌표를 입력
	// false가 반환되면, 재귀를 마치고 다시 원래 위치로 복귀
	// 
	// 트루인 지점이 goll이면 while을 탈출
	//
	std::vector<std::vector<bool>> bAvailable(BOARD_SIZE, std::vector<bool>(BOARD_SIZE));

	for (int y = 0; y < BOARD_SIZE; ++y)
	{
		for (int x = 0; x < BOARD_SIZE; ++x)
		{
			if (_board->GetTileType(Pos{ x,y }) == TileType::EMPTY)
				bAvailable[y][x] = true;
		}
	}

	CheckLextPosition(_pos, bAvailable);
}

void Player::CheckLextPosition(Pos InPos, std::vector<std::vector<bool>>& AvailableList)
{
	//우선 현재 위치를 false로 하고

	if (InPos == _board->GetDest())
	{
		_path.push_back(InPos);
		bIsFinishe = true;
	}

	if (!bIsFinishe)
	{
		AvailableList[InPos.y][InPos.x] = false;
		_path.push_back(InPos);

		for (int i = 0; i < 4; i++)
		{
			Pos NextPos = InPos + delta[i];

			if (AvailableList[NextPos.y][NextPos.x])
			{
				CheckLextPosition(NextPos, AvailableList);
			}
		}
	}

	
}

void Player::MoveToDir()
{
	_pos += delta[(int)_dir];
	_path.push_back(_pos);
}
