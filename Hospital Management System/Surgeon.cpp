#include "Surgeon.h"

Surgeon::Surgeon()
{
	type_of_surgeon = new char[40];
}
Surgeon::Surgeon(char* type, string time, int cab, double fees, char* p, char* r, int a, char g, string ph) :Doctor(time, cab, fees,p,r,a,g,ph)
{
	type_of_surgeon = new char[40];
	int count = 0;

	for (int i = 0; type[i] != '\0'; i++)
	{
		type_of_surgeon[i] = type[i];
		count++;
	}
	type_of_surgeon[count] = '\0';

	
}
void Surgeon::display()
{
	cout << "Surgeon Typr: " << type_of_surgeon << endl;
	Doctor::display();

}
Surgeon::~Surgeon()
{

}