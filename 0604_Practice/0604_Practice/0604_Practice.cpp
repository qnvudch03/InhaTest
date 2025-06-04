// 0604_Practice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//문자열의 길이를 반출력
void MyStrlen(const char* src)
{
    int Strlen = 0;

    //한글은 2배
    while (*src)
    {
        char Temp = *src;
        Strlen++;
        src++;
    }

    std::cout << Strlen << std::endl;
}

//문자열을 dest애 복사한다.
void MyStrcpy(char* dest, const char* src)
{
    int charIndex = 0;
    while (true)
    {
        if (src[charIndex] == 0)
        {
            dest[charIndex] = 0;
            break;
        }
            
        dest[charIndex] = src[charIndex];

        charIndex++;
    }

    std::cout << dest<<std::endl;
}

//문자열을 이어 붙인다
void MyStrcat(char* dest, const char* src)
{
    // 초기화 되지 않은 빈 문자열일 들어왔을 땐 문제가 생긴다,  ? 근데 어떤 값이 들어가 있을 줄 알고 예외처리를 하지???
    //원본 문자열의 끝 위치 확인
    int ArrayEndIndex = 0;

    while (true)
    {
        if (dest[ArrayEndIndex] == NULL)
            break;
        ArrayEndIndex++;
    }


    //복붙
    while (*src)
    {
        dest[ArrayEndIndex] = *src;
        ArrayEndIndex++;
        src++;
    }

    dest[ArrayEndIndex] = 0;
    std::cout << dest<<std::endl;

}

//문자열 뒤집기
void MyStrReverse(char* dest, const char* src)
{
    //src의 문자열 끝 위치 찾기
    int ArrayEndIndex = 0;

    while (true)
    {
        if (src[ArrayEndIndex] == NULL)
            break;
        ArrayEndIndex++;
    }

    //종료 문자 넣어주기
    dest[ArrayEndIndex] = 0;

    //리버스 복붙
    for (ArrayEndIndex; ArrayEndIndex > 0; ArrayEndIndex--)
    {
        dest[ArrayEndIndex - 1] = *src;
        src++;
    }

    std::cout << dest << std::endl;
}

int main()
{
    const char* TestChar = "What Happend";
    const char* Hangle = "한글";
    const wchar_t* Hangle2 = L"한글";

    int Size = sizeof(Hangle2);
    int Size2 = sizeof(TestChar);

    MyStrlen(Hangle);

    int array[] = {0, 5};

    char CharArray1[100];
    char CharArray2[100];
    char CharArray3[100];

    MyStrcpy(CharArray1, TestChar);
    MyStrcat(CharArray1, TestChar);
    MyStrReverse(CharArray2, TestChar);
}
