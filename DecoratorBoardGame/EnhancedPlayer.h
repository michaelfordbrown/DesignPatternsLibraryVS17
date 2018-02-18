#pragma once
#include <memory>
#include <string>
#include "PlayerDecoration.h"

class EnhancedPlayer :
	public PlayerDecoration
{
public:
	int playerSpeed = 1;

	EnhancedPlayer(std::shared_ptr<Player> p);
	EnhancedPlayer(std::string basename, int row, int col);
	EnhancedPlayer(std::string basename, int row, int col, int speed);

	void turn(rotation rotate) override;

	~EnhancedPlayer();
};

