//roster.cpp

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include<sstream>
#include <regex>
#include "roster.h"

using namespace std;

//To parse and add student objects. sets the instance variables from part D1 and updates the roster
void roster::add(const string studentData[]) {
	string studentID; 
	string firstName; 
	string lastName; 
	string emailAddress; 
	int age; 
	int daysInCourse1; 
	int daysInCourse2;
	int daysInCourse3; 
	degreeProgramList degreeProgram = SECURITY;
	vector <string> delimiatedStudentData;
	for (int j = 0; j < 5; j++) {
		string singleStudentData = studentData[j];
		stringstream stream(singleStudentData);
		while (stream.good()) {
			string individualDataPoints;
			getline(stream, individualDataPoints, ',');
			delimiatedStudentData.push_back(individualDataPoints);
			
		}
		studentID = delimiatedStudentData[0];
		firstName = delimiatedStudentData[1];
		lastName = delimiatedStudentData[2];
		emailAddress = delimiatedStudentData[3];
		age = stoi(delimiatedStudentData[4]);
		daysInCourse1 = stoi(delimiatedStudentData[5]);
		daysInCourse2 = stoi(delimiatedStudentData[6]);
		daysInCourse3 = stoi(delimiatedStudentData[7]);
		if (delimiatedStudentData[8] == "SECURITY")
		{
			degreeProgram = SECURITY;
		} 
		if (delimiatedStudentData[8] == "SOFTWARE")
		{
			degreeProgram = SOFTWARE;
		}
		if (delimiatedStudentData[8] == "NETWORK")
		{
			degreeProgram = NETWORK;
		}
		int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
		student* newStudent = new student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
			
		classRosterArray[j] = newStudent;
		
		delimiatedStudentData.clear();
				
		
	}
}

//removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
void roster::remove(string studentId) {
	bool studentIdFound = 0;
	int size = sizeof(classRosterArray)/ sizeof(classRosterArray[0]);
	for (size_t i = 0; i < size; i++)
	{
		if (classRosterArray[i] != nullptr) {
			if (studentId == classRosterArray[i]->getStudentId()) {
				studentIdFound = 1;
				cout << "Student with student ID " << classRosterArray[i]->getStudentId() << " was removed" << endl << endl;
				classRosterArray[i] = nullptr;
				break;
			}
		}
	}
	if (!studentIdFound)
	{
		cout << "The student with Student ID "<< studentId << " was not found" << endl << endl;
	}
}

//prints a complete tab-separated list of student data in the provided format 
//A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. 
//The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
void roster::printAll() {
	cout << "Class Roster:" << endl;
	for (size_t i = 0; i < 5; i++)
	{
		if (classRosterArray[i] == nullptr)
		{
			continue;
		}
		else
		{
			classRosterArray[i]->print();
		}
		
	}
	cout << endl;
}

//prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
void roster::printAverageDaysInCourse(string studentID) {
	int numOfDays1;
	int numOfDays2;
	int numOfDays3;
	int sumOfDays;
	int avgDays;

	for (size_t i = 0; i < 5; i++)
	{
		if (classRosterArray[i]->getStudentId() == studentID) {
			const int* days = { classRosterArray[i]->getNumberOfDaysToCompleteEachCourse() };
			numOfDays1 = days[0];
			numOfDays2 = days[1];
			numOfDays3 = days[2];
			sumOfDays = numOfDays1 + numOfDays2 + numOfDays3;
			avgDays = sumOfDays / 3;
		}
	}
		cout << "The average number of days in the 3 courses for student ID " << studentID << " is " << avgDays<<endl;
}

//Verifies student email addressesand displays all invalid email addresses to the user.
//Note: A valid email includes an at sign('@') and period('.') and does not include a space(' ').
void roster::printInvalidEmails() {
	cout << "Invalid Emails:" << endl;
	string email[5];
	for (size_t i = 0; i < 5; i++) {
		email[i] = classRosterArray[i]->getEmailAddress();
		if ((email[i].find(' ') != std::string::npos) || !(email[i].find('@') != std::string::npos) || !(email[i].find('.') != std::string::npos))
		{
			cout << email[i] << endl;
		}
	}
	cout << endl;
}

//prints out student information for a degree program specified by an enumerated type.
void roster::printByDegreeProgram(degreeProgramList degreeProgram) {
	cout << "Print by Degree Program (SOFTWARE):" << endl;
	for (size_t i = 0; i < 5; i++)
	{
		if (classRosterArray[i]->getDegreeProgramName() == degreeProgram)
		{
			cout << classRosterArray[i]->getStudentId() << "\t";
			cout << classRosterArray[i]->getFirstName() << "\t";
			cout << classRosterArray[i]->getLastName() << "\t";
			cout << classRosterArray[i]->getEmailAddress() << "\t";
			cout << classRosterArray[i]->getAge() << "\t";
			const int* daysInCourse = { classRosterArray[i]->getNumberOfDaysToCompleteEachCourse() };
			cout << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "\t";
			switch (classRosterArray[i]->getDegreeProgramName()) {
			case 0: cout << "SECURITY";
				break;
			case 1: cout << "NETWORK";
				break;
			case 2: cout << "SOFTWARE";
				break;
			}
			cout << endl;
		}
		if (i == 4) {
			cout << endl;
		}
	}
}

roster::roster() {}

roster::~roster() {}
