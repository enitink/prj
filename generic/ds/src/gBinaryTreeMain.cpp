#include <gBinaryTree.h>

using namespace gen::ds::binaryTree;

int main()
{
	gBinaryTreeT<int> ob;
	ob.addNode(10);
	ob.addNode(5);
	ob.addNode(15);
	ob.addNode(20);
	ob.addNode(3);
	ob.addNode(9);

	ob.printColSum();	
	return 0;
} 
