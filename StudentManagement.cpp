#include "StudentManagement.h"

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

	Student s(0, "", 0, "", "");
	string temp;
	while (getline(file, temp, ';')) {
		s.id = stoi(temp);
		getline(file, s.name, ';');
		getline(file, temp, ';');
		s.age = stoi(temp);
		getline(file, s.address, ';');
		getline(file, s.hobi);
		students.push_back(s);
	}

	file.close();
}


void StudentManagementSystem::saveStudents() {
	ofstream file("students.txt");
	if (file.is_open()) {
		for (const auto& student : students) {
			file << student.id << ";" << student.name << ";"
				<< student.age << ";" << student.address << ";" << student.hobi << "\n";
		}
		file.close();
	}
	else {
		cout << "Unable to open file to save data." << endl;
	}
}

void StudentManagementSystem::addStudent() {
	int id, age;
	string name, address, hobi;
	/* Input ID */
	while (true) {
		cout << "Enter ID: ";
		cin >> id;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Input tidak valid. Harap masukkan angka yang benar.\n";
		}
		else {
			bool isDuplicate = false;
			for (const auto& student : students) {
				if (student.id == id) {
					isDuplicate = true;
					break;
				}
			}

			if (isDuplicate) {
				cout << "ID sudah terdaftar. Harap masukkan ID yang berbeda.\n";
			}
			else {
				break;
			}
		}
	}
	/* Input Nama */
	cout << "Enter Name: ";
	cin.ignore();
	getline(cin, name);
	/* Input Usia */
	while (true) {
		cout << "Enter Age: ";
		cin >> age;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Input tidak valid. Harap masukkan angka yang benar.\n";
		}
		else {
			break;
		}
	}
	/* Input Alamat */
	cout << "Enter Address: ";
	cin.ignore();
	getline(cin, address);
	/* Input Hobi */
	cout << "Enter Hobi: ";
	cin.ignore();
	getline(cin, hobi);

	students.push_back(Student(id, name, age, address, hobi));
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
		cout << student.id << " | Nama = " << student.name << " | Usia = "
			<< student.age << " | Alamat = " << student.address << " | Hobi = " << student.hobi << endl;
	}
}

void StudentManagementSystem::updateStudent(int id) {
	bool found = false;
	for (auto& student : students) {
		if (student.id == id) {
			found = true;
			/* Input Nama */
			cout << "Enter Name: ";
			cin.ignore();
			getline(cin, student.name);
			/* Input Usia */
			while (true) {
				cout << "Enter Age: ";
				cin >> student.age;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Input tidak valid. Harap masukkan angka yang benar.\n";
				}
				else {
					break;
				}
			}
			/* Input Alamat */
			cout << "Enter Address: ";
			cin.ignore();
			getline(cin, student.address);
			/* Input Hobi */
			cout << "Enter Hobi: ";
			cin.ignore();
			getline(cin, student.hobi);

			saveStudents();
			cout << "Student updated successfully!" << endl;
			break;
		}
	}
	if (!found) {
		cout << "Student with ID " << id << " not found." << endl;
	}
}

void StudentManagementSystem::deleteStudent(int id) {
	bool found = false;
	for (auto it = students.begin(); it != students.end(); ++it) {
		if (it->id == id) {
			found = true;
			students.erase(it);
			saveStudents();
			cout << "Student deleted successfully!" << endl;
			break;
		}
	}
	if (!found) {
		cout << "Student with ID " << id << " not found." << endl;
	}
}
