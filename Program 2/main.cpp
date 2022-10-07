#include <iostream>
#include <string>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


// Implement the Date member functions here

Date::Date(){
    day = 1;
    month = 1;
    monthName = "January";
    year = 2000;
}

Date::Date(unsigned m, unsigned d, unsigned y){
    
    bool date = false;

    
    if(m>12){
        date = true;
        m = 12;
    }
    else if(m <= 0){
        date = true;
        m = 1;
    }
    
    if(d > daysPerMonth(m, y)){
        date = true;
        d = daysPerMonth(m, y);
    }
    else if(d <= 0){
        date = true;
        d = 1;
    }
    
    month = m;
    day = d;
    year = y;
    monthName = name(m);
    
    if(date == true){
       cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
    }
    
    return;
}








   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */

Date::Date(const string &mn, unsigned d, unsigned y){
    
    bool date = false;
    
    unsigned m = number(mn);
    string mn1 = mn;
    mn1.at(0) = toupper(mn1.at(0));

    if(m <= 0){
        m = 1;
        d = 1;
        y = 2000;
        mn1 = "January";
        cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
    }        

    if(d > daysPerMonth(m, y)){
        date = true;
        d = daysPerMonth(m, y);        
    }
    
    else if(d <= 0){
        date = true;
        d = 1;
    }
    
    month = m;
    day = d;
    year = y;
    monthName = mn1;
    
    if(date == true){
        cout << "Invalid date values: Date corrected to " << m << "/" << d << "/" << y << "." << endl;
    }
}















void Date::printNumeric() const{
    cout << month << '/' << day << '/' << year;
}

void Date::printAlpha() const{
    cout << monthName << ' ' << day << ", " << year;
}

bool Date::isLeap(unsigned y) const{
    
    bool isLeap = false;
    
    if(y % 4 == 0) {
        if(y % 100 == 0) {
            if(y % 400 == 0) {
                isLeap = true;
            }
        }
        else {
            isLeap = true;
        }
    }
    
    return isLeap;
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const{
    
    if(m == 1){
        return 31;
    }
    if(m == 2 && isLeap(y)){
        return 29;
    }
    if(m == 2 && !isLeap(y)){
        return 28;
    }
    if(m == 3){
        return 31;
    }
    if(m == 4){
        return 30;
    }
    if(m == 5){
        return 31;
    }
    if(m == 6){
        return 30;
    }
    if(m == 7){
        return 31;
    }
    if(m == 8){
        return 31;
    }
    if(m == 9){
        return 30;
    }
    if(m == 10){
        return 31;
    }
    if(m == 11){
        return 30;
    }
    if(m == 12){
        return 31;
    }
    return 0;
}

string Date::name(unsigned m) const{
    if(m == 1){
        return "January";
    }
    if(m == 2){
        return "February";
    }
    if(m == 3){
        return "March";
    }
    if(m == 4){
        return "April";
    }
    if(m == 5){
        return "May";
    }
    if(m == 6){
        return "June";
    }
    if(m == 7){
        return "July";
    }
    if(m == 8){
        return "August";
    }
    if(m == 9){
        return "September";
    }
    if(m == 10){
        return "October";
    }
    if(m == 11){
        return "November";
    }
    if(m == 12){
        return "December";
    }
    return 0;
}

unsigned Date::number(const string &mn) const{
   if(mn == "January" || mn == "january"){
      return 1;
   } 
   else if(mn == "February" || mn == "february"){
      return 2;
   } 
   else if(mn == "March" || mn == "march"){
      return 3;
   } 
   else if(mn == "April" || mn == "april"){
      return 4;
   } 
   else if(mn == "May" || mn == "may"){
      return 5;
   } 
   else if(mn == "June" || mn == "june"){
      return 6;
   }
   else if(mn == "July" || mn == "july"){
      return 7;
   } 
   else if(mn == "August" || mn == "august"){
      return 8;
   } 
   else if(mn == "September" || mn == "september"){
      return 9;
   } 
   else if(mn == "October" || mn == "october"){
      return 10;
   }
   else if(mn == "November" || mn == "november"){
      return 11;
   }
   else if(mn == "December" || mn == "december"){
      return 12;
   }
   else {
      return 0;
   }
}

// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
