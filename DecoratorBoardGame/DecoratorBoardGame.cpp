// DecoratorBoardGame.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <string>
#include <iostream>
#include<memory>
#include <array>

#define BOARDSIZE 5
#define BOARDCOLSIZE BOARDSIZE
#define BOARDROWSIZE BOARDCOLSIZE 
#define PLAYERSTARTCOL 0
#define PLAYERSTARTROW 0

class AbstractBoardSquare {
public:

};

class AbstractPlayer {

};

class Player : public AbstractPlayer {
public:
	std::string name;

public:
	Player(std::string basename) { name.assign(basename); }


};


class BoardSquare : public AbstractBoardSquare {
public:
	Player *space;
	bool northboundary;
	bool eastboundary;
	bool southboundary;
	bool westboundary;

public:
	BoardSquare()
	{
		space = nullptr;
		northboundary = false;
		eastboundary = false;
		southboundary = false;
		westboundary = false;
	}
};


class Board {
private:
	Player *player;
	BoardSquare board[BOARDCOLSIZE][BOARDROWSIZE];

public:
	Board(unsigned int squarelength) {

		for (int i = 0; i < BOARDCOLSIZE; i++)
		{
			// Put up board boundaries
			board[0][i].southboundary = true;
			board[(BOARDCOLSIZE - 1)][i].northboundary = true;
		}

		player = new Player("pawn");
		PlacePlayer(player, PLAYERSTARTROW, PLAYERSTARTCOL);
	}

	~Board() {
		if (player != nullptr)
		{
			delete player;
			player = nullptr;
		}
	}

	void PlacePlayer(Player *player, int row, int col)
	{
		board[row][col].space = player;
	}

	void DisplayBoard()
	{
		for (int y = (BOARDROWSIZE - 1); y >= 0; y--)
		{
			// Display square contents
			for (int x = 0; x < BOARDCOLSIZE; x++)
			{
				if (board[y][x].space != nullptr)
				{
					std::cout << board[y][x].space->name;
				}
				else
				{
					std::cout << "(" << x << ", " << y << ")";
				}
				std::cout << "\t\t";
			}
			std::cout << std::endl;
		}
	}
};

int main()
{
	Board ChessBoard(BOARDSIZE);
	ChessBoard.DisplayBoard();



	getchar();
	return 0;
}



