/* student struct and prototypes */

struct student{
	char fname[100];
	char lname[100];
	int euid;
    float gpa;
};

int getInput(struct student *db,int size);
void readData(struct student*, int*);
void printMenu();
void printDatabase(struct student*, int);
void findRecordByEuid(struct student*, int);
void findRecordByName(struct student*, int);
void findRecordByLowestGpa(struct student*, int);
void findRecordByHighestGpa(struct student*, int);
void findHighGpas(struct student*, int);
