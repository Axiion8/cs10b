#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

int main(int argc, char* argv[]){

    vector<double> flightPath;
    vector<double> liftC;
    string stringFileInput;
    string stringUserInput;
    double userInput;
    
    stringFileInput = argv[1];
    
    readData(stringFileInput, flightPath, liftC);
        
    cin >> userInput;
    if(!isOrdered(flightPath)){
        reorder(flightPath, liftC);
    }
    
    if (interpolation(userInput, flightPath, liftC) == -6){
        cout << interpolation(userInput, flightPath, liftC) << " out of bounds" << endl;
    }
    else{
        cout << interpolation(userInput, flightPath, liftC) << endl;
    }
    
    cout << "Would you like to enter another flight path? Type Yes or No" << endl;
    cin >> stringUserInput;
    
    return 0;
}

void readData(const string &stringFileInput, vector<double> &flightPath, vector<double> &liftC){
    
    ifstream fin(stringFileInput);
    
    if (!fin.is_open()){
        cout << "Error opening " << stringFileInput << endl;
        return;
    }
    
    else{
        
        int numCheck = 0;
        double readTemp;
        
        while(fin >> readTemp){
            if((numCheck%2) == 0){
                flightPath.push_back(readTemp);
            }
            if((numCheck%2) == 1){
                liftC.push_back(readTemp);
            }
            ++numCheck;
        }
    }
    fin.close();
}

bool isOrdered(const vector<double> &flightPath){
    if(flightPath.size() == 0){
        return true;
    }
    
    for(unsigned int i = 0; i < flightPath.size()-1; ++i){
        if(flightPath.at(i) > flightPath.at(i+1)){
            return false;
        }
    }
    return true;
}

void reorder(vector<double> &flightPath, vector<double> &liftC){
    if (flightPath.size() != 0){
        for (unsigned int i = 0; i < flightPath.size(); ++i){
            double small = i;
            for (unsigned int j = i+1; j < flightPath.size(); ++j){
                if (flightPath.at(j) < flightPath.at(small)){
                    small = j;
                }
            }
            double temp1 = flightPath.at(i);
            double temp2 = liftC.at(i);
            flightPath.at(i) = flightPath.at(small);
            liftC.at(i) = liftC.at(small);
            flightPath.at(small) = temp1;
            liftC.at(small) = temp2;
        }
    }
}

double interpolation(double userInput, const vector<double> &flightPath, const vector<double> &liftC){
    
    if (userInput < flightPath.at(0) || userInput > flightPath.back()){
        return -6;
    }
    
    for (unsigned int i = 0; i < flightPath.size(); ++i){
        if (flightPath.at(i) == userInput){
            return liftC.at(i);
        }
    }
    
    for (unsigned int j = 0; j < flightPath.size(); ++j){
        if (flightPath.at(j) > userInput){
            double pre = j-1;
            return liftC.at(pre) + ((userInput - flightPath.at(pre))/(flightPath.at(j) - flightPath.at(pre)))*(liftC.at(j) - liftC.at(pre));
        }
    }
    return 0;
}