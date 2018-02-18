#include "stdafx.h"
#include "BoardFunctions.h"

int GetNextColPosition(std::vector<std::vector<BoardSquare>> board, std::shared_ptr<Player> player)
{
	switch (player->facingDirection)
	{
	case EAST:

		if (!(board[player->colPosition][player->rowPosition].eastWall))
			return (player->colPosition + 1);
		break;

	case WEST:
		if (!(board[player->colPosition][player->rowPosition].westWall))
			return (player->colPosition - 1);
		break;

	default:
		break;
	}
	return player->colPosition;
}


int GetNextRowPosition(std::vector<std::vector<BoardSquare>>board, std::shared_ptr<Player> player)
{
	switch (player->facingDirection)
	{
	case NORTH:
		if (!(board[player->colPosition][player->rowPosition].northWall))
			return (player->rowPosition + 1);
		break;

	case SOUTH:
		if (!(board[player->colPosition][player->rowPosition].southWall))
			return (player->rowPosition - 1);
		break;

	default:
		break;
	}
	return player->rowPosition;
}

