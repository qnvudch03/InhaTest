#include "pch.h"
#include "Helper.h"
#include "BallMap.h"
#include "PlayerBall.h"

#include <Windows.h>
#include <random>

#define MAX_BALLNUMBER 7



const char* Map[MAP_WIDTH][MAP_HEIGHT];
Position NullPosition;

void ClearMap();
Position* MakeNewBall();

Position* BallManagerArray[MAX_ARRAYBALL];

int main()
{
    //입력

    //로직

    //출력


    SetCursorOnOff(false);

    Position PlayerPosition = { MAP_WIDTH /2, MAP_HEIGHT-1};

    int FrameCount = 3;

    while (true)
    {
        FrameCount--;

        if (FrameCount == 0)
        {
            //공을 새로이 할당

            for (int BallIndex = 0; BallIndex < MAX_ARRAYBALL; BallIndex++)
            {
                if (BallManagerArray[BallIndex] != nullptr)
                    continue;

                Position* NewBall = MakeNewBall();
                BallManagerArray[BallIndex] = NewBall;
                break;
            }

            FrameCount = 3;
        }

        ClearMap();

        MoveDir PlayerInput = HandleKeyInput();

        BallMap::UpdateBall();

        UpdatePlayer(&PlayerPosition, PlayerInput);

        BallMap::PrintMap(&PlayerPosition);

        if (BallMap::CheckCollision(&PlayerPosition))
        {
            break;
        }

        Sleep(50);

    }
}

void ClearMap()
{
    SetCursorPosition(0, 0);

    for (int horizon = 0; horizon < MAP_HEIGHT; horizon++)
    {
        for (int vertical = 0; vertical < MAP_WIDTH; vertical++)
        {
            std::cout << "□";
        }
        std::cout << '\n';
    }

    SetCursorPosition(0, 0);
}

Position* MakeNewBall()
{
    Position* NewPosition = new Position;

    std::random_device rd;
    int RandomIndex = (rd() % MAP_WIDTH);

    NewPosition->x = RandomIndex;
    NewPosition->y = 0;

    return NewPosition;
}
