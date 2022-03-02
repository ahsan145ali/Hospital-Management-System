#include "Pharmacy.h"

Pharmacy::Pharmacy():floor(2)
{
	choose = 0;
}
Pharmacy::Pharmacy(Medicine &m,Snacks &s,const int f):floor(f)
{
	medicine=m;
	snacks=s;
}
istream& operator>>(istream& is,Pharmacy& object)
{
again3:
	cout << endl << "\t\t\t\t\t_______________________________" << endl;
	cout<<"\t\t\t\t\t\t   option?"<<endl;
	cout<<"\t\t\t\t\t   1. Snacks"<<endl;
	cout<<"\t\t\t\t\t   2. Medicine"<<endl;
	cout<<"\t\t\t\t\t   3. Exit Pharmacy"<<endl;
	cout  << "\t\t\t\t\t_______________________________" << endl;
	cin>>object.choose;
	if (object.choose <= 0 || object.choose > 3 || !cin)
	{
		cout <<endl<< "*Invalid entry*" << endl;
		cin.clear();
		cin.ignore();
		goto again3;
	}
	// loop deleted for(int i=0;object.choose!=3;i++)
		if (object.choose == 1)
		{
			system("pause");
			system("cls");
			is>>object.snacks;
			return is;
		}
		if (object.choose == 2)
		{
			system("pause");
			system("cls");
			is>>object.medicine;
			return is;
		}
}
ostream& operator<<(ostream& os,Pharmacy& object)
{
	if (object.choose == 1)
	{

		os << object.snacks;
		return os;
	}
	else if (object.choose == 2)
	{

		os << object.medicine;
		return os;
	}
	
}
Pharmacy::~Pharmacy()
{
}