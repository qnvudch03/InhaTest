// 0529-Practice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <random>

void swap(int& FirstNum, int& SecondNum)
{
    int Temp = FirstNum;

    FirstNum = SecondNum;

    SecondNum = Temp;
}

void RandomDeath(int& PlyaerHP, int& MonsterHP)
{
    std::random_device rd;
    int RandomNumber = rd() & 1;

    // 1 or 0 배출
    if (RandomNumber)
        PlyaerHP = 0;
    else
        MonsterHP = 0;
}

int main()
{
    int A = 7;
    int B = 13;

    int* pA = &A;

    int** ppA = &pA;

    int*& rpA = pA;

    swap(A, B);

    RandomDeath(A, B);
}
