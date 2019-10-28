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
#include "student.h"
using namespace std;

#define CHUNKSIZE 5

class students {
public:
  students();
  ~students();
  void addStudent();
  void printStudents();
  void saveStudents();
  void loadStudents();
  void getStudents(int id);
  student *studentList;
private:
  int studentCount;
  int studentCap;

};
