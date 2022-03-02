#include "Room.h"


Room::Room():total_rooms(10)
{
	 room_arr = new int*[10];
	for (int i = 0; i < 10; i++)
	{
		room_arr[i] = new int[10];
	}

	int c = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			room_arr[i][j] = c;
			c++;
		}
	}

	room_arr[0][0] = 0;
	room_arr[0][1] = 0;

	
}

void Room::free_room()
{
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		
		for (int j = 0; j < 10; j++)
		{
			count++;
			if (count == free_r)
			{
				room_arr[i][j] = free_r;
				break;
			}
			//cout << count << " ";
			
			
		}
		//cout << endl;
		
	}

}
void Room::set_free_r(int r)
{
	free_r = r;
	free_room();


}
istream& operator>>(istream& is ,Room& object)
{
	is>>object.room_type;
	return is;
}
ostream& operator<<(ostream& os,Room& object)
{
	os<<object.room_type;
	return os;
}

void Room::display_rooms()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << room_arr[i][j] << " ";
		}
		cout << endl;
	}
}
int Room::checK_room_avail(int input)
{
	int check = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (room_arr[i][j] == input)
			{
				room_arr[i][j] = 0;
				check++;
				break;
			}
		}
	}
	return check;
}
Room::~Room()
{
}