//main.cpp

#pragma once
#include <string>
#include <iostream>
#include "roster.h"


using namespace std;

int main() {

	string courseInfo = "SCRIPTING AND PROGRAMMING - APPLICATIONS - C867";
	string programLanguage = "Programing Language: C++";
	string myInfo = "Liridon Asllani - Student ID: 010722931";
	cout << courseInfo << endl << programLanguage << endl << myInfo << endl;
	cout << endl;

	//import student data and add myself as the last student
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Liridon,Asllani,lasllan@wgu.edu,35,10,15,20,SOFTWARE"
	};

	//Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
	roster classRoster;

	//Parse and add student data to student object and then to class roster
	classRoster.add(studentData);

	//Print the roster with all students
	classRoster.printAll();

	//Print list of invalid emails
	classRoster.printInvalidEmails();

	//Print the average days in course by student
	for (size_t i = 0; i < 5; i++)
	{
		if (i == 0) {
			cout << "Average Days in Course by Student ID:" << endl;
		}
		string studentId = classRoster.classRosterArray[i]->getStudentId();
		classRoster.printAverageDaysInCourse(studentId);
		if (i == 4) {
			cout << endl;
		}
	}

	//Print list of students with the Software degree type
	classRoster.printByDegreeProgram(SOFTWARE);

	//Remove student with ID A3
	classRoster.remove("A3");

	//Print the current roster with all students
	classRoster.printAll();

	//Remove student with ID A3
	classRoster.remove("A3");

	classRoster.~roster();

}