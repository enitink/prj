#include<stdio.h>
main()
 {
  int a[20],n,i,j,k;
  clrscr();
  printf("\nEnter the number of elements");
  scanf("%d",&n);
  printf("\nEnter the elements");
  for(i=0;i<n;++i)
    scanf("%d",&a[i]);
  printf("\nEnter the number to be inserted");
  scanf("%d",&j);
  printf("\nEnter the position");
  scanf("%d",&k);
  printf("\nThe elements of the array are\n");
  for(i=0;i<n;++i)
    printf(" %d",a[i]);
  for(i=n-1;i>=k-1;--i)
    a[i+1]=a[i];
  a[k-1]=j;
  printf("\nThe elements after the insertion\n");
  for(i=0;i<=n;++i)
    printf(" %d",a[i]);
  getch();
 }