#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "TestOccurences.h"

using namespace std;

int main() {
	testAll();
	testAllExtended();
	TestOccurences();
	cout << "Test over" << endl;
	system("pause");
}
