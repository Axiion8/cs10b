#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here

int fileSum(const string&);

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

// Place fileSum implementation here

int fileSum(const string &filename){
    
    int temp;
    int temp1 = 0;
    ifstream inFS;
    inFS.open(filename);
    
    if(!inFS.is_open()){
        cout << "Error opening " << filename << endl;
        exit (1);
    }
    
    else{
        while (inFS >> temp){
            temp1 += temp;
        }
        return temp1;
    }
}