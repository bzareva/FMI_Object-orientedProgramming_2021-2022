#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>

struct Date {

public:

	int day;
	int month;
	int year;

	Date(int d = 4, int m = 4, int y = 2002);
	void printDate()const;

};

#endif //_DATE_H_
