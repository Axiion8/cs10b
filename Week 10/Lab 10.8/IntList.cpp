#include <utility>
#include <iostream>

#include "IntList.h"

bool IntList::bubbleUp() {
	bool answer = false;
	if(head == nullptr){
		return false;
	}
	if(head->next == nullptr){
		return false;
	}

	answer = bubbleUp(head->next);
	if(head->value > head->next->value){
		answer = true;
		// cout << "head " << head->value << " // next " << head->next->value << endl;
		swap(head->value, head->next->value);
	}
	return answer;
}

bool IntList::bubbleUp(IntNode *curr) {
	bool answer = false;
	if(curr == nullptr){
		return false;
	}
	if(curr->next == nullptr){
		return false;
	}

	answer = bubbleUp(curr->next);
	if(curr->value > curr->next->value){
		answer = true;
		// cout << "curr " << curr->value << " // next " << curr->next->value << endl;
		swap(curr->value, curr->next->value);
	}
	return answer;
}
