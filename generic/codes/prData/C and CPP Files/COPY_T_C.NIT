#include<stdio.h>
main()
 {
   FILE *op,*wp;
   char ar1[10],ar2[10],ch;
   int size;
   size=sizeof(ch);
   printf("\nPROGRAM FOR COPYING ONE FILE TO ANOTHER");
   printf("\nENTER THE NAME OF THE SOURCE FILE : ");
   scanf(" %s",&ar1);
   printf("\nENTER THE NAME OF THE TARGET FILE : ");
   scanf(" %s",&ar2);
   op=fopen(ar1,"r");
   wp=fopen(ar2,"w");
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
 }
