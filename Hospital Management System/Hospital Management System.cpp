#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include"Account.h"
#include"Hospital.h"
#include"Person.h"
#include"Surgeon.h"
#include"Gynecologist.h"
#include"Child_Specialist.h"
#include"Patient.h"
#include"Worker.h"
#include"Staff.h"
#include"Receptionist.h"
using namespace std;



void create_doctor_surgeon_file()
{
	ofstream docout("Doctors.txt");

	docout << "Tom han  ";
	docout << "123 block 3  ";
	docout << "43  ";
	docout << "M  ";
	docout << "0333-12312312  ";
	docout << "11:22-12:00  ";
	docout << "7  ";
	docout << "12300  ";
	docout << "General Surgeon  ";
	docout << endl;

	docout << "miley han  ";
	docout << "345 block 3  ";
	docout << "33  ";
	docout << "F  ";
	docout << "0333-7898878  ";
	docout << "1:22-5:00  ";
	docout << "9 ";
	docout << "1000  ";
	docout << "Lady Surgeon  ";
	docout << endl;
}
void create_staff_file()
{
	ofstream pout("Staff.txt");

	pout << "Tom han" << endl;
	pout << "123 block 3"<<endl;
	pout << "43"<<endl;
	pout << "M"<<endl;
	pout << "0333-12312312" << endl;
	pout << "11:00-1:00"<<endl;
	pout << "500"<<endl;
	pout << "sweeper"<<endl;


	pout << "billy han" << endl;
	pout << "231 block 31" << endl;
	pout << "33" << endl;
	pout << "M" << endl;
	pout << "0334-112803992" << endl;
	pout << "2:00=5:00" << endl;
	pout << "800" << endl;
	pout << "driver" << endl;
	
}

void update_doctor_file(char *type, string time /*(string)*/, int cab, double f/*fees (double)*/, char* name, char* res, int ag/*age (int)*/, char g, string con /*(string)*/)
{
	ofstream docout("Doctors.txt",ios::app);

	docout << name<<"  "  ;
	docout << res<<"  ";
	docout << ag<<"  ";
	docout << g<<"  ";
	docout << con<<"  ";
	docout << time<<"  ";
	docout << cab<<"  ";
	docout << f<<"  ";
	docout << type<<"  ";
	docout << endl;

	docout.close();

}
void display_all_doctors()
{
	ifstream docin("Doctors.txt");
	cout << "Name\tResidence    age gender\tConatact    timmings\tcabin\tfee\ttype" << endl;
	for (int i = 0; !docin.eof(); i++)
	{
		char* data = new char[200];
		docin.getline(data,200);
		cout << data << endl;
		cout << "***********************************************************************************" << endl;
	}
}

void create_Patient()
{
	ofstream pout("Patients.txt");

	pout << "Tom han" << endl;
	pout << "123 block 3"<<endl;
	pout << "43"<<endl;
	pout << "M"<<endl;
	pout << "0333-12312312" << endl;
	pout << "cough"<<endl;
	pout << "12:00"<<endl;
	pout << "2:00"<<endl;
	pout <<  "1200"<<endl;
	pout << "1"<<endl;

	pout << "billy han" << endl;
	pout << "231 block 31" << endl;
	pout << "33" << endl;
	pout << "M" << endl;
	pout << "0334-112803992" << endl;
	pout << "flu" << endl;
	pout << "8:00" << endl;
	pout << "1:00" << endl;
	pout << "1600" << endl;
	pout << "2" << endl;
	

}

