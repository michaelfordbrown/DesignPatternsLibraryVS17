#include "stdafx.h"
#include "BoardDecoration.h"
#include <iostream>


BoardDecoration::BoardDecoration()
{
	this->prevDeco;
}


BoardDecoration::~BoardDecoration()
{
}

BoardDecoration::BoardDecoration(std::shared_ptr<GamesBoard> bs) {
	this->prevDeco = bs;
}

void BoardDecoration::addPlayer(std::shared_ptr<Player> player) {
	prevDeco->addPlayer(player);
}

void BoardDecoration::movePlayerOneSquare(std::shared_ptr<Player> player) {

	prevDeco->movePlayerOneSquare(player);
}
