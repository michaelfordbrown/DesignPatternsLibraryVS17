#include "stdafx.h"
#include "EnhancedPlayer.h"

EnhancedPlayer::EnhancedPlayer(std::shared_ptr<Player> p) : PlayerDecoration(p) {
	colPosition = p->colPosition;
	rowPosition = p->rowPosition;
	facingDirection = p->facingDirection;
	name = p->name;
	playerSpeed = 1;
	this->prevDeco = p;
}

EnhancedPlayer::EnhancedPlayer(std::string basename, int row, int col) : PlayerDecoration(basename, row, col) {
	colPosition = col;
	rowPosition = row;
	facingDirection = NORTH;
	name = basename;
	playerSpeed = 1;
	this->prevDeco = prevDeco;
}

EnhancedPlayer::EnhancedPlayer(std::string basename, int row, int col, int speed) : PlayerDecoration(basename, row, col) {
	facingDirection = NORTH;
	name.assign(basename);
	colPosition = col;
	rowPosition = row;
	playerSpeed = speed;
	this->prevDeco  = prevDeco;
}

void EnhancedPlayer::turn(rotation rotate)
{
	switch (rotate)
	{
	case LEFT:
		facingDirection = static_cast<compassPoints>((facingDirection - 1 + COMPASSMAX) % COMPASSMAX);
		break;
	case RIGHT:
		facingDirection = static_cast<compassPoints>((facingDirection + 1 + COMPASSMAX) % COMPASSMAX);
		break;
	default:
		break;
	}
	prevDeco->turn(rotate);
}

EnhancedPlayer::~EnhancedPlayer()
{
}
