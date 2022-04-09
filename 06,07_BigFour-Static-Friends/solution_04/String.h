#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>

class String {

private:

	unsigned size;
	char*    string;

	static const unsigned RESIZE;

public:

	String(const char* str = "default");
	String(const String& rhs);
    String& operator=(const String& rhs);
	~String();

	char& at(unsigned index);
	const char& at(unsigned index)const;

	void add(char ch);
	bool insertAt(char ch, unsigned index);
	bool removeAt(unsigned index);
	void resize();

	void strCpy(char* dest, const char* src); 
	unsigned strLen(const char* str);
	int strCmp(const char* str1, const char* str2);
	void strCat(char* dest, const char* src);

	void print()const;

	void setString(const char* str);

	unsigned getSize()const;
	const char* geString()const;

private:

	void copy(const String& obj);
	void free();

};

#endif //_STRING_H_