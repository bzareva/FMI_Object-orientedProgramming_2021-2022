#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>

class Vector {

private:

	unsigned size;
	unsigned capacity;
	int* data;
	
	static const unsigned VECTOR_CAPACITY;
	
public:

	Vector();
	Vector(const int* data, unsigned size);
	Vector(const int& item);
	Vector(const Vector& rhs);
	Vector& operator=(const Vector& rhs);
	~Vector();

	bool empy()const;
	void push_back(int item);
	void pop();
	void insert(unsigned index, const int& item);
	void erase(unsigned index);
	void reserve(unsigned capacity);

	int& at(unsigned index);
	const int& at(unsigned index)const;

	int& front();
	const int& front()const;

	int& back();
	const int& back()const;

	unsigned size()const;
	unsigned capacity()const;

private:

	void copy(const Vector& rhs);
	void free();

};

#endif // _VECTOR_H_
