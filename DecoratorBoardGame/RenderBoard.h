#pragma once
//#include <memory>
#include<iostream>
#include"GamesBoard.h"

class RenderBoard
{
public:
	std::shared_ptr<GamesBoard> gamesBoard;

	RenderBoard();
	RenderBoard(std::shared_ptr<GamesBoard> gb);
	~RenderBoard();

	void displayBoard();
	void displayWalls();
};

