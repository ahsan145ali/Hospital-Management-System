#include "Staff.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
Staff::Staff()
{
	pay=0;
}
Staff::Staff(string t,double in,char* p, char* r, int a, char g, string ph) :Person(p,r,a,g,ph)
{
	timming=t;
	pay=in;
	
}
void Staff::set_timming(string t)
{
	timming=t;
}
void Staff::set_pay(double p)
{
	pay=p;
}
void Staff::display_all_staff()
{
	ifstream pin("Staff.txt");
	cout << "Name\tResidence\tage\tgender\tConatact\ttimmings   pay\tposition" << endl;
	int count = 0;
	for (int i = 0; !pin.eof(); i++)
	{
		char* data = new char[50];
		pin.getline(data, 50);
		count++;
		cout << data << "    ";
		if (count == 8)
		{
			cout << endl;
			cout << "*****************************************************************************************************"<<endl;
			count = 0;
		}
	}
}
string Staff::get_timming()
{
	return timming;
}
double Staff::get_pay()
{
	return pay;
}
void Staff::set_position(string p)
{
	position=p;
}
string Staff::get_position()
{
	return position;
}
void Staff::hire()
{
	char *n=new char[30];
	char* r=new char[30];
	int a=0;
	char g='\0';
	string p_p;
	cout<<"Name: "<<endl;
	cin.getline(n,29);
	set_person_name(n);
	cout<<"Residence: "<<endl;
	cin.getline(r,29);
	set_residence(r);
	cout<<"Age: "<<endl;
	cin>>a;
	set_age(a);
	cout<<"Gender: "<<endl;
	cin>>g;
	set_gender(g);
	cout<<"Person Phone: "<<endl;
	cin>>p_p;
	set_person_phone(p_p);
	cout<<"Position: "<<endl;
	cin>>position;
}
void Staff::display()
{
	cout<<"Timmings: "<<timming<<endl;
	cout<<"Pay: "<<pay<<endl;
	//cout<<"Position: "<<position<<endl;
	Person::display();
}
Staff::~Staff()
{
}