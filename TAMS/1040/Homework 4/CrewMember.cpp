#include "CrewMember.h"
using namespace std;

string CrewMember::getName(){
  return name;
}
string CrewMember::getType(){
  return type;
}
string CrewMember::getStatus(){
  return status;
}
int CrewMember::getID(){
  return id;
}
void CrewMember::setName(string newName){
  name = newName;
}
void CrewMember::setType(string newType){
  type = newType;
}
void CrewMember::setStatus(string newStatus){
  status = newStatus;
}
void CrewMember::setID(int newID){
  id = newID;
}
CrewMember::CrewMember(){
  name = " ";
  type = " ";
  status = " ";
  id = 0;
}
