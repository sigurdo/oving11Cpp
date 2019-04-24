/*#include "LinkedList.h"

namespace LinkedList {
	template<class T> std::ostream & operator<<(std::ostream & os, const Node<T> & node) {
		os << node.getValue();

		return os;
	}

	template<class T> Node<T>* LinkedList<T>::insert(Node<T>* pos, const T& value) {
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

	template<class T> Node<T>* LinkedList<T>::find(const T& value) {
		Node<T>* pos = head.get();
		while (pos != tail) {
			if (pos->getValue() == value) return pos;
			pos = pos->getNext();
		}
		return pos;
	}

	template<class T> Node<T>* LinkedList<T>::remove(Node<T>* pos) {
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

	template<class T> void LinkedList<T>::remove(const T& value) {
		Node<T>* pos = find(value);
		if (pos != tail) remove(pos);
	}

	template<class T> std::ostream & operator<<(std::ostream & os, const LinkedList<T>& list) {
		Node<T>* pos = list.head.get();
		while (pos != list.tail) {
			os << pos->getValue() << std::endl;
			pos = pos->getNext();
		}

		return os;
	}
}*/