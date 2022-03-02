#include "Account.h"
#include<iostream>
#include<fstream>
#include<string>
#include <stdlib.h> 
#include<time.h>
#include<conio.h>
using namespace std;

double Account::amount = 1000;

Account::Account()
{
	
}
void Account:: disp()
{
	cout << "\t\t\t********************************************************************" << endl;
	cout << "\t\t\t* ************************************************************** * *" << endl;
	cout << "\t\t\t* * ********************************************************** * * *" << endl;
	cout << "\t\t\t* * *                                                          * * *" << endl;
	cout << "\t\t\t* * *                          WELCOME                         * * *" << endl;
	cout << "\t\t\t* * *                                                          * * *" << endl;
	cout << "\t\t\t* * *                        LOGIN PANNEL                      * * *" << endl;
	cout << "\t\t\t* * *                                                          * * *" << endl;
	cout << "\t\t\t* * *                      signup  /  signin                   * * *" << endl;
	cout << "\t\t\t* * *                                                          * * *" << endl;
	cout << "\t\t\t* * ********************************************************** * * *" << endl;
	cout << "\t\t\t* ************************************************************** * *" << endl;
	cout << "\t\t\t********************************************************************" << endl;
}
void Account::set_hospital(Hospital& obj)
{
	this->hos = &obj;

}
void Account::hospital_dis()
{
	this->hos->hospital_dis();
}

void Account:: create_acc_disp()
{
	cout << "\t\t\t********************************************************************" << endl;
	cout << "\t\t\t* ************************************************************** * *" << endl;
	cout << "\t\t\t* * ********************************************************** * * *" << endl;
	cout << "\t\t\t* * *                                                          * * *" << endl;
	cout << "\t\t\t* * *                    CREATE AN ACCOUNT                     * * *" << endl;
	cout << "\t\t\t* * *                                                          * * *" << endl;
	cout << "\t\t\t* * ********************************************************** * * *" << endl;
	cout << "\t\t\t* ************************************************************** * *" << endl;
	cout << "\t\t\t********************************************************************" << endl;
}

void Account::sign_in_disp()
{
	cout << "\t\t\t********************************************************************" << endl;
	cout << "\t\t\t* ************************************************************** * *" << endl;
	cout << "\t\t\t* * ********************************************************** * * *" << endl;
	cout << "\t\t\t* * *                                                          * * *" << endl;
	cout << "\t\t\t* * *                          SIGN IN                         * * *" << endl;
	cout << "\t\t\t* * *                                                          * * *" << endl;
	cout << "\t\t\t* * ********************************************************** * * *" << endl;
	cout << "\t\t\t* ************************************************************** * *" << endl;
	cout << "\t\t\t********************************************************************" << endl;
}
int Account::check_repeat_username(string namee)
{
	ifstream scan("usernames.txt");

	int check = 0;
	
	for (int i = 0; !scan.eof(); i++)
	{
		string n;
		getline(scan, n);
		if (n == namee)
		{
			check++;
			break;
		}
	}
	if (check == 1)
	{
		return 1;
	}
	else
	return 0;
	
	

}

