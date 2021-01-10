#include "roster.h"
#include "degree.h"
#include <string>
#include <iostream>
#include <sstream>

//Constructor
Roster::Roster() {
	for (int i = 0; i < 5; i++) {
		classRosterArray[i] = nullptr;
		rosterSpotStatus[i] = 0;
	}
}

//Destructor
Roster::~Roster() {
}

//Creates a new Student object and assigns it to a free roster spots
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int found = 0;
	int i = 0;

	Student* student = new Student;

	student->setStudentID(studentID);
	student->setFirstName(firstName);
	student->setLastName(lastName);
	student->setAge(age);
	student->setEmailAddress(emailAddress);
	student->setDaysToComplete(daysInCourse1, daysInCourse2, daysInCourse3);
	student->setDegreeProgram(degreeProgram);

	while (found == 0 && i < 5) {
		if (rosterSpotStatus[i] == 0) {
			classRosterArray[i] = student;
			rosterSpotStatus[i] = 1;

			found = 1;
		}
		i++;
	}

	if (found == 0) {
		cout << "No Empty Spaces in Roster." << endl;
	}
}

//Deletes student object
void Roster::remove(string studentID) {	
	string x = "-";
	int i = 0;
	int found = 0;

	for (int i = 0; i < 5; i++) {

		if (classRosterArray[i] != nullptr) {
			x = classRosterArray[i]->getStudentID();
			if (x == studentID) {
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				rosterSpotStatus[i] = 0;
				found = 1;
			}
		}
		else {
			found = 0;
		}
	}

	if (found == 0) {
		cout << "Student not Found" << endl;
	}
	else {
		cout << "Student removed from roster." << endl;
	}
	cout << endl;
}

//Prints all roster information
void Roster::printAll() {
	for (int i = 0; i < 5; i++) {

		if (classRosterArray[i] == nullptr) {
		}
		else {
			classRosterArray[i]->Print();
			cout << endl;
		}
	}
}

//Prints average days in course for specified student
void Roster::printAverageDaysInCourse(string studentID) {
	int course1 = 0;
	int course2 = 0;
	int course3 = 0;
	int average = 0;
	string x = "-";
	int i = 0;
	int found = 0;

	while (found == 0 && i < 5) {
		x = classRosterArray[i]->getStudentID();

		if (x == studentID) {
			found = 1;
		}
		i++;
	}

	if (found == 1) {
		course1 = classRosterArray[i-1]->getDaysToComplete(0);
		course2 = classRosterArray[i-1]->getDaysToComplete(1);
		course3 = classRosterArray[i-1]->getDaysToComplete(2);

		average = (course1 + course2 + course3) / 3;

		cout << "Average Days in Course for student " << x << ": " << average << endl << endl;
	}
	
}

//Checks for invalid emails: Valid email has '@', '.', and no spaces ' '
void Roster::printInvalidEmails() {
	string email = "-";
	bool found = false;
	bool valid1 = true;
	bool valid2 = true;
	bool valid3 = true;
	int npos = 0;

	cout << "Invalid Emails:" << endl;

	for (int i = 0; i < 5; i++) {
		if (rosterSpotStatus[i] == 1) {
			email = classRosterArray[i]->getEmailAddress();

			std::size_t found1 = email.find("@");
			if (found1 != std::string::npos) {
				valid1 = true;
			}
			else {
				valid1 = false;
			}

			std::size_t found2 = email.find(".");
			if (found2 != std::string::npos) {
				valid2 = true;
			}
			else {
				valid2 = false;
			}

			std::size_t found3 = email.find(" ");
			if (found3 != std::string::npos) {
				valid3 = false;
			}
			else {
				valid3 = true;
			}

			if (valid1 == false || valid2 == false || valid3 == false) {
				cout << email << endl;
			}
		}
	}
	cout << endl;
}

//Prints all students in roster with specified degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	DegreeProgram degree = SECURITY;
	
	for (int i = 0; i < 5; i++) {
		degree = classRosterArray[i]->getDegreeProgram();

		if (degree == degreeProgram) {
			classRosterArray[i]->Print();
			cout << endl;
		}
	}

}