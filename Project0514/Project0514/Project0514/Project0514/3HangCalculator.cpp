#include <iostream>

using namespace std;

int main(void)
{
	//Bool dead
	/*int CurrentHP = 0;
	cout << "���� HP : ";
	cin >> CurrentHP;

	bool bIsDead = (CurrentHP > 0) ? false : true;

	if (bIsDead)
		cout << "YOU DIE";
	else
		cout << "YOU LIVE";*/


	//��ū��
	/*int FirstNum = 0;
	int SecondNum = 0;

	cout << "�� ���� �Է��ϼ��� : ";
	cin >> FirstNum >> SecondNum;

	int BiggerNum = (FirstNum > SecondNum) ? FirstNum : SecondNum;

	cout << "�� ū���� : " << BiggerNum;*/

	//¦ Ȧ
	/*int IValue = 0;
	cout << "���ڸ� �Է��ϼ���. ";
	cin >> IValue;

	if (IValue == 0)
		return 0;

	bool IsEvenNum = (IValue % 2 == 0) ? true : false;

	if (IsEvenNum)
		cout << "¦�� �Դϴ�.";

	else
		cout << "Ȧ�� �Դϴ�.";*/

	//�� �� ���� Ȯ��
	int Score = 0;
	cout << "���� ���� : ";
	cin >> Score;

	bool IsPassed = (Score > 60) ? true : false;

	if (IsPassed)
		cout << "\nPASS!!";

	else
		cout << "\nFAIL!!";
	
	return 0;
}