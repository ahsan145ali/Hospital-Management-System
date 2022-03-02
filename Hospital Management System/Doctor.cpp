#include "Doctor.h"

Doctor::Doctor()
{
}
Doctor::Doctor(string t, int c, double f, char* p, char* r, int a, char g, string ph) :Person(p,r,a,g,ph)
{
	
	doctor_timming = t;
	cabin = c;
	fees = f;
	
}
void Doctor::set_doctor_timming(string t)
{
	doctor_timming=t;
}
void Doctor::set_cabin(int c)
{
	cabin=c;
}
void Doctor::set_fees(double f)
{
	fees=f;
}
//void Doctor::set_patient_no(int p)
//{
//
//	patient_no=p;
//}
string Doctor::get_doctor_timming()
{
	return doctor_timming;
}
int Doctor::get_cabin()
{
	return cabin; 
}
double Doctor::get_fees()
{
	return fees;
}
//int Doctor::get_patient_no()
//{
//	return patient_no;
//}
void Doctor::display()
{
	cout << "timming: " << doctor_timming << endl;
	cout << "Cabin No: " << cabin << endl;
	cout << "Fees: " << fees << endl;
	Person::display();
}
Doctor::~Doctor()
{
}