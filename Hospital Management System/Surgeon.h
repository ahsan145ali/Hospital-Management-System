#pragma once

#include"Doctor.h"

class Surgeon:public Doctor
{
private:
	char* type_of_surgeon;
public:
	Surgeon();
	Surgeon(char*, string, int, double, char* , char* , int , char , string );
	 void display();
	~Surgeon();
};