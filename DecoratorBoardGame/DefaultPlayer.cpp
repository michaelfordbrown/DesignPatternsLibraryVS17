#include "stdafx.h"
#include "DefaultPlayer.h"
#include "PlayerFunctions.h"
#include <string>

// CONSTRUCTOR: 
DefaultPlayer::DefaultPlayer(std::string basename) {
	// Set-up new Player at default board position
	facingDirection = compassPoints::NORTH;
	name.assign(basename);
	colPosition = 0;
	rowPosition = 0;
}

DefaultPlayer::DefaultPlayer(std::string basename, int row, int col) {
	// Set-up new Player at given co-ordinates
	facingDirection = compassPoints::NORTH;
	name.assign(basename);
	colPosition = col;
	rowPosition = row;
}

void DefaultPlayer::turn(rotation rotate) {

	PlayerTurn(this, rotate);
}

DefaultPlayer::~DefaultPlayer()
{
}
