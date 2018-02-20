#pragma once
#include <memory>
#include<iostream>
#include"GamesBoard.h"


#define BOARDSIZE 5
#define BOARDCOLSIZE BOARDSIZE
#define BOARDROWSIZE BOARDCOLSIZE 

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

