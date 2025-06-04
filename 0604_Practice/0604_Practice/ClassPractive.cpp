#include <iostream>

#include "Player.h"

int main(void)
{
	Player player1;
	Player player2(500, 3);

	player2.HealMe();
}