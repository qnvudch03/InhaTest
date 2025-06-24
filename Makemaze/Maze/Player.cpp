#include "pch.h"
#include "Player.h"
#include "Board.h"
#include <map>
#include <queue>

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

	std::vector<std::vector<bool>> bAvailable(BOARD_SIZE, std::vector<bool>(BOARD_SIZE));

	for (int y = 0; y < BOARD_SIZE; ++y)
	{
		for (int x = 0; x < BOARD_SIZE; ++x)
		{
			if (_board->GetTileType(Pos{ x,y }) == TileType::EMPTY)
				bAvailable[y][x] = true;
		}
	}

	//재귀함수 방식
	//{
	////현 자기위치에서,
	//// 4방향의 true를 확인하고, true인 곳으로 들어가서 계속 true true 확인
	//// true를 탈 떄 마다, _path에 좌표를 입력
	//// false가 반환되면, 재귀를 마치고 다시 원래 위치로 복귀
	//// 
	//// 트루인 지점이 goll이면 while을 탈출
	////

	//	CheckLextPosition(_pos, bAvailable);
	//}


	//스택방식
	{

		//들어가야 할 방에 들어있는 stack을 만든다.
		// 
		//방에 들어가면, 인접한 방을 검색해 들어 가야 할 방으로 넣는다.(_path 추가)
		//
		std::stack<Pos> Stack;
		Stack.push(_pos);

		do
		{
			//들어온 현재 방 확인
			Pos CurrentPos = Stack.top();

			//목적지와 같다면 탈출
			if (CurrentPos == _board->GetDest())
			{
				_path.push_back(CurrentPos);
				break;
			}

			//이미 방문했던 방이면 탈출
			if (bAvailable[CurrentPos.y][CurrentPos.x] == false)
				continue;

			//새로운 방에대한 처리
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

	//발견한 사람을 관리해야 한다.
	// 
	// 각 노드별 가장 처음 발견된 노드를 체크, 그리고 자신의 발견노드로 부모 노드를 지정
	// 노드를 '발견 노드에 저장'
	// 
	// 목표를 발견한 노드를 발견한 노드를 발견한 ------- 최초노드를 
	// 발견한 사람이 자기 자신일 떄 까지 계속 찾기

	std::map<Pos, Pos> NodeFinderMap;
	std::queue<Pos> ToDoQueue;
	std::stack<Pos> ResultPath;

	ToDoQueue.push(_pos);

	//key 값 : 자기 노드 Pos, Value : 찾은놈 노드 Pos
	NodeFinderMap.insert(std::make_pair(_pos, _pos));

	while (!ToDoQueue.empty())
	{
		Pos CurrentPos = ToDoQueue.front();
		bAvailable[CurrentPos.y][CurrentPos.x] = false;
		ToDoQueue.pop();

		//주위에 이동가능한 노드 찾기
		for (int i = 0; i < 4; i++)
		{
			Pos NextPos = CurrentPos + delta[i];

			//찾았다!
			if (bAvailable[NextPos.y][NextPos.x])
			{
				//동일한 NextPos에 대한 중복값은 무시된다.(제일 먼저 발견한 놈이 저장된다)
				NodeFinderMap.insert(std::make_pair(NextPos, CurrentPos));
				ToDoQueue.push(NextPos);
			}
		}
	}

	//찾을 Pos를 key 값으로 가진 Pos를 찾고, 그걸 key 값으로 가진 Pos 찾고, 그걸 다시...
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

	//결과 stack에 들어가있는 데이터를 반대로 _path에 저장
	while (!ResultPath.empty())
	{
		_path.push_back(ResultPath.top());
		ResultPath.pop();
	}

	//마지막 목적지 주소 넘겨주기
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


	//가장 가까운 놈을 찾는건 맞아
	//비용 맵이 필요하다
	//각 Pos는 자기위 위치 값과, 출발점에서 자기가 몇 번째 코스트 값인지 가지고 있다.

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

			//찾았다!
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

	//결과 stack에 들어가있는 데이터를 반대로 _path에 저장
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
