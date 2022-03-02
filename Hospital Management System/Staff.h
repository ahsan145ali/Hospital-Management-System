#pragma once

#include <iostream>
#include<string>
#include "Person.h"
using namespace std;

class Staff:public Person
{
private:
	string timming;
	double pay;
	string position;
public:
	Staff();
	Staff(string,double,char*,char*,int,char,string);
	void set_timming(string);
	void set_pay(double);
	void set_position(string);
	string get_position();
	string get_timming();
	double get_pay();
	void hire();
	void display_all_staff();
	virtual void display();
	
	~Staff();
};