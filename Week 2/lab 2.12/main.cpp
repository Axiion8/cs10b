#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    
    string inputFile;
    string outputFile;

   // Assign to inputFile value of 2nd command line argument
   // Assign to outputFile value of 3rd command line argument
   
    inputFile = argv[1];
    outputFile = argv[2];
    
   // Create input stream and open input csv file.
    ifstream inFS(inputFile);
    
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
    
    if(!inFS.is_open()){
        cout << "Error reading " << inputFile << endl;
        return 1;
    }
    
   // Read in integers from input file to vector.
    
    vector<int> intV;
    int temp;
    char comma;
    
    while(inFS >> temp){
        intV.push_back(temp);
        inFS >> comma;
    }

   // Close input stream.
 
    inFS.close();

   // Get integer average of all values read in.

    double average;
    double total = 0;
    
    for(unsigned int i = 0; i < intV.size(); ++i){
        total += intV.at(i);
    }
    
    average = total / intV.size();
    
   // Convert each value within vector to be the difference between the original value and the average.
    
   for(unsigned int j = 0; j < intV.size(); ++j) {
	   intV.at(j) = intV.at(j) - average;
   }
    
   // Create output stream and open/create output csv file.
    
    ofstream outFS(outputFile);
    
   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
    
    if(!outFS.is_open()){
        cout << "Error opening " << outputFile << endl;
        return 1;
    }
    
   // Write converted values into ouptut csv file, each integer separated by a comma.
    
    for(unsigned int c = 0; c < intV.size(); ++c){
        outFS << intV.at(c);
        if(c + 1 < intV.size()){
            outFS << ',';
        }
    }
    
   // Close output stream.
    outFS.close();
    
   return 0;
}