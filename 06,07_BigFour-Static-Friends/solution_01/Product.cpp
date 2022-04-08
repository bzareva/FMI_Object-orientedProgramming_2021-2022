#include "Product.h"

Product::Product()
{
	name = new char[5];
	strcpy_s(name, 5, "beer");

	isAvailability = true;
	price = 3.44;
}

Product::Product(const char* prodName, bool prodAvailable, double goodsPrice)
{
	size_t len = strlen(prodName);
	name = new char[len + 1];
	strcpy_s(name, len + 1, prodName);

    isAvailability = prodAvailable;
	price = goodsPrice;
}

Product::Product(const Product& rhs) 
{
	copy(rhs);
}

Product& Product::operator=(const Product& rhs)
{
	if (this != &rhs)
	{
		free();
		copy(rhs);
	}
	
	return *this;
}

Product::~Product() 
{
	free();
}

void Product::copy(const Product& rhs)
{
	size_t len = strlen(rhs.name);
	name = new char[len + 1];
	strcpy_s(name, len, rhs.name);

	price = rhs.price;
	isAvailability = rhs.isAvailability;
}

void Product::free() 
{
	delete[]name;
}
