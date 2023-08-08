//student.cpp

#pragma once
#include <string>
#include "student.h"
#include <iostream>


//accessor (i.e., getter) definitions for each instance variable from part D1	
const std::string student::getStudentId() {
	return studentId;
}
const std::string student::getFirstName() {
	return firstName;
};
const std::string student::getLastName() {
	return lastName;
}
const std::string student::getEmailAddress() {
	return emailAddress;
}
const int student::getAge() {
	return age;
}
const int* student::getNumberOfDaysToCompleteEachCourse() {
	return numberOfDaysToCompleteEachCourse;
}
const degreeProgramList student::getDegreeProgramName() {
	return degreeProgramName;
}

//mutator (i.e., setter) definitions for each instance variable from part D1
void student::setStudentId(std::string studentId) {
	this->studentId = studentId;
}
void student::setFirstName(std::string firstName) {
	this->firstName = firstName;
}
void student::setLastName(std::string lastName) {
	this->lastName = lastName;
}
void student::setEmailAddress(std::string emailAddress) {
	this->emailAddress = emailAddress;
}
void student::setAge(int age) {
	this->age = age;
}
void student::setNumberOfDaysToCompleteEachCourse(int numberOfDaysToCompleteEachCourse[]) {
	//this->numberOfDaysToCompleteEachCourse = new int[3];
	this->numberOfDaysToCompleteEachCourse[0] = numberOfDaysToCompleteEachCourse[0];
	this->numberOfDaysToCompleteEachCourse[1] = numberOfDaysToCompleteEachCourse[1];
	this->numberOfDaysToCompleteEachCourse[2] = numberOfDaysToCompleteEachCourse[2];
}
void student::setDegreeProgramName(degreeProgramList degreeProgramName) {
	this->degreeProgramName = degreeProgramName;
}

//constructor using all of the input parameters provided in the table
student::student(
	string studentId,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int numberOfDaysToCompleteEachCourse[],
	degreeProgramList degreeProgramName) {
	setStudentId(studentId);
	setFirstName(firstName);
	setLastName(lastName);
	setEmailAddress(emailAddress);
	setAge(age);
	setNumberOfDaysToCompleteEachCourse(numberOfDaysToCompleteEachCourse);
	setDegreeProgramName(degreeProgramName);
	return;
};

//print() to print specific student data
//A1[tab] First Name : John[tab] Last Name : Smith[tab] Age : 20[tab]daysInCourse : {35, 40, 55} Degree Program : Security.
void student::print() {
	cout << this->getStudentId() << "\t";
	cout << "First Name: " << this->getFirstName() << "\t";
	cout << "Last Name: " << this->getLastName() << "\t";
	//cout << classRosterArray[i]->getEmailAddress() << "\t"; not required per rubric
	cout << "Age: " << this->getAge() << "\t";
	const int* daysInCourse = { this->getNumberOfDaysToCompleteEachCourse() };
	cout << "Days: " << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "\t";
	cout << "Degree Program: ";
	switch (this->getDegreeProgramName()) {
	case 0: cout << "SECURITY" << "\t";
		break;
	case 1: cout << "NETWORK" << "\t";
		break;
	case 2: cout << "SOFTWARE" << "\t";
	}
	cout << endl;
}
student::~student() {
}