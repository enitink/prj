#include<iostream.h>
#include<conio.h>

class foot
{
    private :

	     float feet,*f;
         float inches,*i;

        void fnwhile(float);

    public  :

    foot()
    {
	     feet=0;
	     inches=0;
	 }

	 foot(float f,float i)
	 {
	     feet=f;
	     inches=i;
	 }

	 void setsisystem(float f,float i)
	 {
	     feet=(((f*12)+i)* 2.492)/100;
	     return;
	 }

	 void setfpssystem(float f,float i)
	 {
	     i = (f*12) + i;
	     feet=0;
	     inches=0;
	     fnwhile(i);
	     return;
	 }

	 float getfeetvalue(void)
	 {	  return feet;	  }

	 float getinchesvalue(void)
	 {   return inches; }

    ~foot()
    {
    		delete f;
         delete i;
         cout << "\nObject declaimed";
    }
};

void foot :: fnwhile(float i)
{
	while(i>=12)
   {
	++feet;
	i-=12;
   }
      inches=i;
   return;
}

int main(void)
{
	foot footclass;
   float f,i;

   cout << endl << "    PROGRAM FOR FINDING THE VALUE, OF ENTERED VALUE, IN FPS AND SI SYSTEMS" << endl;
   cout <<         "********************************************************************************" << endl;
   cout << endl << endl << "Enter the feet value	:";
   cin >> f;
   cout << endl << "Enter the inches value	:";
   cin >> i;

   footclass.setsisystem(f,i);
   cout << endl << endl << "The value of the enterd " << f
        << "\" " << i << "\'" << " in SI system is  : "
        << footclass.getfeetvalue() << "m" ;

   footclass.setfpssystem(f,i);
   cout << endl << endl << "The value of the enterd " << f
        <<"\" "  << i << "\'" << " in FPS system is : "
        << footclass.getfeetvalue() << "\" " <<
        footclass.getinchesvalue() << "\'";

   getch();
   return 0;
}
