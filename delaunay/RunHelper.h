#pragma once
#include "TestsRunner.h"
#define TM TestMethod

class RunHelper
{
public:
	RunHelper() {
		srand(time(NULL));
		ConsoleHelper* ch = new ConsoleHelper();
		TestsRunner tr(ch);

		tmList tml = setTests(ch);
		tr.RunTests(1,tml);
	}

	tmList setTests(IMessage* rhmsg) {
		tmList* curtml = new tmList();
		curtml->push_back(TM(new Maur1(), rhmsg));
		curtml->push_back(TM(new Maur2(), rhmsg));
		curtml->push_back(TM(new Method3(), rhmsg));
		curtml->push_back(TM(new Method4(), rhmsg));
		curtml->push_back(TM(new Method5(), rhmsg));
		curtml->push_back(TM(new Method6(), rhmsg));

		return* curtml;
	}

	~RunHelper() {}

};
