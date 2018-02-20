#pragma once
#include "BoardDecoration.h"
#include "EnhancedPlayer.h"

class EnhancedSquare : public BoardSquare{
public:
	std::shared_ptr<EnhancedPlayer> enhancedBoardSpace;
};

class EnhancedBoard :
	public BoardDecoration
{
public:

	void addPlayer(std::shared_ptr<EnhancedPlayer> player);
	void movePlayerOneSquare(std::shared_ptr<EnhancedPlayer> player);
	int GetPowerNextSquare(std::vector<std::vector<EnhancedSquare>> eBoard, std::shared_ptr<EnhancedPlayer> player);

	std::vector<std::vector<EnhancedSquare>> eBoard;
	
	EnhancedBoard();
	EnhancedBoard(std::shared_ptr<GamesBoard> gb);
	~EnhancedBoard();
};

