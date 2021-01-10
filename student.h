#pragma once
#include "degree.h"

using namespace::std;

class Student {
public:
	//Accessor Functions
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int getDaysToComplete(int course);
	DegreeProgram getDegreeProgram();

	//Mutator Functions
	void setStudentID(string inStudentID);
	void setFirstName(string inFirstName);
	void setLastName(string inLastName);
	void setEmailAddress(string inEmailAddress);
	void setAge(int inAge);
	void setDaysToComplete(int inDaysToComplete1, int inDaysToComplete2, int inDaysToComplete3);
	void setDegreeProgram(DegreeProgram inDegree);

	void Print();
	Student();
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToComplete[3];
	DegreeProgram degree;
};