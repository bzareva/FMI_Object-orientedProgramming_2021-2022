#include "String.h"

String::String(const char* str) :size(strLen(str))
{
	string = new char[size + 1];
	strCpy(string, str);
}

String::String(const String& rhs)
{
	copy(rhs);
}

String& String::operator=(const String& rhs) 
{
	if (this != &rhs)
	{
		free();
		copy(rhs);
	}

	return *this;
}

String::~String() 
{
	free();
}

char& String::at(unsigned index) 
{
	if (index < 0 || index > size) 
	{
		throw std::out_of_range("Invalid index!");
	}

	return string[index];
}

const char& String::at(unsigned index)const 
{
	if (index < 0 || index > size) 
	{
		throw std::out_of_range("Invalid index!");
	}

	return string[index];
}

void String::add(char ch) 
{
	try
	{
		resize();
	}
	catch (std::out_of_range& e)
	{
		std::cerr << e.what() << std::endl;
	}

	string[size] = ch;
	++size;
	string[size] = '\0';
}

bool String::insertAt(char ch, const unsigned index) 
{
	if (index < 0 || index > size) 
	{
		return false;
	}

	try {
		resize();

	}
	catch (std::out_of_range& e) 
	{
		std::cerr << e.what() << std::endl;
	}
	
	for (unsigned i = size; i > index; --i) 
	{
		string[i] = string[i - 1];
	}

	string[index] = ch;
	++size;

	return true;
}

bool String::removeAt(unsigned index) 
{
	if (index < 0 || index > size) 
	{
		return false;
	}

	for (unsigned i = index; i < size - 1; ++i)
	{
		string[i] = string[i + 1];
	}

	string[size - 1] = '\0';
	--size;

	return true;
}

void String::resize()
{
	size = size + 1;
	char* curr = new char[size];
	strCpy(curr, string);

	if (string != nullptr) 
	{
		free();
	}

	string = curr;
}

void String::strCpy(char* dest, const char* src) 
{
	while (*src) 
	{
		*dest = *src;
		++src;
		++dest;
	}

	*dest = '\0';
}

unsigned String::strLen(const char* str) 
{
	unsigned length = 0;
	while (*str)
	{
		++str;
		++length;
	}

	return length;
}

int String::strCmp(const char* str1, const char* str2)
{
	while (*str1 && (*str1 == *str2))
	{
		++str1;
		++str2;
	}

	return *str1 - *str2;
}

void String::strCat(char* dest, const char* src) 
{
	while (*dest) 
	{
		++dest;
	}

	strCpy(dest, src);
}

void String::setString(const char* str)
{
	if (string != nullptr)
	{
		free();
	}

	size = strLen(str);
	string = new char[size];
	strCpy(string, str);
}

unsigned String::getSize()const 
{
	return size;
}

const char* String::geString()const
{
	return string;
}

void String::copy(const String& obj) 
{
	size = obj.size;
	string = new char[size + 1];
	strCpy(string, obj.string);
}

void String::free() 
{
	delete[]string;
}
