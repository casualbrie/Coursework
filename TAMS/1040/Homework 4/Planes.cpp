#include "Planes.h"
using namespace std;

int Planes::searchPlane(string planeNum){
  for(int i = 0; i < planeList.size(); ++i){
    if(planeList.at(i).getTail() == planeNum) {
      return i;
    }
  }
  return -1;
}
bool Planes::addPlane(Plane newPlane){
  if (searchPlane(newPlane.getTail()) == -1) {
    planeList.push_back(newPlane);
    return true;
  }
  else {
    return false;
  }
}
bool Planes::editPlane(Plane edited){
  int planeIterator = searchPlane(edited.getTail());
  if (planeIterator == -1) {
    return false;
  }
  else {
    if (edited.getMake() != " ") {
      planeList.at(planeIterator).setMake(edited.getMake());
    }
    if (edited.getStatus() != " ") {
      planeList.at(planeIterator).setStatus(edited.getStatus());
    }
    if (edited.getModel() != 0) {
      planeList.at(planeIterator).setModel(edited.getModel());
    }
    if (edited.getSeats() != 0) {
      planeList.at(planeIterator).setSeats(edited.getSeats());
    }
    if (edited.getRange() != 0) {
      planeList.at(planeIterator).setRange(edited.getRange());
    }
    return true;
  }
}
bool Planes::deletePlane(string planeNum){
  int planeIterator = searchPlane(planeNum);
  if (planeIterator == -1) {
    return false;
  }
  else {
    planeList.erase(planeList.begin() + planeIterator);
    return true;
  }
}
void Planes::printPlanes(){
  for(int i = 0; i < planeList.size(); ++i) {
    cout << planeList.at(i).getTail() << endl;
  }
}
bool Planes::printEntry(string planeID) {
  int planeIterator = searchPlane(planeID);
  if (planeIterator == -1) {
    return false;
  }
  else {
    cout << planeList.at(planeIterator).getTail() << endl;
    cout << planeList.at(planeIterator).getMake() << endl;
    cout << planeList.at(planeIterator).getStatus() << endl;
    cout << planeList.at(planeIterator).getModel() << endl;
    cout << planeList.at(planeIterator).getSeats() << endl;
    cout << planeList.at(planeIterator).getRange() << endl;
    return true;
  }
}
