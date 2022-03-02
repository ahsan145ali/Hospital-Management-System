#include "Worker.h"
#include <fstream>

Worker::Worker()
{
}
Worker::Worker(string ty, string t, double in, char* p, char* r, int a, char g, string ph) :Staff(t,in,p,r,a,g,ph)
{
	worker_type = ty;
}
void Worker::set_worker_type(string w)
{
	worker_type=w;
}
//void Worker::set_worker_place(string w)
//{
//	worker_place=w;
//}

void Worker::display()
{
	cout << "Worker Type: " << worker_type << endl;
	Staff::display();

}
string Worker::get_worker_type()
{
	return worker_type;
}
//string Worker:: get_worker_place()
//{
//	return worker_place;
//}
void Worker::update_Worker(string ty, string t, double in, char* p, char* r, int a, char g, string ph)
{

	ofstream docout("Staff.txt", ios::app);

	docout << p << endl;
	docout << r << endl;
	docout << a << endl;
	docout << g << endl;
	docout << ph << endl;
	docout << t << endl;
	docout << in << endl;
	docout << ty << endl;



	docout.close();
}
Worker::~Worker()
{
}