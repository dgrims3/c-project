#include "student.h"
#include <iostream>
#include <string>
using namespace  std;

//Constructor
Student::Student(string student_ID, string first_name, string last_name, string email, int age, int days_to_complete[], DegreeProgram degree_program) {
	this->student_ID = student_ID;
	this->first_name = first_name;
	this->last_name = last_name;
	this->email = email;
	this->age = age;
	for (int i = 0; i < 3; i++)
		this->days_to_complete[i] = days_to_complete[i];
	this->degree_program = degree_program;
}

//Setters 
	void Student::set_student_ID(string new_student_ID) {
		student_ID = new_student_ID;
	}

	void Student::set_first_name(string new_first_name) {
		first_name = new_first_name;
	}

	void Student::set_last_name(string new_last_name) {
		last_name = new_last_name;
	}

	void Student::set_email(string new_email) {
		email = new_email;
	}

	void Student::set_age(int new_age) {
		age = new_age;
	}

	void Student::set_days_to_complete(int a[]) {
		this->days_to_complete[0] = a[0];
		this->days_to_complete[1] = a[1];
		this->days_to_complete[2] = a[2];

	}

	void Student::set_degree_program(DegreeProgram new_degree_program) {
		degree_program = new_degree_program;
	}

//Getters
	string Student::get_student_ID() {
		return student_ID;
	}
	
	string Student::get_first_name() {
		return first_name;
	}
	
	string Student::get_last_name() {
		return last_name;
	}
	
	string Student::get_email() {
		return email;
	}
	
	int Student::get_age() {
		return age;
	}

	int* Student::get_days_to_complete() {
			return days_to_complete;
	}
	
	DegreeProgram Student::get_degree_program() {
		return degree_program;
	}
	

	//Functions
	void Student::print() {
		
		string d_program;
		if (degree_program == DegreeProgram::SOFTWARE) {
			d_program = "Software";
		}
		if (degree_program == DegreeProgram::NETWORK) {
			d_program = "Network";
		}
		if (degree_program == DegreeProgram::SECURITY) {
			d_program = "Security";
		}
		cout << student_ID << "\t" << first_name << "\t" << last_name << "\t" << email << "\t" << age << "\t" << "{";
			for (int i = 0; i < 3; i++) {
			cout << days_to_complete[i] << ",";
		}
			cout << "}" << "\t" << d_program << endl;
	}