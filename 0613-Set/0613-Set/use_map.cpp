#include <iostream>

#include <map>

int main(void)
{
	//제약없는 아무런 문자가 입력될 것이다. (문자를 미리 정할 수 없다. 입력된 문자와 숫자를 세 주는 기능)
	//각 문자가 몇 번 나왔는지 세야 한다.
	// 문자를 key 값으로 map을 만들고, 몇번나왔는지는 value로 ++


	char InputValue = 0;
	std::map<char, int> charCountMap;

	std::cout << "======================\n";
	std::cout << "입력문자 : ";

	while (true)
	{
		InputValue = std::cin.get();

		if (InputValue == '\n')
			break;

		if (charCountMap.find(InputValue) == charCountMap.end())
		{
			charCountMap.insert(std::make_pair(InputValue, 1));
		}

		else
		{
			charCountMap[InputValue] += 1;
		}

	}

	for (auto iter : charCountMap)
	{
		std::cout << iter.first << " 의 등장 횟수 : " << iter.second << '\n';
	}

	return 0;
}