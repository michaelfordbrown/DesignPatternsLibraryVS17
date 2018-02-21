#include "stdafx.h"
#include "InnerWallBoard.h"

InnerWallBoard::InnerWallBoard()
{
}

InnerWallBoard::~InnerWallBoard()
{
}

InnerWallBoard::InnerWallBoard(std::shared_ptr<GamesBoard> gb, int colPosition, int rowPosition, compassPoints wallSide) : BoardDecoration(gb) {
	board.resize(BOARDCOLSIZE);
	
	for (int c = 0; c < BOARDCOLSIZE; c++)
	{
		board[c].resize(BOARDROWSIZE);
		for (int r = 0; r < BOARDROWSIZE; r++)
		{
			board[c][r].boardSpace = nullptr;	
			board[c][r].northWall = gb->board[c][r].northWall;
			board[c][r].southWall = gb->board[c][r].southWall;
			board[c][r].westWall = gb->board[c][r].westWall;
			board[c][r].eastWall = gb->board[c][r].eastWall;
		}
	}

	this->prevDeco = gb;
	switch (wallSide)
	{
	case NORTH:
		gb->board[colPosition][rowPosition].northWall = true;
		board[colPosition][rowPosition].northWall = true;
		prevDeco->board[colPosition][rowPosition].northWall = true;
		break;
	case SOUTH:
		gb->board[colPosition][rowPosition].southWall = true;
		board[colPosition][rowPosition].southWall = true;
		prevDeco->board[colPosition][rowPosition].southWall = true;
		break;
	case WEST:
		gb->board[colPosition][rowPosition].westWall = true;
		board[colPosition][rowPosition].westWall = true;
		prevDeco->board[colPosition][rowPosition].westWall = true;
		break;
	case EAST:
		gb->board[colPosition][rowPosition].eastWall = true;
		board[colPosition][rowPosition].eastWall = true;
		prevDeco->board[colPosition][rowPosition].eastWall = true;
		break;
	default:
		break;
	}
}

InnerWallBoard::InnerWallBoard(std::shared_ptr<InnerWallBoard> iwb, int colPosition, int rowPosition, compassPoints wallSide) : BoardDecoration(iwb->prevDeco)
{
	for (int c = 0; c < BOARDCOLSIZE; c++)
	{
		board[c].resize(BOARDROWSIZE);
		for (int r = 0; r < BOARDROWSIZE; r++)
		{
			board[c][r].boardSpace = nullptr;
			board[c][r].northWall = iwb->board[c][r].northWall;
			board[c][r].southWall = iwb->board[c][r].southWall;
			board[c][r].westWall = iwb->board[c][r].westWall;
			board[c][r].eastWall = iwb->board[c][r].eastWall;
		}
	}
	
	this->prevDeco = iwb->prevDeco;
	switch (wallSide)
	{
	case NORTH:
		board[colPosition][rowPosition].northWall = true;
		prevDeco->board[colPosition][rowPosition].northWall = true;
		break;
	case SOUTH:
		board[colPosition][rowPosition].southWall = true;
		prevDeco->board[colPosition][rowPosition].southWall = true;
		break;
	case WEST:
		board[colPosition][rowPosition].westWall = true;
		prevDeco->board[colPosition][rowPosition].westWall = true;
		break;
	case EAST:
		board[colPosition][rowPosition].eastWall = true;
		prevDeco->board[colPosition][rowPosition].eastWall = true;
		break;
	default:
		break;
	}
}

void InnerWallBoard::movePlayerOneSquare(std::shared_ptr<Player> player)
{
	
	prevDeco->movePlayerOneSquare(player);
}

