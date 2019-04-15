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

void insertOrdered(list<Person>& l, const Person& p) {
	list<Person>::iterator it = l.begin();
	while (it != l.end() && it->etternavn < p.etternavn) it++;
	l.insert(it, p);
}

ostream& operator<<(ostream& out, Person& pers) {
	out << pers.fulltNavn();

	return out;
}