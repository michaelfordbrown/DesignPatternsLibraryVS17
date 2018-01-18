// CompositePattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

/* 
// Component is the superclass 
// which File and Folder classes extend 
// It has: 
// - Name, as a String 
// - the Date Created 
// - the Date Last Modified 
// It can: 
// - rename itself 
// - update the Last Modified date 

class Component {
public: string name;
	tm* dateCreated; 
	tm* dateLastModified;
};
*/

class Component { 
public: string name; 
		tm* dateCreated; 
		tm* dateLastModified; 
/* 
// INPUT: a String 
// Custom Constructor for the Component Class, 
// Upon creation, the dates created and last modified 
// are set to the current date an object would be created 
*/ 

	Component( string n) { 
		this-> name = n; 
		this-> dateCreated = new tm(); 
		this-> dateLastModified = new tm();
	}
};

/*
// General Item Class (a.k.a. File): 
// contains all fields and methods defined at Component 
// Also has: 
// - a file type, as a string 
*/

class File : public Component {
public: string fileType;

/* 
// INPUT: a String 
// Custom Constructor for the File Class, 
// Follows the same procedure 
// as the superclass, 
// Then sets the file type 
*/ 

	File(string n, string f) : Component(n) {
		this->fileType = f; 
	} 
};

// General Group Class (a.k.a. Folder): 
// contains all fields and methods 
// defined at Component 
// Also has: 
// - a List of Components, which can 
// contain either Items or Groups 
class Folder : public Component {
public: vector <Component>* contents = new vector <Component>();
		Folder( string n) : Component( n){
		}
};

int main()
{

	Folder* top = new Folder(" Top Folder");
	File* a = new File(" A", "Spreadsheet");
	File* b = new File(" B", "Picture"); 
	Folder* mid = new Folder(" Mid Folder"); 

	top->contents->push_back(*a); 
	top->contents->push_back(*b); 
	top->contents->push_back(*mid); 

	File* c = new File(" C", "Video"); 
	File* d = new File(" D", "Letter Document"); 
	Folder* bot = new Folder(" Bottom Folder"); 

	mid->contents->push_back(*c); 
	mid->contents->push_back(*d); 
	mid->contents->push_back(*bot); 

	File* e = new File(" E", "PDF"); 
	bot->contents->push_back(*e);

	std::cout << top->name << "\n"; 
	for (Component i : *top->contents) {
		std::cout << "" << i.name << "\n";
	} 
	
	for (Component i : *mid->contents) {
		std::cout << "" << i.name << "\n";
	} 
	
	for (Component i : *bot->contents) {
		std::cout << "" << i.name << "\n";
	}

	getchar();

    return 0;
}

