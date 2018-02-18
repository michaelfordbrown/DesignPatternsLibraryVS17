#pragma once
#include "Player.h"
#include <memory>

class PlayerDecoration :
	public Player
{
public:
	//Previous Decroation
	std::shared_ptr<Player> prevDeco;

	// Mandatory base class methods (that were virtual):
	void turn(rotation rotate);

	// CONSTRUCTOR:
	// Constructor based upon a previous player
	PlayerDecoration(std::shared_ptr<Player> p);

	// Construction of new player at default board co-ordiantes (0,0) with given Name
	PlayerDecoration(std::string basename);

	// Construction of new player at board co-ordiantes given board co-ordinates with given Name
	PlayerDecoration(std::string basename, int row, int col);

	~PlayerDecoration();
};

