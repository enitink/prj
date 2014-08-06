#include "Product.h"
#include "Orders.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

Product::Product()
{
	
}

Product::~Product()
{
	map<string, Orders*>::iterator itbegin = buy.begin();
	map<string, Orders*>::iterator itend = buy.end();
	for ( ; itbegin != itend; ++itbegin )
	{
		Orders* lPtr = itbegin->second;
		delete lPtr; 
	} 
	buy.clear();
	itbegin = sell.begin();
	itend = sell.end();
	for ( ; itbegin != itend; ++itbegin )
	{
		Orders* lPtr = itbegin->second;
		delete lPtr; 
	}
	sell.clear();
}

int Product::addOrder(string& lOrderId, unsigned lOrderType, unsigned lPrice)
{
	Orders* lPtr = new Orders(lOrderId, lOrderType, lPrice);
	
	pair<map<string,Orders*>::iterator, bool> ret;
	if ( 1 == lOrderType )
		ret = buy.insert(pair<string, Orders*>(lOrderId, lPtr));
	else
		ret = sell.insert(pair<string, Orders*>(lOrderId, lPtr));
	if (ret.second==false)
	{
		delete lPtr;
		return 0;
	}
	return 1;
}

int Product::delOrder(string& lOrderId)
{
	map<string, Orders*>::iterator it = buy.find(lOrderId);
	if ( it == buy.end() )
		return 0;
	buy.erase(it);
	return 1;
}
	
int Product::print(string& lProductId)
{
	cout << lProductId << endl;
	string dummy;
	vector<Orders> dst(0, Orders(dummy, 1,1));
	dst.clear();
	map<string, Orders*>::iterator itbegin = buy.begin();
	map<string, Orders*>::iterator itend = buy.end();
	for ( ; itbegin != itend; ++itbegin )
	{
		dst.push_back(*(itbegin->second));
	}
	cout << "Buy:" << endl;
	Orders comparator(dummy, 2, 1);
	sort(dst.begin(), dst.end(), comparator);
	int i;
	for (i = 0; i < buy.size(); ++i)
		cout << dst[i].getOrderId() << " " << dst[i].getPrice() << endl; 

	dst.clear();
	itbegin = sell.begin();
	itend = sell.end();
	for ( ; itbegin != itend; ++itbegin )
	{
		dst.push_back(*(itbegin->second));
	}
	cout << "Sell:" << endl;
	sort(dst.begin(), dst.end(), comparator);
	for (i = 0; i < sell.size(); ++i)
		cout << dst[i].getOrderId() << " " << dst[i].getPrice() << endl; 
	
	return true;
}
