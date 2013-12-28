#include	<iostream>
#include	<cstring>
#include	<algorithm>
#include	<numeric>

using namespace std;

#define		floop(i,s,e)	for(i = s; i < e; ++i)
#define		MAX		10000000

int row,col,i,j;
int arr[10][10], carr[10][10];
int tarr[10];
int assigned[10];
bool line[10][2];

void setallzero(){
	memset(arr, 0, sizeof(arr));
	memset(tarr, 0, sizeof(tarr));
	memset(assigned, 0, sizeof(assigned));
}

void input_array(){
	cout << endl << "Enter row col";
	cin >> row >> col;

	floop(i,0,row)
		floop(j,0,col)
			cin >> arr[i][j];
	memcpy(carr, arr, sizeof(arr));
}

void row_op(){
	int min;
	floop(i, 0, row){
		min = *min_element(&arr[i][0], &arr[i][col]);
		floop(j, 0, col)
			arr[i][j] -= min;
	}
}

void col_op(){
	int min;
	floop(i, 0, col){
		floop(j, 0, row)
			tarr[j] = arr[j][i]; 
		min = * min_element(&tarr[0], &tarr[row]);
		floop(j,0,row)
			arr[j][i] -= min;
	}
}

int minlocfind(){
	int min = row + 1;
	tarr[min] = MAX;
	floop(i, 0, row){
		if(tarr[i] > 0)
			if(tarr[i] < tarr[min])
				min = i;
	}
	tarr[row + 1] = 0;
	return min;
}

int search(int loc){
	floop(i, 0, row)
		if(arr[i][loc] == 0)
			return i;
	return -1;
}

void assign(){
	int minloc, colloc;
	memset(assigned, -1, sizeof(assigned));
	memset(tarr, 0, sizeof(tarr));
	floop(i, 0, col)
		floop(j, 0, row)
			if(arr[j][i] == 0)
				++tarr[i];
	while( 0 != accumulate(&tarr[0], &tarr[row], 0)){
		minloc = minlocfind();
		colloc = search(minloc);
		assigned[minloc] = colloc;
		tarr[minloc] = 0;
		floop(i, 0, col)
			if(0 == arr[colloc][i]){
				arr[colloc][i] = MAX;
				--tarr[i];
				if(tarr[i] < 0)
					tarr[i] = 0;
			}
	}
}

bool check_assign(){
	floop(i, 0, row)
		if(assigned[i] == -1)
			return false;	
	return true;
}

void replace_zeros(){
	floop(i,0,row)
		floop(j,0,col)
			if( MAX == arr[i][j] )
				arr[i][j] = 0;
}

int max_elementRow(){
	int max = 0;
	floop(i, 1, row){	
		if(arr[row][max] < arr[row][i])
			max = i;
	}
	return max;
}
int max_elementColomn(){
	int max = 0;
	floop(i, 1, row)	
		if(arr[max][col] < arr[i][col])
			max = i;
	return max;
}

void drawline(){
	memset(line, 0, sizeof(line));
	floop(i,0,row)
		floop(j,0,col)
			if(arr[i][j] == 0){
				++arr[i][col];
				++arr[row][j];
			}
	int zeros = accumulate(&arr[row][0], &arr[row][col], 0);
	int maxr, maxc;
	while(zeros){
		maxc = max_elementRow();
		maxr = max_elementColomn();
		if(arr[row][maxc] > arr[maxr][col]){
			line[maxc][1] = true;
			zeros -= arr[row][maxc];
			arr[row][maxc] = 0;
		}
		else{
			line[maxr][0] = true;
			zeros -= arr[maxr][col];
			arr[maxr][col] = 0; 
		}
	}
}

void repeat(){
	int min = MAX;
	replace_zeros();
	drawline();
	floop(i,0,row)
		floop(j,0,col){
			if((line[i][0] == false) && (line[j][1] == false))
				if(min > arr[i][j])
					min = arr[i][j];
		}
	floop(i,0,row)
		floop(j,0,col){
			if((line[i][0] == true) && (line[j][1] == true))
				arr[i][j] += min;
			if((line[i][0] == false) && (line[j][1] == false))
				arr[i][j] -= min;
		}
	assign();
}

int min_cost(){
	int cost = 0;
	floop(i, 0, row)
		cost += carr[i][assigned[i]];
	return cost;
}

void print_result(){
	cout << endl << "Assignment Policy" << endl;
	floop(i, 0, row)
		cout << i + 1 << "->" << assigned[i] + 1 << endl;
	cout << "Min Cost : " << min_cost() << endl;
}

int main(){
	setallzero();
	input_array();
	col_op();
	row_op();
	assign();
	while(!check_assign())
		repeat();
	print_result();
	return 0;
}
