#include <ContainerClass.h>

int main()
{
	ContainerClass ob;

	ob.OnOrderAdd("Product1", "Order1", 1, 100);
	ob.OnOrderAdd("Product1", "Order2", 1, 101);
	ob.OnOrderAdd("Product2", "Order3", 1, 99);
	ob.OnOrderAdd("Product2", "Order4", 2, 100);
	ob.OnOrderAdd("Product1", "Order4", 2, 100);
	ob.OnOrderAdd("Product1", "Order5", 2, 101);
	ob.OnOrderAdd("Product2", "Order6", 2, 99);
	ob.OnOrderAdd("Product2", "Order7", 2, 100);
	ob.OnOrderAdd("Product1", "Order8", 1, 100);
	ob.OnOrderAdd("Product1", "Order9", 1, 101);
	ob.OnOrderAdd("Product2", "Order10", 1, 99);
	ob.OnOrderAdd("Product2", "Order11", 1, 100);
	ob.OnOrderAdd("Product1", "Order12", 2, 100);
	ob.OnOrderAdd("Product1", "Order13", 1, 101);
	ob.OnOrderAdd("Product2", "Order14", 2, 99);
	ob.OnOrderAdd("Product2", "Order15", 2, 100);

	ob.Print();	
	
	return 0;
}
