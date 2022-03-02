#include "Hospital.h"


Hospital::Hospital()
{	
	choose = 0;
}
Hospital::Hospital(Person &object): name("hospital"), address("bahria-town"), phone_num("123456789")
{
	this->person = &object;
	
}
void Hospital::hospital_dis()
{
	cout << "\t\t\t********************************************************************" << endl;
	cout << "\t\t\t* ************************************************************** * *" << endl;
	cout << "\t\t\t* * ********************************************************** * * *" << endl;
	cout << "\t\t\t* * *                                                          * * *" << endl;
	cout << "\t\t\t* * *                    What You Want To Access               * * *" << endl;
	cout << "\t\t\t* * *                                                          * * *" << endl;
	cout << "\t\t\t* * *                      1) Pharmacy                         * * *" << endl;
	cout << "\t\t\t* * *                      2) Doctors                          * * *" << endl;
	cout << "\t\t\t* * *                      3) Patients                         * * *" << endl;
	cout << "\t\t\t* * *                      4) Staff                            * * *" << endl;
	cout << "\t\t\t* * *                      5) Exit                             * * *" << endl;
	cout << "\t\t\t* * ********************************************************** * * *" << endl;
	cout << "\t\t\t* ************************************************************** * *" << endl;
	cout << "\t\t\t********************************************************************" << endl;
}
void Hospital::set_choose(int c)
{
	choose = c;
}
istream& operator>>(istream& is, Hospital& object)
{
	
	
	
		if (object.choose == 1)
		{
			cout << "pharmacy" << endl;
			is >> object.pharmacy;
			return is;
		}
		/*else if (object.choose == 2)
		{
			cout << "room" << endl;
			is >> object.room;
			return is;
		}*/
		else if (object.choose == 5)
		{
			cout << "Thank You For Visiting" << endl;
			return is;
		}
	
}
ostream& operator<<(ostream& os,Hospital& object) 
{
	if (object.choose == 1)
	{

		os << object.pharmacy;
		return os;
	}
	else if (object.choose == 2)
	{

		os << object.room;
		return os;
	}

	
}
void Hospital::set_class_person()
{
	//this->person->set_person_name("AHSAN");
	//this->person->set_person_phone("03355487492");
	this->person->display();
	//cout << this->person->get_person_name();
	//cout << this->person->get_person_phone();
}

void Hospital::set_class_person_gye()
{
	//this->person->set_person_name("AHSAN");
	//this->person->set_person_phone("03355487492");
	this->person->display();
	//cout << this->person->get_person_name();
	//cout << this->person->get_person_phone();
}
void Hospital::set_class_person_cs()
{
	//this->person->set_person_name("AHSAN");
	//this->person->set_person_phone("03355487492");
	this->person->display();
	//cout << this->person->get_person_name();
	//cout << this->person->get_person_phone();
}
void Hospital::set_class_Patient()
{
	//this->person->set_person_name("AHSAN");
	//this->person->set_person_phone("03355487492");
	this->person->display();
	//cout << this->person->get_person_name();
	//cout << this->person->get_person_phone();
}
void Hospital::set_class_staff()
{
	//this->person->set_person_name("AHSAN");
	//this->person->set_person_phone("03355487492");
	this->person->display();
	//cout << this->person->get_person_name();
	//cout << this->person->get_person_phone();
}
Hospital::~Hospital()
{
}
