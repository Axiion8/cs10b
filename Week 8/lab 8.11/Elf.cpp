#include "Elf.h"
#include <iostream>

Elf::Elf(const string& name, double hp, double atkStr, string family) : Character(ELF, name, hp, atkStr) {
	this->family = family;
}

string Elf::getFamily() {
	return this->family;
}

void Elf::attack(Character& opponent){
	
	double damage = (this->health/MAX_HEALTH) * this->attackStrength;
	
	if(opponent.getType() == ELF){
		
        Elf &opp = dynamic_cast<Elf &>(opponent);

		if(opp.getFamily() == this->family){
            cout << "Elf " << this->name << " does not attack Elf " << opp.getName() <<  "." << endl;
            cout << "They are both members of the " << this->family << " family" << "." << endl;
			return;
		}
        opp.damage(damage);
        cout << "Elf " << this->name << " shoots an arrow at " << opp.getName() << " --- TWANG!!" << endl;
        cout << opp.getName() << " takes " << damage << " damage." << endl;
	}
	else{
        opponent.damage(damage);
        cout << "Elf " << this->name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
	}
}