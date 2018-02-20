#pragma once
#include "Player.h"
#include "PlayerFunctions.h"

class DefaultPlayer :
	public Player
{
public:
	void turn(rotation rotate) override;

	// CONSTRUCTOR: 
	DefaultPlayer(std::string basename);
	DefaultPlayer(std::string basename, int row, int col);

	~DefaultPlayer();
};

