#include <iostream>
#include "studentManagement.h"

using namespace std;

int main() {
	StudentManagementSystem sms;
	int choice;
	int id;

	do {
		cout << "\n--- Student Management System ---\n";
		cout << "1. Add Student\n";
		cout << "2. Display Students\n";
		cout << "3. Update Student\n";
		cout << "4. Delete Student\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Input tidak valid. Harap masukkan angka yang benar.\n";
		}
		else {
			switch (choice) {
			case 1:
				sms.addStudent();
				break;
			case 2:
				sms.displayStudents();
				break;
			case 3:
				cout << "Enter ID of the student to update: ";
				cin >> id;
				sms.updateStudent(id);
				break;
			case 4:
				cout << "Enter ID of the student to delete: ";
				cin >> id;
				sms.deleteStudent(id);
				break;
			case 5:
				cout << "Exiting...\n";
				break;
			default:
				cout << "Invalid choice. Please try again.\n";
			}
		}
	} while (choice != 5);

	return 0;
}
