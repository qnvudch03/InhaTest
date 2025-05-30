#include <iostream>
#include <ctime>

using namespace std;

int main(void)
{
	srand((unsigned int)time(NULL));
	int RandomNumber = rand() % 100;

	int Chance = 0;
	int GuessNumber = 0;

	while (true)
	{
		
		std::cout << "숫자를 입력 해 봐요 :  ";
		std::cin >> GuessNumber;
		cout << '\n';

		if (RandomNumber == GuessNumber)
		{
			cout << "\nGoll !!\n";
			break;
		}

		else if (RandomNumber > GuessNumber) { cout << "UP                        "<< "Try : "<<++Chance <<'\n'; }
		else if (RandomNumber < GuessNumber) { cout << "DOWN                        " << "Try : " << ++Chance << '\n'; }
		else
		{
			cout << "Error!!";
			break;
		}

	}

	cout << "Score : " << Chance;
	return 0;
}