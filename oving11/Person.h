#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person
{
	string fornavn;
	string etternavn;

	string fulltNavn();

public:
	Person(string fornavn, string etternavn);
	~Person();

	friend ostream& operator<<(ostream&, Person&);
};