int main()
{



	Account Acc;
	Acc.disp();

	create_doctor_surgeon_file();
	create_Patient();
	create_staff_file();


	int log = 0;

	while (log == 0)
	{
		cout << endl << "\t\t\t\t\t    1)SIGN UP          2)SIGN IN" << endl;
		int choice = 0;

		again1:
		cout << "Enter Choice: " << endl;
		cin >> choice;
		if (choice<0 || choice>2 || !cin)
		{
			cout << "INVALID ENTRY!" << endl;
			cin.clear();
			cin.ignore();
			goto again1;
		}

		system("pause");
		system("cls");
		if (choice == 1)
		{
			Acc.sign_up();
			Acc.disp();
		}
		else if (choice == 2)
		{
			Acc.sign_in_disp();
			log = Acc.sign_in();
		}

	}

	Person per;
	Room room;
	Hospital hospital(per);
	Snacks snacks;
	Medicine medicine;
	medicine.create_file_medicine();
	snacks.create_snack_file();// creating file of snacks to select from

	Acc.set_hospital(hospital);
	Acc.hospital_dis();
	//hospital.hospital_dis();
	int choose = 0;
	cout << endl;
again2:
	cout << "Enter: ";
	cin >> choose;
	
	if (choose <= 0 || choose > 5 || !cin)
	{
		cout << "INAVLID ENTRY!" << endl;
		cin.clear();
		cin.ignore();

		goto again2;
	}
	for (int i = 0; choose != 6; i++)
	{
		if (choose == 1)
		{

			hospital.set_choose(choose);
			cin >> hospital;
			cout << hospital;
			system("pause");
			system("cls");
		}
		else if (choose == 2)
		{
			system("pause");
			system("cls");
			cout << "\t\t\t\t\t**********************" << endl;
			cout << "\t\t\t\t\t1) Add a Doctor" << endl;
			cout<< "\t\t\t\t\t2) View All Doctors " << endl;
			cout << "\t\t\t\t\t**********************" << endl;
			int ch = 0;
			cin >> ch;
			if (ch == 1)
			{
				cout <<"\t\t\t\t\t*******************" << endl;
				cout << "\t\t\t\t\t  Doctor Type?" << endl;
				cout << "\t\t\t\t\t1) Surgeon" << endl;
				cout << "\t\t\t\t\t2) Gynecologist" << endl;
				cout<< "\t\t\t\t\t3) Child Specialist" << endl;
				cout <<"\t\t\t\t\t*******************" << endl;
				int ch2 = 0;
				cin >> ch2;
				if (ch2 == 1)
				{

					system("pause");
					system("cls");
					char *type = new char[30];
					cout << endl;
					cout << "Enter Suregon Type: ";
					cin.ignore();
					cin.getline(type, 30);

					cout << "Enter Timmings (0:00-0:00): " << endl;
					string time;
					getline(cin,time);

					cout << "Enter Cabin Number: " << endl;
					int cab;
					enteragin10:
					cin >> cab;
					if (!cin)
					{
						cout << "Invalid Entry" << endl;
						cin.clear();
						cin.ignore();
						goto enteragin10;
					}


					cout << "Enter Fees Per Patient: " << endl;
					double f;
					enteragin11:
					cin >> f;
					if (!cin)
					{
						cout << "Invalid Entry" << endl;
						cin.clear();
						cin.ignore();
						goto enteragin11;
					}


					cin.ignore();
					char *name = new char[30];
					cout << "Enter Name: " << endl;
					cin.getline(name, 30);

					char *res = new char[30];
					cout << "Enter Residence: " << endl;
					cin.getline(res, 30);

					cout << "Enter age: " << endl;
					int ag;
					enteragin12:
					cin >> ag;
					if (!cin)
					{
						cout << "Invalid Entry" << endl;
						cin.clear();
						cin.ignore();
						goto enteragin12;
					}



					cout << "Enter Gender (M/F): " << endl;
					char g;
					cin >> g;

					cout << "Enter Contact Number: " << endl;
					string con;
					cin >> con;

					update_doctor_file(type, time /*(string)*/, cab, f/*fees (double)*/, name, res, ag/*age (int)*/, g, con /*(string)*/);
					Surgeon surgeon(type, time /*(string)*/, cab, f/*fees (double)*/, name, res, ag/*age (int)*/, g, con /*(string)*/);

					Hospital h(surgeon);

					h.set_class_person();

				}
				else if (ch2 == 2)
				{
					system("pause");
					system("cls");

					char *type = new char[30];
					cout << endl;
					cout << "Enter Specialized in: ";
					cin.ignore();
					cin.getline(type, 30);

					cout << "Enter Timmings (0:00-0:00): " << endl;
					string time;
					getline(cin, time);

					cout << "Enter Cabin Number: " << endl;
					int cab;
					enteragin13:
					cin >> cab;
					if (!cin)
					{
						cout << "Invalid Entry" << endl;
						cin.clear();
						cin.ignore();
						goto enteragin13;
					}

					cout << "Enter Fees Per Patient: " << endl;
					double f;
					enteragin14:
					cin >> f;
					if (!cin)
					{
						cout << "Invalid Entry" << endl;
						cin.clear();
						cin.ignore();
						goto enteragin14;
					}

					cin.ignore();
					char *name = new char[30];
					cout << "Enter Name: " << endl;
					cin.getline(name, 30);

					char *res = new char[30];
					cout << "Enter Residence: " << endl;
					cin.getline(res, 30);

					cout << "Enter age: " << endl;
					int ag;
					enteragin15:
					cin >> ag;
					if (!cin)
					{
						cout << "Invalid Entry" << endl;
						cin.clear();
						cin.ignore();
						goto enteragin15;
					}

					cout << "Enter Gender (M/F): " << endl;
					char g;
					cin >> g;

					cout << "Enter Contact Number: " << endl;
					string con;
					cin >> con;

					update_doctor_file(type, time /*(string)*/, cab, f/*fees (double)*/, name, res, ag/*age (int)*/, g, con /*(string)*/);
					Gynecologist gye(type, time /*(string)*/, cab, f/*fees (double)*/, name, res, ag/*age (int)*/, g, con /*(string)*/);
					Hospital h(gye);
					h.set_class_person_gye();


				}
				else if (ch2 == 3)
				{
					system("pause");
					system("cls");


					char *type = new char[30];
					cout << endl;
					cout << "Enter Pedriatic Type: ";
					cin.ignore();
					cin.getline(type, 30);

					cout << "Enter Timmings (0:00-0:00): " << endl;
					string time;
					getline(cin, time);

					cout << "Enter Cabin Number: " << endl;
					int cab;
					enteragin16:
					cin >> cab;
					if (!cin)
					{
						cout << "Invalid Entry" << endl;
						cin.clear();
						cin.ignore();
						goto enteragin16;
					}

					cout << "Enter Fees Per Patient: " << endl;
					double f;
					enteragin17:
					cin >> f;
					if (!cin)
					{
						cout << "Invalid Entry" << endl;
						cin.clear();
						cin.ignore();
						goto enteragin17;
					}


					cin.ignore();
					char *name = new char[30];
					cout << "Enter Name: " << endl;
					cin.getline(name, 30);

					char *res = new char[30];
					cout << "Enter Residence: " << endl;
					cin.getline(res, 30);

					cout << "Enter age: " << endl;
					int ag;
					enteragin18:
					cin >> ag;
					if (!cin)
					{
						cout << "Invalid Entry" << endl;
						cin.clear();
						cin.ignore();
						goto enteragin18;
					}

					cout << "Enter Gender (M/F): " << endl;
					char g;
					cin >> g;

					cout << "Enter Contact Number: " << endl;
					string con;
					cin >> con;

					update_doctor_file(type, time /*(string)*/, cab, f/*fees (double)*/, name, res, ag/*age (int)*/, g, con /*(string)*/);
					Child_Specialist CS(type, time /*(string)*/, cab, f/*fees (double)*/, name, res, ag/*age (int)*/, g, con /*(string)*/);
					Hospital h(CS);
					h.set_class_person_gye();

				}

			}
			else if (ch == 2)
			{
				display_all_doctors();
			}

			system("pause");
			system("cls");
		}
		else if (choose == 3)
		{

			system("pause");
			system("cls");
			cout << "1) Add a Patient" << endl << "2) View All Admitted Patients " << endl << "3) Search A Patient " << endl << "4) View Rooms" << endl << "5) Disharge Pateint" << endl;
			int ch = 0;
			cin >> ch;
			if (ch == 1)
			{

				cout << "Enter Disese: " << endl;
				string dis;
				cin >> dis;
				cout << "Enter time of admit: " << endl;
				string ta;
				cin >> ta;
				cout << "Enter time of discharge: " << endl;
				string td;
				cin >> td;
				cout << "Fees charged: " << endl;
				double charge;
				enter_again222:
				cin >> charge;
				if (!cin)
				{
					cout << "Invalid Entry" << endl;
					cin.clear();
					cin.ignore();
					goto enter_again222;
				}
				Acc.amount = Acc.amount + charge;
				//room number checck start
			enter_room:
				cout << "Enter Room to Allot: " << endl;
				int r;
				enteragin20:
				cin >> r;
				if (!cin)
				{
					cout << "Invalid Entry" << endl;
					cin.clear();
					cin.ignore();
					goto enteragin20;
				}
				int check = 0;

				check = room.checK_room_avail(r);

				if (check == 0)
				{
					cout << "Room taken Already,Choose another" << endl;
					goto enter_room;
				}
				//room number check end



				cin.ignore();
				char *name = new char[30];
				cout << "Enter Name: " << endl;
				cin.getline(name, 30);

				char *res = new char[30];
				cout << "Enter Residence: " << endl;
				cin.getline(res, 30);

				cout << "Enter age: " << endl;
				int ag;
			enter_again22:
				cin >> ag;
				if (!cin)
				{
					cout << "Invalid Entry" << endl;
					cin.clear();
					cin.ignore();
					goto enter_again22;
				}

				cout << "Enter Gender (M/F): " << endl;
				char g;
				cin >> g;

				cout << "Enter Contact Number: " << endl;
				string con;
				cin >> con;


				Patient patient(room, dis, ta, td, charge, r, name, res, ag, g, con);
				patient.update_patient_file(dis, ta, td, charge, r, name, res, ag, g, con);
				Hospital h(patient);
				h.set_class_Patient();



			}
			else if (ch == 2)
			{
				Patient p_dis;

				p_dis.display_all_patients();
			}
			else if (ch == 3)
			{
				Patient p_search;
				p_search.search_patient();
			}
			Patient p;
			p.set_room_obj(room);
			if (ch == 4)
			{

				p.display_rooms();
			}
			else if (ch == 5)
			{
				p.discharge_patient();
			}

			system("pause");
			system("cls");
		}
		else if (choose == 4)
		{
			cout << "\t\t\t\t\t************************" << endl;
			cout <<"\t\t\t\t\t1) Add Staff" << endl;
			cout<< "\t\t\t\t\t2) Display All Staff" << endl;
			cout << "\t\t\t\t\t************************" << endl;
			int choice;
			cout << "Enter: ";
			cin >> choice;

			if (choice == 1)
			{
				cout << "\t\t\t\t\t************************" << endl;
				cout << "\t\t\t\t\t1) Add Worker" << endl;
				cout << "\t\t\t\t\t2) Add Receptionaist" << endl;
				cout << "\t\t\t\t\t************************" << endl;
				cout << "Enter: ";
				int c;
				cin >> c;
				if (c == 1)
				{
					//cin.ignore();
					cout << "Enter Timmings(hh:mm-hh:mm): " << endl;
					string time;
					cin >> time;
					cout << "Enter Pay: " << endl;
					double p;
				enteragin0:
					cin >> p;
					if (!cin)
					{
						cout << "Invalid Entry" << endl;
						cin.clear();
						cin.ignore();
						goto enteragin0;
					}

					cin.ignore();
					cout << "Enter Position: " << endl;
					string work;
					getline(cin,work);
					//cin.ignore();
					char *name = new char[30];
					cout << "Enter Name: " << endl;
					cin.getline(name, 30);

					char *res = new char[30];
					cout << "Enter Residence: " << endl;
					cin.getline(res, 30);

					cout << "Enter age: " << endl;
					int ag;
					enteragin01:
					cin >> ag;
					if (!cin)
					{
						cout << "Invalid Entry" << endl;
						cin.clear();
						cin.ignore();
						goto enteragin01;
					}

					cout << "Enter Gender (M/F): " << endl;
					char g;
					cin >> g;

					cout << "Enter Contact Number: " << endl;
					string con;
					cin >> con;

					Worker worker(work, time, p, name, res, ag, g, con);
					Hospital h(worker);
					h.set_class_staff();
					worker.update_Worker(work, time, p, name, res, ag, g, con);

					system("pause");
					system("cls");
				}
				else if (c == 2) // receptionaist
				{
					//cin.ignore();
					cout << "Enter Timmings(hh:mm-hh:mm): " << endl;
					string time;
					cin >> time;
					cout << "Enter Pay: " << endl;
					double p;
					enteragin00:
					cin >> p;
					if (!cin)
					{
						cout << "Invalid Entry" << endl;
						cin.clear();
						cin.ignore();
						goto enteragin00;
					}
					cin.ignore();
					cout << "Enter Education: " << endl;
					string ed;
					getline(cin,ed);
					
					char *name = new char[30];
					cout << "Enter Name: " << endl;
					cin.getline(name, 30);

					char *res = new char[30];
					cout << "Enter Residence: " << endl;
					cin.getline(res, 30);

					cout << "Enter age: " << endl;
					int ag;
					enteragin001:
					cin >> ag;
					if (!cin)
					{
						cout << "Invalid Entry" << endl;
						cin.clear();
						cin.ignore();
						goto enteragin001;
					}

					cout << "Enter Gender (M/F): " << endl;
					char g;
					cin >> g;

					cout << "Enter Contact Number: " << endl;
					string con;
					cin >> con;

					Receptionist recep(ed, time, p, name, res, ag, g, con);
					Hospital h(recep);
					h.set_class_staff();
					recep.update_recep_file(ed, time, p, name, res, ag, g, con);

					system("pause");
					system("cls");
				}

			}
			else if (choice == 2)
			{
				Staff s;
				s.display_all_staff();
			}
			system("pause");
				system("cls");
		

		}
		else if (choose == 5)
		{
			cout << endl << "EXITING ADMIN PANEL" << endl << "THANK YOU!" << endl;
			break;

		}


		Acc.hospital_dis();
		cout << endl;
		cout << "Enter: ";
		cin >> choose;
	}
}