#include <iostream>

using namespace std;

int main(void)
{
	//1���� 10���� ���
	/*for (int i = 1; i <= 10; i++)
		std::cout << i << '\n';*/

	//10���� 1���� ����غ���
	/*for (int i = 10; i > 0; i--)
		std::cout << i << '\n';*/

	//1���� 10������ ������ �� ��� �� ����
	/*int NumSum = 0;

	for (int i = 1; i <= 10; i++)
	{
		NumSum += i;
	}
	std::cout << NumSum << '\n';*/

	//2�� for������ ������ ��� �� ����
	/*for (int BaseNum = 1; BaseNum <= 9; BaseNum++)
	{
		for (int NumMultiPly = 1; NumMultiPly <= 9; NumMultiPly++)
		{
			std::cout << BaseNum << " * " << NumMultiPly << " = " << BaseNum * NumMultiPly << '\n';
		}

		std::cout << "-----end Line-----\n\n";
	}*/


	//10������ ���� ��, ¦���� ��� �� ����
	/*int UserInputValue = -1;

	std::cout << "���ڸ� �Է� �ϼ��� : ";
	std::cin >> UserInputValue;

	std::cout << '[';

	for (int i = 1; i <= UserInputValue; i++)
	{
		if (i % 2 != 0)
			continue;

		std::cout << ' ' << i;
	}
	std::cout << " ]";*/


	//������
	
	int StarNum = 0;
	cout << "�� �� �� : ";
	cin >> StarNum;

	cout << "\n\n";

	//1�ܰ�
	/*for (int i = 1; i <= StarNum; i++)
	{
		for (int stamp = 1; stamp <= i; stamp++)
		{
			cout << '*';
		}
		cout << '\n';
	}*/

	//2�ܰ�
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

	//3�ܰ�
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

	//4�ܰ�
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

	//���� ¦�� �� �� ��� Startcount��ŭ �ѹ� �� ���
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

	//Count -2 �� �ؼ�, ��� ���
}