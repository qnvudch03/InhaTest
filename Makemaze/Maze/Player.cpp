#include "pch.h"
#include "Player.h"
#include "Board.h"
#include <map>
#include <queue>

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

	std::vector<std::vector<bool>> bAvailable(BOARD_SIZE, std::vector<bool>(BOARD_SIZE));

	for (int y = 0; y < BOARD_SIZE; ++y)
	{
		for (int x = 0; x < BOARD_SIZE; ++x)
		{
			if (_board->GetTileType(Pos{ x,y }) == TileType::EMPTY)
				bAvailable[y][x] = true;
		}
	}

	//����Լ� ���
	//{
	////�� �ڱ���ġ����,
	//// 4������ true�� Ȯ���ϰ�, true�� ������ ���� ��� true true Ȯ��
	//// true�� Ż �� ����, _path�� ��ǥ�� �Է�
	//// false�� ��ȯ�Ǹ�, ��͸� ��ġ�� �ٽ� ���� ��ġ�� ����
	//// 
	//// Ʈ���� ������ goll�̸� while�� Ż��
	////

	//	CheckLextPosition(_pos, bAvailable);
	//}


	//���ù��
	{

		//���� �� �濡 ����ִ� stack�� �����.
		// 
		//�濡 ����, ������ ���� �˻��� ��� ���� �� ������ �ִ´�.(_path �߰�)
		//
		std::stack<Pos> Stack;
		Stack.push(_pos);

		do
		{
			//���� ���� �� Ȯ��
			Pos CurrentPos = Stack.top();

			//�������� ���ٸ� Ż��
			if (CurrentPos == _board->GetDest())
			{
				_path.push_back(CurrentPos);
				break;
			}

			//�̹� �湮�ߴ� ���̸� Ż��
			if (bAvailable[CurrentPos.y][CurrentPos.x] == false)
				continue;

			//���ο� �濡���� ó��
			bAvailable[CurrentPos.y][CurrentPos.x] = false;
			Stack.pop();

			for (int i = 0; i < 4; i++)
			{
				Pos NextPos = CurrentPos + delta[i];

				if (bAvailable[NextPos.y][NextPos.x])
				{
					Stack.push(NextPos);
					_path.push_back(NextPos);
				}
			}

		} while (!(Stack.empty()));
	}
	
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

void Player::Calculate_BFS()
{
	std::vector<std::vector<bool>> bAvailable(BOARD_SIZE, std::vector<bool>(BOARD_SIZE));

	for (int y = 0; y < BOARD_SIZE; ++y)
	{
		for (int x = 0; x < BOARD_SIZE; ++x)
		{
			if (_board->GetTileType(Pos{ x,y }) == TileType::EMPTY)
				bAvailable[y][x] = true;
		}
	}

	//�߰��� ����� �����ؾ� �Ѵ�.
	// 
	// �� ��庰 ���� ó�� �߰ߵ� ��带 üũ, �׸��� �ڽ��� �߰߳��� �θ� ��带 ����
	// ��带 '�߰� ��忡 ����'
	// 
	// ��ǥ�� �߰��� ��带 �߰��� ��带 �߰��� ------- ���ʳ�带 
	// �߰��� ����� �ڱ� �ڽ��� �� ���� ��� ã��

	std::map<Pos, Pos> NodeFinderMap;
	std::queue<Pos> ToDoQueue;
	std::stack<Pos> ResultPath;

	ToDoQueue.push(_pos);

	//key �� : �ڱ� ��� Pos, Value : ã���� ��� Pos
	NodeFinderMap.insert(std::make_pair(_pos, _pos));

	while (!ToDoQueue.empty())
	{
		Pos CurrentPos = ToDoQueue.front();
		bAvailable[CurrentPos.y][CurrentPos.x] = false;
		ToDoQueue.pop();

		//������ �̵������� ��� ã��
		for (int i = 0; i < 4; i++)
		{
			Pos NextPos = CurrentPos + delta[i];

			//ã�Ҵ�!
			if (bAvailable[NextPos.y][NextPos.x])
			{
				//������ NextPos�� ���� �ߺ����� ���õȴ�.(���� ���� �߰��� ���� ����ȴ�)
				NodeFinderMap.insert(std::make_pair(NextPos, CurrentPos));
				ToDoQueue.push(NextPos);
			}
		}
	}

	//ã�� Pos�� key ������ ���� Pos�� ã��, �װ� key ������ ���� Pos ã��, �װ� �ٽ�...
	Pos Target = _board->GetDest();
	while (true)
	{
		auto iter = NodeFinderMap.find(Target);

		//if(iter->first == iter->second)
		if ((iter->first.x == iter->second.x) && (iter->first.y == iter->second.y))
		{
			break;
		}

		ResultPath.push(iter->second);
		Target = iter->second;
	}

	//��� stack�� ���ִ� �����͸� �ݴ�� _path�� ����
	while (!ResultPath.empty())
	{
		_path.push_back(ResultPath.top());
		ResultPath.pop();
	}

	//������ ������ �ּ� �Ѱ��ֱ�
	_path.push_back(_board->GetDest());
}

