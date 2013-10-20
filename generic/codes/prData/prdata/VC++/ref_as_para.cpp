#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

class student
{
	private:
   	char *name;
      int *rollno;
      char *subject[5];
      int loop(char *);

   public:
   	student()
      {
         name=(char *) malloc(sizeof(char)*30);
         rollno=(int *) malloc(sizeof(int)* 1);
         subject[0]=(char *) malloc(sizeof(char) * 20);
         subject[1]=(char *) malloc(sizeof(char) * 20);
         subject[2]=(char *) malloc(sizeof(char) * 20);
         subject[3]=(char *) malloc(sizeof(char) * 20);
         subject[4]=(char *) malloc(sizeof(char) * 20);

         strcpy(name,"no name");
			rollno=0;
         strcpy(subject[0],"subject");
         strcpy(subject[1],"subject");
	 strcpy(subject[2],"subject");
	 strcpy(subject[3],"subject");
	 strcpy(subject[4],"subject");
      }

      student(char *n,int r,char *sub[])
      {
	 name=(char *) malloc(sizeof(char)*30);
	 rollno=(int *) malloc(sizeof(int)* 1);
	 subject[0]=(char *) malloc(sizeof(char) * 20);
	 subject[1]=(char *) malloc(sizeof(char) * 20);
	 subject[2]=(char *) malloc(sizeof(char) * 20);
	 subject[3]=(char *) malloc(sizeof(char) * 20);
	 subject[4]=(char *) malloc(sizeof(char) * 20);

	 strcpy(name,n);
			*rollno=r;
	 strcpy(subject[0],sub[0]);
	 strcpy(subject[1],sub[1]);
	 strcpy(subject[2],sub[2]);
	 strcpy(subject[3],sub[3]);
	 strcpy(subject[4],sub[4]);
      }

      student(student & st)
      {
	 name=(char *) malloc(sizeof(char)*30);
	 rollno=(int *) malloc(sizeof(int)* 1);
	 subject[0]=(char *) malloc(sizeof(char) * 20);
	 subject[1]=(char *) malloc(sizeof(char) * 20);
	 subject[2]=(char *) malloc(sizeof(char) * 20);
	 subject[3]=(char *) malloc(sizeof(char) * 20);
	 subject[4]=(char *) malloc(sizeof(char) * 20);

		 strcpy(name,st.name);
		 rollno=st.rollno;
	 strcpy(subject[0],st.subject[0]);
	 strcpy(subject[1],st.subject[1]);
	 strcpy(subject[2],st.subject[2]);
	 strcpy(subject[3],st.subject[3]);
	 strcpy(subject[4],st.subject[4]);
      }

      void setname(char *n)
      {
	 strcpy(name,n);
      }

      void setrollno(int roll)
      {
	 *rollno = roll;
      }

      void setsubject(char *sub[])
      {
	 strcpy(subject[0],sub[0]);
	 strcpy(subject[1],sub[1]);
	 strcpy(subject[2],sub[2]);
	 strcpy(subject[3],sub[3]);
	 strcpy(subject[4],sub[4]);
      }

      char * getname()
      {
	return name;
      }

      int * getrollno()
      {
	return rollno;
      }

      char ** getsubject()
      {
	return subject;
      }

      void show()
      {
	cout << endl << "Name of the student :" << name;
	 cout << endl << "Roll no of the student :" << *rollno;
	 cout << endl << "Subject 1 :" << *(subject + 0);
	 cout << endl << "Subject 2 :" << *(subject + 1);
	 cout << endl << "Subject 3 :" << *(subject + 2);
	 cout << endl << "Subject 4 :" << *(subject + 3);
	 cout << endl << "Subject 5 :" << *(subject + 4);
      }

      void search(char *sub)
      {
	 int i;
	 i=loop(sub);
	 if(i >= -1)
	    cout << endl <<  "The subject has been found : The given subject was" << *(subject + i);
	 else
	    cout << endl <<  "The subject has not been found";
      }

};

int student :: loop(char *sub)
{
	for(int i = 0; i < 5; ++i)
   {
	if(*(subject+i) == sub)
	   return i;
   }

   return -1;
}

void main(void)
{
   student ob1,ob2(ob1);

   char *n;
   char *sub[5];
   int roll;

   cout << endl <<  "enter name";
   cin >> n;
   ob1.setname(n);

   cout << endl << "enter roll";
   cin >> roll;
   ob1.setrollno(roll);

   cout << endl <<  "enter subjects";
   for(int i = 0; i < 5; ++i)
   {
	cout << endl <<  "enter subject[" << i << "]";
	cin >> sub[i];
   }

   cout << "\ncontents of ob1";
   ob1.show();

   cout << "\ncontents of ob2";
   ob2.show();


   getch();
}


