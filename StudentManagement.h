#ifndef STUDENTMANAGEMENTSYSTEM_H
#define STUDENTMANAGEMENTSYSTEM_H

#include "Student.h"
#include <vector>
#include <iostream>
#include <fstream>

class StudentManagementSystem {
private:
    vector<Student> students;

    void loadStudents();
    void saveStudents();

public:
    StudentManagementSystem();

    void addStudent();
    void displayStudents() const;
    void updateStudent(int id);
    void deleteStudent(int id);
};

#endif // STUDENTMANAGEMENTSYSTEM_H
