#pragma once

#include <iostream>
#include <memory>
#include <ostream>
#include <string>

// test code 
//void testLinkedList();


namespace LinkedList {
template<class T> class Node {
private:
	const T value;    // The data held by the LinkedList
	std::unique_ptr<Node> next; // unique_ptr to the next node
	Node* prev;                 // raw (non-owning) ptr to the previous node
public:
	Node() : value(), next(nullptr), prev(nullptr) {}
	// construct a node with string value, a unique_ptr to the next node, and a pointer to the previous node
	Node(const T& value, std::unique_ptr<Node> next, Node* prev)
		: value(value)
		, next(std::move(next))
		, prev(prev)
	{}
	// We can use the default destructor, since unique_ptr takes care of deleting memory
	~Node() = default;
	// return the value of the node
	T getValue() const { return value; }

	// return a raw (non-owning) pointer to the next node
	Node* getNext() const { return next.get(); }
	// return a raw (non-owning) pointer to the previous node
	Node* getPrev() const { return prev; }

	template<class T> friend class LinkedList;
};

// write the value of the node to the ostream
template<class T> std::ostream & operator<<(std::ostream & os, const Node<T> & node) {
	os << node.getValue();

	return os;
}

template<class T> class LinkedList {
private:
	// ptr to the first node
	std::unique_ptr<Node<T>> head;
	// a raw pointer to the last node, the last node is always a dummy node
	// this is declared as a const ptr to a Node, so that tail never can
	// point anywhere else
	Node<T>* const tail;
public:
	//create the dummy node, and make tail point to it
	LinkedList()
		: head(std::make_unique<Node<T>>())
		, tail(head.get())
	{}
	~LinkedList() = default;

	//if next is a nullptr (i.e. head is the dummy node), the list is emtpy
	bool isEmpty() const { return !head->next; }


	//return a pointer to first element
	Node<T>* begin() const { return head.get(); }
	//return a pointer to beyond-end element
	Node<T>* end() const { return tail; }

	// The insert function takes a pointer to node (pos) and a string (value). It creates a new
	// node which contains value. The new node is inserted into the LinkedList BEFORE the
	// node pointed to by pos.
	Node<T>* insert(Node<T> *pos, const T& value) {
		if (pos == head.get()) {
			head = std::make_unique<Node<T>>(value, std::move(head), nullptr);
			head->next->prev = head.get();

			return head.get();
		}

		else {
			pos->prev->next = std::make_unique<Node<T>>(value, std::move(pos->prev->next), pos->prev);
			pos->prev = pos->prev->next.get();

			return pos->prev;
		}
	}

	// The find function traverses the linked list and returns a pointer to the first node
	// that contains the value given.
	// If the value isn't in the list, find returns a pointer to the dummy node at the end
	// of the list.
	Node<T>* find(const T& value) {
		Node<T>* pos = head.get();
		while (pos != tail) {
			if (pos->getValue() == value) return pos;
			pos = pos->getNext();
		}
		return pos;
	}

	// The remove function takes a pointer to a node, and removes the node from the list. The
	// function returns a pointer to the element after the removed node.
	Node<T>* remove(Node<T>* pos) {
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

	// The remove function takes a string and removes the first node which contains the value.
	void remove(const T& value) {
		Node<T>* pos = find(value);
		if (pos != tail) remove(pos);
	}
};

	// write a string representation of the list to the ostream
template<class T> std::ostream & operator<<(std::ostream & os, const LinkedList<T>& list) {
	Node<T>* pos = list.begin();
	while (pos != list.end()) {
		os << pos->getValue() << std::endl;
		pos = pos->getNext();
	}

	return os;
}
}// namespace LinkedList



