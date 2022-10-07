#include "Wizard.h"
#include <iostream>

Wizard::Wizard(const string& name, double hp, double atkStr, int rank) : Character(WIZARD, name, hp, atkStr){
	this->rank = rank;
}

int Wizard::getRank(){
	return this->rank;
}

void Wizard::attack(Character& opponent){
	double damage;
	
	if(opponent.getType() == WIZARD){
		
		Wizard &opp = dynamic_cast<Wizard &>(opponent);
		
		damage = (static_cast<double>(this->rank)/opp.getRank()) * this->attackStrength;
		opp.damage(damage);
	}
	
	else{
		damage = this->attackStrength;
		opponent.damage(damage);
	}
    cout << "Wizard " << this->name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
    cout << opponent.getName() << " takes " << damage << " damage." << endl;	
}