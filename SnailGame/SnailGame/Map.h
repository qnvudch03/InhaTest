#pragma once

extern int Score;

extern const char* Map[MAP_WIDTH][MAP_HEIGHT];

void ClearMap();

void PrintMap(Position** SnilArray, Position** FoodArray);
void PrintMap(Position** SnilArray, Position** FoodArray, Position** DieteFoodArray);