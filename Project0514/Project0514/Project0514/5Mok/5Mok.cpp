// 5Mok.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include "Black.h"
#include "White.h"
#include "Board.h"

#define GAMESIZE 10

//오목판
int G_Chessboard[GAMESIZE][GAMESIZE] = {};

using namespace std;

int main()
{
	bool WhiteTurn = true;

	while (true)
	{
		Turn_White();

		Turn_Black();


		//반환이 false변 게임종료 탈출
		int stop = 0;
		std::cin >> stop;
	}
}
