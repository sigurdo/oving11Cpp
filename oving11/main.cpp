#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <random>
#include <time.h>

#include "Person.h"
#include "LinkedList.h"
#include "functionTemplates.cpp"

using namespace std;

void replace(vector<string>& vec, string old, string replacement) {
	for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
		if (*it == old) {
			it = vec.erase(it);
			it = vec.insert(it, replacement);
		}
	}
}

void replace(set<string>& sett, string old, string replacement) {
	for (set<string>::iterator it = sett.begin(); it != sett.end(); it++) {
		if (*it == old) {
			it = sett.erase(it);
			it = sett.insert(it, replacement);
		}
	}
}

void oppg1() {
	vector<string> ting1{ "abc", "abc", "ikke abc", "abc", "ikke abc" };

	replace(ting1, "abc", "def");
	for (vector<string>::iterator it = ting1.begin(); it != ting1.end(); it++) {
		cout << *it << endl;
	}

	cout << "-----Set:-----" << endl;

	set<string> ting2{ "abc", "abc", "ikke abc", "abc", "ikke abc" };
	for (set<string>::iterator it = ting2.begin(); it != ting2.end(); it++) {
		cout << *it << endl;
	}

	replace(ting2, "abc", "ghi");
	for (set<string>::iterator it = ting2.begin(); it != ting2.end(); it++) {
		cout << *it << endl;
	}
}

void oppg2() {
	Person tester[] {
		{ "Jan", "One" },
		{ "Jan", "Two" },
		{ "Jan", "Three" },
		{ "Jan", "Four" },
		{ "Jan", "Five" },
		{ "Jan", "Six" },
		{ "Jan", "Seven" }
	};

	list<Person> testList;

	for (int i = 0; i < 7; i++) insertOrdered(testList, tester[i]);

	for (auto it = testList.begin(); it != testList.end(); it++) cout << *it << endl;
}

void oppg3() {
	LinkedList::LinkedList list1;
	string str = "Halla";
	LinkedList::Node* val1 = list1.insert(list1.begin(), str);
	str = "Halla2";
	LinkedList::Node* val2 = list1.insert(list1.begin(), str);
	str = "Halla3";
	LinkedList::Node* val3 = list1.insert(list1.begin(), str);
	str = "Halla4";
	LinkedList::Node* val4 = list1.insert(list1.begin(), str);
	str = "Halla5";
	LinkedList::Node* val5 = list1.insert(list1.begin(), str);

	list1.remove(val2);
	list1.remove("Halla3");
	list1.remove("Hallaaa");

	cout << list1 << endl;

	cout << list1.find("Halla")->getValue() << endl;

	/*
		b)
			Lenkede lister er bedre fordi at når du legger til flere elementer så slipper du å flytte på alle elementene som lå der fra før av. Arrays kalles tabeller på norsk fordi de er basert på å ha en forhåndsdefinert størrelse, akkurat som vanlige tabeller. Det samme gjelder vector.
			Hvis jeg nå skulle laget en stack eller queue ville jeg lagd en ny klasse som arvet fra LinkedList og som er en linked list, bare med pop og push funksjoner som tar seg av innholdsadministrasjon.
	*/
}

void oppg4() {
	cout << maximum<int>(3, 5) << endl;
	cout << maximum<char>('a', 'A') << endl;

	Person pers1{ "Fettmann", "Bollerud" };
	Person pers2{ "Fettdame", "Bollesen" };

	Person pers3 = maximum<Person>(pers1, pers2);
	cout << pers3 << endl;

	vector<Person> pers{
		Person{"Osama", "Bin Laden"},
		Person{"Osama", "Bin Laban"},
		Person{"Marme", "Laden"},
		Person{"Glemteå", "Laden"},
		Person{"Hvorvardetjeg", "Laden"}
	};
	cout << endl << pers << endl;

	shuffle(pers);
	cout << pers << endl;
}

int main() {
	srand(time(nullptr));

	cin.get();
	return 0;
}