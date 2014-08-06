#ifndef _PRODUCT_H
#define _PRODUCT_H

#include <map>
#include <string>

using std::map;
using std::string;

class Orders;

class Product
{
public:
	Product();
	~Product();

	int addOrder(string&, unsigned, unsigned);
	int delOrder(string&);

	int print(string&);
private:
	map<string, Orders*> buy;
	map<string, Orders*> sell;
};

#endif //_PRODUCT_H
