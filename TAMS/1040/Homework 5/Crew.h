#include <vector>
#include <iostream>
#include "CrewMember.h"
using namespace std;

class Crew {
public:
  int searchCrew(int crewID);
  bool addCrew(CrewMember newCrew);
  bool editCrew(CrewMember edited);
  bool deleteCrew(int crewID);
  void printCrew();
  bool printEntry(int crewID);
  vector<CrewMember> crewList;
};
