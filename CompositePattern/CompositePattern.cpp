// CompositePattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>

#ifdef MEMORYDEBUG
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#endif

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
*/

class Component { 
public: string name; 
		shared_ptr<tm> dateCreated; 
		shared_ptr<tm> dateLastModified; 
/* 
// INPUT: a String 
// Custom Constructor for the Component Class, 
// Upon creation, the dates created and last modified 
// are set to the current date an object would be created 
*/ 

	Component( string n) { 
		this-> name = n; 
		this-> dateCreated = make_shared<tm>(); 
		this-> dateLastModified = make_shared<tm>();

#ifdef MEMORYDEBUG
		cout << "Created Component\n";
#endif
	}

#ifdef MEMORYDEBUG
	~Component()
	{
		cout << "Destroyed Component\n";
	}
#endif
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

#ifdef MEMORYDEBUG
		cout << "Created File\n";
#endif
	}

#ifdef MEMORYDEBUG
	~File()
	{
		cout << "Destroyed File\n";
	}
#endif

};

// General Group Class (a.k.a. Folder): 
// contains all fields and methods 
// defined at Component 
// Also has: 
// - a List of Components, which can 
// contain either Items or Groups 
class Folder : public Component {
public: 
	vector<shared_ptr<Component>> contents;
	Folder(string n) : Component(n) {
#ifdef MEMORYDEBUG
		cout << "Created Folder\n";
#endif
	}

#ifdef MEMORYDEBUG
		~Folder()
		{
			cout << "Destroyed Folder\n";
		}
#endif
};

int main()
{
	{
		shared_ptr<Folder> top = make_shared<Folder>("Top Folder");
		shared_ptr<File> a = make_shared<File>("A", "Spreadsheet");
		shared_ptr<File> b = make_shared<File>("B", "Picture");
		shared_ptr<Folder> mid = make_shared<Folder>("Mid Folder");

		top->contents.push_back(a);
		top->contents.push_back(b);
		top->contents.push_back(mid);

		shared_ptr<File> c = make_shared<File>("C", "Video");
		shared_ptr<File> d = make_shared<File>("D", "Letter Document");
		shared_ptr<Folder> bot = make_shared<Folder>("Bottom Folder");

		mid->contents.push_back(c);
		mid->contents.push_back(d);
		mid->contents.push_back(bot);

		shared_ptr<File> e = make_shared<File>("E", "PDF");
		bot->contents.push_back(e);

		std::cout << top->name << "\n";


		for (shared_ptr<Component> i : top->contents) {
			std::cout << "" << i->name << "\n";
		}

		for (shared_ptr<Component> i : mid->contents) {
			std::cout << "" << i->name << "\n";
		}

		for (shared_ptr<Component> i : bot->contents) {
			std::cout << "" << i->name << "\n";
		}
	}

	getchar();

#ifdef MEMORYDEBUG
	_CrtDumpMemoryLeaks();
#endif

    return 0;
}

