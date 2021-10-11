#ifndef H_STUDENT
#define H_STUDENT
#include <string>
#include <iostream>
using namespace std;

class Student{
	private:
		int id;
		string name;
		string dorm;

	public:
		Student(int, string, string);
		int getID() const;
		string getName() const;
		string getDorm() const;
		void print();
};
#endif