#include "Crew.h"
using namespace std;

int Crew::searchCrew(int crewID){
  for(int i = 0; i < crewList.size(); ++i){
    if(crewList.at(i).getID() == crewID) {
      return i;
    }
  }
  return -1;
}
bool Crew::addCrew(CrewMember newCrew){
  if (searchCrew(newCrew.getID()) == -1) {
    crewList.push_back(newCrew);
    return true;
  }
  else {
    return false;
  }
}
bool Crew::editCrew(CrewMember edited){
  int crewIterator = searchCrew(edited.getID());
  if (crewIterator == -1) {
    return false;
  }
  else {
    if (edited.getName() != " ") {
      crewList.at(crewIterator).setName(edited.getName());
    }
    if (edited.getType() != " ") {
      crewList.at(crewIterator).setType(edited.getType());
    }
    if (edited.getStatus() != " ") {
      crewList.at(crewIterator).setStatus(edited.getStatus());
    }
    return true;
  }
}
bool Crew::deleteCrew(int crewID){
  int crewIterator = searchCrew(crewID);
  if (crewIterator == -1) {
    return false;
  }
  else {
    crewList.erase(crewList.begin() + crewIterator);
    return true;
  }
}
void Crew::printCrew(){
  for(int i = 0; i < crewList.size(); ++i) {
    cout << crewList.at(i).getID() << endl;
  }
}
bool Crew::printEntry(int crewID) {
  int crewIterator = searchCrew(crewID);
  if (crewIterator == -1) {
    return false;
  }
  else {
    cout << crewList.at(crewIterator).getID() << endl;
    cout << crewList.at(crewIterator).getName() << endl;
    cout << crewList.at(crewIterator).getStatus() << endl;
    cout << crewList.at(crewIterator).getType() << endl;
    return true;
  }
}
