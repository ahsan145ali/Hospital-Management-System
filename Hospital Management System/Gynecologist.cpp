#include "Gynecologist.h"

Gynecologist::Gynecologist()
{
	specialize_in = new char[30];

}

Gynecologist::Gynecologist(char* sp,string time, int cab, double fees, char* p, char* r, int a, char g, string ph) :Doctor(time, cab, fees, p, r, a, g, ph)
{
	specialize_in = new char[40];
	int count = 0;

	for (int i = 0; sp[i] != '\0'; i++)
	{
		specialize_in[i] = sp[i];
		count++;
	}
	specialize_in[count] = '\0';
}

void Gynecologist::display()
{
	cout << "Specialized in: " << specialize_in << endl;
	Doctor::display();

}
Gynecologist::~Gynecologist()
{
}