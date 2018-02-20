#include "stdafx.h"
#include "InnerWallBoard.h"

InnerWallBoard::InnerWallBoard()
{
}

InnerWallBoard::~InnerWallBoard()
{
}

InnerWallBoard::InnerWallBoard(std::shared_ptr<GamesBoard> gb, int colPosition, int rowPosition, compassPoints wallSide) : BoardDecoration(gb) {
	this->prevDeco = gb;
	switch (wallSide)
	{
	case NORTH:
		prevDeco->board[colPosition][rowPosition].northWall = true;
		break;
	case SOUTH:
		prevDeco->board[colPosition][rowPosition].southWall = true;
		break;
	case WEST:
		prevDeco->board[colPosition][rowPosition].westWall = true;
		break;
	case EAST:
		prevDeco->board[colPosition][rowPosition].eastWall = true;
		break;
	default:
		break;
	}
}

InnerWallBoard::InnerWallBoard(std::shared_ptr<InnerWallBoard> iwb, int colPosition, int rowPosition, compassPoints wallSide) : BoardDecoration(iwb->prevDeco)
{
	this->prevDeco = iwb->prevDeco;
	switch (wallSide)
	{
	case NORTH:
		prevDeco->board[colPosition][rowPosition].northWall = true;
		break;
	case SOUTH:
		prevDeco->board[colPosition][rowPosition].southWall = true;
		break;
	case WEST:
		prevDeco->board[colPosition][rowPosition].westWall = true;
		break;
	case EAST:
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

