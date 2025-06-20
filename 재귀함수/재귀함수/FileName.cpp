#include <iostream>
#include <vector>

std::vector<bool> bIsaffected;

void DFS(std::vector<std::vector<int>>& List, int Computerindex = 0)
{
	for (int i = 0; i < List[Computerindex].size(); i++)
	{
		int EffectedComputer = List[Computerindex][i];

		if (bIsaffected[EffectedComputer])
			continue;

		bIsaffected[EffectedComputer] = true;
		DFS(List, EffectedComputer);
	}
}

int main(void)
{
	int ComputerNum = 0;
	std::cin >> ComputerNum;

	int PariNum = 0;
	std::cin >> PariNum;

	std::vector<std::vector<int>> Linkedlist(ComputerNum);
	bIsaffected.resize(ComputerNum, false);

	for (int i = 0; i < PariNum; i++)
	{
		int A, B;
		std::cin >> A >> B;

		Linkedlist[A - 1].push_back(B - 1);
		Linkedlist[B - 1].push_back(A - 1); // 양방향
	}

	bIsaffected[0] = true;
	DFS(Linkedlist, 0);

	int Answer = 0;
	for (int i = 1; i < bIsaffected.size(); i++) // 1번 컴퓨터 제외
	{
		if (bIsaffected[i])
			Answer++;
	}

	std::cout << Answer;
}