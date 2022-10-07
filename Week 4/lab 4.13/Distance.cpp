#include "Distance.h"
#include "cmath"
Distance::Distance() {
    feet = 0;
    inches = 0;
    
}

Distance::Distance(unsigned ft, double in) {
    
    feet = ft;
    inches = in;
    init();
    
}

Distance::Distance(double in) {
    feet = 0;
    inches = in;
    init();
    
}

unsigned Distance::getFeet() const {
    
    return feet;
    
}

double Distance::getInches() const {
    
    return inches;
}

double Distance::distanceInInches() const {
    
    return ((feet * 12) + inches);
    
}

double Distance::distanceInFeet() const {
    
    return (feet + (inches/12));
    
}

double Distance::distanceInMeters() const {
    
    return (((feet * 12) + inches) * .0254);
    
}

const Distance Distance::operator+(const Distance &rhs) const {
    
    Distance temp = Distance(feet + rhs.feet, inches + rhs.inches);
    
    return temp;
    
}

const Distance Distance::operator-(const Distance &rhs) const {
    
    return Distance(distanceInInches() - rhs.distanceInInches());


    
}


ostream & operator<<(ostream &out, const Distance &rhs) {
    out << rhs.feet << "' " << rhs.inches << "\"";
    return out;
}

void Distance::init() {
    feet = abs(feet);
    if (inches < 0) {
        inches = inches * -1;
    }
    
    while (inches >= 12) {
        inches = inches - 12;
        feet += 1;
    }
    
    
}