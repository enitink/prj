#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Item
{
public:
	Item() {}
	Item(string& name, float& price)
	:  _name(name),
	   _price(price) 
	{}
	bool operator<(const Item& rhs)
	{
		return this->_name<rhs._name;
	}
public:
	string _name;
	float _price;
};

bool menuItemComp(const Item& lhs, const Item& rhs) {return lhs._name<rhs._name;}

class Menu
{
public:
	void AddItem(string& name, float& price)
	{
		Item newItem(name,price);
		_menu.push_back(newItem);
	}

public:
	vector<Item> _menu;
};

/*
class Order
{
public:
	void addItemToOrder(Item& item)
	{
		_orderList.push_back(item);
	}
	void addItemsToOrder(vector<Item>& items)
	{
		std::vector<Item>::iterator it = items.begin();
		for( ; it != items.end(); ++it)
			_orderList.push_back(*it);
	}
private:
	vector<Item> _orderList; 
};
*/

class Resturant
{
public:
	Resturant(string& name, unsigned int capacity)
	: _name(name), 
	_capacity(capacity),
	  _orderId(0)
	{}

	bool addOrder(Item& item)
	{
		if (_orderList.size() >= _capacity)
			return false;
		_orderList[_orderId++] = item; //need to reset oder id too
	}

	bool completeOrder(int orderId)
	{
		map<int, Item>::iterator it = _orderList.find(orderId);
		_orderList.erase(it);
		//notify system
	}

	bool addItemsToMenu() { return false;}
public:
	string _name;
	unsigned int _capacity;
	map<int, Item> _orderList;
	Menu	_menu;
	unsigned int _orderId;
};

class strategiesIMPL 
{
public:
	virtual bool applyStrategy(Resturant& restlist, vector<Item>& items)
	{ return false; }
};

class allItemsAvailableStrategy : public strategiesIMPL
{
public:
	virtual bool applyStrategy(Resturant& restlist, vector<Item>& items)
	{
		int foundres = true;
		vector<Item>::iterator it2 = items.begin();
		for (; it2 != items.end(); ++it2)
		{
			vector<Item>::iterator it1 = restlist._menu._menu.begin();
			bool found = false;
			for(; it1 != restlist._menu._menu.end(); ++it1)
			{
				if (it1->_name == it2->_name)
				{
					found = true;
					break;
				}
			}
			if (!found)
			{
				foundres = false;
				break;
			}
		}
		if (foundres)
			return foundres;
	}
};

class bestPriceStrategy
{
public:
	virtual Resturant& applyStrategy(vector<Resturant>& restlist, vector<Item>& items)
	{
			
	}
};

class foodOrderSystem
{
public:
	void addNewResturant(string& name, unsigned int capacity)
	{
		Resturant newRest(name, capacity);
		_resturant.push_back(newRest);
	}
	void alterMenuItem(string& restname, string& itemname, float& price)
	{
		vector<Resturant>::iterator it = _resturant.begin();
		for (; it != _resturant.begin(); ++it)
		{
			if(it->_name == restname)
			{
				it->_menu.AddItem(itemname, price);
			}
		}
	}
	void placeOrder(vector<Item> & itemList)
	{
		vector<strategiesIMPL>::iterator it = _strategies.begin();
		vector<Resturant>::iterator it1 = _resturant.begin();		//instead prepare templist
		for( ; it != _strategies.end(); ++it)
		{
			for(; it1 != _resturant.end(); ++it1)
				if ( it->applyStrategy(*it1, itemList) == false)
					_resturant.erase(it1);
		}

	}
	void displayReturantWiseItems()
	{
	}

private:
	vector<Resturant> _resturant;
	vector<strategiesIMPL> _strategies; 	
};



///Tests

void Test()
{
	foodOrderSystem sys;

	string res("resturant1");
	string item("item");
	sys.addNewResturant(res, 2);
	float price = 5;
	sys.alterMenuItem(res, item, price);
}

int main()
{
	Test();
	return 0;
}
