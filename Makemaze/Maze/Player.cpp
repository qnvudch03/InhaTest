#include "pch.h"
#include "Player.h"
#include "Board.h"

int Player::Update()
{
	// _path : ��ü ��θ� �����ϰ� �ִ�. 
	// _pathIndex : ���� ��� ������ ������ �ִ���
	if (_pathIndex < _path.size())
	{
		// {0,0} -> {0,1} -> {0,2} -> {1,2}
		//							  index
		_pos = _path[_pathIndex];	// Path�߿��� ����������� ���� ��ġ ����
		_pathIndex++; // ���� ĭ �̵�

		return 0;
	}

	return 1;
}

void Player::Calculate_RightHand()
{
	// ���� �н������� �� ������, ó������ ��ã�� ����
	_path.clear();

	// ���� ��ġ���� ��ã�� ����
	_path.push_back(_pos);

	// ��ǥ������ �˾ƾ� ���� ã�����ִ�.
	Pos dest = _board->GetDest();

	// �������� �˻��ϴ���? _pos == dest/ ��ǥ������ �����ҋ����� �������� 1,2,3 üũ
	// 1. ���� �ٶ󺸴� ������ ��������, ���������� �����ִ���(������or�շ��ִ���) Ȯ��
	// �������� �շ��־ �����ִ�? ���� ������ ȸ��
	// ��ĭ ������ �̵�
	// _path ��ǥ ���.

	// 2. �������� ���̾ �����ִ�.
	// ������� �������� ������ �����ֳ�? 
	// ��ĭ ������ �̵�
	// _path ��ǥ�� ���

	// 3. (1)������ ���� ������, (2) �յ� ���� ����. �ݴ� ����(����)���� ȸ���Ѵ�

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
	//�� �ڱ���ġ����,
	// 4������ true�� Ȯ���ϰ�, true�� ������ ���� ��� true true Ȯ��
	// true�� Ż �� ����, _path�� ��ǥ�� �Է�
	// false�� ��ȯ�Ǹ�, ��͸� ��ġ�� �ٽ� ���� ��ġ�� ����
	// 
	// Ʈ���� ������ goll�̸� while�� Ż��
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
	//�켱 ���� ��ġ�� false�� �ϰ�

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
