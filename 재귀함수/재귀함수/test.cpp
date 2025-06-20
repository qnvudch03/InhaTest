#include <iostream>
#include <vector>

std::vector<bool> bIsaffected;

void DFS(std::vector<std::vector<int>>& List, int Computerindex = 0)
{
	if (List[Computerindex].size() == 0)
		return; 

	for (int i = 0; i <= List[Computerindex].size() - 1; i++)
	{
		int EffectedComputer = List[Computerindex][i];

		if (bIsaffected[EffectedComputer] == true)
			continue;

		bIsaffected[EffectedComputer] = true;
		DFS(List, EffectedComputer);

	}
}

//±íÀÌ Å½»ö
int main(void)
{
	int ComputerNum = 0;
	std::cin >> ComputerNum;

	int PariNum = 0;
	std::cin >> PariNum;

	std::vector<std::vector<int>> Linkedlist(ComputerNum);
	bIsaffected.resize(ComputerNum, false);

	/*Linkedlist[0] = { 1, 4 };
	Linkedlist[1] = { 0, 2, 4 };
	Linkedlist[2] = { 1 };
	Linkedlist[3] = { 6 };
	Linkedlist[4] = { 0, 1, 5 };
	Linkedlist[5] = { 4 };
	Linkedlist[6] = { 3 };*/

	for (int i = 0; i < PariNum; i++)
	{
		int SelectedComputer = 0;
		std::cin >> SelectedComputer;

		int LinkedComputer = 0;
		std::cin >> LinkedComputer;

		Linkedlist[SelectedComputer - 1].push_back(LinkedComputer - 1);
		Linkedlist[LinkedComputer - 1].push_back(SelectedComputer - 1);
	}

	bIsaffected[0] = true;
	DFS(Linkedlist, 0);

	int Answer = 0;
	for (int i = 1; i <= bIsaffected.size() - 1; i++)
	{
		if (bIsaffected[i])
			//std::cout << "[ " << i << " ]";
			Answer++;
	}

	std::cout << Answer;
}