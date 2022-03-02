#include "Patient.h"
#include <iostream>
#include<string>
#include<fstream>
using namespace std;


Patient::Patient()
{
	room_allot=0;
}
Patient::Patient(Room & ro,string prob, string ta, string td, double f,int room, char* p, char* r, int a, char g, string ph) :Person(p, r, a, g, ph)
{
	this->rooms = &ro;
	problem = prob;
	time_admit = ta;
	time_discharge = td;
	fee_charged = f;
	room_allot = room;
}
void Patient::set_problem(string p)
{
	problem=p;
}
void Patient::set_time_admit(string t)
{
	time_admit=t;
}
void Patient::set_time_discharge(string t)
{
	time_discharge=t;
}
void Patient::set_room_allot(int r)
{
	room_allot=r;
}
string Patient::get_problem()
{
	return problem;
}
string Patient::get_time_admit()
{
	return time_admit;
}
string Patient::get_time_discharge()
{
	return time_discharge;
}
int Patient::get_room_allot()
{
	return room_allot;
}
void Patient::add_patient()
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
}
void Patient::allot_room()
{
	cout<<"Enter Room Number"<<endl;
	cin>>room_allot;
}
int Patient::check_file_size()
{
	int count = 0;
	ifstream scan("Patients.txt");

	for (int i = 0; !scan.eof(); i++)
	{
		char *temp = new char[30];
		scan.getline(temp, 30);
		count++;
	}
	return count / 10;
	
}
void Patient::discharge_file_update(string *n, string *r, string *ag , string *g, string *ph, string *pro , string *taa, string *tdd, string *f, string *roo, int size,int skip)
{
	ofstream out("Patients.txt");

	for (int i = 0; i < size; i++)
	{
		if (i != skip)
		{

			out << n[i] << endl;
			out << r[i] << endl;
			out << ag[i] << endl;
			out << g[i] << endl;
			out << ph[i] << endl;
			out << pro[i] << endl;
			out << taa[i] << endl;
			out << tdd[i] << endl;
			out << f[i] << endl;
			out << roo[i] << endl;
		}
	}
}
void Patient::discharge_patient()
{
	int size = 0;
	size=check_file_size();
	string *temp_name = new string[size];
	string *temp_res = new string[size];
	string *temp_age = new string[size];
	string *temp_gender = new string[size];
	string *temp_con = new string[size];
	string *temp_prob = new string[size];
	string *temp_ta = new string[size];
	string *temp_td = new string[size];
	string *temp_fee = new string[size];
	string *temp_room = new string[size];

	ifstream input("Patients.txt");

	for (int i = 0; i < size; i++)
	{
		getline(input, temp_name[i]);
		getline(input, temp_res[i]);
		getline(input, temp_age[i]);
		getline(input, temp_gender[i]);
		getline(input, temp_con[i]);
		getline(input, temp_prob[i]);
		getline(input, temp_ta[i]);
		getline(input, temp_td[i]);
		getline(input, temp_fee[i]);
		getline(input, temp_room[i]);
	}
	cout << "Discharge Patient by: " << endl;
	cout << "1) name " << endl << "2) Residence " << endl;
	int choice = 0;
	cin >> choice;
	int index = 0;
	if (choice == 1) // by name
	{
		int check = 0;
		cout << "Enter name: " << endl;
		cin.ignore();
		string dis_name;
		getline(cin, dis_name);
		for (int i = 0; i < size; i++)
		{
			if (dis_name == temp_name[i])
			{
				index = i;
				cout << "\t\t\t\t\t************************" << endl;
				cout << "\t\t\t\t\t  Patient Discharged" << endl;
				cout << "\t\t\t\t\t************************" << endl;
				check++;
				int a = std::stoi(temp_room[index]);
				this->rooms->set_free_r(a);
				discharge_file_update(temp_name, temp_res, temp_age, temp_gender, temp_con, temp_prob, temp_ta, temp_td, temp_fee, temp_room, size,index);
				break;
				
			}
		}
		if (check == 0)
		{
			cout << "\t\t\t\t\t************************" << endl;
			cout << "\t\t\t\t\t  Patient NOT FOUND" << endl;
			cout << "\t\t\t\t\t************************" << endl;
		}

	}
	else if (choice == 2) // by residence
	{
		int check = 0;
		cout << "Enter Residence: " << endl;
		cin.ignore();
		string re;
		getline(cin, re);
		for (int i = 0; i < size; i++)
		{
			if (re == temp_res[i])
			{
				index = i;
				cout << "\t\t\t\t\t************************" << endl;
				cout << "\t\t\t\t\t  Patient Discharged" << endl;
				cout << "\t\t\t\t\t************************" << endl;
				check++;
				int a = std::stoi(temp_room[index]);
				this->rooms->set_free_r(a);
				discharge_file_update(temp_name, temp_res, temp_age, temp_gender, temp_con, temp_prob, temp_ta, temp_td, temp_fee, temp_room, size, index);
				break;

			}
		}
		if (check == 0)
		{
			cout << "\t\t\t\t\t************************" << endl;
			cout << "\t\t\t\t\t  Patient NOT FOUND" << endl;
			cout << "\t\t\t\t\t************************" << endl;
		}
	}
}
int Patient::find_length(char *arr)
{
	int len = 0;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		len++;
	}
	return len;
}
void Patient::set_room_obj(Room& object)
{
	this->rooms = &object;
}
void Patient::display_rooms()
{
	this->rooms->display_rooms();
}
int Patient::compare(char *to_find,char *to_find_in,int size)
{
	for (int i = 0; to_find_in[i] != '\0'; i++)
	{
		if (to_find[0] == to_find_in[i])
		{
			int index = i;
			int count = 0;
			for (int j = 0; to_find[j] != '\0'; j++)
			{
				if (to_find[j] == to_find_in[index])
				{
					count++;
					index++;
				}
			}
			if (count == size)
			{
				return 1;
			}

		}
	}
	return 0;
}
void Patient::search_patient()
{
	int choose=0;
	cout<<"In which field you want to search? "<<endl;
	cout<<"1. Name"<<endl;
	cout<<"2. residence" << endl;
	cout<<endl<<"Enter "<<endl;
	cin >> choose;
	ifstream pscan("Patients.txt");

	if (choose==1)// by name
	{
		int flag = 0;
		char* name = new char[30];
		cout << "Enter Name: ";
		cin.ignore();
		cin.getline(name, 30);
     	int size=find_length(name);
		
		int count = 0;
		for (int i = 0; !pscan.eof(); i++)
		{

			char *temp = new char[100];
			pscan.getline(temp, 100);
			if (count == 0)
			{

				flag = compare(name, temp, size);
				if (flag > 0)
				{
					cout << "Data You Searched: " << endl;
					cout << "Name\t Residences\t    age\t  gender\tConatact  disease    Time in\tTime out  Fee\t  Room No " << endl;
					cout << "*******************************************************************************************************************" << endl;
					cout << temp << "     ";
					int print = 9;
					for (int j = 0; j < print; j++)
					{
						char *p = new char[50];
						pscan.getline(p, 50);
						cout << p << "     ";
					}
					break;
				}
			}
			count++;
			if (count == 10){
				count = 0;
			}

		}
		if (flag == 0)
		{
			cout << "NOT FOUND!" << endl;
		}
	}
	else if (choose==2) // by residence
	{
		int flag = 0;
		
		char* res = new char[30];
		cout << "Enter Residence: ";
		cin.ignore();
		cin.getline(res, 30);
		int size = find_length(res);

		int count = 0;
		for (int i = 0; !pscan.eof(); i++)
		{
			char* name = new char[30];
			char *temp = new char[100];
			pscan.getline(name, 30);
			pscan.getline(temp, 100);
			if (count == 0)
			{

				flag = compare(res, temp, size);
				if (flag > 0)
				{
					cout << "Data You Searched: " << endl;
					cout << name << endl;
					cout << temp << endl;

					int print = 8;
					for (int j = 0; j < print; j++)
					{
						char *p = new char[50];
						pscan.getline(p, 50);
						cout << p << endl;
					}
					break;
				}
			}
			count++;
			if (count == 5)
			{
				count = 0;
			}

		}
		if (flag == 0)
		{
			cout << "NOT FOUND!" << endl;
		}
	}
	
	
}
void  Patient::display()
{
	cout << "Disease: " << problem<<endl;
	cout << "Time of Admit: " << time_admit << endl;
	cout << "Time of Discharge: " << time_discharge << endl;
	cout << "Fee Charged: " << fee_charged << endl;
	cout << "Room Alloted: " << room_allot << endl;
	Person::display();
}
void Patient::display_all_patients()
{
	ifstream pin("Patients.txt");

	int count = 0;
	cout << "Name\tResidence\tage\tgender\tConatact\tdisease\tTime in\tTime out\tFee\tRoom No " << endl;
	for (int i = 0; !pin.eof(); i++)
	{
		char* data = new char[50];
		pin.getline(data, 50);
		count++;
		cout << data <<"     ";
		if (count == 10)
		{
			cout << endl;
			cout << "*******************************************************************************************************************" << endl;
			count = 0;
		}
	}
}

void Patient::update_patient_file(string prob, string ta, string td, double f, int room, char* p, char* r, int a, char g, string ph)
{
	ofstream docout("Patients.txt", ios::app);

	docout << p <<endl;
	docout << r << endl;
	docout << a << endl;
	docout << g << endl;
	docout << ph << endl;
	docout << prob << endl;
	docout << ta << endl;
	docout << td << endl;
	docout << f << endl;
	docout << room << endl;
	

	docout.close();
}
Patient::~Patient()
{
}