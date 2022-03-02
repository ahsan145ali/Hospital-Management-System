#pragma once

#include "Doctor.h"

class Child_Specialist:public Doctor
{
private:
	char* pedriatic_type;
public:
	Child_Specialist();
	Child_Specialist(char*, string, int, double, char*, char*, int, char, string);
	void display();
	~Child_Specialist();
};