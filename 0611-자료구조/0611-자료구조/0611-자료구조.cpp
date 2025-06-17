// 0611-자료구조.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <random>

#include <algorithm>

const int NumRoterry = 6;

//void CheckOverlab(std::vector* vectorarray);
bool CheckOverlab(std::vector<int>& Numbers);
bool NoneRoundcheck(std::vector<int>& Numbers);
bool MakeNoneOverlabNumbers(std::vector<int>& Numbers);
bool CheckOverlab2(std::vector<int>& Numbers, int RandomNumber);

int main()
{
	std::vector<int> number(NumRoterry, 0);
	std::vector<int>::iterator it = number.begin();

	for (it; it != number.end(); it++)
	{
		std::random_device rd;
		*it = (rd() % 45) + 1;
	}

	/*if (CheckOverlab(number))
	{
		std::cout << "중복이 발생\n";
	}

	else
	{
		std::cout << "중복 없음\n";
	}*/

	if (NoneRoundcheck(number))
	{
		std::cout << "중복이 발생\n";
	}

	else
	{
		std::cout << "중복 없음\n";
	}

}

bool CheckOverlab(std::vector<int>& Numbers)
{
	std::vector<int>::iterator it = Numbers.begin();

	int my = 0;
	int ndex = 0;

	for (int a = 0; a < NumRoterry; a++)
	{
		for (int index = a; index < NumRoterry - 1; index++)
		{
			my = Numbers[a];
			ndex = Numbers[index + 1];

			if (my == ndex)
				return true;
		}
	}

	return false;
	
	
}

bool NoneRoundcheck(std::vector<int>& Numbers)
{
	std::vector<int>::iterator it = Numbers.begin();
	std::sort(Numbers.begin(), Numbers.end() - 1);

	int My = 0;
	int Target = 0;

	for (it; it != Numbers.end() - 1;)
	{
		My = *it;
		Target = *(++it);

		if (My == Target)
			return true;
	}

	return false;
}

bool MakeNoneOverlabNumbers(std::vector<int>& Numbers)
{


	return false;
}

bool CheckOverlab2(std::vector<int>& Numbers, int RandomNumber)
{
	return false;
}
