// SingletonPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream > 
#include <random>

#include <string>

using namespace std;

// A Team has: 
// - a Name (String) 
// - any other fields you want 
class Team {
public: 
	
	string name; 

// CONSTRUCTOR: 
// INPUT: a Team Name (String) 
	
	Team(string n) {
		name = n;
	} 
};

// A Championship has: 
// - a Championship Team 
// it can: 
// - Run a Playoffs Tournament with 8 Teams 

class Championship {
private: 

// Singleton Component #1: 
// - Constructor with 
// private modifier 
// (cannot be accessed 
// from outside the Class) 
	Championship() {}; 

// - - - - - - - - - - - - - - - - - - - - -

/* 
// HELPING FUNCTION to playoffs(): 
// INPUT: - Two Teams: a & b 
//- an integer (to determine winners) 
// OUTPUT: a Team 
// EFFECT: Match between two teams a & b, 
// with the winner as the Output 
 */ 
 // (to be implemented later) 
	Team* match(Team* ta, Team* tb, int odds); 

// Singleton Component #2: 
// - a class object as a field 
// - has Static Modifier 
//( can access field from the class itself) 
// - has private Modifier 
//( cannot be accessed 
// from outside the Class) 
	static Championship* c; 

public: 
// Singleton Component #3 
// - a getObject() method 
// INPUT: none 
// OUTPUT: a Championship object 
// EFFECT: returns the 
// Singleton Championship object 
	static Championship* getChamp();

public: 
	Team* champion;

// INPUT: 8 Teams 
// OUTPUT: none 
// EFFECT: The Playoffs Simulator: 
// - match up the teams pair by pair, 
// - winning teams advance 
// to the next matches 
// - last team becomes 
// the Champion Team 
// NOTE: if a championship already 
// has a champion team, 
// playoffs() will return 
// without simulating the Playoffs 
	void playoffs(
		Team* t1, 
		Team* t2, 
		Team* t3, 
		Team* t4, 
		Team* t5, 
		Team* t6, 
		Team* t7, 
		Team* t8) 
{
// return if champion team already present 
	if (champion != NULL) return;

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
	uniform_int_distribution < > dis( 1, 100); 
	
//- ----- 
// QUARTER -> SEMIFINALS: 

	Team* semi1 = match( t1, t8, dis( gen) % 100); 
	Team* semi2 = match( t2, t7, dis( gen) % 100); 
	Team* semi3 = match( t3, t6, dis( gen) % 100); 
	Team* semi4 = match( t4, t5, dis( gen) % 100); 
	std:: cout << "\n"; 

// SEMIFINALS -> FINALS: 
	Team* finals1 = match( semi1, semi4, dis( gen) % 100); 
	Team* finals2 = match( semi2, semi3, dis( gen) % 100); 
	std:: cout << "\n";

// FINALS -> CHAMPIONSHIP: 

	Team* champ = match( finals1, finals2, dis( gen) % 100); 
	this-> champion = champ;
	std:: cout << "Team " << champ->name << " WIN THE CHAMPIONSHIP!" << "\n";
	}
}; 

// HELPING FUNCTION to playoffs(): 
Team* Championship::match(Team* ta, Team* tb, int odds) {
	if (odds %2 == 0) {
		std::cout << ta->name << " Defeats " << tb->name << "\n";
		return ta;
	} 
	else {
		std::cout << tb->name + " Defeats " + ta->name << "\n";
		return tb;
	}
}

Championship* Championship::getChamp() {
	if (c == NULL) {
		c = new Championship(); 
	} 
	return c;
 };

Championship* Championship::c = NULL;

int main()
{
	// Create 8 Teams: 

	Team* contender1 = new Team("Archers"); 
	Team* contender2 = new Team("Bobcats");
	Team* contender3 = new Team("Centurions"); 
	Team* contender4 = new Team("Danger Zone"); 
	Team* contender5 = new Team("Energy"); 
	Team* contender6 = new Team("Flames");
	Team* contender7 = new Team("Guards");
	Team* contender8 = new Team("Hunters" ); 
	
//Using Singleton: 
	Championship::getChamp()->playoffs( contender1, contender2, contender3, contender4, contender5, contender6, contender7, contender8);

		
	getchar();
    return 0;
}

