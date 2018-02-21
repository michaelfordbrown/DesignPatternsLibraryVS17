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

void DisplayBoard(std::shared_ptr<GamesBoard> gamesBoard)
{
	std::string name = "";
	for (int rx = (BOARDROWSIZE - 1); rx >= 0; rx--)
	{
		// Draw NORTH wall
		for (int col = 0; col < (BOARDCOLSIZE); col++)
		{
			std::cout << "+";
			for (int l = 0; l < SQUARESIZE; l++)
			{
				if (gamesBoard->board[col][rx].northWall)
				{
					std::cout << "-";
					//std::cout << (l % 10);
				}
				else
				{
					std::cout << " ";
				}
			}
		}
		std::cout << "+\n";

		// Add square padding
		for (int col = 0; col < BOARDCOLSIZE; col++)
		{
			if (gamesBoard->board[col][rx].boardSpace != nullptr)
				name = gamesBoard->board[col][rx].boardSpace->name;

			std::cout << " ";
			if (gamesBoard->board[col][rx].westWall)
			{
				std::cout << "|";
			}
			else
			{
				std::cout << " ";
			}
			unsigned int l = 0;
			while (l < (SQUARESIZE - 2))
			{
				if ((gamesBoard->board[col][rx].boardSpace != nullptr) && (l < name.length()))
				{
					std::cout << name[l];
				}
				else
				{
					std::cout << " ";
				}
				l++;
			}
			if (gamesBoard->board[col][rx].eastWall)
			{
				std::cout << "|";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;

		// Draw SOUTH wall
		for (int col = 0; col < (BOARDCOLSIZE); col++)
		{
			std::cout << "+";
			for (int l = 0; l < SQUARESIZE; l++)
			{
				if (gamesBoard->board[col][rx].southWall)
				{
					std::cout << "-";
					//std::cout << (l % 10);
				}
				else
				{
					std::cout << " ";
				}
			}
		}
		std::cout << "+\n";
	}


}