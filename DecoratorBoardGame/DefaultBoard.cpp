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
	
	board[player->colPosition][player->rowPosition].boardSpace = nullptr;

	player->colPosition = GetNextColPosition(board, player);
	player->rowPosition = GetNextRowPosition(board, player);

	board[player->colPosition][player->rowPosition].boardSpace = player;	
};

DefaultBoard::~DefaultBoard()
{
}
