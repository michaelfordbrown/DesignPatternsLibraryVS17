// ObserverPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>

#include <algorithm>
#include <memory>
#include <string>
#include <iostream>

using namespace std;

// A Device module has: 
// - an alert status (a Boolean) 
// - notification updates (as string) 
// - a Location, as a String
// It can: 
// - push alerts 
// - update alerts & notifications 

/*
// All Observing Classes implement 
// an Observer abstraction 
// It can: 
// - update object data based on subjects 
// Observing Classes may need 
// a List of Subjects to access 
// (added on Observer Class) 
 */

class Observer {
public: 
	virtual void update(string loc) = 0;
}; 

/*
// All Subject Classes implement 
// a Subject abstraction 
// It can: 
// - notify observers 
// - add/ remove observers in its update list 
// Subject Classes also need 
// a List of Observers to Update 
// (added on Subject Class) 
 */

class Subject {
public: 
	virtual void notifyObservers() = 0; 
	virtual void addObs(Observer* o) = 0;
	virtual void deleteObs(Observer* o) = 0;
	; 
};

/*
// A single terrorist has: 
// - a Location, as a String 
// - a List of Observer Objects 
// Also implements the Subject Interface; 
// (will need to implement its methods) 
 */

class Terrorist : public Subject {
private:
	// Dynamic container 
	std::vector<std::unique_ptr<Observer>> obs; 

public: 
	string location;

// NEW: from Subject Interface 
	void notifyObservers() {
		for (auto it(obs.begin()), ite(obs.end()); it != ite; ++it)
		{
			(*it)->update(this->location);
		}
	};

	void addObs(Observer* o) {
		obs.push_back(std::move(std::unique_ptr<Observer>(o)));
	};

	void deleteObs(Observer* o) {};

}; 

// A Device module has: 
// - an alert status (a Boolean) 
// - notification updates (as string) 
// - a Location, as a String
// It can: 
// - push alerts 
// - update alerts & notifications 
// Also implements the Observer Interface; 
// (will need to implement its methods) 

class Module : public Observer {
public: 
	string location; 
	bool alert; 
	string notifications; 
	
// EFFECT: if alerts is true, 
// print an alert notice 
	
	void sendAlerts(){
		if (alert) {
			std::cout << "ALERT: " << notifications << "Agents in " << location << "\n";
		}
	}

	// INPUT: a Terrorist Object 
	// OUTPUT: none 
	// EFFECT: if Terrorist and this 
	// module’s locations are the same, 
	// set Alert to true and 
	// update the notification. 
	// Afterwards, send the alerts 

	void update(string loc) {
		if (this->location == loc) {
			this->alert = true;
			this->notifications = "Terrorist Nearby";
		}
		else
		{
			this->alert = false;
			this->notifications = "";
		}
		sendAlerts();
	};
};

int main()
{
	// - - - - - - - - - -- - - - -- - - - -- - - - - 
	// Part 1: Create all Data Objects 
	
	Terrorist* t = new Terrorist(); 
	Module* m1 = new Module(); 
	Module* m2 = new Module(); 
	Module* m3 = new Module(); 
	Module* m4 = new Module(); 
	
	// Part 2: Add all Observers to Subject's List 
	
	t->addObs(m1); 
	t->addObs(m2); 
	t->addObs(m3); 
	t->addObs(m4);

	// Create all locations 
	
	string locs[] = {
		"Los Angeles", 
		"Chicago", 
		"New York", 
		"Seattle", 
		"Cleveland", 
		"Boston", 
		"San Francisco", 
		"Miami", 
		"St. Louis", 
		"Dallas" 
	}; 
	
	// Part 3: Set Observers to their locations 
	
	m1->location = locs[1]; 
	m2->location = locs[4]; 
	m3->location = locs[5]; 
	m4->location = locs[9]; 
	
	// As the Terrorist relocates 
	// all over the US,
	// it will notify all Device Modules 
	// of its location. 
	// Modules will trigger when a Terrorist is nearby. 
	
	for( int i = 0; i < 10; i++) {
		t->location = locs[i]; 
		t->notifyObservers(); 
	} 

	// - - - - - - - - - -- - - - -- - - - -- - - - -

	getchar();

    return 0;
}

