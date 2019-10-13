#pragma once
#include "BaseNode.h"
#include <iostream>


using namespace std;

template<typename T>
class Iterator;

template<typename T>
class BidirectRingList
{
public:
	friend Iterator<T>;

	BidirectRingList() : head{ nullptr }, current{ nullptr } {};

	~BidirectRingList() { clear(); }

	BidirectRingList(BidirectRingList const& toCopy) { *this = toCopy; };

	struct Node : BaseNode<T> {
		Node *prev;
	};

	Iterator<T> begin() {
		return Iterator<T>(head);
	}

	Iterator<T> end() {
		return Iterator<T>(head, true);
	}

	void forEach(void callback(T)) {
		auto begin = this->begin();
		auto end = this->end();

		while (begin != end) {
			callback(*begin);
			++begin;
		}
	}

	void operator=(BidirectRingList const& toAssign) {
		Node *temp = toAssign.head;

		do {
			push(temp->data);
			temp = temp->next;
		} while (temp != toAssign.head);
	}

	void clear() {
		while (head) deleteNode(head->prev);
	};

	void addOrdered(T data) {
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

	bool includes(T data) {
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

	bool remove(T data, bool allEntries = false) {
		if (head == nullptr) {
			return false;
		}

		bool isDeleted = false;
		Node *temp = head->prev;

		do {
			if (temp->next->data == data) {
				deleteNode(temp->next);
				isDeleted = true;

				if (!allEntries) break;
			}
			temp = temp->next;
		} while (temp->next != head);

		return isDeleted;
	}

	void push(T data) {
		addAfter(data, head ? head->prev : nullptr);
	}

	void unshift(T data) {
		push(data);
		head = head->prev;
	}
	
	void print() {
		if (head == nullptr) {
			cout << "No data";
			return;
		}

		forEach([](T data) {
			cout << data << ", ";
		});
	}

	void sort() {
		head->prev->next = nullptr;
		mergeSort(&head);

		Node *temp = head;

		while (temp->next != nullptr) {
			temp->next->prev = temp;
			temp = temp->next;
		}

		head->prev = temp;
		temp->next = head;
	}

	//void sort();
private:
	Node *head;
	Node *current;

	

	void addAfter(T data, Node* target) {
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

	void addFirst(T data) {
		head = new Node;
		head->data = data;
		head->next = head;
		head->prev = head;
	}

	void deleteNode(Node* target) {
		if (target == head) {
			deleteHead();
		}
		else {
			target->prev->next = target->next;
			target->next->prev = target->prev;

			delete target;
		}
	}

	void deleteHead() {
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
};

