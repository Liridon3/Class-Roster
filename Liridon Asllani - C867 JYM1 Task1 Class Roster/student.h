//student.h

#pragma once
#include <string>
#include "degree.h"

using namespace std;

enum dataItem { STUDENTID, FIRSTNAME, LASTNAME, EMAIL, AGE, NUMBEROFDAYS, DEGREE};

class student 
{
	private:
		//Student data for the program include student ID, first name, last name, email address, age, an array of the number of days to complete each course, and degree program 
		string studentId, firstName, lastName, emailAddress;
		int age;
		int numberOfDaysToCompleteEachCourse [3];
		degreeProgramList degreeProgramName;

	public:
		//an accessor (i.e., getter) for each instance variable from part D1
		const string getStudentId();
		const string getFirstName();
		const string getLastName();
		const string getEmailAddress();
		const int getAge();
		const int *getNumberOfDaysToCompleteEachCourse();
		const degreeProgramList getDegreeProgramName();

		// a mutator (i.e., setter) for each instance variable from part D1
		void setStudentId(string studentId);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setEmailAddress(string emailAddress);
		void setAge(int age);
		void setNumberOfDaysToCompleteEachCourse(int numberOfDaysToCompleteEachCourse[]);
		void setDegreeProgramName(degreeProgramList degreeProgramName);

		//constructor using all of the input parameters provided in the table
		student(
			string studentId,
			string firstName,
			string lastName,
			string emailAddress,
			int age,
			int numberOfDaysToCompleteEachCourse[],
			degreeProgramList degreeProgramName
		);

		//print() to print specific student data
		void print();

		~student();
};