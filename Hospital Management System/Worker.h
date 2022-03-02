#pragma once

#include <iostream>
#include<string>
#include "Staff.h"
using namespace std;

class Worker:public Staff
{
private:
	string worker_type;
public:
	Worker();
	Worker(string, string, double, char*, char*, int, char, string);
	void set_worker_type(string);
	void set_worker_place(string);
	string get_worker_type();
	string get_worker_place();
	void display();
	void update_Worker(string, string, double, char*, char*, int, char, string);
	~Worker();
};