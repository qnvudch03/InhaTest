#include "pch.h"
#include "PlayerBall.h"

Position MovementOffset[2] = {
			{-1,0},
			{1,0}
};

void UpdatePlayer(Position* BallPosition, MoveDir Direction)
{
	if (Direction != MoveDir::MOVE_LEFT && Direction != MoveDir::MOVE_RIGHT)
		return;

	Position MovingPosition = *BallPosition;

	if (Direction == MoveDir::MOVE_LEFT)
	{
		if (MovingPosition.x <= 0)
			return;

		MovingPosition = MovingPosition + MovementOffset[MoveDir::MOVE_LEFT];
	}

	else if (Direction == MoveDir::MOVE_RIGHT)
	{
		if (MovingPosition.x >= MAP_WIDTH - 1)
			return;

		MovingPosition = MovingPosition + MovementOffset[MoveDir::MOVE_RIGHT];
	}

	*BallPosition = MovingPosition;
}
