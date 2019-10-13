#pragma once
#include "BidirectRingList.h"

template<typename T>
class Iterator
{
	Iterator(typename BidirectRingList<T>::Node);
	Iterator(const Iterator<T>&);
	~Iterator();

	Iterator& operator=(const Iterator&);
	bool operator==(const Iterator&) const;
	bool operator!=(const Iterator&) const;

	private BidirectRingList<T>::Node current;
};
