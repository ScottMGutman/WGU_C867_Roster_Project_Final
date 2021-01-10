// Student_Databas_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"

int main()
{
    string studentID = "-";
    string firstName = "-";
    string lastName = "-";
    string emailAddress = "-";
    string age = "-";
    string course1 = "-";
    string course2 = "-";
    string course3 = "-";
    string degreeProgramString = "-";
    DegreeProgram degree = SECURITY;

    const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Scott,Gutman,sgutman@wgu.edu,29,5,10,20,SOFTWARE" };

    //Creates Roster Class
    Roster classRoster;

    //Parses the studentData table into all the different parts (Part 2 and 3 of Requrements)
    for(int i = 0; i < 5; i++){
        istringstream inSS(studentData[i]);
        getline(inSS, studentID, ',');
        getline(inSS, firstName, ',');
        getline(inSS, lastName, ',');
        getline(inSS, emailAddress, ',');
        getline(inSS, age, ',');
        int ageint = std::stoi(age);
        getline(inSS, course1, ',');
        int course1int = std::stoi(course1);
        getline(inSS, course2, ',');
        int course2int = std::stoi(course2);
        getline(inSS, course3, ',');
        int course3int = std::stoi(course3);
        getline(inSS, degreeProgramString, ',');

        if (degreeProgramString == "SECURITY") {
            degree = SECURITY;
        }
        else if (degreeProgramString == "NETWORK") {
            degree = NETWORK;
        }
        else if (degreeProgramString == "SOFTWARE") {
            degree = SOFTWARE;
        }

        //Creates a Student object and assigned it to a roster spot
        classRoster.add(studentID, firstName, lastName, emailAddress, ageint, course1int, course2int, course3int, degree);

        inSS.clear();
    }

    //Part 1
    cout << "Course Title: Scripting and Programming - Applications – C867" << endl;
    cout << "Programming Language Used: C++" << endl;
    cout << "WGU Student ID: 001257650" << endl;
    cout << "Name: Scott Gutman" << endl << endl;

    //Part 4
    classRoster.printAll();
    classRoster.printInvalidEmails();

    for (int i = 0; i < 5; i++) {
        string ID = "-";

        ID = classRoster.classRosterArray[i]->getStudentID();
        classRoster.printAverageDaysInCourse(ID);
    }

    classRoster.printByDegreeProgram(SOFTWARE);

    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    //Part 5
    classRoster.~Roster();
}
