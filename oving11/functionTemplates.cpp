//#include <iostream>
#include <vector>
#include <random>

template<class Type> Type maximum(Type a, Type b) {
	return a > b ? a : b;
}

template<class T> void shuffle(std::vector<T>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		int newPos = rand() % vec.size();
		T temp = vec[newPos];
		vec[newPos] = vec[i];
		vec[i] = temp;
	}
}

template<class T> std::ostream& operator<<(std::ostream& out, std::vector<T> vec) {
	out << "[";
	for (int i = 0; i < vec.size(); i++) {
		out << vec[i];
		if (i < vec.size() - 1) out << ", ";
	}
	out << "]";

	return out;
}