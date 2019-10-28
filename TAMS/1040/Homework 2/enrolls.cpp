/*
Name: David Zhao
Course: 1040
Assignment: Homework 2
*/
#include "enrolls.h"
using namespace std;



enrolls::enrolls() {
  enrollCount = 0;
  enrollCap = CHUNKSIZE;
  enrollList = new enroll[CHUNKSIZE];
}
enrolls::~enrolls() {
  delete [] enrollList;
}
void enrolls::addEnrollment(int id, int studentID, int courseID) {
  //int id, studentID, courseID;
  string name, tempClassif;
  if (enrollCount == enrollCap) {
    enroll *temp;
    temp = new enroll[enrollCap + CHUNKSIZE];
    for (int l = 0; l < enrollCount; l++) {
      temp[l] = enrollList[l];
    }
    delete [] enrollList;
    enrollCap += CHUNKSIZE;
    enrollList = temp;
  }
  /*cout << "Enter new enrollment ID: ";
  cin >> id;
  cout << "Enter enrolling student's ID: ";
  cin >> studentID;
  cout << "Enter the ID of the course being enrolled in: ";
  cin >> courseID;
  */
  //moving this stuff of the code to the main function in order to allow for checking if student has < 5 classes or course has < 48 students
  //cout << "name is " << name << endl;
  enrollList[enrollCount].setEnroll(id);
  enrollList[enrollCount].courseEnroll(courseID);
  enrollList[enrollCount].studentEnroll(studentID);
  enrollCount++;
}

void enrolls::printEnrollsGrades() {
  int studentID, courseID;
  cout << "Please enter the ID of the student you want the grades for: ";
  cin >> studentID;
  cout << "Please enter the ID of the course you want the grades for: ";
  cin >> courseID;
  cout << "Grades: \n";
  for (int p = 0; p < enrollCount; p++) {
    if ((studentID == enrollList[p].getStudent()) && (courseID == enrollList[p].getCourse())) {
      enrollList[p].getGrades();
    }
    enrollList[p].getGrades();
  }
}
int enrolls::getEnrollsNames() {
  int courseID, counter = 0;
  cout << "Please enter the ID of the course: ";
  cin >> courseID;
  for (int x = 0; x < enrollCount; x++) {
    for (int t = 0; t < 48; t++) {
      if (courseID == enrollList[x].getCourse()) {
        studentID[t] = enrollList[x].getStudent();
        counter++;
      }
    }
  }
  return counter;
}

void enrolls::saveEnrolls() {
  ofstream output;

  output.open("Gradebook.txt");
  if (output.fail()) {
    cout << "Failed to open stream. Ending program.";
    exit(EXIT_FAILURE);
  }
  output << enrollCount << endl;
  for (int r = 0; r < enrollCount; r++) {
    output << enrollList[r].getEnroll() << " " << enrollList[r].getStudent() << " " << enrollList[r].getCourse() << " " << enrollList[r].getNumGrades() << " ";
    enrollList[r].getGrades();
  }
  output.close();
}
void enrolls::average(int id) {
  for (int i = 0; i < enrollCount; i++) {
    if (enrollList[i].getStudent() == id) {
      enrollList[i].averageGrades();
      cout << "Average: " << enrollList[i].averageGrade << endl;;
    }
  }
}
void enrolls::loadEnrolls() {
  int studentID, courseID, quantityGrades, enrollID, tempGrades[10];
  ifstream input;
  input.open("Gradebook.txt");
  if (input.fail()) {
    cout << "Failed to open stream. Terminating program.";
    exit(EXIT_FAILURE);
  }
  input >> enrollCount;
  delete [] enrollList;
  enrollList = new enroll[enrollCount];
  for (int m = 0; m < enrollCount; m++) {
    input >> enrollID >> studentID >> courseID >> quantityGrades;
    for (int y = 0; y < quantityGrades; y++) {
      input >> tempGrades[y];
    }
    enrollList[m].setEnroll(enrollID);
    enrollList[m].studentEnroll(studentID);
    enrollList[m].courseEnroll(courseID);
    enrollList[m].addGradesLoad(quantityGrades, tempGrades);
  }
  input.close();
}

bool enrolls::checkStudent(int id) {
  int count = 0;
  for(int o = 0; o < enrollCount; o++) {
    if(id == enrollList[o].getStudent()) {
      count++;
    }
  }
  if (count < 5) {
    return true;
  }
  return false;
}

bool enrolls::checkCourse(int id) {
  int count = 0;
  for(int h = 0; h < enrollCount; h++) {
    if(id == enrollList[h].getCourse()) {
      count++;
    }
  }
  if (count < 48) {
    return true;
  }
  return false;
}

void enrolls::addStudentGrades() {
  int amount, studentID, courseID;
  cout << "Enter the amount of grades you want to enter: ";
  cin >> amount;
  cout << "Enter the ID of the student you want to enter grades for: ";
  cin >> studentID;
  cout << "Enter the ID of the course the grades should be input in: ";
  cin >> courseID;
  for(int u = 0; u < enrollCount; u++) {
    if((studentID == enrollList[u].getStudent()) && (courseID == enrollList[u].getCourse())) {
      enrollList[u].addGrades(amount);
    }
  }
}
