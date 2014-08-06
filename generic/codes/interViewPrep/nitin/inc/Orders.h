#ifndef _ORDERS_H
#define _ORDERS_H

#include <string>

using std::string;

class Orders
{
public:
	Orders(string&, unsigned, unsigned);
	~Orders();

	bool operator()(const Orders&, const Orders&);
	//No need of copy constructor, and assignment operator, as shallow copy by their defaults is enough

	string& 		getOrderId();
	unsigned int 	getPrice();

private:
	string 			orderId;
	unsigned		price;
	unsigned		orderType;
};
#endif // _ORDERS_H
