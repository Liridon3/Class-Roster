//roster.h

#pragma once
#include <string>
#include "student.h"
using namespace std;


class roster {
	public:
		void add(const string studentData[]);
			//that sets the instance variables from part D1 and updates the roster

		void remove(string studentID);
			//that removes students from the roster by student ID.If the student ID does not exist, the function prints an error message 
			//indicating that the student was not found.

		void printAll();
			//that prints a complete tab - separated list of student data in the provided format : 
			//A1[tab] First Name : John[tab] Last Name : Smith[tab] Age : 20[tab]daysInCourse : {35, 40, 55} Degree Program : Security.
			//The printAll() function should loop through all the students in classRosterArrayand call the print() function for each student.

		void printAverageDaysInCourse(string studentID);
			//that correctly prints a student’s average number of days in the three courses.The student is identified by the studentID parameter.

		void printInvalidEmails();
			//that verifies student email addressesand displays all invalid email addresses to the user.
			//Note : A valid email should include an at sign('@') and period('.') and should not include a space(' ').

		void printByDegreeProgram(degreeProgramList degreeProgram);
			//that prints out student information for a degree program specified by an enumerated type.

		student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
		//Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”

		roster();
			//constructor

		~roster();
			//destructor

		


};