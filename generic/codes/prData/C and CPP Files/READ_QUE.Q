#include<stdio.h>
typedef struct
 {
  char question[80];
  char ans1[20];
  char ans2[20];
  char ans3[20];
  char ans4[20];
  int ans;
 }data;

main()
 {
  FILE *op;
  data records;
  int i=1;
  long int size;

  op=fopen("questions.dt","rb+");
  size=sizeof(records);

  while(fread(&records,size,1,op)==1)
   {
    printf("\n THE QUESTION NUMBER %d IS:\n",i);
    puts(records.question);
    printf("\nENTER THE ANSWERS :\n: 1 :");
    puts(records.ans1);
    printf("\n: 2 :");
    puts(records.ans2);
    printf("\n: 3 :");
    puts(records.ans3);
    printf("\n: 4 :");
    puts(records.ans4);
    printf("\ncorrect ans is %d",records.ans);
    ++i;
    getch();
 }
}