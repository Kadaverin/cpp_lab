#include "pch.h"
#include "BidirectRingList.h"
#include <iostream>

using namespace std;

template<typename T>
BidirectRingList<T>::BidirectRingList() : head{ nullptr }, current{ nullptr } {};

template<typename T>
BidirectRingList<T>::~BidirectRingList() { clear(); }

template<typename T>
BidirectRingList<T>::BidirectRingList(BidirectRingList const& toCopy) {
	*this = toCopy;
};

template<typename T>
void BidirectRingList<T>::operator=(BidirectRingList const& toAssign) {
	Node *temp = toAssign.head;

	do {
		push(temp->data);
		temp = temp->next;
	} while (temp != toAssign.head);
}

template<typename T>
void BidirectRingList<T>::clear() {
	while (head) deleteNode(head->prev);
};

template<typename T>
void BidirectRingList<T>::addOrdered(T data) {
	if (head == nullptr) {
		addFirst(data);
		return;
	} 
	Node *temp = head;

	do {
		if (temp->data <= data && temp->next->data >= data) {
			addAfter(data, temp);
			return;
		}

		temp = temp->next;
	} while (temp != head);

	addAfter(data, head->prev);
};

template<typename T>
bool BidirectRingList<T>::includes(T data) {
	if (head == nullptr) {
		return false;
	}	

	Node *temp = head;

	do {
		if (temp->data == data) {
			return true;
		}
		temp = temp->next;
	} while (temp != head);

	return false;
}

template<typename T>
bool BidirectRingList<T>::remove(T data, bool all) {
	if (head == nullptr) {
		return false;
	}

	bool isDeleted = false;
	Node *temp = head->prev;

	do {
		if (temp->next->data == data) {
			deleteNode(temp->next);
			isDeleted = true;

			if (!all) break;
		}
		temp = temp->next;
	} while (temp->next != head);

	return isDeleted;
}

template<typename T>
void BidirectRingList<T>::push(T data) {
	addAfter(data, head ? head->prev : nullptr);
}

template<typename T>
void BidirectRingList<T>::unshift(T data) {
	push(data);
	head = head->prev;
}

template<typename T>
void BidirectRingList<T>::addAfter(T data, Node* target) {
	if (head == nullptr) {
		addFirst(data);
		return;
	}

	Node *newNode = new Node;
	newNode->data = data;

	newNode->next = target->next;
	target->next->prev = newNode;

	target->next = newNode;
	newNode->prev = target;
}

template<typename T>
void BidirectRingList<T>::addFirst(T data) {
	head = new Node;
	head->data = data;
	head->next = head;
	head->prev = head;
}

template<typename T>
void BidirectRingList<T>::deleteNode(Node* target) {
	if (target == head) {
		deleteHead();
	} else {
		target->prev->next = target->next;
		target->next->prev = target->prev;

		delete target;
	}
}

template<typename T>
void BidirectRingList<T>::deleteHead() {
	if (head->next == head) {
		delete head;
		head = nullptr;
		return;
	} 

	Node* temp = head;

	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	head = temp->next;

	delete temp;
}


template<typename T>
void BidirectRingList<T>::print() {
	if (head == nullptr) {
		cout << "No data";
		return;
	}

	Node *temp = head;

	do {
		cout << temp->data << ", ";
		temp = temp->next;
	} while (temp != head);
}
