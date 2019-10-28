#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "bubble.h"
#include <string>
#include <iomanip>
using namespace std;

//class structure
typedef struct classStats {
  float mean;
  float min;
  float max;
  float median;
  char *name;
} classStat;


int main()
{
  //creating variables
  ifstream inputStream;
  char fileName[20], title[20], *header;
  classStat allClass;
  cout << "Please enter the name of the data file: ";
  cin >> fileName;
  //opening stream using given name
  inputStream.open(fileName);
  //in case of a mess up
  if (inputStream.fail())
  {
    exit(EXIT_FAILURE);
  }
  //grabbing title for allClass
  inputStream >> title;
  header = new char;
  header = title;
  //initializing students and grabbing memory
  student **students;
  students = new student*[19];
  //grabbing all the values from the file
  for (int i = 0; i < 19; i++) {

      students[i] = new student;
      students[i]->first = new char[20];
      students[i]->last = new char[20];
      inputStream >> students[i]->first;
      inputStream >> students[i]->last;
      inputStream >> students[i]->exam1;
      //debugging
      //cout << students[i]->exam1;
      inputStream >> students[i]->exam2;
      inputStream >> students[i]->exam3;
      students[i]->mean = (students[i]->exam1 + students[i]->exam2 + students[i]->exam3) / 3.0;
      //debugging
      //cout << students[i]->mean << endl;
    }
    //initializing minimum and maximums
    allClass.min = 100;
    allClass.max = 0;
    //bubble sorting!
    bubble(students, 19);
    for (int j = 0; j < 19; j++) {
      //using allClass.mean to avoid creating another variable
      allClass.mean += students[j]->mean;
      //sorting for minimum value
      if (allClass.min > students[j]->mean) {
        allClass.min = students[j]->mean;
        cout << allClass.min;
      }
      //sorting for maximum value
      if (allClass.max < students[j]->mean) {
        allClass.max = students[j]->mean;
      }
      //when at median number
      if (j == 9)
      {
        allClass.median = students[j]->mean;
      }
    }
    //getting true mean
    allClass.mean = allClass.mean / 19;
    //getting title
    allClass.name = header;
    //all the cout good stuff
    cout << "123456789012345678901234567890123456789012345678901234567890" << endl;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    //couting header thing
    cout << setw(8) << allClass.name << setw(8) << "MEAN:  " << allClass.mean << setw(8) << "MIN:  " << allClass.min << setw(8) << "MAX:  " << allClass.max << setw(10) << "MEDIAN:  " << allClass.median << endl;
    //couting all lines and grades and stuff
    for (int k = 0; k < 19; k++) {
      cout << setw(12) << students[k]->first << setw(12) << students[k]->last << setw(7) << students[k]->mean << endl;
    }
    //removing dynamic memory
    for (int l = 0; l < 19; l++) {
      delete [] students[l];
    }
    delete students;

    return 0;
}
