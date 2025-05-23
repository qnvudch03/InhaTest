#pragma once
#include "Position.h"

#define MAP_SIZE 10
#define GollNum 3

enum Color
{
	Red = 12,
	Black = 0,
	Yellow = 14,
};

enum KeyBoard
{
	RIGHT,
	LEFT,
	UP,
	DOWN
};

// Ű���� �Է�
void HandleKeyInput(Position& PlayerPosition, MapInfo* MapInfoArray);
void CheckBoxOverrlap(int KeyboardInput, MapInfo* MapInfoArray);

void SetCursorPosition(int x, int y);
void SetCursorOnOff(bool visible);
void SetCursorColor(Color color, Color bg = Color::Black);