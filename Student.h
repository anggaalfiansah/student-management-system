#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
public:
	int id;
	string name;
	int age;
	string address;
	string hobi;

	// Constructor
	Student(int id, const string& name, int age, const string& address, const string& hobi);

	// Optional: Add getter and setter methods if needed
};

#endif // STUDENT_H