void Player::Calculate_Dijkstra()
{
	std::vector<std::vector<bool>> bAvailable(BOARD_SIZE, std::vector<bool>(BOARD_SIZE));

	for (int y = 0; y < BOARD_SIZE; ++y)
	{
		for (int x = 0; x < BOARD_SIZE; ++x)
		{
			if (_board->GetTileType(Pos{ x,y }) == TileType::EMPTY)
				bAvailable[y][x] = true;
		}
	}

	struct Pos2
	{
		Pos MyPos;
		Pos ParentPos;

		int cost = 0;

		Pos2(Pos Chile, Pos Parent, int cost) : MyPos(Chile), ParentPos(Parent), cost(cost) {}
	};


	//���� ����� ���� ã�°� �¾�
	//��� ���� �ʿ��ϴ�
	//�� Pos�� �ڱ��� ��ġ ����, ��������� �ڱⰡ �� ��° �ڽ�Ʈ ������ ������ �ִ�.

	std::vector<Pos2> CostVector;
	std::queue<Pos2> ToDoQueue;
	std::stack<Pos> ResultStack;

	int Cost = 0;
	ToDoQueue.push(Pos2{ _pos, _pos, 0 });
	
	CostVector.push_back(Pos2{ _pos, _pos, 0});

	while (!ToDoQueue.empty())
	{
		Pos2 CurrentPos = ToDoQueue.front();
		bAvailable[CurrentPos.MyPos.y][CurrentPos.MyPos.x] = false;
		ToDoQueue.pop();

		if (CurrentPos.MyPos == _board->GetDest())
		{
			CostVector.push_back(CurrentPos);
			break;
		}

		for (int i = 0; i < (int)MoveDir::MOVE_MAX; i++)
		{
			Pos NextPos = CurrentPos.MyPos + delta[i];

			//ã�Ҵ�!
			if (bAvailable[NextPos.y][NextPos.x])
			{
				{
					Cost = CurrentPos.cost + 1;
					//Cost = (i <= 3) ? CurrentPos.cost + 1 : CurrentPos.cost + 1.4;
					Pos2 NewPos = Pos2{ NextPos , CurrentPos.MyPos , Cost };

					CostVector.push_back(NewPos);
					ToDoQueue.push(NewPos);
				}
				
			}
		}

	}

	auto TargetPos = CostVector.end() - 1;
	while (true)
	{
		ResultStack.push(TargetPos->MyPos);
		Pos ParentPos = TargetPos->ParentPos;
		int TargetCost = TargetPos->cost - 1;

		if (TargetCost == 0)
			break;

		while (true)
		{
			auto Iter = CostVector.end() - 1;

			if ((Iter->cost != TargetCost) || (Iter->MyPos) != ParentPos)
				Iter = CostVector.erase(Iter);
			else
			{
				TargetPos = Iter;
				break;
			}
		}

		
	}

	//��� stack�� ���ִ� �����͸� �ݴ�� _path�� ����
	while (!ResultStack.empty())
	{
		_path.push_back(ResultStack.top());
		ResultStack.pop();
	}

}

void Player::MoveToDir()
{
	_pos += delta[(int)_dir];
	_path.push_back(_pos);
}
