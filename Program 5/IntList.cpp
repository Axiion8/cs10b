#include "IntList.h"
#include <utility>

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

IntList::IntList(const IntList &cpy){
    head = nullptr;
    tail = nullptr;
    IntNode* temp = cpy.head;
    
    while(temp != nullptr){
        push_back(temp->value);
        temp = temp->next;
    }
}

void IntList::push_back(int value){
    IntNode* temp = new IntNode(value);
    
    if(empty()){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

void IntList::clear(){
    while(!empty()){
        pop_front();
    }
}

ostream & operator<<(ostream &out, const IntList &inputList){
    
	IntNode* temp = inputList.head;
    
	while (temp != nullptr){
		if (temp == inputList.tail) {
			out << temp->value;
		}
		else {
			out << temp->value << " ";
		}
		temp = temp->next;
	}
    
    return out;
}

IntList & IntList::operator=(const IntList &rhs){
    if (this == &rhs){
        return *this;
    }
    
    else{
        clear();

        IntNode* temp = rhs.head;

        while(temp != nullptr){
            push_back(temp->value);
            temp = temp->next;
        }
        return *this;
    }
}

void IntList::selection_sort(){
    
    if(!empty()){
        
        IntNode* minValue = nullptr;
        int temp = 0;
        
        for(IntNode* position = head; position != nullptr; position = position->next){
            
            minValue = position;
            
            for(IntNode* check = position; check != nullptr; check = check->next){
                
                if(minValue->value > check->value){
                    minValue = check;
                }
            }
            
            temp = position->value;
            position->value = minValue->value;
            minValue->value = temp;
        }
    }
}

void IntList::insert_ordered(int value){
    if(empty()){
        push_back(value);
    }
    else if(value<= head->value){
        push_front(value);
    }
    else if(value >= tail->value){
        push_back(value);
    }
    else{
        IntNode* temp = new IntNode(value);
        IntNode* curr = head->next;
        IntNode* prev = head;
        
        while(curr){
            if((value >= prev->value) && (value < curr->value)){
                prev->next = temp;
                temp->next = curr;
                break;
            }
            prev = prev->next;
            curr = curr->next;
        }
    }
}

void IntList::remove_duplicates(){

    if(empty()){
        return;
    }

    else{

        IntNode* curr = head;


        while(curr && curr->next){
            IntNode* prev = curr;
            IntNode* i = curr->next;
            while(i){
                 //cout << i->value << endl;
                if(curr->value == i->value){
                    prev->next = i->next;
					if(i == tail){
						tail = prev;
					}
                    delete i;
                    i = prev->next;
                }
				else{
					prev = i;
					i = i->next;
					//cout << "done" << endl;
				}
            }

            curr = curr->next;
        }
    }
}













// 	if(empty()){
// 		return;
// 	}
	
// 	else{
		
// 		IntNode* curr = head;
		
		
// 		while(curr){
// 			IntNode* prev = curr;
// 			IntNode* i = curr->next;
// 			while(i && i->next){
// 				// cout << i->value << endl;
// 				if(curr->value == i->value){
// 					prev->next = i->next;
// 					delete i;
// 					i = prev->next;
// 				}
// 				prev = i;
// 				i = i->next;
// 			}
			
// 			curr = curr->next;
// 		}
// 	}


// void remove_duplicates(){
//     IntNode* ptr1 = nullptr;
//     IntNode* ptr2 = nullptr;
//     IntNode* start = head;
    
//     if(!empty()){
        
//     }
// }
    /*
    NOTICE: fucntion has to contain a nested while loop to iterate through whole linked list
    
    
    FIRST loop is meant to go through the whole list
        
        //line 133 :set initial pointer "start" to head.
        
            while(start != nullptr)

                ptr1 = start;
                ptr2 = start->next;
                
                    *runs through 2nd while loop that checks for duplicates using value start*

                start = start->next;
            
            *while loop1 ends*
    
    
    
    SECOND loop is meant to check each value with "start" to see if there is any duplicates.
    
    NOTICE: If last node was deleted, ensure that the tail is moved to the very last node. (should be ptr1 since it holds the address of the previous node)
    
        while(ptr2 != nullptr)
            if duplicate exists - 

                
                
            if no duplicate -
                ptr2 = ptr2.next
                ptr1 = 
                //keep on moving through loop till if duplicate is found.

            

            Loop1()
    
    */