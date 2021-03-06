// StrategyPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <random>
#include <iostream>
#include <string>


using namespace std;

/*
// IMPORTANT: 
// In C + +. use these 3 lines of code 
// in order to create 
// a new random number 
// per every run: 
 */ 
 //- ----- 

random_device rd; 
mt19937 gen(rd()); 
uniform_int_distribution<> dis(0, 2); 

//- -----

/* 
// ABSTRACT STRATEGY IMPLEMENTATION: 
// This has: 
// - the signature for the abstract algorithm 
 */ 

class AbstractStrategy {
public: 

// IN: (Your Choice) 
// OUT: (Your Choice) 
// (effect based on Subclass level) 
	
	virtual void Algorithm() = 0; 
};

/* 
// ABSTRACT STRATEGY IMPLEMENTATION: 
*/ 

class RPSStrategy {
public: 

// IN: none 
// OUT: a String 
//( either one of the three picks) 
// (effect based on Subclass level) 
	
	virtual string Algorithm() = 0;
};

class Strategy1 : public AbstractStrategy {
public: 
	
// Abstract Algorithm, 
// as Strategy1: 
	void Algorithm();
};

void Strategy1::Algorithm() {
	
// Implement this algorithm uniquely 
// based on this Strategy1 Class 

}

// Subclass Implementation for Rock: 

class Rock : public RPSStrategy {
public: 

// Abstract Algorithm, as Rock: 
	string Algorithm();
}; 

string Rock::Algorithm() {

// (any other code you want here) 
	return "Rock"; 
};

// Subclass Implementation for Paper: 

class Paper : public RPSStrategy {
public: 
	
// Abstract Algorithm, as Paper: 
	string Algorithm(); 
}; 

string Paper::Algorithm() {
	
// (any other code you want here) 
	return "Paper"; } 

// Subclass Implementation for Scissors: 

class Scissors : public RPSStrategy{ 
public: 
	
// Abstract Algorithm, as Scissors: 
	
	string Algorithm(); 
}; 

string Scissors::Algorithm() { 

// (any other code you want here) 
	
	return "Scissors"; 
};







/*
// A Rock-Paper-Scissors Game has: 
// - the String values for 
// Rock, Paper, and Scissors 
// It can: 
// - generate a random string 
// from either of the three 
// - check if a player wins 
 */

class RPSGame {
public: 
	string RPSVals[3] = {"Rock", "Paper", "Scissors"};
	string RPSGet(); 
	bool checkWin(string s1, string s2);
}; 

/* 
// INPUT: none 
// OUTPUT: a String 
// EFFECT: randomly return 
// either Rock, Paper, or Scissors 
 */

string RPSGame::RPSGet() {
	int i = dis(gen) % 3;
	return RPSVals[i];
} 

/* 
// INPUT: 2 Strings 
// OUTPUT: a Boolean 
// EFFECT: return true if 
// 1st string defeats 2nd string, 
// false otherwise 
 */

bool RPSGame::checkWin(string s1, string s2) {
	if (s1 == s2) return false; 
	bool c1 = (s1 == "Paper") && (s2 == "Rock"); 
	bool c2 = (s1 == "Scissors") && (s2 == "Paper"); 
	bool c3 = (s1 == "Rock") && (s2 == "Scissors"); 
	return c1 || c2 || c3;
} 


int main()
{
	RPSGame* r = new RPSGame(); 
	string aiPick = r->RPSGet(); 

	// Enter either "Paper", "Scissors", 
	// or "Rock" 
	// for the variable myPick 
	// (Normally, a player would 
	// input a value for this) 
	// For now, default pick to Paper 
	
	string myPick = "Paper";

	RPSStrategy* stratPattern = new Rock();

	if (aiPick == "Rock") {
		stratPattern = new Paper(); 
	} 
	
	if (aiPick == "Paper") {
		stratPattern = new Scissors(); 
	} 
	
	if (aiPick == "Scissors") {
		stratPattern = new Rock(); 
	}

	myPick = stratPattern->Algorithm(); 
	
	std::cout << " AI Pick: " << aiPick << "\n";
	std::cout <<" My Pick: " << myPick << "\n";
	std::cout << myPick << " v.s. " << aiPick << "\n";
	if (r->checkWin(myPick, aiPick)) 
		std::cout <<" YOU WIN!" << "\n"; 
	else 
		std::cout <<" sorry, maybe next time..." << "\n";

	getchar();
    return 0;
}

