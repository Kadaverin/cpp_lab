#include "pch.h"

using namespace std;

template<typename Node>
inline void mergeSort(Node** start) {
	Node* head = *start;
	Node* ll1, *ll2;

	if (head == nullptr || head->next == nullptr) {
		return;
	}
	splitList(head, &ll1, &ll2);

	mergeSort(&ll1);
	mergeSort(&ll2);

	*start = mergeList(ll1, ll2);
	return;
}

template<typename Node>
inline void splitList(Node* start, Node** ll1, Node** ll2) {

	Node* slow = start;
	Node* fast = start->next;
	while (fast != nullptr) {
		fast = fast->next;
		if (fast != nullptr) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	*ll1 = start;
	*ll2 = slow->next;

	slow->next = nullptr;
}

template<typename Node>
inline Node* mergeList(Node* ll1, Node* ll2) {
	Node* newhead = nullptr;
	if (ll1 == nullptr)
		return ll2;

	if (ll2 == nullptr)
		return ll1;

	if (ll1->data <= ll2->data) {
		newhead = ll1;
		newhead->next = mergeList(ll1->next, ll2);
	}
	else {
		newhead = ll2;
		newhead->next = mergeList(ll1, ll2->next);
	}
	return newhead;
}









