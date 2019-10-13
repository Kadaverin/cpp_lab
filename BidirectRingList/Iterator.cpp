#include "pch.h"
#include "BidirectRingList.h"
#include "Iterator.h"

template<typename T>
Iterator<T>::Iterator(typename BidirectRingList<T>::Node* node) {
	this.current = node;
}

template<typename T>
Iterator<T>::Iterator(const Iterator<T>& iterator) {
	this.current = iterator.current;
}

template<typename T>
Iterator<T>& Iterator<T>::operator ++() {
	current = current->next;
	return *this;
}

template<typename T>
T& Iterator<T>::operator * () {
	return current->data;
}