#pragma once
#include <memory>
#include"GamesBoard.h"

class DefaultBoard :
	public GamesBoard
{
public:
	void addPlayer(std::shared_ptr<Player> player) override;

	//int DefaultBoard::GetNextColPosition(std::shared_ptr<Player> player);
	//int DefaultBoard::GetNextRowPosition(std::shared_ptr<Player> player);
	void movePlayerOneSquare(std::shared_ptr<Player> player) override;

	void addWall(int rowPosition, int colPosition, compassPoints comPoint) override;
	void displayBoard() override;
	void displayWalls() override;

	DefaultBoard();
	~DefaultBoard();
};

