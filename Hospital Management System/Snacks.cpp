#include "Snacks.h"
#include"Account.h"
#include <iostream>
#include <fstream>
Snacks::Snacks()
{
}
istream& operator>>(istream& is ,Snacks& object)
{
	Account ac;
	object.display_snack_file();// reading from file and displaying
	cout << endl;

	cout << endl<<"Current Hospital Balance: " << ac.amount << endl << endl;
chosoe_snack:
	
	cout << "Choose Your Snack: " << endl;
	is>>object.snack_type;
	cout << endl;
	string pr,quantity;
	ifstream sread("SNACKS.txt");
	int check = 0;
	
	for (int i = 0; !sread.eof(); i++)
	{
		string sn, q;
		string p;
		sread >> sn;
		sread >> q;
		sread >> p;
		if (object.snack_type == sn)
		{
			check++;
			pr = p;
			quantity = q;
			break;
		}
		
	}
	if (check == 0)
	{
		cout << endl << "\t\t\t\t**********************************************" << endl;
		cout << "\t\t\t\t    Snack Not Found, Please Enter Again" << endl;
		cout  << "\t\t\t\t**********************************************" << endl;
		goto chosoe_snack;
	}
	else
	{
		int quan = std::stoi(quantity);
		int buy;
		again4:
		cout << endl<< " How Many you Want to Buy: ";
		cin >> buy;
		if (buy<0 || !cin)
		{
			cout << "INVALID ENTRY!" << endl;
			cin.clear();
			cin.ignore();
			goto again4;
		}
		if (buy>quan)
		{
			cout << endl<<" quantity Not Available, Choose Again" << endl << endl;
			goto chosoe_snack;
		}
		else
		{
			int a = std::stoi(pr);
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
				cout << "\t\t\t\t\t You Bought " << object.snack_type << endl;
				cout <<  "\t\t\t\t   ************************************" << endl;
				ac.amount = ac.amount - (buy*a);
			}
		}
	}
	cout << endl << "Hospital Balance Available : " << ac.amount << endl;
	return is;
}
ostream& operator<<(ostream& os,Snacks& object)
{

	
	os << "Going To Lobby" << endl;
	return os;
}
void Snacks::create_snack_file()
{
		
	ofstream snackout("SNACKS.txt");

	snackout<<"SNACKS\t\tQuantity\tPrice";
	snackout<<endl;
	snackout<<"Lays\t\t 10\t\t 30";
	snackout<<endl;
	snackout<<"water\t\t 10\t\t 50";
	snackout<<endl;
	snackout<<"cola\t\t 10\t\t 80";
	snackout<<endl;
	snackout<<"biscuit\t\t 10\t\t 30";
	snackout<<endl;
	snackout<<"tea\t\t 10\t\t 100";
    snackout<< endl;
	snackout<<"juice\t\t 10\t\t 25";
	
	
}
void Snacks::display_snack_file()
{
	ifstream sin("SNACKS.txt");
	string s,q,p;
	sin>>s;
	sin>>q;
	sin>>p;
	cout << endl << "\t\t\t" << "*****************************************************" << endl;
	cout << "\t\t\t\t" << s << "\t\t" << q << "\t" << p;
	cout << endl << "\t\t\t" << "*****************************************************" << endl;
	for(int i=0;!sin.eof();i++)
	{
		sin>>s;
		sin>>q;
		sin>>p;
	 cout<<endl;
	 cout<<"\t\t\t\t"<<s<<"\t\t"<<q<<"\t\t"<<p;
	}
	cout << endl << "\t\t\t" << "*****************************************************" << endl;
}
Snacks::~Snacks()
{
}