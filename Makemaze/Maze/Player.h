#pragma once

class Player
{
public:

	// 내가 바라보는 방향의 다음 좌표
	Pos delta[(int)MoveDir::MOVE_MAX] =
	{
		Pos(-1, 0),	// 왼쪽
		Pos(1, 0),	// 오른쪽
		Pos(0, -1), // 위쪽
		Pos(0, 1),  // 아래쪽

		Pos(-1, -1), //좌상단
		Pos(1, -1), //우상단
		Pos(-1, 1), //좌하단
		Pos(1, 1) //우하단

	};


	void SetBoard(class Board* board) { _board = board; }
	int Update();

	// 우수법
	void Calculate_RightHand();
	Pos GetMyRightHandPos();
	void LotateToRight();
	void LotateToLeft();

	//DFS
	void Calculate_DFS();
	void CheckLextPosition(Pos InPos, std::vector<std::vector<bool>>& AvailableList);
	bool bIsFinishe = false;


	//BFS
	void Calculate_BFS();

	//Dijkstra
	void Calculate_Dijkstra();

	// 현재 위치
	Pos _pos = Pos(1,1);

	void MoveToDir();

	// 길을 찾아가는 과정을 나타내는 변수.
	// 여러개의 위치를 저장해야한다.
	// vector/list/set/map 
	// 길을 찾아갈때 '순서대로' 플레이어가 이동
	vector<Pos> _path; // {0,0} -> {0,1} -> {0,2} -> {1,2}
	int _pathIndex = 0;	// 현재 어느지점을 지나가고 있는지

	// 그냥 보드 정보를 빠르게 접근하기 위해서 멤버변수로 가지고 있자
	class Board* _board = nullptr;

	// 우수법
	MoveDir _dir = MoveDir::MOVE_RIGHT;	// 플레이어의 현재 진행 방향
};

