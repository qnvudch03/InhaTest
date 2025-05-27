// 0527__Pointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <random>

void MultiPlay(int* pRandomArray, int ArraySize)
{
	if (pRandomArray == nullptr)
		return;

	for (int Count = 0; Count < ArraySize; Count++)
	{
		*pRandomArray *= 2;
		pRandomArray ++;
	}
	
}

double Average(int* pRandomArray, int ArraySize)
{
	if (pRandomArray == nullptr)
		return -1;

	double Average = 0;

	for (int Count = 0; Count < ArraySize; Count++)
	{
		Average += *pRandomArray;
		pRandomArray++;
	}

	return Average / ArraySize;
}

int* MaxArray(int* pRandomArray, int ArraySize)
{
	if (pRandomArray == nullptr)
		return nullptr;

	int MaxNumber = -1;
	int* pMaxNumber = nullptr;

	for (int Count = 0; Count < ArraySize; Count++)
	{
		if (*pRandomArray > MaxNumber)
		//if (*pRandomArray > *pMaxNumber)
		{
			MaxNumber = *pRandomArray;
			pMaxNumber = pRandomArray;
		}
		pRandomArray++;
	}
	
	return pMaxNumber;
}

int main()
{
	std::random_device rd;

	int RandomArray[5] = { 0 };

	for (int& RandomNumber : RandomArray)
	{
		RandomNumber = rd() % 100;
	}

	//배열 값 2배 만들기
	MultiPlay(RandomArray, sizeof(RandomArray)/sizeof(int));

	//배열 요소의 평균 구해보기
	double ArrayAverageNumber = Average(RandomArray, sizeof(RandomArray) / sizeof(int));

	int* MaxArrayNumber = MaxArray(RandomArray, sizeof(RandomArray) / sizeof(int));
	std::cout << *MaxArrayNumber << '\n';
}
