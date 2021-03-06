#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include "Person.h"
#include "LinkedList.h"

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
			Lenkede lister er bedre fordi at n�r du legger til flere elementer s� slipper du � flytte p� alle elementene som l� der fra f�r av. Arrays kalles tabeller p� norsk fordi de er basert p� � ha en forh�ndsdefinert st�rrelse, akkurat som vanlige tabeller. Det samme gjelder vector.
			Hvis jeg n� skulle laget en stack eller queue ville jeg lagd en ny klasse som arvet fra LinkedList og som er en linked list, bare med pop og push funksjoner som tar seg av innholdsadministrasjon.
	*/
}

int main() {
	oppg3();

	cin.get();
	return 0;
}