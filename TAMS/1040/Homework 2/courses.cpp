/*
Name: David Zhao
Course: 1040
Assignment: Homework 2
*/
#include "courses.h"
using namespace std;



courses::courses() {
  courseCount = 0;
  courseCap = CHUNKSIZE;
  courseList = new course[CHUNKSIZE];
}
courses::~courses() {
  delete [] courseList;
}
void courses::addCourse() {
  int id, type;
  string name, location, meetTime, instruc;
  if (courseCount == courseCap) {
    course *temp;
    temp = new course[courseCap + CHUNKSIZE];
    for (int l = 0; l < courseCount; l++) {
      temp[l] = courseList[l];
    }
    delete [] courseList;
    courseCap += CHUNKSIZE;
    courseList = temp;
  }
  cout << "Enter new course ID: ";
  cin >> id;
  cout << "Enter new course's name: ";
  cin >> name;
  cout << "Enter new course's location: ";
  cin >> location;
  cout << "Enter new course's meeting time (ex. 0:00pm, no space): ";
  cin >> meetTime;
  cout << "Enter new course's instructor: ";
  cin >> instruc;
  //cout << "name is " << name << endl;
  courseList[courseCount].setCourseID(id);
  courseList[courseCount].setCourseName(name);
  courseList[courseCount].setCourseLoc(location);
  courseList[courseCount].setCourseTime(meetTime);
  courseList[courseCount].setCourseInstr(instruc);
  courseCount++;
}

void courses::printCourses() {
  for (int p = 0; p < courseCount; p++) {
    cout << courseList[p].getCourseName() << endl;
  }
}

void courses::saveCourses() {
  ofstream output;
  output.open("Gradebook.txt");
  if (output.fail()) {
    cout << "Failed to open stream. Ending program.";
    exit(EXIT_FAILURE);
  }
  output << courseCount << endl;
  for (int r = 0; r < courseCount; r++) {
    output << courseList[r].getCourseID() << " " << courseList[r].getCourseName() << " " << courseList[r].getCourseLoc() << " " << courseList[r].getCourseTime() << " " << courseList[r].getCourseInstr() << endl;
  }
  output.close();
}

void courses::loadCourses() {
  int id;
  ifstream input;
  string courseName, courseLoc, courseTime, courseInstr;
  input.open("Gradebook.txt");
  if (input.fail()) {
    cout << "Failed to open stream. Terminating program.";
    exit(EXIT_FAILURE);
  }
  input >> courseCount;
  delete [] courseList;
  courseList = new course[courseCount];
  for (int m = 0; m < courseCount; m++) {
    input >> id >> courseName >> courseLoc >> courseTime >> courseInstr;
    courseList[m].setCourseID(id);
    courseList[m].setCourseName(courseName);
    courseList[m].setCourseLoc(courseLoc);
    courseList[m].setCourseTime(courseTime);
    courseList[m].setCourseInstr(courseInstr);
  }
  input.close();
}
