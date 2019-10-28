/*
Name: David Zhao
Course: 1040
Assignment: Homework 2
*/
#include "students.h"
using namespace std;



students::students() {
  studentCount = 0;
  studentCap = CHUNKSIZE;
  studentList = new student[CHUNKSIZE];
}
students::~students() {
  delete [] studentList;
}
void students::addStudent() {
  int id, type;
  string name, tempClassif;
  if (studentCount == studentCap) {
    student *temp;
    temp = new student[studentCap + CHUNKSIZE];
    for (int l = 0; l < studentCount; l++) {
      temp[l] = studentList[l];
    }
    delete [] studentList;
    studentCap += CHUNKSIZE;
    studentList = temp;
  }
  cout << "Enter new student ID: ";
  cin >> id;
  cout << "Enter new student's name: ";
  cin >> name;
  cout << "Enter new student's classification (1 for freshman, 2 for sophomore, 3 for junior, 4 for senior, 5 for other): ";
  cin >> type;
  switch (type)
  {
    case 1: studentList[studentCount].setStudentClassif("Freshman");
            break;
    case 2: studentList[studentCount].setStudentClassif("Sophomore");
            break;
    case 3: studentList[studentCount].setStudentClassif("Junior");
            break;
    case 4: studentList[studentCount].setStudentClassif("Senior");
            break;
    case 5: cout << "Please enter the unoffered classification: ";
            cin >> tempClassif;
            studentList[studentCount].setStudentClassif(tempClassif);
            break;
  }
  //cout << "name is " << name << endl;
  studentList[studentCount].setStudentID(id);
  studentList[studentCount].setStudentName(name);
  studentCount++;
}

void students::printStudents() {
  for (int p = 0; p < studentCount; p++) {
    cout << studentList[p].getStudentName() << endl;
  }
}

void students::saveStudents() {
  ofstream output;
  output.open("Gradebook.txt");
  if (output.fail()) {
    cout << "Failed to open stream. Ending program.";
    exit(EXIT_FAILURE);
  }
  output << studentCount << endl;
  for (int r = 0; r < studentCount; r++) {
    output << studentList[r].getStudentID() << " " << studentList[r].getStudentName() << " " << studentList[r].getStudentClassif() << endl;
  }
  output.close();
}
void students::getStudents(int id) {
  for(int f = 0; f < studentCount; f++) {
    if(studentList[f].getStudentID() == id) {
      cout << studentList[f].getStudentName();
    }
  }
}

void students::loadStudents() {
  int id;
  ifstream input;
  string studentName, studentClassif;
  input.open("Gradebook.txt");
  if (input.fail()) {
    cout << "Failed to open stream. Terminating program.";
    exit(EXIT_FAILURE);
  }
  input >> studentCount;
  delete [] studentList;
  studentList = new student[studentCount];
  for (int m = 0; m < studentCount; m++) {
    input >> id >> studentName >> studentClassif;
    studentList[m].setStudentID(id);
    studentList[m].setStudentName(studentName);
    studentList[m].setStudentClassif(studentClassif);
  }
  input.close();
}
