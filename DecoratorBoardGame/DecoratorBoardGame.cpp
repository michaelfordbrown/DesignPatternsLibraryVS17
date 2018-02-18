// DecoratorBoardGame.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <string>
#include <iostream>
#include<memory>
#include <array>
#include <vector>

#define BOARDSIZE 5
#define BOARDCOLSIZE BOARDSIZE
#define BOARDROWSIZE BOARDCOLSIZE 
#define PLAYERSTARTCOL 0
#define PLAYERSTARTROW 0

#include "Player.h"
#include "DefaultPlayer.h"
#include "PlayerDecoration.h"
#include "EnhancedPlayer.h"

#include "BoardSquare.h"
#include "GamesBoard.h"
#include "DefaultBoard.h"
#include "BoardDecoration.h"
#include "EnhancedBoard.h"

#ifdef MEMORYDEBUG
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#endif

using namespace std;

class InnerWallBoard : public BoardDecoration
{
public:

	InnerWallBoard(std::shared_ptr<GamesBoard>gb, int colPosition, int rowPosition, compassPoints wallSide);
	InnerWallBoard(std::shared_ptr<InnerWallBoard> iwb, int colPosition, int rowPosition, compassPoints wallSide);

	void movePlayerOneSquare(std::shared_ptr<Player>player);
};

InnerWallBoard::InnerWallBoard(std::shared_ptr<GamesBoard> gb, int colPosition, int rowPosition, compassPoints wallSide) : BoardDecoration(gb){
	this->prevDeco = gb;
	switch (wallSide)
	{
	case NORTH:
		prevDeco->board[colPosition][rowPosition].northWall = true;
		break;
	case SOUTH:
		prevDeco->board[colPosition][rowPosition].southWall = true;
		break;
	case WEST:
		prevDeco->board[colPosition][rowPosition].westWall = true;
		break;
	case EAST:
		prevDeco->board[colPosition][rowPosition].eastWall = true;
		break;
	default:
		break;
	}
}

InnerWallBoard::InnerWallBoard(std::shared_ptr<InnerWallBoard> iwb, int colPosition, int rowPosition, compassPoints wallSide) : BoardDecoration(iwb->prevDeco)
{
	this->prevDeco = iwb->prevDeco;
	switch (wallSide)
	{
	case NORTH:
		prevDeco->board[colPosition][rowPosition].northWall = true;
		break;
	case SOUTH:
		prevDeco->board[colPosition][rowPosition].southWall = true;
		break;
	case WEST:
		prevDeco->board[colPosition][rowPosition].westWall = true;
		break;
	case EAST:
		prevDeco->board[colPosition][rowPosition].eastWall = true;
		break;
	default:
		break;
	}
}

void InnerWallBoard::movePlayerOneSquare(std::shared_ptr<Player> player)
{
	std::cout << "InnerWallBoard::MPOQ\n";
	prevDeco->movePlayerOneSquare(player);
}


