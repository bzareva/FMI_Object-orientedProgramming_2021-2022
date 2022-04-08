#ifndef _DOCTOR_H_
#define _DOCTOR_H_

#include "Patient.h"

class Doctor {

private:

	static int registered;
	int countPatients;
	char* docName;
	Patient* listOfPatients;

public:

	Doctor();
	Doctor(const char* dName, int count);
	Doctor(const Doctor& rhs);
	Doctor& operator=(const Doctor& rhs);
	~Doctor();

	void print(int limit)const;
	void doRegister(const Patient& p);
	double averageVisits()const;

private:

	void copyDoc(const Doctor& rhs);
	void freeDoc();

};

#endif //_DOCTOR_H_
