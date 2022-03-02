#include "Medicine.h"
#include"Account.h"
Medicine::Medicine()
{
}
istream& operator>>(istream& is ,Medicine& object)
{

	Account ac;
	object.display_file_medicine();
	cout << endl << "Current Hospital Balance: " << ac.amount << endl << endl;
chosoe_medicine:
	cout <<endl<< "Enter Medicinde to Buy: " << endl;
	is>>object.medicine_type;

	ifstream mread("MEDICINES.txt");
	int check = 0;
	string quan;
	string price;
	for (int i = 0; !mread.eof(); i++)
	{
		string m, c, q, p;
		mread >> m;
		mread >> c;
		mread >> q;
		mread >> p;
		if (object.medicine_type == m)
		{
			check++;
			price = p;
			quan = q;
			break;
		}
	}
	if (check == 0)
	{
		cout << endl << "\t\t\t\t**********************************************" << endl;
		cout << "\t\t\t\t    Medicine Not Found, Please Enter Again" << endl;
		cout << endl << "\t\t\t\t**********************************************" << endl;
		goto chosoe_medicine;
	}
	else
	{

		int quantity = std::stoi(quan);
		int buy;
		again5:
		cout << "How Many you Want to Buy: ";
		cin >> buy;
		if (buy<0 || !cin)
		{
			cout << "INVALID ENTRY!" << endl;
			cin.clear();
			cin.ignore();
			goto again5;
		}
		if (buy > quantity)
		{
			cout << "quantity Not Available, Choose Again" << endl << endl;
			goto chosoe_medicine;
		}
		else
		{
			int a = std::stoi(price);
			if (ac.amount <= 0 || ac.amount - (buy*a)<0)
			{
				cout << "\t\t\t\tPurchase Cannoyt be Made" << endl;
				cout << "\t\t\t\tInsufficient Balance" << endl;
				cout << "\t\t\t\tExiting Pharmacy" << endl << endl;

				return is;
			}
			else
			{
				cout << endl << "\t\t\t\t   ************************************" << endl;
				cout << "\t\t\t\t\t Purchase Successful  " << endl;
				cout << "\t\t\t\t\t You Bought " << object.medicine_type << endl;
				cout <<  "\t\t\t\t   ************************************" << endl;
				ac.amount = ac.amount - (buy*a);
			}
		}
		cout << endl << "Hospital Balance Available : " << ac.amount << endl;
	}
	
	return is;
}
ostream& operator<<(ostream& os,Medicine& object)
{
	os << "Going To Lobby" << endl;
	return os;
}
void Medicine::create_file_medicine()
{
	ofstream mout("MEDICINES.txt");

	mout << "Medicines\t\tCure\t\tQuantity\t\tPrice";
	mout << endl;
	mout << "Promethazine\t\t Allergy\t\t 25\t\t 60";
	mout << endl;
	mout << "Methadone\t\t Pain \t\t 19\t\t 75";
	mout << endl;
	mout << "Acefyl\t\t\t Cough \t\t 23\t\t 45";
	mout << endl;
	mout << "Midazolam\t\t Anxiety \t\t 12\t\t 112";
	mout << endl;
	mout << "Trazodone\t\t Depression \t 14\t\t 152";
	mout << endl;
	mout << "Phenytoin\t\t Seizures \t\t 7\t\t 250";
	mout << endl;
	mout << "Actos\t\t\t Diabetes \t\t  33\t\t 220";
	mout << endl;
	mout << "Disprin\t\t\t HeadAche \t 50\t\t 20";
	mout << endl;
	mout << "Flagyl\t\t\t StomachAche \t 45\t\t 70";


	
}
void Medicine::display_file_medicine()
{

	ifstream min("MEDICINES.txt");
	string m, c, q,p;
	min >> m;
	min >> c;
	min >> q;
	min >> p;
	cout << endl << "\t\t\t" << "*************************************************************************" << endl;
	cout << "\t\t\t\t" << m << "\t\t" << c << "\t\t" << q << "\t" << p << endl;
	cout << endl << "\t\t\t" << "*************************************************************************" << endl;
	for (int i = 0; !min.eof(); i++)
	{
		min >> m;
		min >> c;
		min >> q;
		min >> p;
		cout << endl;
		int a = m.length();
		int a2 = c.length();
		if (a < 8)
		{
			if (a2 < 8)
			{

				cout << "\t\t\t\t" << m << "\t\t\t" << c << "\t\t" << q << "\t\t" << p;
			}
			else if (a2>7)
			{
				cout << "\t\t\t\t" << m << "\t\t\t" << c << "\t" << q << "\t\t" << p;
			}
		}
		else
		{
			if (a2 < 8)
			{
				cout << "\t\t\t\t" << m << "\t\t" << c << "\t\t" << q << "\t\t" << p;
			}
			else if (a2>7)
			{
				cout << "\t\t\t\t" << m << "\t\t" << c << "\t" << q << "\t\t" << p;
			}
		}
	}
	cout << endl << "\t\t\t" << "*************************************************************************" << endl;
}
Medicine::~Medicine()
{
}