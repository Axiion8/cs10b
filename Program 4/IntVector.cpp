#include "IntVector.h"

using namespace std;

IntVector::IntVector(unsigned size, int value){
    _size = size;
    _capacity = size;
    _data = new int[_capacity];
    
    for (unsigned int i = 0; i < size; ++i){
        _data[i] = value;
    }
}

unsigned IntVector::size() const{
    return _size;
}

unsigned IntVector::capacity() const{
    return _capacity;
}

bool IntVector::empty() const{
    return _size == 0;
}

const int & IntVector::at(unsigned index) const{
    
    if(index >= _size){
        throw out_of_range("IntVector::at_range_check");
    }
    else{
        return _data[index];
    }
}

int & IntVector::at(unsigned index){
    
        if(index >= _size){
        throw out_of_range("IntVector::at_range_check");
    }
    else{
        return _data[index];
    }
}

const int & IntVector::front() const{
    return _data[0];
}

int & IntVector::front(){
    return _data[0];

}

const int & IntVector::back() const{
    return _data[_size - 1];
}

int & IntVector::back(){
    return _data[_size - 1];
    
}

IntVector::~IntVector(){
    delete[] _data;
    _data = nullptr;
}

void IntVector::expand(){
    
    int* temp = nullptr;
    
    if(_capacity == 0){
        _capacity = 1;
        _data = new int[_capacity];
    }
    
    else{
        temp = _data;
        _capacity *= 2;
        _data = new int[_capacity];
        
        for (unsigned int i = 0; i < _size; ++i){
            _data[i] = temp[i];
        }
        delete[] temp;
    }
}

void IntVector::expand(unsigned amount){
    
    int* temp = nullptr;
    _capacity += amount;
    temp = _data;
    _data = new int[_capacity];
    
    for (unsigned int i = 0; i < _size; ++i){
        _data[i] = temp[i];
    }
    
    delete[] temp;
}

void IntVector::insert(unsigned index, int value){
    
    if(index > _size){
        throw out_of_range("IntVector::insert_range_check");
    }
    
    else {
        ++_size;
        
        if(_size > _capacity){
            expand();
        }
        
        for (unsigned int i = _size; i > index; --i){
            _data[i] = _data[i-1];
        }
        
        _data[index] = value;
    }
}

void IntVector::erase(unsigned index){
    
    if(index >= _size){
        throw out_of_range("IntVector::erase_range_check");
    }
    
    else{
        for (unsigned int i = index; i < _size; i++){
            _data[i] = _data[i + 1];
        }

        --_size;
    }
}

void IntVector::push_back(int value){
    
    ++_size;
    
    if(_size > _capacity){
        expand();
    }
    
    _data[_size - 1] = value;
}

void IntVector::pop_back(){
    --_size;
}

void IntVector::clear(){
    _size = 0;
}

void IntVector::resize(unsigned size, int value){

    if(size > _capacity * 2){
        expand(size - _capacity);
    }
    else if(size > _capacity){
        expand();
    }

    for(unsigned int i = _size; i < size; ++i){
        _data[i] = value;
    }

    _size = size;
}

void IntVector::reserve(unsigned n) {
	if (n > _capacity) {
		expand(n - _capacity);
	}
}

void IntVector::assign(unsigned n, int value){

    if(n > _capacity * 2){
        expand(n - _capacity);
    }
    else if(n > _capacity){
        expand();
    }
    
    for (unsigned int i = 0; i < n; ++i)
    {
        _data[i] = value;
    }
    
    _size = n;
}