#include <iostream>
#include "SortedSet.h"
#include "IntList.h"

using namespace std;

int main() {

	SortedSet test = SortedSet();
	test.push_back(5);
	test.push_back(6);
	test.push_back(9);
	test.add(6);
	test.add(7);
	cout << test << endl;
	
    return 0;
}