#include "pch.h"
#include "BidirectRingList.h"
#include "Iterator.h"
#include <iostream>
#include <algorithm> 

using namespace std;

void printFunction(int data) {
	cout << data << ", ";
}

int main()
{
	BidirectRingList<int> list;
	BidirectRingList<int> secondList;

	list.push(4);
	list.push(2);
	list.push(3);
	list.push(1);


	list.sort();

	cout << "\n list.print(): \n";
	list.print();


	Iterator<int> i = list.begin();

	cout << "\n increment iterator: \n";

	while (i != list.end()) {
		printFunction(*i);
		i++;
	}

	cout << "\n decrement iterator: \n";
	i = list.begin();

	do {
		i--;
		printFunction(*i);
	} while (i != list.end());


	secondList = list;	

	cout << '\n';
	secondList.print();

	list.remove(3);

	cout << '\n';
	list.print();

	list.remove(3, true);

	cout << '\n';
	list.print();

	list.clear();

	cout << '\n';
	list.print();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
