/*
Name: David Zhao
Course: 1040
Assignment: Homework 2
*/
#include <string>
using namespace std;

class student {
	public:
		int getStudentID();
		string getStudentName();
		string getStudentClassif();
		void setStudentID(int newID);
		void setStudentName(string newName);
		void setStudentClassif(string newClassif);
		int id;
		string name;
	private:

		string classif;
};
