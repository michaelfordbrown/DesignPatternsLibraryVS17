#include "stdafx.h"
#include "DefaultBoard.h"
#include "GamesBoard.h"
#include "EnhancedBoard.h"
#include "Player.h"
#include <iostream>

#define BOARDSIZE 5
#define BOARDCOLSIZE BOARDSIZE
#define BOARDROWSIZE BOARDCOLSIZE 


EnhancedBoard::EnhancedBoard()
{
	eBoard.resize(BOARDCOLSIZE);
	for (int i = 0; i < BOARDCOLSIZE; i++)
	{
		eBoard[i].resize(BOARDROWSIZE);
		for (int l = 0; l < BOARDROWSIZE; l++)
		{
			eBoard[i][l].boardSpace = nullptr;
		}
	}
	eBoard.resize(BOARDCOLSIZE);
}

EnhancedBoard::EnhancedBoard(std::shared_ptr<GamesBoard> gb) {
	
	board.resize(BOARDCOLSIZE);
	eBoard.resize(BOARDCOLSIZE);
	for (int c = 0; c < BOARDCOLSIZE; c++)
	{
		board[c].resize(BOARDROWSIZE);
		eBoard[c].resize(BOARDROWSIZE);
		for (int r = 0; r < BOARDROWSIZE; r++)
		{
			board[c][r].boardSpace = nullptr;
			eBoard[c][r].boardSpace = nullptr;
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
		this->prevDeco = gb;
	}

}

EnhancedBoard::~EnhancedBoard()
{
}

void EnhancedBoard::addPlayer(std::shared_ptr<EnhancedPlayer> ePlayer)
{
	eBoard[ePlayer->colPosition][ePlayer->rowPosition].enhancedBoardSpace = ePlayer;
	eBoard[ePlayer->colPosition][ePlayer->rowPosition].boardSpace = ePlayer;
	board[ePlayer->colPosition][ePlayer->rowPosition].boardSpace = ePlayer;
	prevDeco->addPlayer(ePlayer);
};

void EnhancedBoard::movePlayerOneSquare(std::shared_ptr<EnhancedPlayer> ePlayer)
{

	int i = 0;
	while (i <  ePlayer->playerSpeed)
	{
		
		ePlayer->playerSpeed = ePlayer->playerSpeed + GetPowerNextSquare(eBoard, ePlayer);

		eBoard[ePlayer->colPosition][ePlayer->rowPosition].boardSpace = nullptr;
		eBoard[ePlayer->colPosition][ePlayer->rowPosition].enhancedBoardSpace = nullptr;
		board[ePlayer->colPosition][ePlayer->rowPosition].boardSpace = nullptr;

		ePlayer->colPosition = GetNextColPosition(board, ePlayer);
		ePlayer->rowPosition = GetNextRowPosition(board, ePlayer);

		eBoard[ePlayer->colPosition][ePlayer->rowPosition].boardSpace = ePlayer;
		eBoard[ePlayer->colPosition][ePlayer->rowPosition].enhancedBoardSpace = ePlayer;
		board[ePlayer->colPosition][ePlayer->rowPosition].boardSpace = ePlayer;

		prevDeco->movePlayerOneSquare(ePlayer->prevDeco);

		i++;
	}

}

int EnhancedBoard::GetPowerNextSquare(std::vector<std::vector<EnhancedSquare>> eBoard, std::shared_ptr<EnhancedPlayer> ePlayer)
{
	int nextCol = ePlayer->colPosition;
	int nextRow = ePlayer->rowPosition;
	int powerPoints = 0;

	switch (ePlayer->facingDirection)
	{
	case NORTH:
		if (!board[ePlayer->colPosition][ePlayer->rowPosition].northWall)
		{
			nextRow++;
		}
		else
		{
			return powerPoints;
		}
		break;

	case SOUTH:
		if (!board[ePlayer->colPosition][ePlayer->rowPosition].southWall)
		{
			nextRow--;
		}
		else
		{
			return powerPoints;
		}
		break;

	case WEST:
		if (!board[ePlayer->colPosition][ePlayer->rowPosition].westWall)
		{
			nextCol--;
		}
		else
		{
			return powerPoints;
		}
		break;

	case EAST:
		if (!board[ePlayer->colPosition][ePlayer->rowPosition].eastWall)
		{
			nextCol++;
		}
		else
		{
			return powerPoints;
		}
		break;

	default:
		break;
	}

	if (eBoard[nextCol][nextRow].enhancedBoardSpace != nullptr)
	{
		powerPoints = eBoard[nextCol][nextRow].enhancedBoardSpace->playerSpeed;
	}
	return powerPoints;

}
