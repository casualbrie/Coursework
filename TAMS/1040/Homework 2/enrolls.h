/*
Name: David Zhao
Course: 1040
Assignment: Homework 2
*/
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "enroll.h"
using namespace std;

#define CHUNKSIZE 5

class enrolls {
public:
  enrolls();
  ~enrolls();
  void addEnrollment(int id, int studentID, int courseID);
  void printEnrollsGrades();
  int getEnrollsNames();
  void saveEnrolls();
  void loadEnrolls();
  bool checkStudent (int id);
  bool checkCourse (int id);
  void addStudentGrades();
  void average(int id);
  int studentID[48];
  int enrollCount;
private:
  //int enrollCount;
  int enrollCap;
  enroll *enrollList;

};
