#include "Flight.h"
using namespace std;

string Flight::getPlaneID() {
  return planeID;
}
string Flight::getStartPort() {
  return startPort;
}
string Flight::getEndPort() {
  return endPort;
}
string Flight::getStatus() {
  return status;
}
string Flight::getStartTime() {
  return startTime;
}
string Flight::getEndTime() {
  return endTime;
}
int Flight::getPilot() {
  return pilot;
}
int Flight::getCopilot() {
  return copilot;
}
int Flight::getCabin1() {
  return cabin1;
}
int Flight::getCabin2() {
  return cabin2;
}
int Flight::getCabin3() {
  return cabin3;
}
int Flight::getNumPass() {
  return numPass;
}
int Flight::getFlightID() {
  return flightID;
}
void Flight::setPlaneID(string newID) {
  planeID = newID;
}
void Flight::setStartPort(string newStart) {
  startPort = newStart;
}
void Flight::setEndPort(string newEnd) {
  endPort = newEnd;
}
void Flight::setStatus(string newStatus) {
  status = newStatus;
}
void Flight::setStartTime(string newStart) {
  startTime = newStart;
}
void Flight::setEndTime(string newEnd) {
  endTime = newEnd;
}
void Flight::setPilot(int newPilot) {
  pilot = newPilot;
}
void Flight::setCopilot(int newCopilot) {
  copilot = newCopilot;
}
void Flight::setCabin1(int newCabin1) {
  cabin1 = newCabin1;
}
void Flight::setCabin2(int newCabin2) {
  cabin2 = newCabin2;
}
void Flight::setCabin3(int newCabin3) {
  cabin3 = newCabin3;
}
void Flight::setNumPass(int newNum) {
  numPass = newNum;
}
void Flight::setFlightID(int newID) {
  flightID = newID;
}
Flight::Flight() {
  planeID = " ";
  startPort = " ";
  endPort = " ";
  status = " ";
  startTime = " ";
  endTime = " ";
  pilot = 0;
  copilot = 0;
  cabin1 = 0;
  cabin2 = 0;
  cabin3 = 0;
  numPass = 0;
  flightID = 0;
}
