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

	if (pos == head.get()) {
		head = std::make_unique<Node>(value, std::move(head), nullptr);
		head->next->prev = head.get();

		return head.get();
	}

	else {
		pos->prev->next = std::make_unique<Node>(value, std::move(pos->prev->next), pos->prev);
		pos->prev = pos->prev->next.get();

		return pos->prev;
	}
}

LinkedList::Node* LinkedList::LinkedList::remove(Node* pos) {
	if (pos == head.get()) {
		head = std::move(head->next);
		head->prev = nullptr;

		return head.get();
	}

	else {
		pos->next->prev = pos->prev;
		pos->prev->next = std::move(pos->next);

		return pos->next.get();
	}
}

std::ostream & LinkedList::operator<<(std::ostream & os, const LinkedList& list) {
	Node* pos = list.head.get();
	while (pos != list.tail) {
		os << pos->getValue() << std::endl;
		pos = pos->getNext();
	}

	return os;
}