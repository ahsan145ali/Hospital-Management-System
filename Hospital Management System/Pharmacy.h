#pragma once

#include"Snacks.h"
#include "Medicine.h"

class Pharmacy
{
private:
	Medicine medicine;
	Snacks snacks;
	int choose;
	const int floor;
public:
	Pharmacy();
	Pharmacy(Medicine&,Snacks&,const int);
	friend istream& operator>>(istream&,Pharmacy&);
	friend ostream& operator<<(ostream&,Pharmacy&);
	~Pharmacy();
};

