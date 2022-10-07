#include <iostream>

using namespace std;

#include "IntVector.h"

IntVector::IntVector(unsigned capacity, int value){
    _capacity = capacity;
    _size = capacity;
    _data = new int[_capacity];
    
    for(unsigned int i = 0; i < _size; ++i){
        _data[i] = value;
    }
}

IntVector::~IntVector(){
    delete[] _data;
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
    
    if(empty() || index >= _size || index < 0){
        throw out_of_range("IntVector::at_range_check");
    }
    
    return _data[index];
}

const int & IntVector::front() const{
    return _data[0];
}

const int & IntVector::back() const{
    return _data[_size - 1];
}