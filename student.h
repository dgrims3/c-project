#pragma once
#include <iostream>
#include <string>
#include "degree.h"
using namespace  std;

class Student {
	
private:
//attributes
	string student_ID;
	string first_name;
	string last_name;
	string email;
	int age;
	int days_to_complete[3];
	DegreeProgram degree_program;

public:
//constructor
	Student(string student_ID, string first_name, string last_name, string email, int age, int days_to_complete[], DegreeProgram degree_program);

// setters
	void set_student_ID(string);
	void set_first_name(string);
	void set_last_name(string);
	void set_email(string);
	void set_age(int);
	void set_days_to_complete(int a[]);
	void set_degree_program(DegreeProgram);

//getters
	string get_student_ID();
	string get_first_name();
	string get_last_name();
	string get_email();
	int get_age();
	int* get_days_to_complete();
	DegreeProgram get_degree_program();
	
//Functions
	void print();
};

