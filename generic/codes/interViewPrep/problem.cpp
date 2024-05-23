/*
Write a function to find if B is a sub-array of A. For B to be called a sub-array of A,
the elements of B shall occur in A in consecutive indices
 (but they need NOT be in the same order).
*/
// constraint B.size <= A.size

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Plan is to process B, to get map with the count of the number of occurences
// iterate over A [i = 0 - A.size() - 1], search in B for A[i] , decrement B[A[i]] ,
// if B[A[i]] < 0 , remove start position count and then increment B[A[i]] and move start position by 1

 
bool isSubArray(vector<int>& A, vector<int>& B) {
	map<int, int> bmap;
	int i = 0, lenB = B.size();
	for (;i<lenB;++i) {
		if (bmap.find(B[i]) != bmap.end()){
			bmap[B[i]]++;
		} else {
			bmap[B[i]] = 1;
		}
	}
	int lenA = A.size();
	int st = 0;
	map<int, int> bmapcopy = bmap;
	for(i=0;i<lenA;++i) {
		if (bmap.find(A[i]) != bmap.end()) {
			bmap[A[i]]--;
			if (bmap[A[i]] < 0) {
				while((st < i) &&(A[st] != A[i])) {
					bmap[A[st]]++;
					++st;
				}
				bmap[A[i]]++;
				st++;
			}
		} else {
			int sum = 0;
			map<int,int>::iterator it = bmap.begin();
			map<int,int>::iterator eit = bmap.end();
			for (;it != eit;++it) {
				sum += it->second;
			}
			if (sum == 0)
				return true;
			st = i+1;
			bmap = bmapcopy;	
		}
	}
	map<int,int>::iterator it = bmap.begin();
	map<int,int>::iterator eit = bmap.end();

	int sum = 0;
	for (;it != eit;++it) {
		sum += it->second;
	}

	return (sum == 0);
}

int main() {
	{	
		vector<int> A = {3,2,7,1,4,6};
		vector<int> B = {7,1,4}; // Here, B is a sub-array of A  ==> TRUE
		cout << endl << "Expected TRUE : " <<  isSubArray(A, B);
	}
	{
		vector<int> A = {3,2,7,1,4,6};
		vector<int> B = {1,4,7}; //. Here, B is a sub-array of A  ==> TRUE
		cout << endl << "Expected TRUE : " << isSubArray(A, B);
	}
	{
		vector<int> A = {3,2,7,1,4,6};
		vector<int> B = {4,7,1}; //. Here also, B is a sub array of A  ==> TRUE
		cout << endl << "Expected TRUE : " << isSubArray(A, B);
	}
	{
		vector<int> A = {3,2,7,1,4,6};
		vector<int> B = {3,1,4}; //. Here, B is not a sub array of A  ==> FALSE
		cout << endl << "Expected FALSE : " << isSubArray(A, B);
	}
	{	
		vector<int> A = {3,2,7,7,4,6};
		vector<int> B = {7,4,4}; //. Here, B is not a sub array of A  ==> FALSE
		cout << endl << "Expected FALSE : " << isSubArray(A, B);
	}
	{
		vector<int> A = {2,2,2,2,2,7};
		vector<int> B = {2,2,2,2,7}; //. Here, B is a sub array of A  ==> TRUE
		cout << endl << "Expected TRUE : " << isSubArray(A, B);
	}
	return 0;
}

