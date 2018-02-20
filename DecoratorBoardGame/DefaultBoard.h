#pragma once
#include"GamesBoard.h"

class DefaultBoard :
	public GamesBoard
{
public:
	void addPlayer(std::shared_ptr<Player> player) override;
	void movePlayerOneSquare(std::shared_ptr<Player> player) override;
		
	DefaultBoard();
	~DefaultBoard();
};

