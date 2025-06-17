#include <iostream>

#include <map>

int main(void)
{
	//������� �ƹ��� ���ڰ� �Էµ� ���̴�. (���ڸ� �̸� ���� �� ����. �Էµ� ���ڿ� ���ڸ� �� �ִ� ���)
	//�� ���ڰ� �� �� ���Դ��� ���� �Ѵ�.
	// ���ڸ� key ������ map�� �����, ������Դ����� value�� ++


	char InputValue = 0;
	std::map<char, int> charCountMap;

	std::cout << "======================\n";
	std::cout << "�Է¹��� : ";

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
		std::cout << iter.first << " �� ���� Ƚ�� : " << iter.second << '\n';
	}

	return 0;
}