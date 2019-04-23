#include "LinkedList.h"

std::ostream & operator<<(std::ostream & os, const LinkedList::Node & node) {
	os << node.getValue();

	return os;
}

LinkedList::Node* LinkedList::LinkedList::insert(Node* pos, const std::string& value) {
	//LinkedList::Node* nextTemp = std::move(pos->getNext());
	//LinkedList::Node ny{ value, std::make_unique<LinkedList::Node>(pos), pos->getPrev() };
	//auto s2 = std::make_unique<Node>(value, pos, pos->getPrev());
	//return s2.get(); 

	/*if (pos == head.get()) {
		
	}

	else {*/
		pos->prev->next = std::make_unique<Node>(value, std::move(pos->prev->next), pos->prev);
		pos->prev = pos->prev->next.get();
		return pos->prev;
	//}
}
