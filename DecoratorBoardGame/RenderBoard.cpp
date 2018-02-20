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

void RenderBoard::displayBoard()
{
	std::cout << "Render Games Board\n";
	for (int y = (BOARDROWSIZE - 1); y >= 0; y--)
	{
		// Display square contents
		for (int x = 0; x < BOARDCOLSIZE; x++)
		{

			if (gamesBoard->board[y][x].boardSpace != nullptr)
			{
				std::cout << gamesBoard->board[y][x].boardSpace->name;
			}
			else
			{
				std::cout << "(" << y << ", " << x << ")";
			}
			std::cout << "\t\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
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
