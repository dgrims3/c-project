#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Roster {

public:
// Destructor
	~Roster();
// array of pointers to Student objects
	Student* classRosterArray[5];
	int count = 0;
//functions
	void parse(string);
	void add(string student_ID, string first_name, string last_name, string email, int age, int days_to_complete0, int days_to_complete1, int days_to_complete2, DegreeProgram degree_program);
	void printall();
	void remove(string);
	void printAverageDaysInCourse(string);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeprogram);
};