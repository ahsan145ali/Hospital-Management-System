#pragma once

#include <iostream>
#include<string>
#include "Person.h"
using namespace std;

class Doctor:public Person
{
private:
	string doctor_timming;
	int cabin;
	double fees;
	//int patient_no;
public:
	Doctor();
	Doctor(string, int, double, char* , char* , int , char , string );
	void set_doctor_timming(string);
	void set_cabin(int);
	void set_fees(double);
	//void set_patient_no(int);
	string get_doctor_timming();
	int get_cabin();
	double get_fees();
	//int get_patient_no();
	virtual void display();
	~Doctor();
};