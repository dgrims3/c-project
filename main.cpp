
#include <iostream>
#include "student.h"
#include <string>
#include "roster.h"
using namespace std;

/*
This project demonstrates Object Oriented Programming and use of pointers in c++ by
taking an array of strings listed below as "studentData" and turning them into objects
of the Student class. The Roster class creates an array of pointers to the Student objects
and accesses and manipulates them through functions of the Roster class.
*/

int main()
{ 
    //string of data to be turned into Student objects
    const string studentData[5] = {
     "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
     "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
     "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
     "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
     "A5,David,Grimsley,dgrimsley89@gmail.com,33,23,34,45,SOFTWARE" };
     
    // studentData table is parsed and values are passed into Student class.
    // the "parse" function uses the "add" function to pass the data to Student class
     Roster classRoster;
     for (int i = 0; i < 5; i++) {
         classRoster.parse(studentData[i]);
     }

     //prints entire class roster array
     classRoster.printall();
     cout << endl;

     //parses emails and returns any with invalid format
     classRoster.printInvalidEmails();
     cout << endl;

     //prints average days in course for each student
     {for (int i = 0; i < 5; i++) { classRoster.printAverageDaysInCourse(classRoster.Roster::classRosterArray[i]->get_student_ID()); }}
     cout << endl;

     //prints students by degree program
     classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
     cout << endl;

     //removes desired student from roster
     classRoster.remove("A3");
     cout << endl;

     //removed student does not print
     classRoster.printall();
     cout << endl;

     //trying to remove student again will result in an error message
     classRoster.remove("A3");
    
    return 0;
}

