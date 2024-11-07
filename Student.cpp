#include "Student.h"

// Konstruktor yang benar
Student::Student(int id, const string& name, int age, const string& address, const string& hobi)
    : id(id), name(name), age(age), address(address), hobi(hobi) {}
