#pragma once
#include "BidirectRingList.h"

template<typename T>
class Iterator
{
public:
	Iterator(typename BidirectRingList<T>::Node);
	Iterator(const Iterator<T>&);
	~Iterator();

	Iterator& operator=(const Iterator&);
	bool operator==(const Iterator&) const;
	bool operator!=(const Iterator&) const;

private:
	typename BidirectRingList<T>::Node current;
};
