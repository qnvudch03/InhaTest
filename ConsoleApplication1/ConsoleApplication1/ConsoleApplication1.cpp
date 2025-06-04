// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    int A[5] = { 13, 15, 10, 11, 14 };

    int* pA = A;

    int Number1 = A[1];

    int Number2 = *pA;

    int Number3 = *(pA + 4);

    int Number4 = pA[3];

}
