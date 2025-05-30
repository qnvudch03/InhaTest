#pragma once
#include "Helper.h"

Position** SpawnNewFood(Position* HeadPosition, Position** FoodArray);

void UpdateSnail(Position** SnialArray, MoveDir PlayerInput);

bool CheckEatFood(Position* SnialHead, Position** FoodArray);
bool CheckEatDietFood(Position* SnialHead, Position** DieteFoodArray);

bool CheckCollision(Position** SnailArray);