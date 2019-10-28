/*
Name: David Zhao
Course: 1040
Assignment: Homework 2
*/
#include "student.h"
using namespace std;



int student::getStudentID() {
	return id;
}

string student::getStudentName() {
	return name;
}

string student::getStudentClassif() {
	return classif;
}

void student::setStudentID(int newID) {
	id = newID;
}

void student::setStudentName(string newName) {
	name = newName;
}

void student::setStudentClassif(string newClassif) {
	classif = newClassif;
}
