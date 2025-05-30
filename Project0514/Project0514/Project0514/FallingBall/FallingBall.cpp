#include "pch.h"    
#include "Helper.h"
#include <Windows.h>

void EnableMemoryLeakDetection() 
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

int main()
{
    EnableMemoryLeakDetection();

    SetCursorOnOff(false);

    while (true)
    {
        SetCursorPosition(0, 0);

        //if (spawnTimer++ % 3 == 0) // 5프레임마다 공 생성
        //{
        //    SpawnBall();
        //}

        //MoveDir input = HandleKeyInput();

        //UpdateBalls();
        //UpdatePlayer(input);

        //PrintMap();

        // 입력
        
        // 로직
        
        // 출력

        Sleep(100); // 0.1초 대기 (프레임 간격)
    }
}
