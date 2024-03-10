#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <assert.h>
#include <iostream>
using namespace std;

bool relationTestOccurences(TComp e1, TComp e2) {
	return e1 > e2;
}

void TestOccurences()
{
	SortedBag sb(relationTestOccurences);
	sb.add(5);
	sb.add(6);
	sb.add(0);
	sb.add(5);
	sb.add(10);
	sb.add(10);
	sb.add(8);
	sb.add(20);
	sb.add(20);
	sb.add(20);
	//20 appears 3 times
	//5 appears 2 times
	//10 appers 2 times
	//6, 0 and 8 appear only once
	try {
		sb.addOccurrences(3, 20);
		assert(sb.nrOccurrences(20) == 6);
		assert(sb.size() == 13);
		cout << "first good" << endl;

		sb.addOccurrences(13, 100);
		assert(sb.nrOccurrences(100) == 13);
		assert(sb.size() == 26);
		cout << "second good" << endl;

		sb.addOccurrences(2, 6);
		assert(sb.size() == 28);
		assert(sb.nrOccurrences(6) == 3);
		cout << "third good" << endl;

		sb.addOccurrences(0, 23);
		assert(sb.nrOccurrences(23) == 1);
		assert(sb.size() == 29);
		cout << "fourth good" << endl;

		sb.addOccurrences(-1, 29);
	}
	catch(int nr){
		cout << "Number is negative!" << endl;
	}
}
