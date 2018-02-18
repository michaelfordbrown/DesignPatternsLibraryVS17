#pragma once
#include "BoardSquare.h"
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
	//int getPowerNextSquare(std::shared_ptr<EnhancedPlayer> player);
	int GetPowerNextSquare(std::vector<std::vector<EnhancedSquare>> eBoard, std::shared_ptr<EnhancedPlayer> player);
	void displayBoard();
	/*int EnhancedBoard::GetNextColPosition(std::shared_ptr<Player> player);
	int EnhancedBoard::GetNextRowPosition(std::shared_ptr<Player> player);*/

	std::vector<std::vector<EnhancedSquare>> eBoard;
	
	EnhancedBoard();
	EnhancedBoard(std::shared_ptr<GamesBoard> gb);
	~EnhancedBoard();
};

