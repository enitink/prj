#include<stdio.h>
main(int argc,char *argv[])
 {
   FILE *wp;
   char ch=' ';
   wp=fopen(argv[1],"r");
   if(wp==NULL)
    {
      wp=fopen(argv[1],"w");
      printf("\nTo save the file type ^ at the end");
      while(ch!='^')
       {
        fputc(ch,wp);
	scanf("%c",&ch);
       }
      printf("\nThe file has been succefully created");
    }
   else
    {
      printf("\n The specified file already exists.");
    }
    fclose(wp);
    argc=argc;
 }
