#include<stdio.h>
main()
 {
  int j,i,a[10],n,t;
  clrscr();
  printf("\n\t\tPROGRAM FOR FINDING MAX. & MIN. NO. FROM AN ARRAY");
  printf("\n\nENTER THE NO. OF ELEMENTS:");
  scanf("%d",&n);
  printf("\nENTER THE ARRAY : ");
  for(i=0;i<n;++i)
    scanf("%d",&a[i]);
  printf("\nTHE ENTERED ARRAY IS : ");
  for(i=0;i<n;++i)
    printf(" %d",a[i]);

  for(i=0;i<n-1;++i)
   {
    for(j=0;j<n-i-1;++j)
     {
      if(a[j]>a[j+1])
	{
	 t=a[j];
	 a[j]=a[j+1];
	 a[j+1]=t;
	}
      }
    }
  printf("\nTHE MAX. NO. IS %d \n AND THE MIN. NO. IS %d",a[n-1],a[0]);
  getch();
 }