#pragma once

class Player
{
public:

	// ���� �ٶ󺸴� ������ ���� ��ǥ
	Pos delta[(int)MoveDir::MOVE_MAX] =
	{
		Pos(-1, 0),	// ����
		Pos(1, 0),	// ������
		Pos(0, -1), // ����
		Pos(0, 1),  // �Ʒ���

		Pos(-1, -1), //�»��
		Pos(1, -1), //����
		Pos(-1, 1), //���ϴ�
		Pos(1, 1) //���ϴ�

	};


	void SetBoard(class Board* board) { _board = board; }
	int Update();

	// �����
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

	// ���� ��ġ
	Pos _pos = Pos(1,1);

	void MoveToDir();

	// ���� ã�ư��� ������ ��Ÿ���� ����.
	// �������� ��ġ�� �����ؾ��Ѵ�.
	// vector/list/set/map 
	// ���� ã�ư��� '�������' �÷��̾ �̵�
	vector<Pos> _path; // {0,0} -> {0,1} -> {0,2} -> {1,2}
	int _pathIndex = 0;	// ���� ��������� �������� �ִ���

	// �׳� ���� ������ ������ �����ϱ� ���ؼ� ��������� ������ ����
	class Board* _board = nullptr;

	// �����
	MoveDir _dir = MoveDir::MOVE_RIGHT;	// �÷��̾��� ���� ���� ����
};

