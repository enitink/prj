#include <stdio.h>

int binary_search(int A[], int key, int imin, int imax)
{
  if (imax < imin)
    return -1;
  else
    {
      int imid = (imin+imax)/2;
      if (A[imid] > key)
        return binary_search(A, key, imin, imid-1);
      else if (A[imid] < key)
        return binary_search(A, key, imid+1, imax);
      else
        return imid;
    }
}

int main()
{
	int r,c,i,j,found,q,f,p;
	int arr[1000][1000];
	scanf("%d%d",&r,&c);
	for(i = 0; i < r; ++i)
		for(j = 0; j < c; ++j)
			scanf("%d",&arr[i][j]);
	scanf("%d",&q);
	for(j=0; j < q; ++j)
	{
		scanf("%d",&f);
		found = 0;
		for(i=0; i < r; ++i)
		{
			p = binary_search(arr[i], f, 0, c);
			if ( p == -1)
				continue;
			else
			{
				found = 1;
				printf("%d %d\n", i, p); 
			}
		}
		if ( !found )
			printf("-1 -1\n");
	}
	return 0;
}

