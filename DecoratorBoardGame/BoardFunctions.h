#pragma once
#include <vector>
#include<iostream>

#include"BoardSquare.h"
#include"GamesBoard.h"

#define SQUARESIZE 15

int GetNextColPosition(std::vector<std::vector<BoardSquare>> board, std::shared_ptr<Player> player);
int GetNextRowPosition(std::vector<std::vector<BoardSquare>>board, std::shared_ptr<Player> player);
void DisplayBoard(std::shared_ptr<GamesBoard> gamesBoard);