#pragma once
#include <iostream>
#include <string>
#include <list>

#include "Person.h"

using namespace std;

class Person
{
	string fornavn;
	string etternavn;

	string fulltNavn();

public:
	Person(string fornavn, string etternavn);
	~Person();

	friend void insertOrdered(list<Person>& l, const Person& p);

	friend ostream& operator<<(ostream&, Person&);

	friend bool operator>(Person& pers1, Person& pers2);
};
