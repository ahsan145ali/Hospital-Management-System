#pragma once

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Room
{
private:
	int **room_arr;
	const int total_rooms;
	int free_r;
	string room_type;
public:
	Room();
	friend istream& operator>>(istream&,Room&);
	friend ostream& operator<<(ostream&,Room&);
	void display_rooms();
	void set_free_r(int );
	void free_room();
	int checK_room_avail(int);
	~Room();
};

