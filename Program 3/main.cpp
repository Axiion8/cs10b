#include <iostream>

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;

void mainMenu(ShoppingCart&);
void option(ShoppingCart&);

int main(){
    
	ShoppingCart cart;
	string name;
	string date;
	
	cout << "Enter customer's name: ";
	getline(cin, name);
    cout << endl;
    
	cout << "Enter today's date: " << endl;
	getline(cin, date);
	cout << endl;
	
    cart = ShoppingCart(name, date);
    
	cout << "Customer name: " << cart.customerName() << endl;
	cout << "Today's date: " << cart.date() << endl;
	cout << endl;
	
	mainMenu(cart);
    
    return 0;
}

void mainMenu(ShoppingCart& cart) {
	cout << "MENU" << endl;
	cout << "a - Add item to cart" << endl;
	cout << "d - Remove item from cart" << endl;
	cout << "c - Change item quantity" << endl;
	cout << "i - Output items' descriptions" << endl;
	cout << "o - Output shopping cart" << endl;
	cout << "q - Quit" << endl;
	cout << endl;
	option(cart);
}
    
void option(ShoppingCart& cart) {
	cout << "Choose an option: " << endl;
	
	char choice;
	cin >> choice;
	cin.ignore();
	
	if (choice == 'a') {
		string name;
		string desc;
		int price;
		int quantity;
		
		cout << endl << "ADD ITEM TO CART" << endl;
        
		cout << "Enter the item name: " << endl;
		getline(cin, name);
        
		cout << "Enter the item description: " << endl;
		getline(cin, desc);
        
		cout << "Enter the item price: " << endl;
		cin >> price;
        
		cout << "Enter the item quantity: " << endl;
		cin >> quantity;
        
		ItemToPurchase addItemToCart(name, desc, price, quantity);
		
		cart.addItem(addItemToCart);
		cout << endl;
		mainMenu(cart);
	}
	else if (choice == 'd') {
		string tempRemove;
		
		cout << endl << "REMOVE ITEM FROM CART" << endl;
		cout << "Enter name of item to remove: " << endl;
		getline(cin, tempRemove);
		
		cart.removeItem(tempRemove);
		mainMenu(cart);
	}
	else if (choice == 'c') {
		string name1;
		int quantity;
		
		cout << endl << "CHANGE ITEM QUANTITY" << endl;
		cout << "Enter the item name: " << endl;
		getline(cin, name1);
        
		cout << "Enter the new quantity: " << endl << endl;
		cin >> quantity;
		
		ItemToPurchase changeItem(name1, "", 0, quantity);
		cart.modifyItem(changeItem);
		mainMenu(cart);
	}
	else if (choice == 'i') {
		cout << endl << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
		cart.printDescriptions();
		mainMenu(cart);
	}
	else if (choice == 'o') {
		cout << endl << "OUTPUT SHOPPING CART" << endl;
		cart.printTotal();
		mainMenu(cart);
	}
	else if (choice == 'q') {
	}
	else {
		option(cart);
	}
}