#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "Person.h"

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

int main() {
	Person test1{ "Jan", "Ove" };

	cin.get();
	return 0;
}