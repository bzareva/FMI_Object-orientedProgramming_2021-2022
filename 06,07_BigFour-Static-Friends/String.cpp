
// author  Michael Zarkov 

#include <iostream>
#include <cstring>
#include "String.h"

const size_t String::BUFF_SIZE = 256;


String::String() : size(0), capacity(0) {
	str = new char[capacity + 1];
	*str = '\0';
}
String::String(const String& other) {
	size = other.size;
	capacity = other.capacity;
	str = new char[capacity + 1];
	strcpy(str, other.str);
}
String::String(const char* other_str) : size(0), capacity(0), str(nullptr) {
	if (!other_str) 
		throw ("Trying to read from nullptr!");
	
	capacity = strlen(other_str);
	size = capacity;
	str = new char[capacity + 1];
	strcpy(str, other_str);
}
String::~String() {
	delete[] str;
}

String& String::operator=(const String& other) {
	if (this != &other) {
		if (other.size > capacity) {
			delete[] str;
			capacity = other.size;
			str = new char[capacity + 1];
		}
		
		strcpy(str, other.str);
		size = other.size;
	}

	return *this;
}
String& String::operator+=(char ch) {
	if (ch != '\0') {
		if (size >= capacity)	// If the string is full, resize it.
			resize(1);

		str[size] = ch;
		str[size + 1] = '\0';
		++size;
	}
	
	return *this;
}
char String::operator[](size_t index) const {
	if (index <= size)
		return str[index];
	else
		throw std::out_of_range("Reading from invalid index!");
}

std::ostream& operator<<(std::ostream& outStream, String string) {
	if (outStream.good()) {
		outStream << string.getCString();
	}
	return outStream;
}

void String::resize(size_t add_capacity) {
	if (add_capacity == 0)
		return;

	capacity += add_capacity;
	char* new_str = new char[capacity + 1];
	strcpy(new_str, str);
	delete[] str;
	str = new_str;
}
bool String::insertAt(char ch, size_t index) {
	if (ch != '\0' && index <= size) {
		if (size >= capacity)	// If the string is full, resize it.
			resize(1);

		// Shifts the characters by one to the right.
		for (size_t i = size + 1; i > index; --i)
			str[i] = str[i - 1];

		str[index] = ch;
		++size;
	}

	return false;
}
bool String::removeAt(size_t index) {
	if (index < size) {
		str[index] = '\0';
		strcpy(str + index, str + index + 1);	// Shift by one character to the left.
		--size;

		return true;
	}
	else
		throw std::out_of_range("Invalid index!");

	return false;
}
void String::freeUnused() {
	capacity = size;
	char* new_str = new char[capacity + 1];
	strcpy(new_str, str);
	delete[] str;
	str = new_str;
}

const char* String::getCString() const { return str; }
size_t String::getSize() const { return size; }
size_t String::getCapacity() const { return capacity; }
