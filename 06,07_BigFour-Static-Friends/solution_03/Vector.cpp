#include "Vector.h"

const unsigned Vector::VECTOR_CAPACITY = 16;

Vector::Vector() :size(0), capacity(VECTOR_CAPACITY), data(nullptr)
{
	data = new int[capacity];
}

Vector::Vector(const int* data, unsigned size) 
{
	if (size < 0)
	{
		this->size = 0;
	} else {
		this->size = size;
	}

	if (VECTOR_CAPACITY < this->size) 
	{
		this->capacity = this->size + 1;
	} else {
		this->capacity = VECTOR_CAPACITY;
	}

	this->data = new int[this->capacity];
	for (unsigned i = 0; i < this->size; ++i) 
	{
		this->data[i] = data[i];
	}

	if (this->size == 0) {
		this->data = nullptr;
	}
}

Vector::Vector(const int& item) :capacity(VECTOR_CAPACITY), size(1) 
{
	data = new int[capacity];
	data[0] = item;
}

Vector::Vector(const Vector& rhs) 
{
	copy(rhs);
}

Vector& Vector::operator=(const Vector& rhs) 
{
	if (this != &rhs) 
	{
		free();
		copy(rhs);
	}

	return *this;
}

Vector::~Vector() 
{
	free();
}

bool Vector::empy()const
{
	return size == 0;
}

void Vector::push_back(int item) 
{

	if (size + 1 >= capacity) {

		try 
		{
			reserve(2 * size);
		}
		catch (std::out_of_range& e) 
		{
			std::cerr << e.what() << std::endl;
		}
	}

	data[size] = item;
	++size;
}

void Vector::pop() 
{
	--size;
}

void Vector::insert(unsigned index, const int& item)
{
	if (index < 0 || index >= size) 
	{
		throw std::out_of_range("Invalid index!\n");
	}

	if (size >= capacity) {

		try 
		{
			reserve(2 * size);
		}
		catch (std::out_of_range& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	for (unsigned i = size; i > index; --i)
	{
		data[i] = data[i - 1];
	}

	data[index] = item;
	++size;
}

void Vector::erase(unsigned index) 
{
	if (index < 0 || index >= size) 
	{
		throw std::out_of_range("Invalid index!\n");
	}

	for (unsigned i = index; i < size - 1; ++i) 
	{
		data[i] = data[i + 1];
	}

	--size;
}

void Vector::reserve(unsigned capacity)
{
	if (capacity <= 0 || capacity <= this->capacity || capacity <= this->size) {
		throw std::out_of_range("Invalid capacity!\n");
	}

	this->capacity = capacity;

	int* data = new int[this->capacity];
	for (unsigned i = 0; i < this->size && i < this->capacity; ++i) {
		data[i] = this->data[i];
	}

	delete[] this->data;
	this->data = data;
}

int& Vector::at(unsigned index) 
{
	try 
	{
		return data[index];
	}
	catch (std::out_of_range& e) 
	{
		std::cerr << e.what() << std::endl;
	}
}

const int& Vector::at(unsigned index)const 
{
	try
	{
		return data[index];
	}
	catch (std::out_of_range& e) {
		std::cerr << e.what() << std::endl;
	}
}

int& Vector::front() 
{
	return at(0);
}

const int& Vector::front()const 
{
	return at(0);
}

int& Vector::back()
{
	return at(size - 1);
}

const int& Vector::back()const 
{
	return at(size - 1);
}

unsigned Vector::size()const
{
	return size;
}

unsigned Vector::capacity()const 
{
	return capacity;
}

void Vector::copy(const Vector& rhs) {

	capacity = rhs.capacity;
	size = rhs.size;

	data = new int[capacity];
	for (unsigned i = 0; i < rhs.size && i < capacity; ++i) {
		data[i] = rhs.data[i];
	}
}

void Vector::free() 
{
	delete[] data;
}