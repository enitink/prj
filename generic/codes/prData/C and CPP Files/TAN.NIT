#include<stdio.h>
#include"cos.h"
#include<math.h>

main()
 {
   float d,ans,ans1;

   printf("\nEnter the degree");
   scanf("%f",&d);

   ans=sinx(d)/coss(d);

   d=(d*3.14)/180;

   ans1=tan(d);

   printf("%f ans %f",ans,ans1);
   getch();

}
