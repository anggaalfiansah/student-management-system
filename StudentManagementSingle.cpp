#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Class Student
class Student {
public:
    int id;
    string name;
    int age;
    string address;
    string hobby;

    Student(int id, const string& name, int age, const string& address, const string& hobby)
        : id(id), name(name), age(age), address(address), hobby(hobby) {}
};

// Class StudentManagementSystem
class StudentManagementSystem {
private:
    vector<Student> students;

    void loadStudents();
    void saveStudents();
    bool isIdUnique(int id);

public:
    StudentManagementSystem();
    void addStudent();
    void displayStudents() const;
    void updateStudent(int id);
    void deleteStudent(int id);
};

// Implementation
StudentManagementSystem::StudentManagementSystem() {
    loadStudents();
}

void StudentManagementSystem::loadStudents() {
    ifstream file("students.txt");
    if (!file) {
        cout << "File 'students.txt' tidak ditemukan. Membuat file baru." << endl;
        ofstream newFile("students.txt");
        newFile.close();
        return;
    }

    int id, age;
    string name, address, hobby, temp;
    while (getline(file, temp, ';')) {
        id = stoi(temp);
        getline(file, name, ';');
        getline(file, temp, ';');
        age = stoi(temp);
        getline(file, address, ';');
        getline(file, hobby);
        students.push_back(Student(id, name, age, address, hobby));
    }

    file.close();
}

void StudentManagementSystem::saveStudents() {
    ofstream file("students.txt");
    if (file.is_open()) {
        for (const auto& student : students) {
            file << student.id << ";" << student.name << ";" << student.age << ";"
                 << student.address << ";" << student.hobby << "\n";
        }
        file.close();
    } else {
        cout << "Unable to open file to save data." << endl;
    }
}

bool StudentManagementSystem::isIdUnique(int id) {
    for (const auto& student : students) {
        if (student.id == id) {
            return false;
        }
    }
    return true;
}

void StudentManagementSystem::addStudent() {
    int id, age;
    string name, address, hobby;

    while (true) {
        cout << "Enter ID: ";
        cin >> id;
        if (cin.fail() || !isIdUnique(id)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ID tidak valid atau sudah digunakan. Masukkan ID lain.\n";
        } else {
            break;
        }
    }

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);

    while (true) {
        cout << "Enter Age: ";
        cin >> age;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Masukkan angka.\n";
        } else {
            break;
        }
    }

    cout << "Enter Address: ";
    cin.ignore();
    getline(cin, address);

    cout << "Enter Hobby: ";
    getline(cin, hobby);

    students.push_back(Student(id, name, age, address, hobby));
    saveStudents();
    cout << "Student added successfully!" << endl;
}

void StudentManagementSystem::displayStudents() const {
    if (students.empty()) {
        cout << "No students found." << endl;
        return;
    }

    cout << "List of Students:\n";
    for (const auto& student : students) {
        cout << "ID: " << student.id
             << " | Name: " << student.name
             << " | Age: " << student.age
             << " | Address: " << student.address
             << " | Hobby: " << student.hobby << endl;
    }
}

void StudentManagementSystem::updateStudent(int id) {
    for (auto& student : students) {
        if (student.id == id) {
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, student.name);

            cout << "Enter New Age: ";
            cin >> student.age;

            cout << "Enter New Address: ";
            cin.ignore();
            getline(cin, student.address);

            cout << "Enter New Hobby: ";
            getline(cin, student.hobby);

            saveStudents();
            cout << "Student updated successfully!" << endl;
            return;
        }
    }

    cout << "Student with ID " << id << " not found." << endl;
}

void StudentManagementSystem::deleteStudent(int id) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            saveStudents();
            cout << "Student deleted successfully!" << endl;
            return;
        }
    }

    cout << "Student with ID " << id << " not found." << endl;
}

// Main Program
int main() {
    StudentManagementSystem sms;
    int choice;

    while (true) {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            sms.addStudent();
            break;
        case 2:
            sms.displayStudents();
            break;
        case 3: {
            int id;
            cout << "Enter ID to update: ";
            cin >> id;
            sms.updateStudent(id);
            break;
        }
        case 4: {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;
            sms.deleteStudent(id);
            break;
        }
        case 5:
            cout << "Exiting program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
}
