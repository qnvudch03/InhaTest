#include "pch.h"
#include "Helper.h"
#include <Windows.h>


#include "Map.h"
#include "Snail.h"
#include "Logic.h"

#define FOODSPAWNFRAM 5
#define DieteFOODSPAWNFRAM 300


Position* CreateFirstSnial();
Position GetTailPosition(Position** SnailArray);

int Score = 0;

MoveDir CurrentMoveDir = MoveDir::MOVE_RIGHT;

extern Position MovingOffset[4] = {
        {-1, 0},
        {1,0},
        {0,-1},
        {0, 1}
};

int main()
{
    ClearMap();
    SetCursorOnOff(false);
    SetCursorPos(0, 0);

    Position* FirstSnail = CreateFirstSnial();
    Position* FirstFood = nullptr;
    Position* DietFood = nullptr;

    Position* OriginSnailArray[] = { FirstSnail, nullptr };
    Position** SnailArray = MakeSnail(OriginSnailArray);
    Position** FoodArray = { &FirstFood };
    Position** DieteFoodArray = { &DietFood };

    int FoodSpawnPramdCount = FOODSPAWNFRAM;
    int DieteFoodPrameCount = DieteFOODSPAWNFRAM;

    while (true)
    {
        //타이머들
        FoodSpawnPramdCount--;
        DieteFoodPrameCount--;

        //입력
        MoveDir PlayerInput = HandleKeyInput();

        //로직
        UpdateSnail(SnailArray, PlayerInput);

        if (FoodSpawnPramdCount == 0)
        {
            FoodArray = SpawnNewFood(*SnailArray, FoodArray);
            FoodSpawnPramdCount = FOODSPAWNFRAM;
        }

        if (DieteFoodPrameCount == 0)
        {
            DieteFoodArray = SpawnNewFood(*SnailArray, DieteFoodArray);
            DieteFoodPrameCount = DieteFOODSPAWNFRAM;
        }
        

        //먹었는지 않먹었는지

        //일반 밥
        if (CheckEatFood(*SnailArray, FoodArray))
        {
            Position NewTailPosition = GetTailPosition(SnailArray) - MovingOffset[CurrentMoveDir];

            SnailArray = MakeSnail(SnailArray, &NewTailPosition);
        }

        //다이어트 밥
        if (CheckEatDietFood(*SnailArray, DieteFoodArray))
        {
            SnailArray = HalfSnail(SnailArray);
        }


        //벽 or 꼬리게 부딪혔는지 안부딪혔는지
        if (CheckCollision(SnailArray))
        {
            break;
        }

        //출력
        //PrintMap(SnailArray, FoodArray);
        PrintMap(SnailArray, FoodArray, DieteFoodArray);
        Sleep(70);
    }



    //게임 종료 처리
    {

        SetCursorColor(Color::Red);
        SetCursorPosition(SnailArray[0]->past_x * 2, SnailArray[0]->past_y);
        std::cout << "◎";

        SetCursorColor(Color::White);
        SetCursorPosition(0, MAP_HEIGHT + 2);

        delete[] *SnailArray;
        delete[] *FoodArray;

        *SnailArray = nullptr;
        *FoodArray = nullptr;

        int EndInput = 0;
        std::cout << "--Game Over--\n";
        std::cout << "[press any key]\n";
        std::cin >> EndInput;
    }
    
}

Position* CreateFirstSnial()
{
    Position* InitPosition = new Position;
    InitPosition->x = MAP_WIDTH / 2;
    InitPosition->y = MAP_HEIGHT / 2;

    return InitPosition;
}

Position GetTailPosition(Position** SnailArray)
{
    Position TailPosition;

    int SnailCount = 0;
    while (true)
    {
        if (SnailArray[SnailCount] == nullptr)
        {
            break;
        }

        TailPosition = *SnailArray[SnailCount];
        SnailCount++;
    }

    return TailPosition;
}
