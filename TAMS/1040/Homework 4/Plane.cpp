#include "Plane.h"
using namespace std;

string Plane::getMake(){
  return make;
}
string Plane::getTail(){
  return tail;
}
string Plane::getStatus(){
  return status;
}
int Plane::getModel(){
  return model;
}
int Plane::getSeats(){
  return seats;
}
int Plane::getRange(){
  return range;
}
void Plane::setMake(string newMake){
  make = newMake;
}
void Plane::setTail(string newTail){
  tail = newTail;
}
void Plane::setStatus(string newStatus){
  status = newStatus;
}
void Plane::setModel(int newModel){
  model = newModel;
}
void Plane::setSeats(int newSeats){
  seats = newSeats;
}
void Plane::setRange(int newRange){
  range = newRange;
}
Plane::Plane(){
  make = " ";
  tail = " ";
  status = " ";
  model = 0;
  seats = 0;
  range = 0;
}
