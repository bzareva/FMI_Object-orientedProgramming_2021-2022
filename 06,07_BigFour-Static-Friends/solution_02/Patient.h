#ifndef _PATIENT_H_
#define _PATIENT_H_

#include <string.h>
#include "Date.h"

class Patient {

private:

	char* name;
	Date birthDate;
	int visits;

public:

	Patient(const char* pName = "Asen", Date pBirthDate = Date(1,2,2001), int pVisits = 0);
	Patient(const Patient& rhs);
	Patient& operator=(const Patient& rhs);
	~Patient();

	void printPatient()const;
	int getVisit()const;
	const char* getPatientName()const;

private:

	void free();
	void copyPatient(const Patient& rhs);

};

#endif //_PATIENT_H_
