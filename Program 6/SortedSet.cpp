#include "SortedSet.h"

SortedSet::SortedSet() : IntList() { }

SortedSet::SortedSet(const SortedSet &cpy) : IntList(cpy) { }

SortedSet::SortedSet(const IntList&cpy) : IntList(cpy) {
	remove_duplicates();
	selection_sort();
}

SortedSet::~SortedSet() { }

bool SortedSet::in(int data){
	IntNode* curr = head;
	while(curr != nullptr){
		if(data == curr->value){
			return true;
		}
		curr = curr->next;
	}
	return false;
}

SortedSet& SortedSet::operator|(SortedSet& rhs) {
    SortedSet* temp = new SortedSet;
    IntNode* curr = this->head;
	
    while(curr != nullptr) {
        temp->push_back(curr->value);
        curr = curr->next;
    }
	
    curr = rhs.head;
	
    while(curr != nullptr) {
        temp->push_back(curr->value);
        curr = curr->next;
    }
	
    temp->remove_duplicates();
	
    return *temp;
}

SortedSet& SortedSet::operator&(SortedSet& rhs) {
    SortedSet* temp = new SortedSet;
	
    IntNode* curr = this->head;
	
    while(curr != nullptr) {
		
        if (rhs.in(curr->value)) {
            temp->push_back(curr->value);
        }
        curr = curr->next;
    }
	
    return *temp;
}

void SortedSet::add(int data){
	if(!in(data)){
		IntList::insert_ordered(data);
	}
}

void SortedSet::push_front(int data){
	
	if(head == nullptr){
		head = new IntNode(data);
		tail = head;
	}
	
	else if(!in(data) && data < head->value){
		IntNode *temp = new IntNode(data);
		temp->next = head;
		head = temp;
	}
	
	else if(!in(data)){
		add(data);
	}
}

void SortedSet::push_back(int data){
	if(head == nullptr){
		head = new IntNode(data);
		tail = head;
	}
	
	else if(!in(data) && data > tail->value){
		IntNode* temp = new IntNode(data);
		tail->next = temp;
		tail = temp;
	}
	
	else if(!in(data)){
		add(data);
	}
}

void SortedSet::insert_ordered(int data) {
    add(data);
}

SortedSet& SortedSet::operator|=(SortedSet& rhs) {
    SortedSet* temp = new SortedSet(*this|rhs);
	
    IntNode* curr = rhs.head;
	
    while(curr != nullptr) {
        this->push_back(curr->value);
        curr = curr->next;
    }
    return *temp;
}

SortedSet& SortedSet::operator&=(SortedSet& rhs) {
    SortedSet* temp = new SortedSet(*this&rhs);
    IntNode* curr = temp->head;
    this->clear();
	
    while (curr != nullptr) {
        this->add(curr->value);
        curr = curr->next;
    }
    return *temp;
}