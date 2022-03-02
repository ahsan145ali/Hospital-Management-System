#include "Receptionist.h"
#include<fstream>
Receptionist::Receptionist()
{
}
Receptionist::Receptionist(string ed, string t, double in, char* p, char* r, int a, char g, string ph) :Staff(t,in,p,r,a,g,ph)
{
	education = ed;
}
void Receptionist::set_education(string e)
{
	education=e;
}
void Receptionist::display()
{
	cout << "Education: " << education<<endl;
	Staff::display();
}
void Receptionist::update_recep_file(string ed, string t, double in, char* p, char* r, int a, char g, string ph)
{
	ofstream docout("Staff.txt", ios::app);

	docout << p << endl;
	docout << r << endl;
	docout << a << endl;
	docout << g << endl;
	docout << ph << endl;
	docout << t << endl;
	docout << in << endl;
	docout << ed << endl;



	docout.close();
}
string Receptionist::get_educatiion()
{
	return education;
}
Receptionist::~Receptionist()
{
}