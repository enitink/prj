//i hv tried my best wht i could hv done nishit bhai... it's upon u how do u take it....
// waise aur bhi accha agar koi algorithm hoga tere paas to batana jaroor.....

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

char * Convert(int No, int Base, char * Arr) 
{
	int tempNo = No;
	int BaseR = ((Base == 2)? 1 : ((Base == 8)? 7 : 15)); //i m not checking the rest;
	int Shift = ((Base == 2)? 1 : ((Base == 8)? 3 : 4)); //i m not checking the rest;
	int Mid;
	int i = 0;
		
	while(tempNo != 0)
	{
		Mid = tempNo & BaseR;
		
		if(Mid > 9)
			Mid = Mid + 55;
		else
			Mid = Mid + 48;
		
		Arr[i] = char(Mid);
		++i;
		tempNo = tempNo >> Shift;
	}
	Arr[i] = '\0';
	return Arr;
}

int main()
{
	char Arr[32];
	cout << endl << "170 to baxe 2 = ";
	cout << Convert(170, 2, Arr); //Nishit Bhai tu reverse print kara dena... mujhe yaad hi
	cout << endl << "170 to baxe 8= ";//nahi aa raha hai ke kaise reverse print karate the...
	cout << Convert(170, 8, Arr);//aur maine books bhi kaaaaafi aache se rakh diya hai almira 
	cout << endl << "170 to baxe 8 = ";//mein so c++ book bhi nahi dekh paaaaaa raha hoon...
	cout << Convert(170, 16, Arr);//so tu hi reverse kar dena yaar......
	cout << endl;
	return 0;
}