int main()
{
	{		
		/* Create a square playing board  5 x 5 */
		shared_ptr<GamesBoard>gamesBoard = make_shared<DefaultBoard>();
		//gamesBoard->displayWalls();
		//gamesBoard->displayBoard();

		/* Add player upon the board at 0.0 facing North */
		shared_ptr<Player> playerOne = make_shared<DefaultPlayer>("Player 1");
		gamesBoard->addPlayer(playerOne);
		gamesBoard->displayBoard();

		cout << "\nPlay One Added To Board\n";

		/* Add inner walls to the game board*/
		shared_ptr<InnerWallBoard>innerWallBoard = make_shared<InnerWallBoard>(gamesBoard, 2, 2, NORTH);
		innerWallBoard = make_shared<InnerWallBoard>(innerWallBoard, 2, 2, EAST);
		//innerWallBoard->displayWalls();
		cout << std::endl;

		/* Move player East by one square */
		playerOne->turn(RIGHT);
		innerWallBoard->movePlayerOneSquare(playerOne);
		//cout << "\nPlayer One has Moved\n";
		//innerWallBoard->displayBoard();
		cout << std::endl;

		/* Move player North by ten squares */
		playerOne->turn(LEFT);
		for (int i = 0; i < 10; i++)
		{
			innerWallBoard->movePlayerOneSquare(playerOne);
			//cout << "\nPlayer One has Moved North\n";
		}
		//innerWallBoard->displayBoard();
		cout << std::endl;

		/* Move player East by ten squares */
		playerOne->turn(RIGHT);
		for (int i = 0; i < 10; i++)
		{
			innerWallBoard->movePlayerOneSquare(playerOne);
			//cout << "\nPlayer One has Moved East\n";
		}
		//innerWallBoard->displayBoard();
		cout << std::endl;

		/* Add new walls to the board */
		cout << "\nNew Inner Wall Added\n";
		innerWallBoard->addWall(2, 2, compassPoints::NORTH);
		innerWallBoard->displayWalls();
		innerWallBoard->displayBoard();
		cout << std::endl;

		/* Make Enhanced Games Board*/
		cout << "\nMake Enhanced Games Board\n";
		shared_ptr<EnhancedBoard>enhancedGamesBoard = make_shared<EnhancedBoard>(innerWallBoard);
		//enhancedGamesBoard->displayWalls();
		//enhancedGamesBoard->displayBoard();
		cout << std::endl;

		/* Add Power Item to the board */
		cout << "\nAdd Power Cookie to the new board\n";
		shared_ptr<EnhancedPlayer> cookieOne = make_shared<EnhancedPlayer>("Cookie 1",  0, 1,1);
		cout << "\n" << cookieOne->name << " has item power of " << cookieOne->playerSpeed << endl;
		enhancedGamesBoard->addPlayer(cookieOne);
		enhancedGamesBoard->displayBoard();

		/* Make player 2 to eat cookies */
		cout << "\nEnhance Player One\n";
		shared_ptr<EnhancedPlayer> enhancedPlayerOne = make_shared<EnhancedPlayer>(playerOne);
		cout << "\n" << enhancedPlayerOne->name << " has speed " << enhancedPlayerOne->playerSpeed << endl;
		enhancedGamesBoard->addPlayer(enhancedPlayerOne);
		enhancedGamesBoard->displayBoard();
		cout << std::endl;

		/* Move player west by four squares */
		enhancedPlayerOne->turn(LEFT);
		enhancedPlayerOne->turn(LEFT);
		for (int i = 0; i < 4; i++)
		{
			enhancedGamesBoard->movePlayerOneSquare(enhancedPlayerOne);
		}
		enhancedGamesBoard->displayBoard();
		cout << std::endl;

		/* Move player 1 South by three square */
		enhancedPlayerOne->turn(LEFT);
		for (int i = 0; i < 3; i++)
		{
			enhancedGamesBoard->movePlayerOneSquare(enhancedPlayerOne);
		}
		enhancedGamesBoard->movePlayerOneSquare(enhancedPlayerOne);
		cout << "\nPlayer One has Moved into Cookie square\n";
		enhancedGamesBoard->displayBoard();
		cout << std::endl;

		/* Move player 1 East by one square */
		enhancedPlayerOne->turn(LEFT);
		for (int i = 0; i < 1; i++)
		{
			enhancedGamesBoard->movePlayerOneSquare(enhancedPlayerOne);
		}
		enhancedGamesBoard->movePlayerOneSquare(enhancedPlayerOne);
		cout << "\nPlayer One has Moved into Cookie square\n";
		enhancedGamesBoard->displayBoard();


		cout << "\nPress Any Key To Continue . . . \n";

		getchar();

	}

#ifdef MEMORYDEBUG
	_CrtDumpMemoryLeaks();
#endif



	return 0;
}