#include <iostream>

#include "ShoppingCart.h"

using namespace std;


ShoppingCart::ShoppingCart() : _customerName("none"), _currentDate("January 1, 2016"), _cartItems(0) {
    return;
}

ShoppingCart::ShoppingCart(const string name, const string date) {
	_customerName = name;
    _currentDate = date;
}


string ShoppingCart::customerName() const {
    return _customerName;
}

string ShoppingCart::date() const {
    return _currentDate;
}

void ShoppingCart::addItem(const ItemToPurchase& item){
    _cartItems.push_back(item);
}

void ShoppingCart::removeItem(const string _name){
    bool itemFound = false;
    int index;
    
    for (unsigned int i = 0; i < _cartItems.size(); ++i){
        if(_cartItems.at(i).name() == _name){
            itemFound = true;
            index = i;
            break;
        }
    }
    
    if(itemFound == true){
        _cartItems.erase(_cartItems.begin() + index);
    }
    if(itemFound == false){
        cout << "Item not found in cart. Nothing removed." << endl << endl;
    }
    
    for(unsigned int j = index; j < _cartItems.size(); ++j){
        _cartItems.at(j) = _cartItems.at(j+1);
    }
}

void ShoppingCart::modifyItem(const ItemToPurchase item){
    bool itemFound = false;
    int index;
    
    for (unsigned int i = 0; i < _cartItems.size(); ++i){
        if(_cartItems.at(i).name() == item.name()){
            itemFound = true;
            index = i;
        }
    }
    
    if(item.price() != 0){
		_cartItems.at(index).setPrice(item.price());
    }            
     
    if(item.quantity() != 0){
		_cartItems.at(index).setQuantity(item.quantity());
    }

    if(item.description() != "none"){
		_cartItems.at(index).setDescription(item.description());
    }    
    
    if(itemFound == false){
        cout << "Item not found in cart. Nothing modified. " << endl << endl;
    }
}

int ShoppingCart::numItemsInCart() const {
    int numItems = 0;
    for (unsigned int i = 0; i < _cartItems.size(); ++i){
        numItems += _cartItems.at(i).quantity();
    }
    return numItems;
}

double ShoppingCart::costOfCart() const {
    double cost = 0;
    for (unsigned int i = 0; i < _cartItems.size(); ++i){
        cost += (_cartItems.at(i).price() * _cartItems.at(i).quantity());
    }
    return cost;
}

void ShoppingCart::printTotal() const{
    
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << "Number of Items: " << numItemsInCart() << endl;
    cout << endl;
    
    if(_cartItems.size() <= 0){
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    else if(_cartItems.size() > 0){
        for(unsigned int i = 0; i < _cartItems.size(); ++i){
            _cartItems.at(i).printItemCost();
            cout << endl;
        }
    }
    cout << endl << "Total: $" << costOfCart() << endl << endl;
}

void ShoppingCart::printDescriptions() const{
	cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
	cout << endl;
	cout << "Item Descriptions" << endl;
	for (unsigned i = 0; i < _cartItems.size(); ++i) {
		_cartItems.at(i).printItemDescription();
		cout << endl;
	}
	cout << endl;
}