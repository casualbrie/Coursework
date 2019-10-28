/*
Name: David Zhao
Course: 1040
Assignment: Homework 2
*/
#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "course.h"
using namespace std;

#define CHUNKSIZE 5

class courses {
public:
  courses();
  ~courses();
  void addCourse();
  void printCourses();
  void saveCourses();
  void loadCourses();
private:
  int courseCount;
  int courseCap;
  course *courseList;
};
