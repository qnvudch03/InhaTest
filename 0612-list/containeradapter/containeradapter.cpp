// containeradapter.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<char>Container;
	stack<char>Checker;

	char Input = 0;

	bool bIsMatch = false;

	while (true)
	{
		Input = cin.get();
		//cin >> Input;


		if (Input == '\n')
			break;

		else if (Input == '(' || Input == ')')
		{
			Container.push(Input);
		}
	}

	while (true)
	{
		if (Container.empty())
			break;

		char TopChar = Container.top();

		if (TopChar == ')')
		{
			Checker.push(TopChar);
		}

		else
		{
			Checker.pop();
		}

		Container.pop();

	}


	if (Checker.empty())
	{
		std::cout << "서로 매칭합니다.\n";
	}

	else
	{
		std::cout << "서로 다릅니다.\n";
	}

}
