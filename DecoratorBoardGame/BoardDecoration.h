#pragma once
#include <memory>
#include "GamesBoard.h"

class BoardDecoration :
	public GamesBoard
{
public:
	std::shared_ptr<GamesBoard> prevDeco;

	void addPlayer(std::shared_ptr<Player> player);
	void movePlayerOneSquare(std::shared_ptr<Player> player);

	BoardDecoration();

	BoardDecoration(std::shared_ptr<GamesBoard> bs);

	~BoardDecoration();
};

