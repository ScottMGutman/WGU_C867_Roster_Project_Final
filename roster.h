#pragma once
#include "student.h"
#include "degree.h"

using namespace::std;

class Roster {
public:
	Roster();
	~Roster();
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	//Valid email has '@', '.', and no spaces ' '
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

	Student* classRosterArray[5];
	
private:
	int rosterSpotStatus[5];
};
