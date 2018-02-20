#pragma once
#include "BoardDecoration.h"
#include <iostream>

class InnerWallBoard :
	public BoardDecoration
{
public:
	InnerWallBoard(std::shared_ptr<GamesBoard>gb, int colPosition, int rowPosition, compassPoints wallSide);
	InnerWallBoard(std::shared_ptr<InnerWallBoard> iwb, int colPosition, int rowPosition, compassPoints wallSide);

	void movePlayerOneSquare(std::shared_ptr<Player>player);

	InnerWallBoard();
	~InnerWallBoard();
};

