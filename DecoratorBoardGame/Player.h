#pragma once
#include <string>

// Player turning control and facing points
enum rotation { LEFT = 0, RIGHT = 1 };
enum compassPoints { NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3, COMPASSMAX = WEST + 1 };

// General abstraction class
class Player
{
public:
	// IN: - Player name 
	// OUT: none 
	// (Implementation done by Subclasses)

	// Function for changing player facing direction (N/S/E/W) using rotation (L/R)
	virtual void turn(rotation rotate) = 0;

	// Name of the Player element
	std::string name;

	// Direction of movement
	compassPoints facingDirection;

	// Position on the board
	int colPosition;
	int rowPosition;

	Player();
	~Player();
};

