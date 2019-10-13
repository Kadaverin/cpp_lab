#include "BidirectRingList.h"
#include "Iterator.h"

template<typename T>
Iterator<T>::Iterator(BidirectRingList<T>::Node node) {
	this.current = node;
}

template<typename T>
Iterator<T>::Iterator(const Iterator<T>& iterator) {
	this.current = 
}