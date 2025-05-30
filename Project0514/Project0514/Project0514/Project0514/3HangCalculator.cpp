#include <iostream>

using namespace std;

int main(void)
{
	//Bool dead
	/*int CurrentHP = 0;
	cout << "현재 HP : ";
	cin >> CurrentHP;

	bool bIsDead = (CurrentHP > 0) ? false : true;

	if (bIsDead)
		cout << "YOU DIE";
	else
		cout << "YOU LIVE";*/


	//더큰수
	/*int FirstNum = 0;
	int SecondNum = 0;

	cout << "두 수를 입력하세요 : ";
	cin >> FirstNum >> SecondNum;

	int BiggerNum = (FirstNum > SecondNum) ? FirstNum : SecondNum;

	cout << "더 큰수는 : " << BiggerNum;*/

	//짝 홀
	/*int IValue = 0;
	cout << "숫자를 입력하세요. ";
	cin >> IValue;

	if (IValue == 0)
		return 0;

	bool IsEvenNum = (IValue % 2 == 0) ? true : false;

	if (IsEvenNum)
		cout << "짝수 입니다.";

	else
		cout << "홀수 입니다.";*/

	//합 불 여부 확인
	int Score = 0;
	cout << "너의 점수 : ";
	cin >> Score;

	bool IsPassed = (Score > 60) ? true : false;

	if (IsPassed)
		cout << "\nPASS!!";

	else
		cout << "\nFAIL!!";
	
	return 0;
}