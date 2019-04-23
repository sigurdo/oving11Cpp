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

	cout << val1->getValue() << endl;
	cout << val2->getValue() << endl;
}

int main() {
	oppg3();

	cin.get();
	return 0;
}