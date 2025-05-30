#include "pch.h"
#include "Snail.h"

Position** MakeSnail(Position** SnailArray, Position* NewLocation)
{
    int CurrentSize = 0;

    while (true)
    {
        if (SnailArray[CurrentSize] != nullptr && SnailArray[CurrentSize]->x !=0)
        {
            CurrentSize++;
        }

        else
            break;
    }

    Position** NewSnail = new Position*[CurrentSize + 2];

    //기존 스네일 포인터의 값 복사
    for (int i = 0; i < CurrentSize; i++)
    {
        NewSnail[i] = new Position;
        NewSnail[i]->x = SnailArray[i]->x;
        NewSnail[i]->y = SnailArray[i]->y;
    }

    //신규꼬리 값과 꼬리 nullptr 재 생성

    if (NewLocation != nullptr)
    {
        NewSnail[CurrentSize] = new Position;
        NewSnail[CurrentSize]->x = NewLocation->x;
        NewSnail[CurrentSize]->y = NewLocation->y;
    }
    else
    {
        NewSnail[CurrentSize] = nullptr;
    }

    NewSnail[CurrentSize + 1] = nullptr;

    delete[] *SnailArray;

    return NewSnail;
}

Position** HalfSnail(Position** SnailArray)
{
    int snailCount = 0;

    while (true)
    {
        if (SnailArray[snailCount] == nullptr)
            break;
        snailCount++;
    }

    if (snailCount == 1)
        return SnailArray;

    else
    {
        int DividNum = snailCount / 2;
        for (snailCount; snailCount > DividNum; snailCount--)
        {
            SnailArray[snailCount - 1] = nullptr;
        }
    }

    return SnailArray;
}
