#include<stdio.h>
#include<stdlib.h>
void binary_search(int*,int,int);
void binary_search(int l[],int e,int n)
 {
  int p,k=0;
  p=e/2;
  l[0]=0;
  do
   {
    if(n==l[p]||n==l[p+1])
     {
	k=1;
	break;
      }
    else
     {
      if(n>p)
	p=(p+e)/2;
      else
	p=p/2;
      }
    }
  while((k!=1)&&(p!=0)&&(p!=n-1));
  if(k==1)
    printf("The number %d was found at %d in the given list.",n,p);
  else
    printf("\nThe number was not found in the given list");
 }
void main()
 {
   int e,n,list[50],i;
   printf("\ninput the number of elements in the list:");
   scanf("%i",&e);
   printf("\nEnter the elements of the list:");
   for(i=1;i<=e;i++)
    scanf("%d",&list[i]);
 do
  {
   printf("\nEnter the number thar u want to search :");
   scanf(" %d",&n);
   binary_search(list,e,n);
   printf("want to continue");
   scanf("%d",&i);
  }
 while(i!=0);
  getch();
 }