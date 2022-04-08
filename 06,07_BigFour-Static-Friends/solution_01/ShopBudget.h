#ifndef _SHOP_BUDGET_H_
#define _SHOP_BUDGET_H_

#include "Product.h"

class ShopBudget {

private:

	static double budget;
	int countOfGoods;
	Product* goods;

public:
	
	ShopBudget();
	ShopBudget(int count, Product* shopGoods);
	ShopBudget(const ShopBudget& rhs);
	ShopBudget& operator=(const ShopBudget& rhs);
	~ShopBudget();

	bool sale(const Product& product);
	double getBudget()const;

private:

	void copyShop(const ShopBudget& rhs);
	void freeShop();

};

#endif //_SHOP_BUDGET_H_
