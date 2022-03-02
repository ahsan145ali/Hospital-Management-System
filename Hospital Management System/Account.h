#pragma once
#include<string>
#include"Hospital.h"
using namespace std;


class Account
{
private:
	string name;
	Hospital *hos;
public:
	static double amount;
	Account();
	void disp();
	void set_hospital(Hospital&);
	void create_acc_disp();
	void sign_up();
	int sign_in();
	int forgot_password();
	int change_password();
	void sign_in_disp();

	void hospital_dis();
	int check_repeat_username(string);
	~Account();
};

