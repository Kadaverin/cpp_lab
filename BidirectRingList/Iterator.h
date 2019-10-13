#pragma once
#include "BidirectRingList.h"

template<typename T>
class Iterator
{
public:
	bool done;

	Iterator(typename BidirectRingList<T>::Node *head, bool done = false) {
		start = head;
		current = head;
		this->done = done;
	}

	Iterator(const Iterator<T>& iterator) {
		start = iterator.start;
		current = iterator.current;
		done = iterator.done;
	}

	Iterator<T>& first() {
		current = start;
		done = false;
		return *this;
	}

	Iterator<T>& last() {
		current = start->prev;
		done = false;
		return *this;
	}

	Iterator<T>& operator ++() {
		current = current->next;

		if (current == start) {
			done = true;
		}

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

		if (current == start) {
			done = true;
		}

		return *this;
	}

	Iterator<T>& operator --(int)
	{
		Iterator<T> oldValue = *this;
		this->operator--();
		return oldValue;
	};

	
	T& operator * () {
		return current->data;
	}

	~Iterator() {
		current = nullptr;
		start = nullptr;
	};

	//Iterator& operator=(const Iterator&);
	bool operator==(const Iterator& iter) {
		return current == iter.current && done == iter.done;
	};

	bool operator!=(const Iterator& iter) {
		return !operator==(iter);
	};

private:
	typename BidirectRingList<T>::Node *current;
	typename BidirectRingList<T>::Node *start;
};
