#include <iostream>

using namespace std;

int moves;

void DescribeDiscMoves(int n, int startPost, int endPost)
{	
	int tempPost;
	if (n == 1)
	{
		cout << "Move the top disc from post "
			 << startPost << " to post " << endPost << ".\n";
		++moves;
	}
	else
	{
		tempPost = 6 - startPost - endPost;
		DescribeDiscMoves(n-1, startPost, tempPost);
		cout << "Move the top disc from post "
			 << startPost << " to post " << endPost << ".\n";
		DescribeDiscMoves(n-1, tempPost, endPost);
		++moves;
	}	
}

int main()
{
	char ans = 'y';
	cout << "\nThis program solves the Tower of Hanoi problem by "
			"describing the sequence\nof disc moves that will achieve "
			"the transfer of n discs from the initial\npost to the "
			"final post, according to the following rules: \n\n"
			"1. Only one disc can be moved at a time.\n"
			"2. No disc can be placed on top of a smaller disc.\n\n"
			"The amount of time to compute the moves increases "
			"dramatically as the\nnumber of discs increases. For "
			"illustrative purposes keep the number\nof discs to "
			"four or five at most.\n";
	do
	{
		int n;
		moves = 0;
		cout << "\nHow many discs would you like to move? ";
		cin >> n;
		DescribeDiscMoves(n, 1, 3);
		cout << "Total Moves Was = " << moves;
		cout << "\nDo U want to Continue";
		cin >> ans;
	}while (ans == 'y');
	return 0;
}