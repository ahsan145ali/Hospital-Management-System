#pragma once

#include "Doctor.h"

class Gynecologist:public Doctor
{
private:
	char* specialize_in;
public:
	Gynecologist();
	Gynecologist(char*, string, int, double, char*, char*, int, char, string);
	void display();
	~Gynecologist();
};