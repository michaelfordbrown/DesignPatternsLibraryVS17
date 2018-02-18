#pragma once
#include <vector>
#include"BoardSquare.h"

int GetNextColPosition(std::vector<std::vector<BoardSquare>> board, std::shared_ptr<Player> player);
int GetNextRowPosition(std::vector<std::vector<BoardSquare>>board, std::shared_ptr<Player> player);