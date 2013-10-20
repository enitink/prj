#include<stdio.h>
typedef struct
 {
  char c;
 }copy;
main(int argc,char *argv[])
 {
   FILE *op;
   copy ch;
   long int size;
   size=sizeof(ch);
   op=fopen(argv[1],"r");
   if(op==NULL)
      printf("\n The specified file name or path is invalid");
   else
    {
     while(fread(&ch,size,1,op)==1)
      printf("%c",ch);
    }
   fclose(op);
  argc=argc;
 }
