#include "pch.h"
#include "BaseNode.h"

using namespace std;

template<typename T>
class LinkedListMergeSortFunctor {
	void splitList(BaseNode<T>* start, BaseNode<T>** ll1, BaseNode** ll2) {

		BaseNode* slow = start;
		BaseNode* fast = start->next;
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

	BaseNode* mergeList(BaseNode* ll1, BaseNode* ll2) {
		BaseNode* newhead = nullptr;
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

	void mergeSort(BaseNode** start) {
		BaseNode* head = *start;
		BaseNode* ll1, *ll2;
	
		if (head == nullptr || head->next == nullptr) {
			return;
		}
		splitList(head, &ll1, &ll2);

		mergeSort(&ll1);
		mergeSort(&ll2);

		*start = mergeList(ll1, ll2);
		return;
	}
};


template<typename T> void mergeSort(BaseNode<T>* node) { /* sort */ }
template<typename T> void mergeSort(BIdirectNode<T>* node) { 
	/* ... */; mergeSort(dynamic_cast<BaseNode<T>*>(node)); /* ... */
}
