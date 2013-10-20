//program to determine the determinant of a matrix

#include<iostream.h>
#include<string.h>
main(){

	int i,j,row,col;
	float lsum = 0, gsum = 0, partial = 1;
	float (*a)[10] = new float [5][10];
	float (*a1)[10] = new float [5][10];

/*	char (*s)[25] = new char [5][25];
	strcpy(s[0], "prat");
	cout << "\nS[0] = " << s[0];*/
	
	cout << "\n\nPlease specify the dimension of the matrix : \n";
	cout << "\t\tNo. of rows : ";
	cin >> row;
	cout << "\n\t\tNo. of columns : ";
	cin >> col;
	
	if (row != col){
		cout << "\nSORRY! Since no. of rows and cols. are different,\nhence,determinant cannot be determined.\n\n";
	
		return 0;
	}

	else{

		cout << "\n\nPlease enter the elements of the matrix : ";
		for (i = 0; i < row; i++)
			for(j = 0; j < col; j++){
				cin >> a[i][j];
				a1[i][j] = a[i][j];
			}

		for (i = 0; i < row; i++)
			for(j = 0; j < col - 1; j++)
				a1[i][j + row] = a1[i][j];

		for(i = 0; i < row; i++){
				
			partial = 1;

			for(j = 0; j < row; j++)
				partial *= a1[j][i + j];

			gsum +=partial;

		}

		for( i = row - 1; i < 2 * row - 1; i++){
			partial = 1;
			for(j = 0; j < row; j++)
				partial *= a1[j][i - j];

			lsum += partial;
		}

	}


	cout << "\nThe matrix entered is :\n\n\t\t";
	for (i = 0; i < row; i++){
		for(j = 0; j < col; j++)
			cout << a[i][j] << "\t";
			cout << "\n\n\t\t";
	}
	

	cout << "\n\nThe determinant of the given matrix : " << (gsum - lsum) << "\n\n";
	
	delete []a;
	delete []a1;
	//delete []s;
	
	return 0;
}