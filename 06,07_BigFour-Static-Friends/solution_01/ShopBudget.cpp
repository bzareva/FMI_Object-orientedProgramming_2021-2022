#include "ShopBudget.h"

double ShopBudget::budget = 0.0;

ShopBudget::ShopBudget()
{
	countOfGoods = 1;

	goods = new Product[countOfGoods];
	goods[0] = Product("wine", true, 8.45);
	budget += goods[0].price;
}

ShopBudget::ShopBudget(int count, Product* shopGoods)
{
	if (count <= 0) 
	{
		countOfGoods = 1;

		goods = new Product[countOfGoods];
		goods[0] = Product("wine", true, 6.88);

		budget += 6.88;

	} else {

		countOfGoods = count;
		goods = new Product[countOfGoods];

		for (int i = 0; i < countOfGoods; ++i)
		{
			goods[i] = shopGoods[i];

			goods[i].isAvailability = shopGoods[i].isAvailability;

			budget += shopGoods[i].price;
		}
	}
}

ShopBudget::ShopBudget(const ShopBudget& rhs)
{
	copyShop(rhs);
}

ShopBudget& ShopBudget::operator=(const ShopBudget& rhs)
{
	if (this != &rhs)
	{
		freeShop();
		copyShop(rhs);
	}
	
	return *this;
}

ShopBudget::~ShopBudget()
{
	freeShop();
}

bool ShopBudget::sale(const Product& product)
{
	for (int i = 0; i < countOfGoods; ++i)
	{
		if (goods[i].isAvailability && !strcmp(goods[i].name, product.name))
		{
			goods[i].isAvailability = false;
			budget -= goods[i].price;

			return true;
		}
	}

	return false;
}

double ShopBudget::getBudget()const
{
	return budget;
}

void ShopBudget::copyShop(const ShopBudget& rhs)
{
	countOfGoods = rhs.countOfGoods;
	goods = new Product[countOfGoods];

	for (int i = 0; i < countOfGoods; ++i)
	{
		goods[i] = rhs.goods[i];
	}

	budget = rhs.budget;
}

void ShopBudget::freeShop()
{
	delete[] goods;
}
