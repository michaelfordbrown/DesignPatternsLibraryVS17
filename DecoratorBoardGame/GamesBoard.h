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
	virtual void addWall(int rowPosition, int colPosition, compassPoints comPoint) {};
	virtual void displayBoard() {};
	virtual void displayWalls() {};

	std::vector<std::vector<BoardSquare>> board;
	
	

	GamesBoard();
	~GamesBoard();
};

