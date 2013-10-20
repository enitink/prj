#include	<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

#include	<cstring>

#define		SIZE		1000

int		arr[SIZE];
int 		tarr[SIZE];

void MergeSort(int Spos, int Lpos){
	int mid, tSpos, tLpos, i, tmid;
	tSpos = Spos;
	tLpos = Lpos;
	if(Spos < Lpos){
		mid = (Spos + Lpos) / 2;
		MergeSort(Spos, mid);
		MergeSort(mid + 1, Lpos);
		memset(tarr, 0, sizeof(tarr));
		if(arr[mid] > arr[mid + 1]){
			i = 0;
			tmid = mid;
			while((tSpos <= mid) && (tmid < Lpos)){
				if(arr[tSpos] < arr[tmid + 1]){
					tarr[i] = arr[tSpos];
					++tSpos;
					++i;
				}
				else{
					tarr[i] = arr[tmid + 1];
					++tmid;
					++i;
				}
			}
			if(tSpos <= mid){
				memcpy(tarr + i, arr + tSpos, sizeof(int) * (mid - tSpos + 1));
			}
			else
				memcpy(tarr + i, arr + tmid + 1, sizeof(int) * (tLpos + 3));
			memcpy(arr + Spos, tarr, sizeof(int) * (Lpos - Spos + 1));			
		}
		return;
	}
	else
		return;
}

int main(){
	int a = SIZE;
	while(a){
		cin >> arr[a - 1];
		--a;
	}
	MergeSort(0, SIZE - 1);
	for(a = 0; a < SIZE; ++a)
		cout << arr[a] << endl;
	return 0;
}
