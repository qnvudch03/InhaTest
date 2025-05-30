#include <iostream>

int SelectMenu()
{
	int InputValue = 0;

	std::cout << "1. 게임 시작\n"
		<< "2. 설정\n"
		<< "3. 종료\n";

	std::cin >> InputValue;

	return InputValue;
}

int main(void)
{
	std::cout << "메뉴를 선택하세요.\n";

	int SelectIndex = SelectMenu();

	switch (SelectIndex)
	{
	case 1:
		std::cout << "게임 시작\n";
		break;
	case 2:
		std::cout << "설정 시작\n";
		break;
	case 3:
		std::cout << "게임 종료\n";
		break;
	default:
		break;
	}

	return 0;
}
