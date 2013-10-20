#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>

typedef struct
 {
   int dd;
   int mm;
   int yy;
 }date;

class Author
 {
    private :
         char Name[30];
         char Qualification[30];
         date DateofBirth;
         char emailid[30];

    public :

         Author()
          {
            strcpy(Name,"No name");
            strcpy(Qualification,"Nothing");
            strcpy(emailid,"---------@---------");
            DateofBirth.dd=00;
            DateofBirth.mm=00;
            DateofBirth.yy=00;
          }

         Author(char *na,char *quali,date dob,char *em)
          {
            strcpy(Name,na);
            strcpy(Qualification,quali);
            strcpy(emailid,em);
            DateofBirth.dd=dob.dd;
            DateofBirth.mm=dob.mm;
            DateofBirth.yy=dob.yy;
          }

         void setname(char na[30])
          {
            strcpy(Name,na);
            return;
          }

         void setqualification(char quali[30])
          {
            strcpy(Qualification,quali);
            return;
          }

         void setdateofbirth(date dob)
          {
            DateofBirth.dd=dob.dd;
            DateofBirth.mm=dob.mm;
            DateofBirth.yy=dob.yy;
            return;
          }

         void setemailid(char em[30])
          {
            strcpy(emailid,em);
            return;
          }

         char *getname()
          { return(Name); }

         char *getqualification()
          { return(Qualification); }

         char *getemailid()
          { return(emailid); }

         date getdateofbirth()
          { return(DateofBirth); }
 };

 void main()
  {
    Author authors[10];
    date dob;
    char name[30],quali[30],em[30];
    int i;

    //clrscr();
    cout << "PROGRAM FOR INPUTING AND DISPLAYING LIST OF AUTHOR OF BOOKS" << endl;
    cout << "ENTER THE DETAILS FOR ALL THE AUTHOR'S" << endl;

    for(i=0;i<10;i+=2)
     {
        cout << "\nEnter the Name of Author\t :" ;
        cin >> name;
        authors[i].setname(name);
        cout << "\nEnter the Qualification of Author\t :";
        cin >> quali;
        authors[i].setqualification(quali);
        cout << endl << "\nEnter the Date of Birth of Author\t :";
        cin >> dob.dd;
        cin >> dob.mm;
        cin >> dob.yy;
        authors[i].setdateofbirth(dob);
        cout << endl << "\nEnter the Emailid of Author\t :";
        cin >> em;
        authors[i].setemailid(em);
     }

    //clrscr();

    for(i=0; i < 10; ++i)
     {
       cout << "\nName of the Author\t:" << authors[i].getname();
       cout << "\nQualification of the Author\t:" << authors[i].getqualification();
       dob=authors[i].getdateofbirth();
       cout << "\nDate of Birth of the Author\t:" << authors[i].getname();
       cout << "\nEmailid of the Author\t:" << authors[i].getemailid();
       getch();
     }
 }




