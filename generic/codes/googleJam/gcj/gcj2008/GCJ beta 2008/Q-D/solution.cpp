#include<iostream>
#include<fstream>
#include<cstring>
#include<new>
#include<math.h>

#define LINESIZE = 100

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;

void Intialize(char * ptr, int ln){
	for(int i = 0; i < ln; ++i)
		ptr[i] = '\0';
	return;
}

int main(){
	
	ifstream fin("D-small-practice.in");
	int TotalCases = 0;

	char * line = new char(LINESIZE); // for reading each line of the input file
	Intialize(line, LINESIZE);

	fin.getline(line, LINESIZE);
	TotalCases = atoi(line);

	cout << endl << "Total No. of Cases" << TotalCases;

	fin.close();

	return 0;
}
