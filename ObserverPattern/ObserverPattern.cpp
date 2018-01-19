// ObserverPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>

#include <algorithm>
#include <memory>

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
	virtual void update() = 0; 
	// enter any other methods here
};

/*
// Observing Classes have: 
// - working version of 
// the update() method 
// - any number of additional 
// fields & methods 
 */ 

class ObservingClass : public Observer {
public: 

// enter any key fields here; 
// INPUT: (optional) 
// OUTPUT: none 
// EFFECT: updates data 
// in response to subject 
	void update() {

	// make any changes to observer's 
	// key fields here 

	} 
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
	virtual void addObs(Observer o) = 0;
	virtual void deleteObs(Observer o) = 0;
	// enter any other methods here 
};

/* 
// Subject Classes have: 
// - a List of Observers to notify 
// - a working version of notifyObservers() 
// - any number of additional fields & methods 
// Subject Classes also need 
// a List of Observers to Update // (added on Subject Class) 
 */ 

class SubjectClass : public Subject {
	// enter any key fields here;
private:
	vector<Observer>* obs = new vector <Observer>();

public: 
	
// INPUT: (optional) 
// OUTPUT: none 
// EFFECT: updates all observers 
// in list of any changes 
	void notifyObservers(){
		for (var o : obs) { 
			o-> update();
		} 
	}

// Add/ Delete Methods: 
// INPUT: - an Observer 
// OUTPUT: none 
// EFFECT: updates data 
// in response to subject 
	
	void addObs( Observer* o) {};
	void deleteObs( Observer* o) {};
};


int main()
{
    return 0;
}

