#include<iostream>
#include<fstream>
#include<cstring>
#include<new>
#include<math.h>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;

void Intialise(char * ptr, int ln){
	for(int i = 0; i < ln; ++i)
		ptr[i] = '\0';
	return;
}

void Sort(int SqFrequency[10][3], int n){
	int temp;
	int i, j;

	for(i = 0; i < n; ++i)
		for(j = 0; j < n - i - 1; ++j)
			if(SqFrequency[j][0] > SqFrequency[j + 1][0]){
				temp = SqFrequency[j][0];
				SqFrequency[j][0] = SqFrequency[j + 1][0];
				SqFrequency[j + 1][0] = temp;
				temp = SqFrequency[j][1];
				SqFrequency[j][1] = SqFrequency[j + 1][1];
				SqFrequency[j + 1][1] = temp;
				temp = SqFrequency[j][2];
				SqFrequency[j][2] = SqFrequency[j + 1][2];
				SqFrequency[j + 1][2] = temp;
			}
	for(i = 0; i < n; ++i)
		for(j = 0; j < n - i - 1; ++j)
			if(SqFrequency[j][0] == SqFrequency[j + 1][0]){
				if(SqFrequency[j][2] < SqFrequency[j + 1][2]){
					temp = SqFrequency[j][0];
					SqFrequency[j][0] = SqFrequency[j + 1][0];
					SqFrequency[j + 1][0] = temp;
					temp = SqFrequency[j][1];
					SqFrequency[j][1] = SqFrequency[j + 1][1];
					SqFrequency[j + 1][1] = temp;
					temp = SqFrequency[j][2];
					SqFrequency[j][2] = SqFrequency[j + 1][2];
					SqFrequency[j + 1][2] = temp;
				}
			}
	return;
}

int main(){

	const int LINESIZE = 101;
	ifstream fin("A-small-attempt1.in");
	ofstream fout("Q1.out");
	int i, j;
	
	char SearchEngines[10][LINESIZE];
	int searchengine_no;
	int SearchQueries[100];
	int searchqueries_no;
	int SQFrequency[10][3];
	int Current_SearchE;

	for(i = 0; i < 10; ++i){
		SQFrequency[i][0] = 0;
		SQFrequency[i][1] = i;
		SQFrequency[i][2] = 0;
	}

	char * line = new char(LINESIZE); // for reading each line of the input file
	Intialise(line, LINESIZE);

	int cases;  //No. of times loop to be run!!
	int totalcases; //No. of total cases for the problem;
	int optimal_switching; //to store no. of switching...
	

	fin.getline(line, LINESIZE);
	totalcases = atoi(line);
	
	for(cases = 1; cases <= totalcases; ++cases){
		Intialise(line, LINESIZE);
		fin.getline(line, LINESIZE);
		searchengine_no = atoi(line);

		for(i = 0; i < 10; ++i){
			SQFrequency[i][0] = 0;
			SQFrequency[i][1] = i;
			SQFrequency[i][2] = 0;
		}

		Intialise(line, LINESIZE);
		for(i = 0; i < searchengine_no; ++i){
			fin.getline(line, LINESIZE);
			strcpy(SearchEngines[i],line);
		}
		
		Intialise(line, LINESIZE);
		fin.getline(line, LINESIZE);
		searchqueries_no = atoi(line);
		
		Intialise(line, LINESIZE);
		for(i = 0; i < searchqueries_no; ++i){
			
			fin.getline(line, LINESIZE);

			for(j = 0; j < searchengine_no; ++j)
				if(!strcmp(line, SearchEngines[j]))
					break;
			if(SQFrequency[j][0] == 0)
				SQFrequency[j][2] = i;
			++SQFrequency[j][0];
			SearchQueries[i] = j;
		}

		Sort(SQFrequency, searchengine_no);
		optimal_switching = 0;
		Current_SearchE = SQFrequency[0][1];

		if(SQFrequency[0][0] != 0) {
			for(i = 0; i < searchqueries_no; ++i){
				if(SearchQueries[i] == Current_SearchE){
					if(i == 0){
						--SQFrequency[0][0];
						Current_SearchE = SQFrequency[0][1];
					}
					else {
						++optimal_switching;
						for(j = 0; j < searchengine_no; ++j)
							if(SearchQueries[i] == SQFrequency[0][1])
								break;
						--SQFrequency[j][0];
						Sort(SQFrequency, searchengine_no);
						Current_SearchE = SQFrequency[0][0];
					}
				}
				else {
					for(j = 0; j < searchengine_no; ++j)
						if(SearchQueries[i] == SQFrequency[0][1])
							break;
					--SQFrequency[j][0];
					Sort(SQFrequency, searchengine_no);
				}
			}
		}

		fout << "Case #" << cases << ": " << optimal_switching << endl;
	}
	
	fin.close();
	fout.close();

	cout << endl;
	return 0;
}
