#include <iostream>

#include "ItemToPurchase.h"

using namespace std;

ItemToPurchase::ItemToPurchase() : _name("none"), _description("none"), _price(0), _quantity(0){
    return;
}

ItemToPurchase::ItemToPurchase(const string name, const string description, const double price, const int quantity) {
	_name = name;
	_price = price;
	_quantity = quantity;
    _description = description;
}

void ItemToPurchase::setName(const string inputName){
    _name = inputName;
}

string ItemToPurchase::name() const {
    return _name;
}

void ItemToPurchase::setPrice(const double inputPrice){
    _price = inputPrice;
}

double ItemToPurchase::price() const {
    return _price;
}

void ItemToPurchase::setQuantity(const int inputQuantity){
    _quantity = inputQuantity;
}

int ItemToPurchase::quantity() const {
    return _quantity;
}

void ItemToPurchase::setDescription(const string inputDescription){
    _description = inputDescription;
}

string ItemToPurchase::description() const {
    return _description;
}

void ItemToPurchase::printItemCost() const {
    cout << _name << ' ' << _quantity << " @ $" << _price << " = $" << (_quantity * _price);
}

void ItemToPurchase::printItemDescription() const {
    cout << _name << ": " << _description;
}