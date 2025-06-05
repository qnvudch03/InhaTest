// warrior.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "Archor.h"
#include "Magician.h"
#include "Soldier.h"

#include <random>

#include <iostream>

int main()
{
    std::random_device rd;

    int randomnumber = rd() & 3;
    std::cout << "Hello World!\n";
}
