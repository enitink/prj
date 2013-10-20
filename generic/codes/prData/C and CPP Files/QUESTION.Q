#include<stdio.h>
typedef struct
 {
  char question[80];
  char ans1[20];
  char ans2[20];
  char ans3[20];
  char ans4[20];
  int an;
 }data;

main()
 {
  FILE *wp;
  data records;
  int i=0;
  long int size;
  char ans='y';

  wp=fopen("questions.dt","ab+");
  size=sizeof(records);

  while(ans=='y')
   {
    printf("\nENTER THE QUESTION NUMBER %d  :\n",i);
    fflush(stdin);
    gets(records.question);
    printf("\nENTER THE ANSWERS :\n: 1 :");
    fflush(stdin);
    gets(records.ans1);
    printf("\n: 2 :");
    fflush(stdin);
    gets(records.ans2);
    printf("\n: 3 :");
    fflush(stdin);
    gets(records.ans3);
    printf("\n: 4 :");
    fflush(stdin);
    gets(records.ans4);
    printf("\nENTER THE CORRECT ANS NO. :");
    fflush(stdin);
    scanf("%d",&records.an);
    fwrite(&records,size,1,wp);
    printf("\ndo u want to continue");
    ans=getche();
    ans=tolower(ans);
    ++i;
 }
}