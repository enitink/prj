/* WRITE A PROGRAM TO DETERMIND WHETHER A
   MATRIX IS SINGULAR OR NOT */

/* THIS PROBLEM HAS BEEN SOLVED BY CRAMER'S RULE.*/

# include<stdio.h>

int i, j;
float mat[10][10];
float mat1[10][10];

void display( int, int);
void input( int, int);
float Singular_Matrix(int, int);

void display( int row, int col)
{
		for(i = 0; i < row; i++)
		{
				for(j = 0; j < col; j++)
				{
						printf("  %f", mat[i][j]);
				}
				printf("\n");
		}
}

void input( int row, int col)
{
		for(i = 0 ; i< row; i++)
		{
				for(j = 0 ;  j<col; j++)
				{
						printf("Input Value for : %d: %d: ", i+1, j+1);
						scanf("%f", &mat[i][j]);
				}
		}
}

float Singular_Matrix( int row1, int col1)
{
		int i, j, k, l;
		float sum=0, psum=0, partial=0, nsum=0;
		if(row1 == col1)
		{
				printf("\n Number rows  = Number of cols");
				printf("\n Singular Test is possible\n");

				if(row1 < 3)
				{
						sum = mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
						return(sum);
				}
				else
				{
						for(k = 0; k <row1; k++)
								for(j = 0; j < row1; j++)
										mat1[k][j] = mat[k][j];

						for(k = 0; k <row1; k++)
								for(j = row1; j < (2*row1-1); j++)
										mat1[k][j] = mat1[k][j-row1];

						for(l = 0; l <row1; l++)
						{
								partial = 1;
								for(i = 0; i <row1; i++)
								{
										partial *= mat1[i][i+l];
								}
								psum += partial;
						}

						for(l = row1-1; l < ( 2*row1 -1); l++)
						{
								partial = 1;
								for(i =0; i < row1; i++)
								{
										partial *=mat1[i][l-i];
								}
								nsum += partial;
						}
						sum = psum - nsum ;
						return(sum);
				}
		}

		else
				printf("\n Check about singularity is not possible");

		return 0;
}

void main()
{
		float Determinant;
		int r,c;
		printf("\n Input the number of rows:");
		scanf("%d", &r);
		printf(" Input the number of cols:");
		scanf("%d", &c);
		input(r, c);
		printf("\n Entered Two Dimensional array is as follows:\n");
		display(r, c);
		Determinant = Singular_Matrix(r, c);
		printf("\n Determinant is : %d", Determinant);

		if(Determinant == 0)
				printf("\n The Above matrix is Singular");
		else
				printf("\n Above matrix is not singular");
}

linkfloat()
{
		float a=0,*b;
		b=&a;
		a=*b;
}
