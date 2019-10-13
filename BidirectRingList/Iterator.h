#pragma once
#include "BidirectRingList.h"

template<typename T>
class Iterator
{
public:
	Iterator(typename BidirectRingList<T>::Node *head) {
		start = head;
		current = head;
	}

	Iterator(const Iterator<T>& iterator) {
		start = iterator.start;
		current = iterator.current;
	}

	Iterator<T>& toFirst() {
		current = start;
		return *this;
	}

	Iterator<T>& toLast() {
		current = start->prev;
		return *this;
	}

	Iterator<T>& operator ++() {
		current = current->next;
		return *this;
	}

	Iterator<T>& operator ++(int)
	{
		Iterator<T> oldValue = *this;
		this->operator++();
		return oldValue;
	};

	Iterator<T>& operator --() {
		current = current->prev;
		return *this;
	}

	Iterator<T>& operator --(int)
	{
		Iterator<T> oldValue = *this;
		this->operator--();
		return oldValue;
	};

	void forEach(void callback (T) ) {

		toLast();

		do {
			this->operator++();
			callback(this->operator*());
		} while (current != start->prev);

	}

	
	T& operator * () {
		return current->data;
	}

	~Iterator() {
		current = nullptr;
		start = nullptr;
	};

	//Iterator& operator=(const Iterator&);
	bool operator==(const Iterator& iter) {
		return current == iter.current;
	};

	bool operator!=(const Iterator& iter) {
		return !operator==(iter);
	};

private:
	typename BidirectRingList<T>::Node *current;
	typename BidirectRingList<T>::Node *start;
};
