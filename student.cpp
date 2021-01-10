#include "student.h"
#include <iostream>

Student::Student() {
	studentID = "null";
	firstName = "null";
	lastName = "null";
	emailAddress = "null";
	age = 0;
	daysToComplete[0] = 0;
	daysToComplete[1] = 0;
	daysToComplete[2] = 0;
	degree = SECURITY;
	return;
}

//Prints Student information
void Student::Print() {
	string input = "null";
	int course = 0;

	cout << studentID << '\t' << "First Name: " << firstName << '\t' << "Last Name: " << lastName << '\t' << "Age: " << age << '\t'
		<< "Days In Course: {" << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << "} "
		<< "Degree Program: ";

	if (degree == SECURITY) {
		cout << "SECURITY" << endl;
	}
	else if (degree == NETWORK) {
		cout << "NETWORK" << endl;
	}
	else {
		cout << "SOFTWARE" << endl;
	}
}

//Accessors
string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmailAddress() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

int Student::getDaysToComplete(int course) {
	return daysToComplete[course];
}

DegreeProgram Student::getDegreeProgram() {
	return degree;
}

//Mutators
void Student::setStudentID(string inStudentID) {
	this->studentID = inStudentID;
}

void Student::setFirstName(string inFirstName) {
	firstName = inFirstName;
}

void Student::setLastName(string inLastName) {
	lastName = inLastName;
}

void Student::setEmailAddress(string inEmailAddress) {
	emailAddress = inEmailAddress;
}

void Student::setAge(int inAge) {
	age = inAge;
}

void Student::setDaysToComplete(int inDaysToComplete1, int inDaysToComplete2, int inDaysToComplete3) {
	daysToComplete[0] = inDaysToComplete1;
	daysToComplete[1] = inDaysToComplete2;
	daysToComplete[2] = inDaysToComplete3;
}

void Student::setDegreeProgram(DegreeProgram inDegree) {
	degree = inDegree;
}