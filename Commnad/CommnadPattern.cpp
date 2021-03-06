// Commnad.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
#include<functional>

#include<vector>

using namespace std;

struct think {
	void operator()() {
		cout << "think ";
	}
};

struct walk {
	void operator()() {
		cout << "walk ";
	}
};

struct hide {
	void operator ()() {
		cout << "hide ";
	}
};

/*
// Overhead in using function better to use template (inline) below
void doit(function<void()> f) {
	f();
}
*/

template <typename FUNCTION>
void doit(FUNCTION f) {
	f();
}

void thisIsATest() {

	doit(think{});
	doit(walk{});

	hide()();

	function<void()> f{ walk{} };
	f();
	doit(f);

	f = think{};
	f();
}

struct macroCommand:vector<function<void()>> {
	using vector<function<void()>>::vector;
	void operator()() {
		for (auto &x : *this) {
			if (x)x();
		}
	}
};

void testMacroCmd() {
	macroCommand m;
	m.push_back(think{});
	m.push_back(walk{});
	m.push_back(m);
	m();
}
int main()
{
	cout << "This Is A Test\n";
	thisIsATest();

	cout << "\nTest Macro Command\n";
	testMacroCmd();

	getchar();
    return 0;
}

