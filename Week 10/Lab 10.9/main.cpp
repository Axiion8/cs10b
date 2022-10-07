#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool rCopy(ifstream & inFS, ofstream & outFS);
bool rCopy(const string & inputFile, const string & outputFile);

int main(int argc, char *argv[]){
	
	string F;
	string outF;
	if (argc != 3){
		cout << "Error" << endl;
		exit(1);
	}
	F = argv[1];
	outF = argv[2];
	rCopy(F, outF);
	
	return 0;
}

bool rCopy(ifstream & inFS, ofstream & outFS){
	char c;
	if (inFS.get(c)){
		rCopy(inFS,outFS);
		outFS << c;
	}
}

bool rCopy(const string & inputFile, const string & outputFile){
	ifstream inFS;
	inFS.open(inputFile);
	
	if(inFS.is_open() == false){
		cout << "Error opening " << inputFile << endl
		<< "Copy not completed" << endl;
		return false;
	}
	
	ofstream outFS;
	outFS.open(outputFile);
	
	if(inFS.is_open() == false){
		cout << "Error opening " << outputFile << endl
		<< "Copy not completed" << endl;
		return false;
	}
	rCopy(inFS, outFS);
	
	inFS.close();
	outFS.close();
	
	return true;
}