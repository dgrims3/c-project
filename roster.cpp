#include <iostream>
#include <vector>
#include <string>
#include "student.h"
#include "roster.h"
using namespace std;

//destructor
Roster::~Roster() {
	for (int i = 0; i < count; i++) {
		delete classRosterArray[i];
	}
}


void Roster::parse(string data) {

	size_t right = data.find(",");
	string student_ID = data.substr(0, right);

	size_t left = right + 1;
	right = data.find(",", left);
	string first_name = data.substr(left, right - left);

	left = right + 1;
	right = data.find(",", left);
	string last_name = data.substr(left, right - left);

	left = right + 1;
	right = data.find(",", left);
	string email = data.substr(left, right - left);

	left = right + 1;
	right = data.find(",", left);
	int age = stoi(data.substr(left, right - left));

	left = right + 1;
	right = data.find(",", left);
	int days_to_complete0 = stoi(data.substr(left, right - left));

	left = right + 1;
	right = data.find(",", left);
	int days_to_complete1 = stoi(data.substr(left, right - left));

	left = right + 1;
	right = data.find(",", left);
	int days_to_complete2 = stoi(data.substr(left, right - left));

	left = right + 1;
	right = data.find(",", left);
	string d_program = data.substr(left, right - left);

	DegreeProgram degree_program = DegreeProgram::NETWORK;
	if (d_program == "SOFTWARE") {
		degree_program = DegreeProgram::SOFTWARE;
	}
	else if (d_program == "SECURITY") {
		degree_program = DegreeProgram::SECURITY;
	}
	add(student_ID, first_name, last_name, email, age, days_to_complete0, days_to_complete1, days_to_complete2, degree_program);
}


void Roster::add(string student_ID, string first_name, string last_name, string email, int age, int days_to_complete0, int days_to_complete1, int days_to_complete2, DegreeProgram degree_program) {
	
	int days[3] = { days_to_complete0, days_to_complete1, days_to_complete2 };
	classRosterArray[count++] = new Student(student_ID, first_name, last_name, email, age, days, degree_program);
}

void Roster::printall() {
	for (int i = 0; i < count; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID) {

	string studID = studentID;

	if (studID == "A1") {
		cout << "A1 average day's in course = ";
		cout << (classRosterArray[0]->get_days_to_complete()[0] +
			classRosterArray[0]->get_days_to_complete()[1] +
			classRosterArray[0]->get_days_to_complete()[2]) / 3 << endl;
	}
	else if (studID == "A2") {
		cout << "A2 average day's in course = ";
		cout << (classRosterArray[1]->get_days_to_complete()[0] +
			classRosterArray[1]->get_days_to_complete()[1] +
			classRosterArray[1]->get_days_to_complete()[2]) / 3 << endl;
	}
	else if (studID == "A3") {
		cout << "A3 average day's in course = ";
		cout << (classRosterArray[2]->get_days_to_complete()[0] +
			classRosterArray[2]->get_days_to_complete()[1] +
			classRosterArray[2]->get_days_to_complete()[2]) / 3 << endl;
	}

	else if (studID == "A4") {
		cout << "A4 average day's in course = ";
		cout << (classRosterArray[3]->get_days_to_complete()[0] +
			classRosterArray[3]->get_days_to_complete()[1] +
			classRosterArray[3]->get_days_to_complete()[2]) / 3 << endl;
	}
	else if (studID == "A5") {
		cout << "A5 average day's in course = ";
		cout << (classRosterArray[4]->get_days_to_complete()[0] +
			classRosterArray[4]->get_days_to_complete()[1] +
			classRosterArray[4]->get_days_to_complete()[2]) / 3 << endl;
	}
	else cout << "invalid ID entered";
};

void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; i++) {
		size_t email = classRosterArray[i]->get_email().find(" ");
		if (email != string::npos) {
			cout << classRosterArray[i]->get_email() << endl;
		}
		size_t email1 = classRosterArray[i]->get_email().find(".");
		if (email1 == string::npos) {
			cout << classRosterArray[i]->get_email() << endl;
		}
		size_t email2 = classRosterArray[i]->get_email().find("@");
		if (email2 == string::npos) {
			cout << classRosterArray[i]->get_email() << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degree_program){
	for (int i = 0; i < 5; i++){
		if (classRosterArray[i] != nullptr && classRosterArray[i]->get_degree_program() == degree_program) {
			classRosterArray[i]->print();
		}
	}
}

void Roster::remove(string studentID) {

	string studID = studentID;
	
	if (studID == "A1" && classRosterArray[0] != nullptr) {
		classRosterArray[0] = { nullptr };
	}
	else if (studID == "A2" && classRosterArray[1] != nullptr) {
		classRosterArray[1] = { nullptr };
	}
	else if (studID == "A3" && classRosterArray[2] != nullptr) {
		classRosterArray[2] = { nullptr };
	}
	else if (studID == "A4" && classRosterArray[3] != nullptr) {
		classRosterArray[3] = { nullptr };
	}
	else if (studID == "A5" && classRosterArray[4] != nullptr) {
		classRosterArray[4] = { nullptr };
	}
	else cout << "Student ID not found.";
};