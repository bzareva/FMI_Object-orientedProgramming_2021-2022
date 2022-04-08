#include "Patient.h"

Patient::Patient(const char* pName, Date pBirthDate, int pVisits)
	:visits(pVisits), birthDate(pBirthDate)
{
	size_t len = strlen(pName);
	name = new char[len + 1];
	strcpy_s(name, len + 1, pName);
}

Patient::Patient(const Patient& rhs)
{
	copyPatient(rhs);
}

Patient& Patient::operator=(const Patient& rhs)
{
	if (this != &rhs) 
	{
		free();
		copyPatient(rhs);
	}

	return *this;
}

Patient::~Patient()
{
	free();
}

void Patient::printPatient()const
{
	std::cout << "Name of patient: " << name << ", visits: " << visits;
	std::cout << ", \nbirth date: \n";
	birthDate.printDate();
}

int Patient::getVisit()const
{
	return visits;
}

const char* Patient::getPatientName()const
{
	return name;
}

void Patient::free()
{
	delete[] name;
}

void Patient::copyPatient(const Patient& rhs)
{
	size_t len = strlen(rhs.name);
	name = new char[len + 1];
	strcpy_s(name, len + 1, rhs.name);

	visits = rhs.visits;
	birthDate.day = rhs.birthDate.day;
	birthDate.month = rhs.birthDate.month;
	birthDate.year = rhs.birthDate.year;
}
