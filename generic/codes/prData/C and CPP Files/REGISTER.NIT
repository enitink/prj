#include<stdio.h>
#include<time.h>
main()
 {
 time_t s,fi;
 int c,n=10;
 long int l,lm=100000000;
 register int f,f1,f2;
 time(&s);
 for(l=0;l<=lm;++l)
  {
   f1=1; f2=1;
    for(c=1;c<=n;++c)
     {
      f=(c<3)?1:f1+f2;
      f1=f2;
      f2=f;
     }
   }
 --c;
  time(&fi);
  printf("\ni=%d  f=%d",c,f);
  printf("\ntime taken:%0.01f seconds ",difftime(fi,s));
 getch();
 }