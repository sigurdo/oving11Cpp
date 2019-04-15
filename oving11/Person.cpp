#include "Person.h"


Person::Person(string fornavn, string etternavn) :
	fornavn{ fornavn },
	etternavn{ etternavn }
{
	cout << "Opprettet person: " << *this << endl;
}


Person::~Person()
{
}

string Person::fulltNavn() {
	return fornavn + " " + etternavn;
}

ostream& operator<<(ostream& out, Person& pers) {
	out << pers.fulltNavn() << endl;

	return out;
}