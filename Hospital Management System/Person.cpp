#include "Person.h"

Person::Person()
{
	person_name=new char[30];
	residence=new char[30];
	age=0;
	gender='\0';
}
Person::Person(char* p, char* r, int a, char g, string ph)
{
	person_name = new char[30];
	residence = new char[30];
	age = 0;
	gender = '\0';
	
	int count = 0;
	
	for (int i = 0; p[i] != '\0'; i++)
	{
		
		person_name[i] = p[i];
		count++;
	}

	person_name[count] = '\0';

	 count = 0;
	for (int i = 0; r[i] != '\0'; i++)
	{
		residence[i] = r[i];
		count++;
	}
	residence[count] = '\0';

	age = a;
	gender = g;
	person_phone = ph;


}
void Person::set_person_name(char* p)
{
	int count=0;
	for(int i=0;p[i]!='\0';i++)
	{
	  person_name[i]=p[i];
	  count++;
	}
	person_name[count]='\0';


}
void Person::set_residence(char* r)
{
	int count=0;
	for(int i=0;r[i]!='\0';i++)
	{
		residence[i]=r[i];
		count++;
	}
	residence[count]='\0';
}
void Person::set_age(int a)
{
		age=a;
}
void Person::set_gender(char g)
{
	gender=g;
}
void Person::set_person_phone(string p)
{
	person_phone=p;
}
char* Person::get_person_name()
{
	return person_name;
}
char* Person::get_residence()
{
	return residence;
}
int Person::get_age()
{
	return age;
}
char Person::get_gender()
{
	return gender;
}
string Person::get_person_phone()
{
	return person_phone;
}
void Person::display()
{
	cout << "Name: " << person_name << endl;
	cout << "Residence: " << residence << endl;
	cout << "Age: " << age << endl;
	cout << "Gender: " << gender << endl;
	cout << "phone: " << person_phone << endl;
	
	
}
Person::~Person()
{
}