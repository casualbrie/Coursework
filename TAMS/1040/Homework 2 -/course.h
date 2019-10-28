/*
Name: David Zhao
Course: 1040
Assignment: Homework 2
*/
#include <string>
using namespace std;

class course {
public:
  int getCourseID();
  string getCourseName();
  string getCourseLoc();
  string getCourseTime();
  string getCourseInstr();
  void setCourseID(int newID);
  void setCourseLoc(string newLoc);
  void setCourseTime(string newTime);
  void setCourseInstr(string newInstr);
  void setCourseName(string newName);
private:
  int id;
  string name;
  string location;
  string meetingTime;
  string instructor;
};
