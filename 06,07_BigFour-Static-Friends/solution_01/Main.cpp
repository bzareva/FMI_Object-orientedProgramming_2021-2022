#include <iostream>
#include "ShopBudget.h"

int main()
{

	Product p1("coffe", true, 1.45);
	Product p2("ice cream", true, 3.56);
	Product p3("fries", true, 6.45);
	Product p4("strawberry", true, 8.35);
	Product p5("bananas", true, 3.45);

	Product goods[5];
	goods[0] = p1;
	goods[1] = p2;
	goods[2] = p3;
	goods[3] = p4;
	goods[4] = p5;
	
	ShopBudget shop(5, goods);

	if (shop.sale(p4) && shop.sale(p1) && shop.sale(p3))
	{
		std::cout << shop.getBudget() << std::endl;
	}

	return 0;
}
