#include "stdafx.h"
#include "PlayerDecoration.h"

// CONSTRUCTOR:
PlayerDecoration::PlayerDecoration(std::shared_ptr<Player> p) {
	// Attach to previous decoration
	this->prevDeco = p;
}

PlayerDecoration::PlayerDecoration(std::string basename) {
	// Set-up new Player at default board position
	facingDirection = compassPoints::NORTH;
	name.assign(basename);
	colPosition = 0;
	rowPosition = 0;
}

PlayerDecoration::PlayerDecoration(std::string basename, int row, int col) {
	// Set-up new Player at given co-ordinates
	facingDirection = compassPoints::NORTH;
	name.assign(basename);
	colPosition = col;
	rowPosition = row;
}

void PlayerDecoration::turn(rotation rotate) {

	prevDeco->turn(rotate);
}

PlayerDecoration::~PlayerDecoration()
{
}
