#include<iostream>

using std :: endl;
using std :: cout;
using std :: cin;

#include<iomanip>

using std :: setw;

class Time
{
private :
	int hh;
	int mm;
	int ss;
public :
	Time()
	{
		hh = mm = ss = 0;		
	}
	Time(int hh, int mm, int ss)
	{
		SetTime(hh,mm,ss);
	}
	void SetTime(int hh, int mm, int ss)
	{
		this->hh = hh;
		this->mm = mm;
		this->ss = ss;
		if(this->ss >= 60)
		{
			this->ss -= 60;
			this->mm += 1;
		}
		if(this->mm >= 60)
		{
			this->mm -= 60;
			this->hh += 1;
		}
		if(this->hh >= 24)
			this->hh -= 24;				 
	}
	Time SumTime(Time T)
	{
		return Time(hh + T.hh, mm + T.mm, ss + T.ss);
	}
	void DisplayTime()
	{
		cout << setw(2) << hh << " : " << setw(2) << mm << " : " << setw(2) << ss;
	}
};

int main()
{
	Time T,S,R;
	int hh,mm,ss;
		
	cout << endl << "Enter Time T : (hh mm ss)";
	cin >> hh >> mm >> ss;
	
	T.SetTime(hh,mm,ss);
	
	cout << endl << "Enter Time S : (hh mm ss)";
	cin >> hh >> mm >> ss;
	
	S.SetTime(hh,mm,ss);
	
	R = T.SumTime(S);
	
	cout << endl << "Time T : ";
	T.DisplayTime();
	
	cout << endl << "Time S : ";
	S.DisplayTime();
	
	cout << endl << "Time T + S : ";
	R.DisplayTime();
	
	cout << endl;
	return 0;
}
