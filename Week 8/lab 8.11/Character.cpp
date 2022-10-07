#include "Character.h"
#include <iostream>

Character::Character(HeroType hero, const string & name, double hp, double atkStr){
	this->type = hero;
	this->name = name;
	this->health = hp;
	this->attackStrength = atkStr;
}

HeroType Character::getType() const{
	return type;
}

const string & Character::getName() const{
	return name;
}

int Character::getHealth() const{
	return health;
}

void Character::damage(double d){
	this->health -= d;
}

bool Character::isAlive() const{
	return health > 0;
}