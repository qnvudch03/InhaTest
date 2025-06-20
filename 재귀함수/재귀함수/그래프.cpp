#include <iostream>
#include <vector>

std::vector<bool> bIsaffected(7, false);

void DFS(std::vector<std::vector<int>>& List, int Computerindex = 0)
{
	for (int i = 0; i <= List[Computerindex].size() - 1; i++)
	{
		int EffectedComputer = List[Computerindex][i];

		if (bIsaffected[EffectedComputer] == true)
			continue;

		bIsaffected[EffectedComputer] = true;
		DFS(List, EffectedComputer);
			
	}
}

//깊이 탐색
int main(void)
{
	//만약 컴퓨터 수가 동적이라면 상수를 넣으면 안되겠지
	std::vector<std::vector<int>> Linkedlist(7);

	Linkedlist[0] = { 0, 1, 4 };
	Linkedlist[1] = { 0, 1, 2, 4 };
	Linkedlist[2] = { 1, 2 };
	Linkedlist[3] = { 3, 6 };
	Linkedlist[4] = { 0, 1, 4, 5 };
	Linkedlist[5] = { 4, 5 };
	Linkedlist[6] = { 3, 6 };

	DFS(Linkedlist, 1);

	for (int i = 0; i <= bIsaffected.size() - 1; i++)
	{
		if (bIsaffected[i])
			std::cout << "[ " << i << " ]";
	}
}