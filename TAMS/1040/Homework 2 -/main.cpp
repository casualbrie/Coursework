/*
Name: David Zhao
Course: 1040
Assignment: Homework 2
*/
#include "students.h"
#include "enrolls.h"
#include "courses.h"
using namespace std;

void loaddata();
void storedata();

students group;
courses classes;
enrolls enrollments;

int main() {
  cout << "Department: TAMS\n"
       << "Course: 1040\n"
       << "Homework 2\n"
       << "Name: David Zhao\n"
       << "Email: dz0086@my.unt.edu\n";
  int choice = -1;
  int id, studentID, courseID, amount;

  while (choice != 0) {
    cout << "Please select an option:\n" << "0 - Quit\n1 - Add a new course\n2 - Add a new student\n3 - Add a student to a course\n"
    << "4 - Add grades for a student in a course\n5 - Print a list of all grades for a student in a course\n6 - Print a list of all students in a course\n"
    << "7 - Compute the average for a student in a course\n8 - Print a list of all courses\n9 - Print a list of all students\n10 - Compute the average for a course\n"
    << "11 - Store Grade book to a file\n12 - Load Grade book from a disk file\n"
         << "Select an option: ";
    cin >> choice;
    switch (choice) {
      case 1: classes.addCourse();
              break;
      case 2: group.addStudent();
              break;
      case 3: cout << "Enter new enrollment ID: ";
              cin >> id;
              cout << "Enter enrolling student's ID: ";
              cin >> studentID;
              cout << "Enter the ID of the course being enrolled in: ";
              cin >> courseID;
              if (!(enrollments.checkStudent(studentID) && enrollments.checkCourse(courseID))) {
                break;
              } else {
                enrollments.addEnrollment(id, studentID, courseID);
                break;
              }
              break;
      case 4: enrollments.addStudentGrades();
              break;
      case 5: enrollments.printEnrollsGrades();
              break;
      case 6: cout << "Please enter the course: ";
              cin >> courseID;
              for (int l = 0; l < enrollments.enrollCount; l++) {
                if (enrollments.enrollList[l].getCourse() == courseID) {
                  for (int k = 0; k < enrollments.enrollCount; k++) {
                    if (group.studentList[k].id == enrollments.enrollList[l].getStudent()) {
                      cout << group.studentList[k].name << endl;
                    }
                  }
                }
              }
              break;
      case 7: cout << "Please enter the id of the student: ";
              cin >> studentID;
              for (int j = 0; j < enrollments.enrollCount; j++){
                enrollments.average(studentID);
              }
              break;
      case 8: classes.printCourses();
              break;
      case 9: group.printStudents();
              break;
      case 10:
              break;
      case 11: group.saveStudents();
               classes.saveCourses();
               enrollments.saveEnrolls();
              break;
      case 12: group.loadStudents();
               classes.loadCourses();
               enrollments.loadEnrolls();
              break;
    }
  }
}

void loaddata() {
  group.loadStudents();
  classes.loadCourses();
  enrollments.loadEnrolls();
}

void storedata() {
  group.saveStudents();
  classes.saveCourses();
  enrollments.saveEnrolls();
}
