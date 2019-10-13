#pragma once
#include "Iterator.h"

template<typename T>
class BidirectRingList
{
public:
	friend Iterator;

	BidirectRingList();
	~BidirectRingList();
	BidirectRingList(BidirectRingList const& list);

	struct Node {
		T data;
		Node *next;
		Node *prev;
	};

	bool remove(T data, bool all = false);
	bool includes(T data);

	void push(T data);
	void unshift(T data);

	void operator=(BidirectRingList const& toCopy);
	BidirectRingList operator++();
	BidirectRingList operator++(int);

	void addOrdered(T data);
	void print();

	void clear();

	/*void remove(T data);
	
	
	void moveCurrentPoTerToHead();
	void moveCurrentPoTerToTail();
	bool operator! () const;
	void operator=(BidirectRingList const&);
	BidirectRingList operator++ (T);
	BidirectRingList& operator++ ();
	void sort();*/
private:
	Node *head;
	Node *current;

	void add(T data, Node* target);
	void addAfter(T data, Node* target);
	void addFirst(T data);
	void deleteNode(Node* target);
	void deleteHead();


	/*
	void deleteHead();
	void copy(BidirectRingList const&);*/
};

