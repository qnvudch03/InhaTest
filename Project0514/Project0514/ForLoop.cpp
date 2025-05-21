#include <iostream>

using namespace std;

int main(void)
{
	//1부터 10까지 출력
	/*for (int i = 1; i <= 10; i++)
		std::cout << i << '\n';*/

	//10부터 1까지 출력해보기
	/*for (int i = 10; i > 0; i--)
		std::cout << i << '\n';*/

	//1부터 10까지의 숫자의 합 출력 해 보기
	/*int NumSum = 0;

	for (int i = 1; i <= 10; i++)
	{
		NumSum += i;
	}
	std::cout << NumSum << '\n';*/

	//2중 for문으로 구구단 출력 해 보기
	/*for (int BaseNum = 1; BaseNum <= 9; BaseNum++)
	{
		for (int NumMultiPly = 1; NumMultiPly <= 9; NumMultiPly++)
		{
			std::cout << BaseNum << " * " << NumMultiPly << " = " << BaseNum * NumMultiPly << '\n';
		}

		std::cout << "-----end Line-----\n\n";
	}*/


	//10까지의 숫자 중, 짝수만 출력 해 보기
	/*int UserInputValue = -1;

	std::cout << "숫자를 입력 하세요 : ";
	std::cin >> UserInputValue;

	std::cout << '[';

	for (int i = 1; i <= UserInputValue; i++)
	{
		if (i % 2 != 0)
			continue;

		std::cout << ' ' << i;
	}
	std::cout << " ]";*/


	//별찍어보기
	
	int StarNum = 0;
	cout << "별 줄 수 : ";
	cin >> StarNum;

	cout << "\n\n";

	//1단계
	/*for (int i = 1; i <= StarNum; i++)
	{
		for (int stamp = 1; stamp <= i; stamp++)
		{
			cout << '*';
		}
		cout << '\n';
	}*/

	//2단계
	/*for (int i = 1; i <= StarNum; i++)
	{
		for (int stamp = StarNum; stamp >= 1; stamp--)
		{
			if (stamp <= i)
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
	}*/

	//3단계
	/*int Starcount = 1;
	for (int stamp = StarNum; stamp >= 0; stamp--)
	{
		for (int i = 1; i <= stamp; i++)
		{
			cout << ' ';
		}

		for (int i = 1; i <= Starcount; i++)
		{
			cout << '*';
		}
		Starcount += 2;
		cout << '\n';
	}*/

	//4단계
	int Starcount = 1;
	int stamp = 0;
	int BlankIndex = 0;
	int StarIndex = 0;
	for (stamp = StarNum; stamp >= 1; stamp--)
	{
		if (StarNum / 2 >= stamp)
			break;

		for (BlankIndex = 1; BlankIndex <= stamp; BlankIndex++)
		{
			cout << ' ';
		}

		for (StarIndex = 1; StarIndex <= Starcount; StarIndex++)
		{
			cout << '*';
		}
		Starcount += 2;
		cout << '\n';

	}

	//줄이 짝수 줄 일 경우 Startcount만큼 한번 더 출력
	if (StarNum % 2 == 0)
	{
		for (BlankIndex = 1; BlankIndex <= stamp +1; BlankIndex++)
		{
			cout << ' ';
		}

		for (StarIndex = 1; StarIndex <= Starcount - 2; StarIndex++)
		{
			cout << '*';
		}
	}

	for (stamp; stamp >= 0; stamp--)
	{
		cout << '\n';
		for (BlankIndex = 1; BlankIndex <= stamp + 1; BlankIndex++)
		{
			cout << ' ';
		}

		for (StarIndex = 1; StarIndex <= Starcount - 2; StarIndex++)
		{
			cout << '*';
		}
		Starcount -= 2;
	}

	//Count -2 씩 해서, 계속 출력
}