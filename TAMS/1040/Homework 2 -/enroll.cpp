/*
Name: David Zhao
Course: 1040
Assignment: Homework 2
*/
#include "enroll.h"
using namespace std;

enroll::enroll() {
  for(int i = 0; i < 10; i++) {
    grades[i] = -1;
  }
  numberGrades = 0;
}
void enroll::courseEnroll(int id) {
  courseID = id;
}
void enroll::studentEnroll(int id) {
  studentID = id;
}
void enroll::setEnroll(int id) {
  enrollmentID = id;
}
int enroll::getEnroll() {
  return enrollmentID;
}
int enroll::getStudent() {
  return studentID;
}
int enroll::getCourse() {
  return courseID;
}
void enroll::getGrades() {
  //cout << numberGrades << endl;
  for (int i = 0; i < numberGrades; i++) {
    cout << grades[i] << endl;
  }
}
int enroll::getNumGrades() {
  return numberGrades;
}
void enroll::averageGrades() {
  for (int j = 0; j < numberGrades; j++) {
    averageGrade = averageGrade + grades[j];
  }
  averageGrade = averageGrade / numberGrades;
  if (averageGrade >= 89.5) {
    letterGrade = 'A';
  } else if (averageGrade >= 79.5) {
    letterGrade = 'B';
  } else if (averageGrade >= 69.5) {
    letterGrade = 'C';
  } else {
    letterGrade = 'F';
  }
}
void enroll::addGrades(int newGrades) {
  int tempNumGrades = numberGrades;
  for (int k = (tempNumGrades + 1); k < (newGrades + tempNumGrades + 1); k++) {
    cout << "Please enter a new grade: ";
    cin >> grades[k];
    numberGrades++;
  }
}
void enroll::addGradesLoad(int newGrades, int tempGrades[]) {
  for (int b = 0; b < newGrades; b++) {
    grades[b] = tempGrades[b];
  }
}
