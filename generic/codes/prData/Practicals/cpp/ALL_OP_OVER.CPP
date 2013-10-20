#include<iostream.h>
#include<conio.h>

class mks
{
	private :

   	int length;
      int weight;
      int time;

	public :

   	mks()
      {
      	length=0;
         weight=0;
         time=0;
		}

      mks(int l,int w,int t)
      {
			length=l;
         weight=w;
         time=t;
      }

      mks operator+(mks ob)
      {
      	return mks(length + ob.length, weight + ob.weight, time + ob.time);
      }

      mks operator-(mks ob)
      {
      	return mks(length - ob.length, weight - ob.weight, time - ob.time);
      }

      mks operator*(mks ob)
      {
      	return mks(length * ob.length, weight * ob.weight, time * ob.time);
      }

      mks operator/(mks ob)
      {
      	return mks(length / ob.length, weight / ob.weight, time / ob.time);
      }

      mks operator++()
      {
         return mks(++length,++weight,++time);
      }

      mks operator++(int)
      {
      	return mks(length++,weight++,time++);
      }

      mks operator--()
      {
         return mks(--length,--weight,--time);
      }

      mks operator--(int)
      {
	return mks(length--,weight--,time--);
      }

      void show()
      {
	cout << "length = " << length;
	 cout << "weight = " << weight;
	 cout << "time = " << time;
      }
};

int main()
{
   clrscr();
   mks ob1(1,1,1),ob2(100,200,300);
   mks result;

   cout << "\nsum of objects = ";
   result=ob1+ob2;
   result.show();

   cout << "\nsub of objects = ";
   result=ob1-ob2;
   result.show();

   cout << "\nproduct of objects = ";
   result=ob1*ob2;
   result.show();

   cout << "\ndivision of objects = ";
   result=ob1/ob2;
   result.show();

   cout << "\nprefix increament operator on ob1 = ";
   ++ob1;
   ob1.show();

   cout << "\npostix increament operator on ob2 = ";
   ob2++;
   ob2.show();

   cout << "\nprefix decreament operator on ob1 = ";
   --ob1;
   ob1.show();

   cout << "\npostix decreament operator on ob2 = ";
   ob2++;
   ob2.show();

   getch();

  return 0;
}

