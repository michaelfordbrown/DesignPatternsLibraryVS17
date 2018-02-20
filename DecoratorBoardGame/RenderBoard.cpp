#include "stdafx.h"
#include "RenderBoard.h"


RenderBoard::RenderBoard()
{
}

RenderBoard::RenderBoard(std::shared_ptr<GamesBoard> gb)
{
	gamesBoard = gb;
}

RenderBoard::~RenderBoard()
{
}

#define SQUARESIZE 15
std::string name = "";

void RenderBoard::displayBoard()
{
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

		// Add top square padding
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
				std::cout << "|";
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
				std::cout << "|";
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

void RenderBoard::displayWalls()
{
	std::cout << "Render Games Board Walls\n";
	bool displayBlankCell = true;
	for (int y = (BOARDROWSIZE - 1); y >= 0; y--)
	{
		// Display square contents
		for (int x = 0; x < BOARDCOLSIZE; x++)
		{
			if (gamesBoard->board[y][x].westWall)
			{
				std::cout << "WWWWW";
				//displayBlankCell = false;
			}

			if (gamesBoard->board[y][x].northWall)
			{
				std::cout << "NNNNN";
				displayBlankCell = false;
			}

			if (gamesBoard->board[y][x].southWall)
			{
				std::cout << "SSSSS";
				displayBlankCell = false;
			}

			if (gamesBoard->board[y][x].eastWall)
			{
				if ((!gamesBoard->board[y][x].northWall) && (!gamesBoard->board[y][x].southWall))
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
	std::cout << std::endl;
}
