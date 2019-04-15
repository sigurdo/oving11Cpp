#include "LinkedList.h"

std::ostream & operator<<(std::ostream & os, const LinkedList::Node & node) {
	os << node.getValue();

	return os;
}

LinkedList::Node* insert(LinkedList::Node* pos, const std::string& value) {
	LinkedList::Node* nextTemp = std::move(pos->getNext());
	LinkedList::Node ny{ value, nextTemp, pos->getPrev() };
}
