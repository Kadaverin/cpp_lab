#include "pch.h"
#include "BidirectRingList.h"
#include <iostream>

using namespace std;

BidirectRingList::BidirectRingList() : head{ nullptr }, current{ nullptr } {};
BidirectRingList::~BidirectRingList() { clear(); }
BidirectRingList::BidirectRingList(BidirectRingList const& toCopy) {
	*this = toCopy;
};

void BidirectRingList::operator=(BidirectRingList const& toAssign) {
	Node *temp = toAssign.head;

	do {
		push(temp->data);
		temp = temp->next;
	} while (temp != toAssign.head);
}

BidirectRingList BidirectRingList::operator++() {
	if (this->current != nullptr) {
		this->current = this->current->next;
	}

	return *this;
}

void BidirectRingList::clear() {
	while (head) deleteNode(head->prev);
};


void BidirectRingList::addOrdered(int data) {
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

bool BidirectRingList::includes(T data) {
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

bool BidirectRingList::remove(T data, bool all) {
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


void BidirectRingList::push(T data) {
	addAfter(data, head ? head->prev : nullptr);
}

void BidirectRingList::unshift(T data) {
	push(data);
	head = head->prev;
}


void BidirectRingList::addAfter(T data, Node* target) {
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

void BidirectRingList::addFirst(T data) {
	head = new Node;
	head->data = data;
	head->next = head;
	head->prev = head;
}

void BidirectRingList::deleteNode(Node* target) {
	if (target == head) {
		deleteHead();
	} else {
		target->prev->next = target->next;
		target->next->prev = target->prev;

		delete target;
	}
}

void BidirectRingList::deleteHead() {
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


void BidirectRingList::print() {
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



