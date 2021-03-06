// FactoryPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>

#ifdef MEMORYDEBUG
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#endif

using namespace std;

/* 
// A Sports Ball has: 
// - the Type of ball it is 
// - an array of materials used 
// to manufacture it 
// - its size, as a radius (inches) 
// - any additional comments required 
// - the company brand that made it 
// - a product name 
*/ 

class SportsBall {
public:
	string type; 
	vector <string> materialsUsed; 
	float radius; 
	string comments; 
	string make; 
	string modelName; 

#ifdef MEMORYDEBUG
	SportsBall()
	{
		cout << "Created SportsBall\n";
	}

	~SportsBall()
	{
		cout << "Destroyed SportsBall\n";
	}
#endif
};

class BallFactory {
public: 

/*
// INPUT: none 
// OUTPUT: a Sports Ball object 
// EFFECT: Creates a Sports Ball; 
// Classes that implement this will have 
// their own distinctions in making one 
*/ 
	virtual shared_ptr<SportsBall> createBall() = 0;
};

// The Basketball Maker: 
// - creates basketball objects 
// with distinct fields 
class BasketballMaker : public BallFactory {
public: 
// (method implements the 
// Interface Version) 
// EFFECT: Creates a sports ball 
// as a Basketball 
	shared_ptr<SportsBall> createBall() { 
		shared_ptr<SportsBall> b = make_shared<SportsBall>();
		b->type = "Basketball"; 
		b->materialsUsed.reserve(3); 
		b->materialsUsed.push_back("rubber"); 
		b->materialsUsed.push_back("fiber"); 
		b->materialsUsed.push_back("synthetic composite");
		b->radius = 4.8f; 
		b->make = "Spalding"; 
		b->modelName = "Series Basketball"; 
		return b;
	}

#ifdef MEMORYDEBUG
	BasketballMaker()
	{
		cout << "Created BasketballMaker\n";
	}

	~BasketballMaker()
	{
		cout << "Destoryed BasketballMaker\n";
	}
#endif
};


// The Baseball Maker: 
// - creates baseball objects with distinct fields 
class BaseballMaker : public BallFactory { 
// (method implements the Interface Version) 
// EFFECT: Creates a sports ball as a Basketball 
public:
	shared_ptr<SportsBall> createBall() {
		shared_ptr<SportsBall> b = make_shared<SportsBall>();
		b->type = "Baseball"; 
		b->materialsUsed.reserve(6); 
		b->materialsUsed.push_back("cork");
		b->materialsUsed.push_back("wool"); 
		b->materialsUsed.push_back("poly/ cotton"); 
		b->materialsUsed.push_back("cowhide"); 
		b->materialsUsed.push_back("yarn"); 
		b->materialsUsed.push_back("composite rubber"); 
		b->radius = 1.45f; 
		b->make = "Rawlings"; 
		b->modelName = "MLB Official Baseball"; 
		return b;
	}

#ifdef MEMORYDEBUG
	BaseballMaker()
	{
		cout << "Created BaseballMaker\n";
	}

	~BaseballMaker()
	{
		cout << "Destoryed BaseballMaker\n";
	}
#endif
};


// The Soccerball Maker: 
// - creates soccer ball objects with distinct fields 
class SoccerballMaker : public BallFactory {
public:
	// (method implements the Interface Version) 
	// EFFECT: Creates a sports ball as a Soccer ball
	shared_ptr<SportsBall> createBall() {
		shared_ptr<SportsBall> b = make_shared<SportsBall>();
		b->type = "SoccerBall";
		b->materialsUsed.reserve(2);
		b->materialsUsed.push_back("polyester");
		b->materialsUsed.push_back("latex rubber");
		b->radius = 4.32f;
		b->make = "Adidas";
		b->modelName = "FIFA World Cup Football";
		return b;
	}

#ifdef MEMORYDEBUG
	SoccerballMaker()
	{
		cout << "Created SoccerballMaker\n";
	}

	~SoccerballMaker()
	{
		cout << "Destoryed SoccerballMaker\n";
	}
#endif
};
		
int main()
{
	{
		// Creating the Factories 
		shared_ptr<BallFactory> f1 = make_shared<BasketballMaker>();
		shared_ptr<BallFactory> f2 = make_shared<BaseballMaker>();
		shared_ptr<BallFactory> f3 = make_shared<SoccerballMaker>();

		// Creating a basketball object: 
		// Use the Basketball Factory 
		// to make Basketballs 
		shared_ptr<SportsBall> bb1 = f1->createBall();

		// Creating a baseball object: 
		// Use the Baseball Factory 
		// to make Baseballs 
		shared_ptr<SportsBall> bb2 = f2->createBall();

		// Creating a soccer ball object: 
		// Use the Baseball Factory 
		// to make Soccer Ball 
		shared_ptr<SportsBall> bb3 = f3->createBall();

		// TESTING: 
		// This line should print out "Basketball" 
		std::cout << bb1->type << std::endl;

		// This line should print out "Baseball" 
		std::cout << bb2->type << std::endl;

		// This line should print out "Soccerball" 
		std::cout << bb3->type << std::endl;
	}
	getchar();

#ifdef MEMORYDEBUG
	_CrtDumpMemoryLeaks();
#endif
    return 0;
}

