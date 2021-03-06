// DecoratorPattern.cpp : Defines the entry point for the console application.
//

/* MMORPG Characters: 

In Massively-Multiplayer Online Role-Playing fantasy games before, 
playable characters often fall into certain character archetypes 
- i.e., the Healer, the Wizard, the Archer, the Armoured Knight, and so on. 
And as you play the game longer, 
your player characters gradually improve and become stronger.
*/

#include "stdafx.h"

#include <iostream>
#include <memory>

#ifdef MEMORYDEBUG
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#endif

using namespace std;

/* 
// DECORATOR IMPLEMENTATION: 
// Character abstraction with: 
// - a single skill 
// - health points (int) 
// - attack power (int)
 */

class Character {
public: 

// IN: - a Target Character 
// OUT: none 
// (Implementation done 
// by Subclasses) 
	virtual void skill(shared_ptr<Character> target) = 0; 
	int hp; 
	int atk; 
};

/*
When a character is newly created, 
it will be an instance of our default class . 
Hence, it needs to be an extension of our main abstraction.
*/

class DefaultChar:public Character {

// Common Procedure, 
// implemented as Base Object 

public: 
	void skill(shared_ptr<Character> target);

// (include any other fields 
// and procedures as you wish) 
// CONSTRUCTOR: 
	DefaultChar() {
		this->hp = 12; 
		this->atk = 1;

#ifdef MEMORYDEBUG
		cout << "Created DefaultChar\n";
#endif
	} 

#ifdef MEMORYDEBUG	
	~DefaultChar()
	{
		cout << "Destroyed DefaultChar\n";
	}
#endif
}; 

void DefaultChar::skill(shared_ptr<Character> target) {
	cout << "Default Skill: No Attack.\n";
}

/*
The Decoration class is also an abstraction, 
which generalizes every augmentation and 
decoration you’ll apply to your object. 
So let’s apply this concept to our situation. 
We need to create a generalization for every augmentation to our characters:
*/

class Decoration : public Character {
// Common Procedure, 
// implemented as Decoration 

public: 
	shared_ptr<Character> prevDeco;
	void skill(shared_ptr<Character> target);

// CONSTRUCTOR:
	Decoration(shared_ptr<Character> c) {
		this->prevDeco = c; 

#ifdef MEMORYDEBUG
		cout << "Created Decoration\n";
#endif
	} 

#ifdef MEMORYDEBUG	
	~Decoration()
	{
		cout << "Destroyed Decoration\n";
	}
#endif
};

void Decoration::skill(shared_ptr<Character> target) {
	
// (Implementation done by Subclasses) 
// include any other code you want 

	prevDeco->skill(target);

};

/*
This Greatsword class is an extension of the Decoration class we’ve developed earlier.
It has all the fields and methods of the Decoration Class, plus its own unique traits. */

class GreatSword : public Decoration {
public: 
	
// Weapon damage 
	int damage = 3; 
	
// Common Procedure, 
// implemented as GreatSword 
// (will be an Attack) 
	
	void skill(shared_ptr<Character> target);
	
// CONSTRUCTOR: 
	
	GreatSword(shared_ptr<Character> c):Decoration( c){
		this->prevDeco = c;

#ifdef MEMORYDEBUG
		cout << "Created GreatSword\n";
#endif
	}

#ifdef MEMORYDEBUG	
	~GreatSword()
	{
		cout << "Destroyed GreatSword\n";
	}
#endif
}; 

void GreatSword:: skill(shared_ptr<Character> target) {
	
// ATTACK TARGET: 

	target-> hp -= damage; 
	prevDeco->skill(target); 
	cout << typeid(this).name() << " Attack with " << damage << " hit points.\n";
}

/*
Let’s also design a Fiery Battle Axe. 
Like the GreatSword, 
it also has an attack as its skill() method.
*/
class FieryBattleAxe : public Decoration {
public: 
	
// Weapon damage 

	int damage = 2; 
	int magicPower = 2; 
	
// Common Procedure, 
// implemented as FieryBattleAxe 
// (will be an Attack) 

	void skill(shared_ptr<Character> target);
	
// CONSTRUCTOR: 
	
	FieryBattleAxe(shared_ptr<Character> c) : Decoration( c){
		this-> prevDeco = c; 

#ifdef MEMORYDEBUG
		cout << "Created FieryBattleAxe\n";
#endif
	}

#ifdef MEMORYDEBUG	
	~FieryBattleAxe()
	{
		cout << "Destroyed FieryBattleAxe\n";
	}
#endif
}; 

void FieryBattleAxe::skill(shared_ptr<Character> target) {
	
// ATTACK TARGET: 
	
	target->hp -= damage + magicPower; 
	prevDeco->skill( target); 
	cout << typeid(this).name() << " Attack with " << damage << " hit points.\n";
}

/*
we can also create a Shield too:
*/

class GoldenShield : public Decoration {
public: 
	int armorBonus = 10; 
	
// Common Procedure, implemented as GoldenShield 
	
	void skill(shared_ptr<Character> target);
	
// CONSTRUCTOR: 
	
	GoldenShield(shared_ptr<Character> c):Decoration(c){
		this-> prevDeco = c; 

#ifdef MEMORYDEBUG
		cout << "Created GoldenShield\n";
#endif
	}

#ifdef MEMORYDEBUG	
	~GoldenShield()
	{
		cout << "Destroyed GoldenShield\n";
	}
#endif
}; 

void GoldenShield::skill(shared_ptr<Character> target) {
	this-> hp += armorBonus; 
	prevDeco-> skill(target);
}

int main()
{
	{
		/* To create a new character, you’ll set its data type as the abstract class but initialize it as the default class. */

		shared_ptr<Character> me = make_shared<DefaultChar>();

		/* To add decorations to a new character, you’ll simply re-initialize that character as a Decorator object with that same character as the input: */

		me = make_shared<GoldenShield>(me);

		/* You can even add more decorations simultaneously by creating a Decoration within a Decoration : */

		me = make_shared<GreatSword>(make_shared<GoldenShield>(me));

		/* When you make function calls to common procedures, ALL attached Decorators, as well as the Default object, will be called as well. */

		me = make_shared<GreatSword>(make_shared<FieryBattleAxe>(me));

		/*In the second line below, we call the function skill(), targeting a character (ATTACK TARGET):*/
		/*
			Call to Skill, from object ‘me’:
				- GreatSword.Skill() executes
				- FieryBattleAxe.Skill() executes
				- DefaultChar.Skill() executes
		*/

		shared_ptr<Character> you = make_shared<DefaultChar>();
		me->skill(you);

		/* With no Call to Skill, from object ‘me’: 
			- GreatSword.Skill() executes 
			- FieryBattleAxe.Skill() executes 
			- DefaultChar.Skill() executes 
		*/

		you->skill(me);

		getchar();
	}
	#ifdef MEMORYDEBUG
		_CrtDumpMemoryLeaks();
	#endif

    return 0;
}

