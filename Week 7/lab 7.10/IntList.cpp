#include "IntList.h"

using namespace std;

IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList(){
    IntNode* temp = head;
    
    while(temp != nullptr){
        head = temp->next;
        delete temp;
        temp = head;
    }
}

void IntList::push_front(int value){
    
    IntNode* ptr = new IntNode(value);
    
    if(empty()){
        head = ptr;
        tail = ptr;
    }
    
    else if(!empty()){
        ptr->next = head;
        head = ptr;
    }
}

void IntList::pop_front(){
    
    if(!empty()){
        
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        
        else{
            IntNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
}

bool IntList::empty() const{
    return head == nullptr;
}

const int & IntList::front() const{
    return head->value;
}

const int & IntList::back() const{
    return tail->value;
}

ostream & operator<<(ostream &out, const IntList &inputList){
    
    if(!inputList.empty()){
        for (IntNode* ptr = inputList.head; ptr->next != nullptr; ptr = ptr->next){
            cout << ptr->value << ' ';
        }
        cout << inputList.tail->value;
    }
    return out;
}