void Account::sign_up()
{
	
	create_acc_disp();
	//username
	ofstream scan("usernames.txt", ios::app);
	scan.close();
	ofstream scan1("passwords.txt", ios::app);
	scan1.close();
	
	string namee;
	cin.ignore();
	enter_u:
	cout << "Enter Username: " << endl;
	 getline(cin,namee);
	 
	 int x = check_repeat_username(namee);
	 
	 if ( x==1)
	 {
		 cout << "\t\t\t\t\t********************************" << endl;
		 cout << "\t\t\t\t\t  Username Taken, Enter Again" << endl;
		 cout << "\t\t\t\t\t********************************" << endl;
		 goto enter_u;
	 }
	

pass_enter:
	cout << "Enter Password" << endl;
	string pass = "";
	string pass2 = "";

	char ch;
	ch = _getch();
	while (ch != 13) //character 13 is enter
	{
		pass.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	cout << endl << "Confirm Password" << endl;

	char ch2;
	ch2 = _getch();
	while (ch2 != 13) //character 13 is enter
	{
		pass2.push_back(ch2);
		cout << '*';
		ch2 = _getch();
	}

	if (pass2 == pass)
	{
		cout << endl;
		cout << "\t\t\t\t\t ***********************" << endl;
		cout << "\t\t\t\t\t *  Account Created!   *" << endl;
		cout << "\t\t\t\t\t * Now You Can Sign In *" << endl;
		cout << "\t\t\t\t\t ***********************" << endl;
		ofstream fname("usernames.txt", ios::app);
		ofstream fpass("passwords.txt", ios::app);

		fname << namee;
		fname << endl;
		fpass << pass;
		fpass << endl;

		fname.close();
		fpass.close();

		system("pause");
		system("cls");
	}
	else
	{

		cout << "Passwords Do not Match! Enter again" << endl;
		goto pass_enter;
	}

}
int Account:: sign_in()
{
	cin.ignore();
username_again:
	ifstream readN("usernames.txt");
	if (!readN.is_open())
	{
		cout << "\t\t\t\t\tYou Need to Sign Up First!" << endl;
		system("pause");
		system("cls");
		return 0;

	}
	ifstream readP("passwords.txt");
	
	string pass;


	int check = 0;
	cout << "Enter User Name: " << endl;
	
	getline( cin,this->name);
	for (int i = 0; !readN.eof(); i++)
	{
		string n, p;
		getline(readN,n);
	
		getline(readP,p);
		if (n == this->name)
		{
			check++;
			pass = p;
			break;
		}
	}
	if (check == 0)
	{
		cout << endl<<"\t\t\t\t\t**********************"<<endl;
		cout << "\t\t\t\t\t User Name Not Found!" << endl;
		cout << "\t\t\t\t\t**********************" << endl;
		goto username_again;
	}
	else
	{
	pass_again:
		cout << endl << "Enter Password: " << endl;
		string p;
		char ch2;
		ch2 = _getch();
		while (ch2 != 13) //character 13 is enter
		{
			p.push_back(ch2);
			cout << '*';
			ch2 = _getch();
		}
		if (p == pass)
		{
			cout << endl << "\t\t\t\t\t**************************" << endl;
			cout <<"\t\t\t\t\t  Logged In Successfully   " << endl;
			cout <<  "\t\t\t\t\t**************************" << endl;
		}
		else
		{
			cout<<endl << "Wrong Password" << endl;
			cout << "\t\t\t 1) Enter Again  2) Forgot Password" << endl;
			int c = 0;
			cin >> c;

			if (c == 1)
			{
				goto pass_again;
			}
			else
			{
				system("pause");
				system("cls");
				forgot_password();
				
				 return 0;
				
			}
			

		}
	}

	system("pause");
	system("cls");
	return 1;

}
int Account::forgot_password()
{
	ofstream fpass("Reset_Password.txt");

	srand(time(0));
	for (int i = 0; i < 5; i++)
	{
		int a=0;
		a = rand()%10+1;
		fpass << a;
	}
	fpass << endl;
	cout <<endl<< "Enter Your Code from Reset Password File " << endl;
	cout << "Code: ";
	ifstream rpass("Reset_Password.txt");
	string check_code;
	rpass >> check_code;

	enter_code_again:
	string code;
	cin >> code;

	if (check_code == code)
	{
		cout<<endl << "  Code Mactched!" << endl;
		cout << "  Change Your Password" << endl;
		change_password();
		return 0;

	}
	else
	{
		cout<<endl<< "  Code Not Matched!" << endl;
		cout << "  Enter Again" << endl;
		goto enter_code_again;
	}
	


}
int Account::change_password()
{
	ifstream cname("usernames.txt");
	ifstream cpass("passwords.txt");
	int size = 0;
	cin.ignore();
	for (int i = 0; !cname.eof(); i++)
	{
		string temp;
		getline(cname,temp);
		size++;

	}
	size = size - 1;
	/*string *temp_name = new string[size];
	string *temp_pass = new string[size];*/
	string temp_name[100];
	string temp_pass[100];
	cname.close();
	cname.open("usernames.txt");
	for (int i = 0; i<size; i++)
	{
		string temp;
		string temp2;
		getline(cname, temp);
		getline(cpass, temp2);

		temp_name[i] = temp;
		temp_pass[i] = temp2;

	}

	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (name == temp_name[i])
		{
			index = i;
			break;
		}
	}

	cout << endl << endl;
	

pass_enter2:
	cout << "Enter New Password" << endl;
	string pass = "";
	string pass2 = "";

	char ch;
	ch = _getch();
	while (ch != 13) //character 13 is enter
	{
		pass.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	cout << endl << "Confirm Password" << endl;

	char ch2;
	ch2 = _getch();
	while (ch2 != 13) //character 13 is enter
	{
		pass2.push_back(ch2);
		cout << '*';
		ch2 = _getch();
	}

	if (pass2 == pass)
	{
		cout << endl<<"Password Changed Successfully" << endl;
		temp_pass[index] = pass;
		ofstream wpass("passwords.txt");

		for (int i = 0; i < size; i++)
		{
			wpass << temp_pass[i];
			wpass << endl;
		}
		wpass.close();
			system("pause");
	system("cls");
		return 0;
	}
	else
	{
		cout <<endl<<"Wrong Password,Enter Again" << endl;
		goto pass_enter2;
	}

}
Account::~Account()
{
}
