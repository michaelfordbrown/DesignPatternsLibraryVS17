#pragma once
#include "Player.h"
#include "BoardSquare.h"
#include "BoardFunctions.h"
#include <memory>
#include <vector>

class GamesBoard :
	public BoardSquare
{
public:
	virtual void addPlayer(std::shared_ptr<Player> player) {};
	virtual void movePlayerOneSquare(std::shared_ptr<Player> player) {};

	std::vector<std::vector<BoardSquare>> board;
	
	

	GamesBoard();
	~GamesBoard();
};

