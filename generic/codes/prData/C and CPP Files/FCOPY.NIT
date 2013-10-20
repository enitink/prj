#include<stdio.h>
typedef struct
 {
  char c;
 }copy;
main(int argc,char *argv[])
 {
   FILE *op,*wp;
   copy ch;
   long int size;
   size=sizeof(ch);
   op=fopen(argv[1],"r");
   wp=fopen(argv[2],"w");
   if(op==NULL)
      printf("\n The specified file name or path is invalid");
   else
    {
     while(fread(&ch,size,1,op)==1)
       fwrite(&ch,size,1,wp);
     printf("\nThe file has been succefully copied");
    }
   fclose(op);
   fclose(wp);
  argc=argc;
 }
