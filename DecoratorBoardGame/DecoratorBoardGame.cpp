// DecoratorBoardGame.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <string>
#include <iostream>
#include<memory>
#include <array>
#include <vector>

#ifdef MEMORYDEBUG
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#endif

#define BOARDSIZE 5
#define BOARDCOLSIZE BOARDSIZE
#define BOARDROWSIZE BOARDCOLSIZE 
#define PLAYERSTARTCOL 0
#define PLAYERSTARTROW 0

using namespace std;

enum rotation { LEFT = 0, RIGHT = 1 };
enum compassPoints {NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3, COMPASSMAX = WEST};

#define MAXCOMPASSPOINTS = 
class AbstractBoardSquare {
public:

};

class AbstractPlayer {
public:
	std::string name;
	int colPosition;
	int rowPosition;
};

class Player:public AbstractPlayer {
public:
	compassPoints facingDirection;

	void turn(rotation rot) {
		switch (rot)
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
	};

public:
	Player(std::string basename) {
		name.assign(basename); 
		colPosition = 0;
		rowPosition = 0;
		facingDirection = NORTH;
	}
};


//Board ChessBoard(BOARDSIZE);
//ChessBoard.DisplayBoard();

class BoardSquare : public AbstractPlayer{
public:
	//virtual void addPlayer() = 0;
	shared_ptr<Player> boardSpace;
	bool northWall;
	bool southWall;
	bool westWall;
	bool eastWall;
};

class DefaultBoard: public BoardSquare {

public:
	vector<vector<BoardSquare>> board;

	DefaultBoard() {
		board.resize(BOARDCOLSIZE);
		for (int i = 0; i < BOARDCOLSIZE; i++)
		{
			board[i].resize(BOARDROWSIZE);
			for (int l = 0; l < BOARDROWSIZE; l++)
			{
				board[i][l].boardSpace = nullptr;
				if (i == 0)
				{
					board[i][l].southWall = true;
				}
				else
				{
					board[i][l].southWall = false;
				}

				if (i == (BOARDCOLSIZE - 1))
				{
					board[i][l].northWall = true;
				}
				else
				{
					board[i][l].northWall = false;
				}

				if (l == 0)
				{
					board[i][l].westWall = true;
				}
				else
				{
					board[i][l].westWall = false;
				}

				if (l == (BOARDROWSIZE - 1))
				{
					board[i][l].eastWall = true;
				}
				else
				{
					board[i][l].eastWall = false;
				}
				
				
			}
		}
	}

	void addPlayer(shared_ptr<Player> player)
	{
		board[player->colPosition][player->rowPosition].boardSpace = player;
	};

	void movePlayerOneSquare(shared_ptr<Player> player) {
		board[player->colPosition][player->rowPosition].boardSpace = nullptr;
		switch (player->facingDirection)
		{
		case NORTH:
			if (!board[player->colPosition][player->rowPosition].northWall)
			{
				player->colPosition++;
			}
			break;
		case SOUTH:
			if (!board[player->colPosition][player->rowPosition].southWall)
			{
				player->colPosition--;
			}
			break;
		case WEST:
			if (!board[player->colPosition][player->rowPosition].westWall)
			{
				player->rowPosition--;
			}
			break;
		case EAST:
			if (!board[player->colPosition][player->rowPosition].eastWall)
			{
				player->rowPosition++;
			}
			break;
		default:
			break;
		}
		board[player->colPosition][player->rowPosition].boardSpace = player;
	};


	void displayBoard()
	{
		for (int y = (BOARDROWSIZE - 1); y >= 0; y--)
		{
			// Display square contents
			for (int x = 0; x < BOARDCOLSIZE; x++)
			{
				if (board[y][x].boardSpace != nullptr)
				{
					std::cout << board[y][x].boardSpace->name;
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

	void displayWalls()
	{
		for (int y = (BOARDROWSIZE - 1); y >= 0; y--)
		{
			// Display square contents
			for (int x = 0; x < BOARDCOLSIZE; x++)
			{

				if (board[y][x].westWall)
				{
					std::cout << "WWWWW";
				}

				if (board[y][x].northWall)
				{
					std::cout << "NNNNN";
				}

				if (board[y][x].southWall)
				{
					std::cout << "SSSSS";
				}
				
				if (board[y][x].eastWall)
				{
					std::cout << "EEEEE";
				}


				std::cout << "     ";
			}
			std::cout << std::endl;
		}
	}
};

int main()
{
	{
		/* Create a square playing board  5 x 5 */
		shared_ptr<DefaultBoard>GameBoard = make_shared<DefaultBoard>();
		
		cout << "Board Walls\n";
		GameBoard->displayWalls();
		cout << "\nDefault Board\n";
		GameBoard->displayBoard();

		/* Add playerupon the boardm  at 0.0 facing North*/
		shared_ptr<Player> playerOne = make_shared<Player>("Player One");
		GameBoard->addPlayer(playerOne);
		cout << "\nPlay One Added To Board\n";
		GameBoard->displayBoard();

		/* Move player East by one square */
		playerOne->turn(RIGHT);
		GameBoard->movePlayerOneSquare(playerOne);
		cout << "\nPlayer One has Moved\n";
		GameBoard->displayBoard();

		/* Move player North by ten squares */
		playerOne->turn(LEFT);
		for (int i = 0; i < 3; i++)
		{
			GameBoard->movePlayerOneSquare(playerOne);
			cout << "\nPlayer One has Moved North\n";
			GameBoard->displayBoard();
		}

		/* Move player East by ten squares */
		playerOne->turn(RIGHT);
		for (int i = 0; i < 2; i++)
		{
			GameBoard->movePlayerOneSquare(playerOne);
			cout << "\nPlayer One has Moved East\n";
			GameBoard->displayBoard();
		}

		getchar();
	}
#ifdef MEMORYDEBUG
	_CrtDumpMemoryLeaks();
#endif

	return 0;
}



