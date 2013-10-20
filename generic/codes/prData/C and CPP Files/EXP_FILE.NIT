#include<stdio.h>
#include<dos.h>
typedef struct
 {
  int r;
  char name[25];
  int m1;
  int m2;
  int m3;
 }student;
call();
long int size;
main()
{
  FILE *fp,*p;
  student record;
  int p1=0,r[100],t,c=0,i,j;
  char ans='y';
  clrscr();
  p=fopen("student","ab+");
  size=sizeof(student);
  printf("\n                       WHAT DO U WANT TO DO");
  printf("\n             1). ADD NEW RECORDS");
  printf("\n             2). VIEW LISTING");
  printf("\n             3). SEE ANY SPECIFIED RECORD ");
  printf("\n                          ENTER CHOICE NO.:");
  scanf("%d",&t);
  i=t;
switch(i)
 {
  case 1:
     printf("\nENTER THE DATA FOR THE STUDENTS");
     while(ans=='y')
      {
       printf("\nENTER THE ROLL NO. OF THE STUDENT  ");
       scanf("%d",&record.r);
       printf("\nENTER THE NAME OF THE STUDENT  ");
       fflush(stdin);
       gets(record.name);
       printf("\nENTER THE MARKS1 OF THE STUDENT  ");
       scanf("%d",&record.m1);
       printf("\nENTER THE MARKS2 OF THE STUDENT  ");
       scanf("%d",&record.m2);
       printf("\nENTER THE MARKS3 OF THE STUDENT  ");
       scanf("%d",&record.m3);
       fwrite(&record,size,1,p);
       printf("\nDO YOU WANT TO CONTINUE(Y/N)  ");
       fflush(stdin);
       ans=getche();
       ans=tolower(ans);
      }
  case 2:
    fflush(stdin);
    rewind(p);
    i=0;
    while(fread(&record,size,1,p)==1)
     {
       ++c;
       r[i]=record.r;
       ++i;
     }
    for(i=0;i<=c-1;++i)
     {
      for(j=0;j<=c-i-2;++j)
	{
	 if(r[j]>(r[j+1]))
	  {
	   t=r[j];
	   r[j]=r[j+1];
	   r[j+1]=t;
	  }
	}
     }
    fp=fopen("work","wb+");
    for(i=0;i<c;++i)
     {
      rewind(p);
      for(j=0;j<c;++j)
       {
	while(fread(&record,size,1,p)==1)
	 if(r[i]==record.r)
	  fwrite(&record,size,1,fp);
       }
     }
    fclose(p);
    p=fopen("student","wb+");
    rewind(fp);
    while(fread(&record,size,1,fp)==1)
      fwrite(&record,size,1,p);
    clrscr();
    rewind(p);
    printf("\n   ROLL NO.           NAME                  MARKS1     MARKS2      MARKS3   ");
    printf("\n--------------------------------------------------------------------------------");
    while(fread(&record,size,1,p)==1)
     {
      printf("\n**%6d ** %-20s%18d%11d%12d    **",record.r,record.name,record.m1,record.m2,record.m3);
       ++p1;
      if(p1==20)
       {
	getch();
	p1=0;
       }
     }
    printf("\n\n--------------------------------------------------------------------------------\n");
    fclose(p);
    fclose(fp);
    getch();
    break;
  case 3:
    fflush(stdin);
    call();
    break;
 }
system("del work");
}
call()
 {
  FILE *p;
  student record;
  int k,k1=0;
  char ans;
  clrscr();
  p=fopen("student","rb+");
  printf("\n\n\nENTER WHICH RECORD U WILL LIKE TO VIEW(KEY ROLL NO.:");
  scanf(" %d",&k);
  rewind(p);
  while(fread(&record,size,1,p)==1)
    if(k==record.r)
     {
      k1=1;
      break;
     }
  if(k1==1)
   {
    printf("\n\n               THE RECORD FOR THE GIVEN ROLL NUMBER");
    printf("\n\n   ROLL NO.           NAME                  MARKS1    MARKS2   MARKS3");
    printf("\n------------------------------------------------------------------------\n");
    printf("\n**%6d *** %-20s%18d%10d%8d **",record.r,record.name,record.m1,record.m2,record.m3);
    getch();
    fclose(p);
    return;
   }
  else
   {
    printf("\n\n       RECORD NOT FOUND FOR THE GIVEN ROLL NUMBER");
    printf("\n\n          DO U WANT TO REENTER THE ROLL NUMBER(Y/N)");
    fflush(stdin);
    ans=getche();
    ans=tolower(ans);
    if(ans=='y')
      call();
    else
     {
      fclose(p);
      return;
     }
   }
 }