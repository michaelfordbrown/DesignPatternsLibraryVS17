// StatePattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

/*
// A Transformer Mech currently has: 
// - a location (in coordinates) 
// It can: 
// - fire its main weapon 
// - move its physical location 
*/

class Coordinates;

class AbstractMode; 

/*
// Coordinates have: 
// - longitude and latitude; 
// - height, as meters above current ground level 
*/

class Coordinates {
public: 
	double lat, longt, height;
	
// CONSTRUCTOR: 
	
	Coordinates(double lat, double longt, double height){
		this-> lat = lat; 
		this-> longt = longt; 
		this-> height = height; 

		cout << "Set coordinates to (lat, long height): " << lat << ", " << longt << ", " << height << endl;
	} 
};

class AbstractMode { 
public: 
	int firePower; 
	double firingRate; 
	int moveSpeed; 
	int armor; 
	string mode; 
};

class RobotMode : public AbstractMode {
public: 
	// CONSTRUCTOR: 
	RobotMode(){
		this-> firePower = 0; 
		this-> firingRate = 0; 
		this-> moveSpeed = 10; 
		this-> armor = 10; 
		this-> mode = "ROBOT"; 

		cout << "Setup Robot Mode: \n";
	}
};

class TankMode : public AbstractMode {
public: 

// CONSTRUCTOR: 
	TankMode(){
		this-> firePower = 25; 
		this-> firingRate = 0.75;
		this->moveSpeed = 50; 
		this->armor = 50; 
		this->mode = "TANK";

		cout << "Setup Tank Mode: \n";
	}
};

class BlasterCannonMode : public AbstractMode {
public: 

// CONSTRUCTOR: 
	BlasterCannonMode(){
		this-> firePower = 180; 
		this-> firingRate = 5.0; 
		this-> moveSpeed = 0; 
		this-> armor = 30; 
		this-> mode = "BLASTERCANNON"; 

		cout << "Setup Blast Cannon Mode: \n";
	}
};

class FlightMode : public AbstractMode {
public: 

// CONSTRUCTOR: 
	FlightMode(){
		this-> firePower = 15; 
		this-> firingRate = 0.5; 
		this-> moveSpeed = 105; 
		this-> armor = 20; 
		this-> mode = "FLIGHT"; 

		cout << "Setup Flight Mode: \n";
	}
};

class TransformerMech {
public: 

// Coordinates 
	Coordinates* location; 

// Field for Current State: 
	AbstractMode* currentMode; 
	
// NEW LINE 
	void fireMainWeapon(Coordinates* target); 
	
// NEW LINES: - - - - - - 
// CONSTRUCTOR: 
	
	TransformerMech(Coordinates* c, AbstractMode* am) {
		this-> location = c; 
		this-> currentMode = am; 
	} 
	
	void move(double degrees, double dist);
	void setMode(AbstractMode* s);
	void toggleMode();
};

// IN: a State 
// OUT: none 
// EFFECT: set Mech's State to the input 
void TransformerMech::setMode(AbstractMode* s) {
	this-> currentMode = s;
};

// IN & OUT: none 
// EFFECT: toggle Mech's state to the next one 
void TransformerMech::toggleMode() {
	if (currentMode->mode == "ROBOT")
	{
		cout << "Toogle Mode: Robot to ";
		currentMode = new TankMode();
	}
	
	if (currentMode->mode == "TANK")
	{
		cout << "Toogle Mode: Tank to ";
		currentMode = new BlasterCannonMode();
	}
	
	if (currentMode->mode == "BLASTERCANNON")
	{
		cout << "Toogle Mode: Blaster Cannon to ";
		currentMode = new FlightMode();
	}
	
	if (currentMode->mode == "FLIGHT")
	{
		cout << "Toogle Mode: Flight to ";
		currentMode = new RobotMode();
	}
}

void TransformerMech::fireMainWeapon(Coordinates* target) {
	int damage = currentMode->firePower; 
	double cooldown = currentMode->firingRate; 
	double timer = 0; 
	
	cout << "Fire Main Weapon: damage " << damage << " cooldown " << cooldown << " timer " << timer << endl;
/* 
// (some other code that: 
// - deals damage to the target 
// - increments the timer 
// from 0 to the cooldown time 
// - if timer reaches the cooldown time, 
// weapon can fire at the target again 
*/ 
}

void TransformerMech::move(double degrees, double dist) {
	int speed = currentMode->moveSpeed; 
	
	cout << "Move: Set speed to " << speed << endl;
	
/* 
// some other code that 
// moves this Transformer Mech
// in the given direction (degrees) 
// until it reaches the given distance (dist). 
// 
// The Transformer Mech will move 
// at its move speed, 
// which depends on its current state 
*/

}




int main()
{
	cout << "A Transformer Mech’s ability to move and fire its weapon will depend on what state it’s in.\n As a bipedal robot, it can move modestly, but it doesn’t have a main weapon.\n As a tank, it can move faster, have a higher armor rating, and use a standard weapon.\n As an immobile cannon, it will have an extremely powerful weapon at the cost of its movement ability.\n And as an airborne flyer, it can move extremely fast in all directions.\n";

	cout << "\nSet-up ship 1 \n";
	TransformerMech* p1tm1 = new TransformerMech(new Coordinates(40.7615576, -73.9940587, 0), new RobotMode());
	TransformerMech* p1tm2 = new TransformerMech(new Coordinates(40.7623624, -73.9939141, 0), new RobotMode()); 
	TransformerMech* p1tm3 = new TransformerMech(new Coordinates(40.7617993, -73.9933656, 0), new TankMode());

	cout << "\nSet-up ship 2 \n";
	TransformerMech* p2tm1 = new TransformerMech(new Coordinates(40.7720871, -73.963746, 0), new BlasterCannonMode()); 
	TransformerMech* p2tm2 = new TransformerMech(new Coordinates(40.7549617, -73.9696583, 8180), new FlightMode());
	TransformerMech* p2tm3 = new TransformerMech(new Coordinates(40.7483817, -73.9792723, 7990), new FlightMode());

	cout << "\nSet mode for ship 1 \n";
	p1tm1->setMode(new FlightMode()); 
	p1tm1->move(26.6, 0.00036); 

	cout << "\nSet mode for ship 2 \n";
	p1tm2->setMode(new FlightMode()); 
	p1tm2->move(-94.3, 0.000012); 

	cout << "\nSet mode for ship 3 \n";
	p1tm3->setMode(new FlightMode()); 
	p1tm3->move(132, 0.00045);

	cout << "\nSet up enemy mothership \n";
	Coordinates* enemyMothership = new Coordinates(40.8877895, -73.8721194, 10000);

	cout << "\nCommand ship 2 to move towards mothership\n";
	p2tm1->setMode(new FlightMode());

	cout << "\nShip 2 move towards mother ship\n";
	p2tm1->move(15.6, 0.00063); 
	p2tm2->move(15.6, 0.00064); 
	p2tm3->move(15.6, 0.00062);

	cout << "\nShip 2 change states, unloading weapon\n";
	p2tm1->setMode(new BlasterCannonMode()); 
	p2tm2->setMode(new BlasterCannonMode()); 
	p2tm2->setMode(new BlasterCannonMode());

	cout << "\nShip 2 open fire at enemy threat . .\n";
	p2tm1->fireMainWeapon(enemyMothership); 
	p2tm2->fireMainWeapon(enemyMothership); 
	p2tm3->fireMainWeapon(enemyMothership);
	
	
	getchar();
    return 0;
}

;