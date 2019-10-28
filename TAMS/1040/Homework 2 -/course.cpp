/*
Name: David Zhao
Course: 1040
Assignment: Homework 2
*/
#include "course.h"
using namespace std;


int course::getCourseID() {
  return id;
}

string course::getCourseName() {
  return name;
}

string course::getCourseLoc() {
  return location;
}

string course::getCourseInstr() {
  return instructor;
}

void course::setCourseID(int newID) {
  id = newID;
}

void course::setCourseLoc(string newLoc) {
  location = newLoc;
}

void course::setCourseInstr(string newInstr) {
  instructor = newInstr;
}

void course::setCourseName(string newName) {
  name = newName;
}

void course::setCourseTime(string meetTime) {
  meetingTime = meetTime;
}

string course::getCourseTime() {
  return meetingTime;
}
