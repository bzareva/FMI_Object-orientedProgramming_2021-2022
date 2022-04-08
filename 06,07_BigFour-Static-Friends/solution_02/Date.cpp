#include "Date.h"

Date::Date(int d, int m, int y)
	:day(d), month(m), year(y)
{
	if (d <= 0 || d > 32) 
	{
		day = 2;
	}

	if (m <= 0 || m > 12)
	{
		month = 10;
	}

	if (y < 1000 || y > 9999)
	{
		year = 2007;
	}
}

void Date::printDate()const
{
	std::cout << "[d: " << day << ", m: " << month << ", y: " << year << "]\n";
}
