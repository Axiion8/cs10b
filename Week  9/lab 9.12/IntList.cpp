#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

bool IntList::exists( IntNode *ptr,int value) const{
	if(ptr == nullptr){
		return false;
	}
	
	bool isValInSubList;
	isValInSubList = exist(ptr->next, value);
	
	bool isValOnCurrentNode;
	if(ptr->value == value){
		isValOnCurrentNode = true;
	}
	
	return isValOnCurrentNode || isValInSubList;
}




ostream& operator<<(ostream& out, const IntList& rhs){
	out << rhs.head;
}

ostream& operator<<(ostream& out, IntNode* ptr){
	if(ptr == nullptr){
		return out;
	}
	out << ptr->value << ' ' << ptr->next;
	return out;
}