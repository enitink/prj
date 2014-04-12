#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void printarr(vector<int> & arr, int size)
{
	int i = 0;
	for (;i<size;++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int t,n,caseno=1,i,dw,w;
	float d;
	vector<int> naomi;
	vector<int> ken;
	scanf("%d",&t);
	while(t--)
	{
		dw = w = 0;
		naomi.clear();
		ken.clear();
		scanf("%d",&n);
		for (i=0;i<n;++i)
		{
			scanf("%f",&d);
			naomi.push_back((int)(d * 100000));
		}
		printarr(naomi,n);
		sort(naomi.begin(), naomi.end());
		printarr(naomi,n);
		for (i=0;i<n;++i)
		{
			scanf("%f",&d);
			ken.push_back((int)(d * 100000));
		}
		sort(ken.begin(),ken.end());
		printarr(ken,n);
		printf("Case #%d: %d %d\n",caseno++,dw,w);
	}
}
