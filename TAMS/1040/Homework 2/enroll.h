/*
Name: David Zhao
Course: 1040
Assignment: Homework 2
*/
#include <string>
#include <iostream>
using namespace std;

class enroll {
public:
  enroll();
  void courseEnroll(int id);
  void studentEnroll(int id);
  void setEnroll(int id);
  int getStudent();
  int getCourse();
  void getGrades();
  int getNumGrades();
  int getEnroll();
  void averageGrades();
  void addGrades(int newGrades);
  void addGradesLoad(int newGrades, int tempGrades[]);
  char letterGrade;
  float averageGrade;
private:
  int studentID;
  int courseID;
  int enrollmentID;
  int grades[10];
  int numberGrades;

};
