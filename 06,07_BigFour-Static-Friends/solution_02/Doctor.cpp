#include "Doctor.h"

int Doctor::registered = 0;

Doctor::Doctor()
{
	docName = new char[6];
	strcpy_s(docName, 6, "Lilly");

	countPatients = 1;

	listOfPatients = new Patient[countPatients];
}

Doctor::Doctor(const char* dName, int count)
{
	size_t len = strlen(dName);
	docName = new char[len + 1];
	strcpy_s(docName, len + 1, dName);

	countPatients = count;

	listOfPatients = new Patient[countPatients];
}

Doctor::Doctor(const Doctor& rhs)
{
	copyDoc(rhs);
}

Doctor& Doctor::operator=(const Doctor& rhs)
{
	if (this != &rhs)
	{
		freeDoc();
		copyDoc(rhs);
	}
}

Doctor::~Doctor()
{
	freeDoc();
}

void Doctor::print(int limit)const
{
	for (int i = 0; i < countPatients; ++i)
	{
		if (listOfPatients[i].getVisit() > limit)
		{
			listOfPatients[i].printPatient();
		}
	}
}

void Doctor::doRegister(const Patient& p)
{
	if (registered > countPatients)
	{
		return;
	}

	listOfPatients[registered] = p;
	++registered;
}

double Doctor::averageVisits()const
{
	if (countPatients <= 0)
	{
		return 0.0;
	}

	double total = 0.0;
	for (int i = 0; i < countPatients; ++i)
	{
		total += listOfPatients[i].getVisit();
	}

	return total / countPatients;
}

void Doctor::copyDoc(const Doctor& rhs)
{
	size_t len = strlen(rhs.docName);
	docName = new char[len + 1];
	strcpy_s(docName, len + 1, rhs.docName);

	countPatients = rhs.countPatients;

	listOfPatients = new Patient[countPatients];
	for (int i = 0; i < countPatients; ++i)
	{
		listOfPatients[i] = rhs.listOfPatients[i];
	}
}

void Doctor::freeDoc()
{
	delete[] docName;
	delete[] listOfPatients;
}
