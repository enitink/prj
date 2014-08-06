#include "Orders.h"
#include <iostream>

using namespace std;

Orders::Orders(string& lOrderId, unsigned lOrderType, unsigned lPrice)
	: orderId(lOrderId)
	, price(lPrice)
	, orderType(lOrderType)
{
}

Orders::~Orders()
{
}

bool Orders::operator()(const Orders& lOb, const Orders& rOb)
{
	bool res = false;

	res = (lOb.price > rOb.price);

	return ( 1 == orderType ) ? res : !res;
}

string& Orders::getOrderId()
{
	return orderId;
}

unsigned Orders::getPrice()
{
	return price;
}
