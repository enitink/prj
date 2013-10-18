#ifndef _BINARY_TREE_
#define _BINARY_TREE_

#include <iostream>
#include <cstring>
#include <gCommonDefs.h>
#include <gCommonUtils.h>

using namespace std;
using namespace gen::common::defs;

namespace gen { namespace ds { namespace binaryTree {

typedef enum
{
	TYPE_BST,
	TYPE_AVL,
}treeType_e;

template <class T>
class gBinaryTreeNodeT
{
public:
	gBinaryTreeNodeT(); //default Constructor
	gBinaryTreeNodeT(gBinaryTreeNodeT prevNode, gBinaryTreeNodeT nextNode, T data); //Constructor
	
	gBinaryTreeNodeT(const gBinaryTreeNodeT<T> &) = delete;
	gBinaryTreeNodeT* 	getLeftNode(void)	{ return __pLeftNode; } 
	gBinaryTreeNodeT* 	getRightNode(void) 	{ return __pRightNode; }
	T 					getData(void) 		{ return __data; }

	void setLeftNode(gBinaryTreeNodeT* prevNode) 	{ __pLeftNode = prevNode; }
	void setRightNode(gBinaryTreeNodeT* nextNode) 	{ __pRightNode = nextNode; }
	void setData(T data) 							{ __data = data; }

private:
	gBinaryTreeNodeT* __pLeftNode;
	gBinaryTreeNodeT* __pRightNode;

	T __data;
};

template <class T>
class gBinaryTreeT
{
public:
	gBinaryTreeT(); //default Constructor 
	gBinaryTreeT(const gBinaryTreeT<T>& obj); //Copy Constructor
	virtual ~gBinaryTreeT();

	gBinaryTreeT<T> & operator=(const  gBinaryTreeT<T>& obj);

	void addNode(T data);
	
	gBinaryTreeNodeT<T> * getRoot(void) { return __pRoot; }
	u32_t  getWidth(void) { return (__leftWidth + __rightWidth + 1); }

	void printTree();
	void printColSum();

private:
	void addNodeAsBST(T data);
	void copyData(const  gBinaryTreeNodeT <T> & obj);
	void deleteNodes(gBinaryTreeNodeT <T>  * root);
	void calColSum( gBinaryTreeNodeT <T> * root, s32_t* pColSum, u32_t col = 50);

private:
	gBinaryTreeNodeT <T> *	__pRoot;
	s32_t 				 	__leftWidth;
	s32_t 				 	__rightWidth;
	treeType_e			 	__treeType;
};

template <class T>
gBinaryTreeNodeT<T>::gBinaryTreeNodeT()
	:    __pLeftNode(NULL)
	,    __pRightNode(NULL)
{}

template <class T>
gBinaryTreeNodeT<T>::gBinaryTreeNodeT(gBinaryTreeNodeT prevNode, gBinaryTreeNodeT nextNode, T data)
	:    __pLeftNode(prevNode)
	,    __pRightNode(nextNode)
	,    __data(data)
{}

template <class T>
gBinaryTreeT<T>::gBinaryTreeT()
	:    __pRoot(NULL)
	,	 __leftWidth(0)
	,	 __rightWidth(0)
	,	 __treeType(TYPE_BST)
{}

template <class T>
gBinaryTreeT<T>::gBinaryTreeT(const gBinaryTreeT<T>& obj) //Copy Constructor
{ copyData(obj); }

template <class T>
gBinaryTreeT<T>::~gBinaryTreeT()
{
	deleteNodes(__pRoot);
}

template <class T>
gBinaryTreeT<T> &gBinaryTreeT<T>::operator=(const  gBinaryTreeT<T>& obj)
{
	if (&obj != this)
		copyData(obj);
	return *this;
}

template <class T>
void gBinaryTreeT<T>::addNode(T data)
{
	switch (__treeType)
	{
	case TYPE_BST:
		addNodeAsBST(data);
		break;
	default:
		cout << endl << "Tree type other then BST not implemented";
	}
}

template <class T>
void gBinaryTreeT<T>::printTree()
{
	cout << endl << "gBinaryTree -> Tree printing using breadth first" << endl;
}

template <class T>
void gBinaryTreeT<T>::printColSum()
{
	s32_t* pColSum = new s32_t[__leftWidth + __rightWidth + 1]; // +1 for root
	bzero(pColSum, sizeof(s32_t) * (__leftWidth + __rightWidth + 1));

	calColSum(__pRoot, pColSum, __leftWidth);
	for ( u32_t i = 0; i <= (__leftWidth + __rightWidth) ; ++i)
	{
		cout << "Col : " << (i + 1) << " : " << pColSum[i] << endl;
	}

	delete [] pColSum;
}

template <class T>
void gBinaryTreeT<T>::addNodeAsBST(T data)
{
	gBinaryTreeNodeT <T>  * temp = new gBinaryTreeNodeT<T>();
	temp->setData(data);
	temp->setLeftNode(NULL);
	temp->setRightNode(NULL);

	if (__pRoot == NULL)
		__pRoot = temp;
	else
	{
		gBinaryTreeNodeT <T>* root = __pRoot;
		u32_t leftWidth = 0;
		u32_t rightWidth = 0;
	
		while(true)
		{
			if(root->getData() > data)
			{
				++leftWidth; --rightWidth;
				if(root->getLeftNode())
				{
					root = root->getLeftNode();
					continue;
				}
				root->setLeftNode(temp);
				break;
			}
			else
			{
				++rightWidth; --leftWidth;
				if(root->getRightNode())
				{
					root = root->getRightNode();
					continue;
				}
				root->setRightNode(temp);
				break;
			}	
		}
		__leftWidth  = (__leftWidth < leftWidth) ? leftWidth : __leftWidth;
		__rightWidth = (__rightWidth < rightWidth) ? rightWidth : __rightWidth;
	}
}

template <class T>
void	gBinaryTreeT<T>::copyData(const  gBinaryTreeNodeT <T> & obj)
{
	cout << endl << "Not implemented, copy constructor and = operator will fail";
}

template <class T>
void gBinaryTreeT<T>::deleteNodes(gBinaryTreeNodeT <T>  * root)
{
	//deleting nodes using postOrder traversal
	if (root == NULL)
		return;
	if ( root->getLeftNode() )
		deleteNodes(root->getLeftNode());
	if ( root->getRightNode() )
		deleteNodes(root->getRightNode());
	delete root;
}

template <class T>
void gBinaryTreeT<T>::calColSum(gBinaryTreeNodeT<T> * root, s32_t* pColSum, u32_t col)
{
	if (root == NULL)
		return;
	
	pColSum[col] += root->getData();

	if (root->getLeftNode())
		calColSum(root->getLeftNode(), pColSum, col-1);
	if (root->getRightNode())
		calColSum(root->getRightNode(), pColSum, col+1);
	return;
}

}}} //gen::ds::binaryTree

#endif
