#pragma once

#include<string>
#include<iostream>
#include"Pharmacy.h"
#include"Room.h"
#include"Person.h"
using namespace std;

class Hospital
{
private:
	const string name;
	const string address;
	const string phone_num;
	int choose;
	Pharmacy pharmacy;
	Room room;
	Person *person;

public:
	
	Hospital();
	Hospital(Person &);
	void set_choose(int);
	friend istream& operator>>(istream&,Hospital&);
	friend ostream& operator<<(ostream&,Hospital&);
	void hospital_dis();
	void set_class_person();
	void set_class_person_gye();
	void set_class_person_cs();
	void set_class_Patient();
	void set_class_staff();
	~Hospital();
};

