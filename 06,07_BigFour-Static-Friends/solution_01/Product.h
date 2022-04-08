#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string.h>

class Product {

public:
	
	friend class ShopBudget;

private:
	
	char* name;
	bool isAvailability;
	double price;
	
public:

	Product();
	Product(const char* prodName, bool prodAvailable, double goodsPrice);
	Product(const Product& rhs);
	Product& operator=(const Product& rhs);
	~Product();

private:

	void copy(const Product& rhs);
	void free();

};

#endif //_PRODUCT_H_
