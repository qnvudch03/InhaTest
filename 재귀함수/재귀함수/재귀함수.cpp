// 재귀함수.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class MyClass
{
public:
	MyClass() {};
	~MyClass() {};

	int StackNumber(int Number);
	int CalculateEXP(int TargetLevel);

private:

};

int main()
{
	MyClass A;

	int Sum = A.StackNumber(10);

	std::cout << Sum<<std::endl;

	int TotalEXP = A.CalculateEXP(4);

	std::cout << TotalEXP;

}

int MyClass::StackNumber(int Number)
{
	if (Number == 0)
		return 0;

	return Number + StackNumber(Number - 1);
}

int MyClass::CalculateEXP(int TargetLevel)
{
	if (TargetLevel == 0)
		return 0;

	return 100 * (TargetLevel - 1) + CalculateEXP(TargetLevel - 1);
}
