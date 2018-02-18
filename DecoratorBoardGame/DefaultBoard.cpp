#include "stdafx.h"
#include <memory>
#include <vector>
#include <iostream>
#include <string>
#include "DefaultBoard.h"
#include "GamesBoard.h"
#include "BoardFunctions.h"

#define BOARDSIZE 5
#define BOARDCOLSIZE BOARDSIZE
#define BOARDROWSIZE BOARDCOLSIZE 

DefaultBoard::DefaultBoard()
{
	board.resize(BOARDCOLSIZE);
	for (int c = 0; c < BOARDCOLSIZE; c++)
	{
		board[c].resize(BOARDROWSIZE);
		for (int r = 0; r < BOARDROWSIZE; r++)
		{
			board[c][r].boardSpace = nullptr;
			if (c == 0)
			{
				board[c][r].westWall = true;
			}
			else
			{
				board[c][r].westWall = false;
			}

			if (c == (BOARDCOLSIZE - 1))
			{
				board[c][r].eastWall = true;
			}
			else
			{
				board[c][r].eastWall = false;
			}

			if (r == 0)
			{
				board[c][r].southWall = true;
			}
			else
			{
				board[c][r].southWall = false;
			}

			if (r == (BOARDROWSIZE - 1))
			{
				board[c][r].northWall = true;
			}
			else
			{
				board[c][r].northWall = false;
			}

		}
		
	}
}

void DefaultBoard::addPlayer(std::shared_ptr<Player> player)
{
	board[player->colPosition][player->rowPosition].boardSpace = player;
};

void DefaultBoard::movePlayerOneSquare(std::shared_ptr<Player> player) {
	std::cout << "DefaultBoard::MPOQ\n\n";
	board[player->colPosition][player->rowPosition].boardSpace = nullptr;

	player->colPosition = GetNextColPosition(board, player);
	player->rowPosition = GetNextRowPosition(board, player);

	board[player->colPosition][player->rowPosition].boardSpace = player;	
};

void DefaultBoard::displayBoard()
{
	for (int y = (BOARDROWSIZE - 1); y >= 0; y--)
	{
		// Display square contents
		for (int x = 0; x < BOARDCOLSIZE; x++)
		{
			if (board[y][x].boardSpace != nullptr)
			{
				std::cout << board[y][x].boardSpace->name;
			}
			else
			{
				std::cout << "(" << y << ", " << x << ")";
			}
			std::cout << "\t\t";
		}
		std::cout << std::endl;
	}
}

void DefaultBoard::displayWalls()
{
	bool displayBlankCell = true;
	for (int y = (BOARDROWSIZE - 1); y >= 0; y--)
	{
		// Display square contents
		for (int x = 0; x < BOARDCOLSIZE; x++)
		{
			if (board[y][x].westWall)
			{
				std::cout << "WWWWW";
				//displayBlankCell = false;
			}

			if (board[y][x].northWall)
			{
				std::cout << "NNNNN";
				displayBlankCell = false;
			}

			if (board[y][x].southWall)
			{
				std::cout << "SSSSS";
				displayBlankCell = false;
			}

			if (board[y][x].eastWall)
			{
				if ((!board[y][x].northWall) && (!board[y][x].southWall))
					std::cout << "+---+";
				std::cout << "EEEEE";
				displayBlankCell = false;
			}

			if (displayBlankCell)
			{
				std::cout << "+---+";
			}
			displayBlankCell = true;
		}
		std::cout << std::endl;
	}
}

void DefaultBoard::addWall(int rowPosition, int colPosition, compassPoints comPoint)
{
	switch (comPoint)
	{
	case NORTH:
		board[colPosition][rowPosition].northWall = true;
		break;
	case SOUTH:
		board[colPosition][rowPosition].southWall = true;
		break;
	case WEST:
		board[colPosition][rowPosition].westWall = true;
		break;
	case EAST:
		board[colPosition][rowPosition].eastWall = true;
		break;
	default:
		break;
	}
};

DefaultBoard::~DefaultBoard()
{
}
