#include "Child_Specialist.h"

Child_Specialist::Child_Specialist()
{
	pedriatic_type = new char[40];
}
Child_Specialist::Child_Specialist(char* type, string time, int cab, double fees, char* p, char* r, int a, char g, string ph) :Doctor(time, cab, fees, p, r, a, g, ph)
{
	pedriatic_type = new char[40];
	int count = 0;

	for (int i = 0; type[i] != '\0'; i++)
	{
		pedriatic_type[i] = type[i];
		count++;
	}
	pedriatic_type[count] = '\0';

}

void Child_Specialist::display()
{
	cout << "Child Specialist Pedriatic Type: " << pedriatic_type << endl;
	Doctor::display();

}

Child_Specialist::~Child_Specialist()
{
}