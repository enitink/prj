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

void Convert(char * alien_number, char * source_language, unsigned int * converted_alien_no){
	
	int len_alien_no = strlen(alien_number);
	int len_source_lang = strlen(source_language);
	int i,j;

	for(i = 0; i < len_source_lang ; ++i){
		for(j = 0; j < len_alien_no; ++j){
			if(source_language[i] == alien_number[j])
				converted_alien_no[len_alien_no - j - 1] = i;
		}
	}
	return;
}

void ChangeCode(char * alien_number, char * source_language, char * target_language, char * target_alien_no){

	int len_alien_no = strlen(alien_number);
	int len_source_lang = strlen(source_language);
	int len_target_language = strlen(target_language);
	unsigned int * converted_alien_no = new unsigned int[len_alien_no]; 
	unsigned long int converted_decimal = 0;	
	int i;

	Convert(alien_number, source_language, converted_alien_no);

	for(i = 0; i < len_alien_no; ++i)
		converted_decimal += (converted_alien_no[i] * pow(len_source_lang, i));

	i = 0;
	
	do{
		target_alien_no[i] = target_language[converted_decimal % len_target_language];
		converted_decimal = (converted_decimal -  (converted_decimal % len_target_language)) / len_target_language;
		++i;
	}while(converted_decimal != 0);

	target_alien_no[i] = '\0';

	char * tempchar = new char(strlen(target_alien_no));
	
	strcpy(tempchar, target_alien_no);

	for(i = 0; i < strlen(target_alien_no); ++i)
		target_alien_no[strlen(target_alien_no) - i - 1] = tempchar[i];
	
	return;
}

void Intialise(char * ptr, int ln){
	for(int i = 0; i < ln; ++i)
		ptr[i] = '\0';
	return;
}

int main(){

	ifstream fin("A-small.in");
	ofstream fout("A-small.out");
	
	char * target_alien_no = new char(33);
	Intialise(target_alien_no, 33);
	
	char * alien_number = new char(33);
	Intialise(alien_number, 33);

	char * source_language = new char(95);
	Intialise(source_language, 95);
	
	char * target_language = new char(95);
	Intialise(source_language, 95);	

	char * line = new char(33 + 95 + 95);
	Intialise(line, 33+95+95);

	int i = 0, j = 0, cases = 0, totalcases=0;
	
	fin.getline(line, 33+95+95);
	totalcases = atoi(line);
	
	for(cases = 1; cases <= 100; ++cases){
		line[0] = '\0';
		fin.getline(line, 33+95+95);
		j = 0;
		alien_number[0] = '\0';
		source_language[0] = '\0';
		target_language[0] = '\0';
		target_alien_no[0] = '\0';

		for(i = 0; i < 33+95+95; ++i){
			if(line[i] == ' ') 
				break;
			
			alien_number[j] = line[i];
			++j;
		}
		alien_number[j] = '\0';
		j = 0;
		
		for(++i ; i < 33+95+95; ++i){
			if(line[i] == ' ') 
				break;
			
			source_language[j] = line[i];
			++j;
		}
		source_language[j] = '\0';
		j = 0;

		for( ++i ; i < 33+95+95; ++i){
			if(line[i] == ' ') 
				break;
			
			target_language[j] = line[i];
			++j;
		}
		
		target_language[j] = '\0';

		ChangeCode(alien_number, source_language, target_language, target_alien_no);
		
		fout << "Case #" << cases << ": " << target_alien_no << endl;
	}
	
	fin.close();
	fout.close();

	cout << endl;
	return 0;
}