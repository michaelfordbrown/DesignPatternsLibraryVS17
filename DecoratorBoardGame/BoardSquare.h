#pragma once
#include<memory>
#include "Player.h"

class BoardSquare
{
public:
	std::shared_ptr<Player> boardSpace;
	bool northWall;
	bool southWall;
	bool westWall;
	bool eastWall;

	BoardSquare();
	~BoardSquare();
};

