// DecoratorBoardGame.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include "DefaultPlayer.h"
#include "EnhancedPlayer.h"

#include "BoardFunctions.h"
#include "GamesBoard.h"
#include "DefaultBoard.h"
#include "InnerWallBoard.h"
#include "EnhancedBoard.h"

#ifdef MEMORYDEBUG
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#endif

using namespace std;

int main()
{
	{		
		/* Create a square playing board  5 x 5 */
		shared_ptr<GamesBoard>gamesBoard = make_shared<DefaultBoard>();
		DisplayBoard(gamesBoard);

		/* Add player upon the board at 0.0 facing North */
		shared_ptr<Player> playerOne = make_shared<DefaultPlayer>("Player 1");
		gamesBoard->addPlayer(playerOne);
		DisplayBoard(gamesBoard);

		std::cout << "\nPlay One Added To Board\n";

		/* Add inner walls to the game board*/
		gamesBoard = make_shared<InnerWallBoard>(gamesBoard, 2, 2, NORTH);
		gamesBoard = make_shared<InnerWallBoard>(gamesBoard, 2, 2, EAST);

		/* Move player East by one square */
		playerOne->turn(RIGHT);
		gamesBoard->movePlayerOneSquare(playerOne);
		cout << "\nPlayer One has Moved\n";
		DisplayBoard(gamesBoard);

		/* Move player North by ten squares */
		playerOne->turn(LEFT);
		for (int i = 0; i < 10; i++)
		{
			gamesBoard->movePlayerOneSquare(playerOne);
		}
		DisplayBoard(gamesBoard);
		std::cout << std::endl;

		/* Move player East by ten squares */
		playerOne->turn(RIGHT);
		for (int i = 0; i < 10; i++)
		{
			gamesBoard->movePlayerOneSquare(playerOne);
		}
		DisplayBoard(gamesBoard);

		/* Make Enhanced Games Board*/
		std::cout << "\nMake Enhanced Games Board\n";
		shared_ptr<EnhancedBoard>enhancedGamesBoard = make_shared<EnhancedBoard>(gamesBoard);
		std::cout << std::endl;

		/* Add Power Item to the board */
		std::cout << "\nAdd Power Cookie to the new board\n";
		shared_ptr<EnhancedPlayer> cookieOne = make_shared<EnhancedPlayer>("Cookie 1",  0, 1,1);
		std::cout << "\n" << cookieOne->name << " has item power of " << cookieOne->playerSpeed << endl;
		enhancedGamesBoard->addPlayer(cookieOne);
		DisplayBoard(enhancedGamesBoard);
		
		/* Make player 2 to eat cookies */
		std::cout << "\nEnhance Player One\n";
		shared_ptr<EnhancedPlayer> enhancedPlayerOne = make_shared<EnhancedPlayer>(playerOne);
		std::cout << "\n" << enhancedPlayerOne->name << " has speed " << enhancedPlayerOne->playerSpeed << endl;
		enhancedGamesBoard->addPlayer(enhancedPlayerOne);
		DisplayBoard(enhancedGamesBoard);
		std::cout << std::endl;

		/* Move player west by four squares */
		enhancedPlayerOne->turn(LEFT);
		enhancedPlayerOne->turn(LEFT);
		for (int i = 0; i < 4; i++)
		{
			enhancedGamesBoard->movePlayerOneSquare(enhancedPlayerOne);
		}
		DisplayBoard(enhancedGamesBoard);
		std::cout << std::endl;

		/* Move player 1 South by three square */
		enhancedPlayerOne->turn(LEFT);
		for (int i = 0; i < 3; i++)
		{
			enhancedGamesBoard->movePlayerOneSquare(enhancedPlayerOne);
		}
		enhancedGamesBoard->movePlayerOneSquare(enhancedPlayerOne);
		std::cout << "\nPlayer One has Moved into Cookie square\n";
		DisplayBoard(enhancedGamesBoard);

		/* Move player 1 East by one square */
		enhancedPlayerOne->turn(LEFT);
		for (int i = 0; i < 1; i++)
		{
			enhancedGamesBoard->movePlayerOneSquare(enhancedPlayerOne);
		}
		enhancedGamesBoard->movePlayerOneSquare(enhancedPlayerOne);
		std::cout << "\nPlayer One has Moved into Cookie square\n";
		DisplayBoard(enhancedGamesBoard);

		std::cout << "\nPress Any Key To Continue . . . \n";

		getchar();

	}

// memory leak check
#ifdef MEMORYDEBUG
	_CrtDumpMemoryLeaks();
#endif


	return 0;
}