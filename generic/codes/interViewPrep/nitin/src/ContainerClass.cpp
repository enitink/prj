#include "ContainerClass.h"
#include "Product.h"
#include <iostream>

using namespace std;

ContainerClass::~ContainerClass()
{
	map<string, Product*>::iterator itbegin = productList.begin();
	map<string, Product*>::iterator itend =   productList.end();

	for ( ; itbegin != itend; ++itbegin )
	{
		Product* lPtr = itbegin->second;
		delete lPtr;
	}
	productList.clear();
}

int ContainerClass::OnOrderAdd(char *productId, char *OrderId, int BidOrOffer, int Price)
{
	map<string, Product*>::iterator it = productList.find(string(productId));
	Product* lPtr;
	if ( it == productList.end() )
	{
		lPtr = new Product();
		productList.insert(pair<string,Product*>(string(productId), lPtr));
	}
	else
		lPtr = it->second;
	string lOrderId(OrderId); 
	return lPtr->addOrder(lOrderId, BidOrOffer, Price);
}

int ContainerClass::OnOrderDel(char *productId, char *OrderId)
{
	map<string, Product*>::iterator it = productList.find(string(productId));
	if ( it == productList.end() )
		return 0;
	string lOrderId(OrderId);
	return (it->second)->delOrder(lOrderId);
}

int ContainerClass::Print()
{
	map<string, Product*>::iterator itbegin = productList.begin();
	map<string, Product*>::iterator itend =   productList.end();

	for ( ; itbegin != itend; ++itbegin )
	{
		string lProductId = itbegin->first;
		(itbegin->second)->print(lProductId);
		cout << endl;
	}
	return true;
}
