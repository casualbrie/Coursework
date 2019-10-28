/* Name:        David Zhao
   Email:       dz0086@my.unt.edu
   Description: Mean Green Airlines app
                Program allows the user to create flights, planes, and crew members to
                fly on Mean Green Airlines
*/
#include "Crew.h"
#include "Flights.h"
#include "Planes.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

void loadData();
void saveData();

int main() {
  Flights ListFlights;
  Planes planesList;
  Crew crewsList;

  int choice;
  string temp1, temp2, temp3, temp4, temp5, temp6;
  int num1, num2, num3, num4, num5, num6, num7, locOfPlane, numberSeats;
  vector<int> flightCheck;
  tm compareTime1;
  tm compareTime2;
  tm compareTime3;
  tm compareTime4;
  time_t time1;
  time_t time2;
  time_t time3;
  time_t time4;
  double test;

  memset(&compareTime1, 0, sizeof(tm));
  memset(&compareTime2, 0, sizeof(tm));
  memset(&compareTime3, 0, sizeof(tm));
  memset(&compareTime4, 0, sizeof(tm));
  cout << "Department: TAMS\n"
       << "Course:     1040\n"
       << "Name:       David Zhao\n"
       << "Email:      dz0086@my.unt.edu\n"
       << "Homework 4\n";
  while (choice != 0) {
    cout << "Please select an option.\n"
         << "0 - Quit\n"
         << "1 - Add Crew\n"
         << "2 - Add a Plane\n"
         << "3 - Add a Flight\n"
         << "4 - Delete Crew\n"
         << "5 - Delete a Plane\n"
         << "6 - Delete a Flight\n"
         << "7 - Edit Crew\n"
         << "8 - Edit a Plane\n"
         << "9 - Edit a Flight\n"
         << "10 - Print all crew\n"
         << "11 - Print all Planes\n"
         << "12 - Print all Flights\n"
         << "13 - Print specific crew\n"
         << "14 - Print specific plane\n"
         << "15 - Print specific flight\n"
         << "16 - Print assignment schedule for a plane\n"
         << "17 - Print assignment schedule for a crew member\n"
         << "18 - Print flights from status\n"
         << "19 - Delete Flights from status\n"
         << "20 - Update Flights manually\n"
         << "21 - Store data\n";
    cin >> choice;
    switch(choice) {
      case 0: break;
      case 1:
      {
              cout << "Please enter the name of the crew member: ";
              getline(cin, temp1);
              cout << "Please enter the ID of the crew member: ";
              cin >> num1;
              cout << "Please enter the status of the crew member: ";
              cin >> temp3;
              cout << "Please enter the type of the crew member: ";
              cin >> temp4;
              CrewMember newCrew;
              newCrew.setName(temp1);
              newCrew.setID(num1);
              newCrew.setStatus(temp3);
              newCrew.setType(temp4);
              if (!crewsList.addCrew(newCrew)) {
                cout << "Could not add crew member due to conflicting ID.\n";
              }
              break;
      }
      case 2:
      {
              cout << "Please enter the make of the plane: ";
              cin >> temp1;
              cout << "Please enter the tail number of the plane: ";
              cin >> temp2;
              cout << "Please enter the status of the plane: ";
              cin >> temp3;
              cout << "Please enter the model of the plane: ";
              cin >> num1;
              cout << "Please enter the number of seats of the plane: ";
              cin >> num2;
              cout << "Please enter the range of the plane: ";
              cin >> num3;
              Plane newPlane;
              newPlane.setMake(temp1);
              newPlane.setTail(temp2);
              newPlane.setStatus(temp3);
              newPlane.setModel(num1);
              newPlane.setSeats(num2);
              newPlane.setRange(num3);
              if(!planesList.addPlane(newPlane)) {
                cout << "Could not add plane due to conflicting tail numbers.\n";
              }
              break;
      }
      case 3:
      {
              cout << "Please enter the ID of the flight: ";
              cin >> num7;
              cout << "Please enter the tail mumber of the plane for the flight: ";
              cin >> temp1;
              cin.ignore();
              cout << "Please enter the starting port of the flight: ";
              getline(cin, temp2);
              cout << "Please enter the ending port of the flight: ";
              getline(cin, temp3);
              cout << "Please enter the status of the flight: ";
              cin >> temp4;
              cin.ignore();
              cout << "Please enter the starting time of the flight (ex. 6 December 2001 (hours):(minutes):(seconds)): ";
              getline(cin, temp5);
              cout << "Please enter the ending time of the flight: ";
              getline(cin, temp6);
              cout << "Please enter the pilot's ID: ";
              cin >> num1;
              cout << "Please enter the copilot's ID: ";
              cin >> num2;
              cout << "Please enter the first cabin crew member's ID: ";
              cin >> num3;
              cout << "Please enter the second cabin crew member's ID: ";
              cin >> num4;
              cout << "Please enter the third cabin crew member's ID: ";
              cin >> num5;
              cout << "Please enter the number of passengers for the flight: ";
              cin >> num6;
              for (int i = 0; i < ListFlights.flightList.size(); ++i) {
                if (ListFlights.flightList.at(i).getPlaneID() == temp1) {
                  flightCheck.push_back(i);
                }
                if (ListFlights.flightList.at(i).getPilot() == num1) {
                  flightCheck.push_back(i);
                }
                if (ListFlights.flightList.at(i).getCopilot() == num2) {
                  flightCheck.push_back(i);
                }
                if (ListFlights.flightList.at(i).getCabin1() == num3) {
                  flightCheck.push_back(i);
                }
                if (ListFlights.flightList.at(i).getCabin2() == num4) {
                  flightCheck.push_back(i);
                }
                if (ListFlights.flightList.at(i).getCabin3() == num5) {
                  flightCheck.push_back(i);
                }
              }
              locOfPlane = planesList.searchPlane(temp1);
              numberSeats = planesList.planeList.at(locOfPlane).getSeats();
              if (numberSeats < num6) {
                cout << "Too many passengers.\n";
                break;
              }
              for (int k = 0; k < flightCheck.size(); ++k) {
                strptime((ListFlights.flightList.at(flightCheck.at(k)).getStartTime()).c_str(), "%d %b %Y %H:%M:%S", &compareTime1);
                strptime(temp6.c_str(), "%d %b %Y %H:%M:%S", &compareTime2);
                strptime((ListFlights.flightList.at(flightCheck.at(k)).getEndTime()).c_str(), "%d %b %Y %H:%M:%S", &compareTime3);
                strptime(temp5.c_str(), "%d %b %Y %H:%M:%S", &compareTime4);
                time1 = mktime(&compareTime1);
                time2 = mktime(&compareTime2);
                time3 = mktime(&compareTime3);
                time4 = mktime(&compareTime4);

                test = difftime(time1, time2);
                if (test < 0) {
                  cout << "Invalid time slot.\n";
                  break;
                }
                test = difftime(time4, time3);
                if (test < 0) {
                  cout << "Invalid time slot.\n";
                  break;
                }
              }
              Flight newFlight;
              newFlight.setPlaneID(temp1);
              newFlight.setStartPort(temp2);
              newFlight.setEndPort(temp3);
              newFlight.setStatus(temp4);
              newFlight.setStartTime(temp5);
              newFlight.setEndTime(temp6);
              newFlight.setFlightID(num7);
              newFlight.setPilot(num1);
              newFlight.setCopilot(num2);
              newFlight.setCabin1(num3);
              newFlight.setCabin2(num4);
              newFlight.setCabin3(num5);
              newFlight.setNumPass(num6);
              ListFlights.addFlight(newFlight);
              break;
      }
      case 4:
      {
              cout << "Please enter the ID of the crew member you would like to delete: ";
              cin >> num1;
              if(!crewsList.deleteCrew(num1)) {
                cout << "Could not delete crew member due to invalid ID.\n";
              }
              break;
      }
      case 5:
      {
              cout << "Please enter the tail number of the plane you would like to delete: ";
              cin >> temp1;
              if (!planesList.deletePlane(temp1)) {
                cout << "Could not delete plane due to invalid tail number.\n";
              }
              break;
      }
      case 6:
      {
              cout << "Please enter the ID of the flight you would like to delete: ";
              cin >> num1;
              if (!ListFlights.deleteFlight(num1)) {
                cout << "Could not delete flight due to invalid ID.\n";
              }
              break;
      }
      case 7:
      {
              cout << "Please enter the ID of the crew member you would like to edit: ";
              cin >> num1;
              cout << "Please enter the new status of the crew member (enter a space to change nothing): ";
              cin >> temp1;
              cout << "Please enter the new type of the crew member (enter a space to change nothing): ";
              cin >> temp2;
              cout << "Please enter the new name of the crew member (enter a space to change nothing): ";
              cin >> temp3;
              CrewMember edited;
              edited.setID(num1);
              edited.setStatus(temp1);
              edited.setType(temp2);
              edited.setName(temp3);
              if(!crewsList.editCrew(edited)) {
                cout << "Could not edit due to invalid ID.\n";
              }
              break;
      }
      case 8:
      {
              cout << "Please enter the tail number of the plane you would like to edit: ";
              cin >> temp1;
              cout << "Please enter the new make of the plane (enter a space to change nothing): ";
              cin >> temp2;
              cout << "Please enter the new status of the plane (enter a space to change nothing): ";
              cin >> temp3;
              cout << "Please enter the new model of the plane (enter a 0 to change nothing): ";
              cin >> num1;
              cout << "Please enter the new number of seats of the plane (enter a 0 to change nothing): ";
              cin >> num2;
              cout << "Please enter the new range of the plane (enter a 0 to change nothing): ";
              cin >> num3;
              Plane edited;
              edited.setTail(temp1);
              edited.setMake(temp2);
              edited.setStatus(temp3);
              edited.setModel(num1);
              edited.setSeats(num2);
              edited.setRange(num3);
              if (!planesList.editPlane(edited)) {
                cout << "Could not edit due to invalid tail number.\n";
              }
              break;
      }
      case 9:
      {
              cout << "Please enter the flight ID of the flight you would like to edit: ";
              cin >> num1;
              cout << "Please enter the new plane's tail number: ";
              cin >> temp6;
              cin.ignore();
              cout << "Please enter the new starting port: ";
              getline(cin, temp1);
              cout << "Please enter the new ending port: ";
              getline(cin, temp2);
              cout << "Please enter the new status: ";
              getline(cin, temp3);
              cout << "Please enter the new starting time: ";
              getline(cin, temp4);
              cout << "Please enter the new ending time: ";
              getline(cin, temp5);
              cout << "Please enter the new pilot ID: ";
              cin >> num2;
              cout << "Please enter the new copilot ID: ";
              cin >> num3;
              cout << "Please enter the first new cabin crew: ";
              cin >> num4;
              cout << "Please enter the second new cabin crew: ";
              cin >> num5;
              cout << "Please enter the third new cabin crew: ";
              cin >> num6;
              cout << "Please enter the new number of passengers: ";
              cin >> num7;
              for (int i = 0; i < ListFlights.flightList.size(); ++i) {
                if (ListFlights.flightList.at(i).getPlaneID() == temp6) {
                  flightCheck.push_back(i);
                }
                if (ListFlights.flightList.at(i).getPilot() == num2) {
                  flightCheck.push_back(i);
                }
                if (ListFlights.flightList.at(i).getCopilot() == num3) {
                  flightCheck.push_back(i);
                }
                if (ListFlights.flightList.at(i).getCabin1() == num4) {
                  flightCheck.push_back(i);
                }
                if (ListFlights.flightList.at(i).getCabin2() == num5) {
                  flightCheck.push_back(i);
                }
                if (ListFlights.flightList.at(i).getCabin3() == num6) {
                  flightCheck.push_back(i);
                }
              }
              locOfPlane = planesList.searchPlane(temp1);
              numberSeats = planesList.planeList.at(locOfPlane).getSeats();
              if (numberSeats < num6) {
                cout << "Too many passengers.\n";
                break;
              }
              for (int k = 0; k < flightCheck.size(); ++k) {
                strptime((ListFlights.flightList.at(flightCheck.at(k)).getStartTime()).c_str(), "%d %b %Y %H:%M:%S", &compareTime1);
                strptime(temp6.c_str(), "%d %b %Y %H:%M:%S", &compareTime2);
                strptime((ListFlights.flightList.at(flightCheck.at(k)).getEndTime()).c_str(), "%d %b %Y %H:%M:%S", &compareTime3);
                strptime(temp5.c_str(), "%d %b %Y %H:%M:%S", &compareTime4);
                time1 = mktime(&compareTime1);
                time2 = mktime(&compareTime2);
                time3 = mktime(&compareTime3);
                time4 = mktime(&compareTime4);

                test = difftime(time1, time2);
                if (test < 0) {
                  cout << "Invalid time slot.\n";
                  break;
                }
                test = difftime(time4, time3);
                if (test < 0) {
                  cout << "Invalid time slot.\n";
                  break;
                }
              }
              Flight newFlight;
              newFlight.setPlaneID(temp1);
              newFlight.setStartPort(temp2);
              newFlight.setEndPort(temp3);
              newFlight.setStatus(temp4);
              newFlight.setStartTime(temp5);
              newFlight.setEndTime(temp6);
              newFlight.setFlightID(num7);
              newFlight.setPilot(num1);
              newFlight.setCopilot(num2);
              newFlight.setCabin1(num3);
              newFlight.setCabin2(num4);
              newFlight.setCabin3(num5);
              newFlight.setNumPass(num6);
              ListFlights.addFlight(newFlight);
              break;
      }
      case 10:
      {
              crewsList.printCrew();
              break;
      }
      case 11:
      {
              planesList.printPlanes();
              break;
      }
      case 12:
      {
              ListFlights.printFlights();
              break;
      }
      case 13:
      {
              cout << "Please enter the ID of the crew member: ";
              cin >> num1;
              if(!crewsList.printEntry(num1)) {
                cout << "Invalid ID.\n";
              }
              break;
      }
      case 14:
      {
              cout << "Please enter the tail number of the plane: ";
              cin >> temp1;
              if(!planesList.printEntry(temp1)) {
                cout << "Invald tail number.\n";
              }
              break;
      }
      case 15:
      {
              cout << "Please enter the ID of the flight: ";
              cin >> num1;
              if(!ListFlights.printEntry(num1)) {
                cout << "Invalid ID.\n";
              }
              break;
      }
      case 16:
      {
              cout << "Please enter the tail number of the plane: ";
              cin >> temp1;
              num1 = ListFlights.printFlightsAssignment(temp1);
              cout << "Plane has " << num1 << " assignments.\n";
              break;
      }
      case 17:
      {
              cout << "Please enter the ID of the crew member: ";
              cin >> num1;
              num2 = ListFlights.printCrewAssignment(num1);
              cout << "Crew member has " << num2 << " assignments.\n";
              break;
      }
      case 18:
      {
              cout << "Please enter the exact status you want to find: ";
              cin >> temp1;
              num1 = ListFlights.printFlightStatus(temp1);
              cout << "There are " << num1 << " flights with that status.\n";
              break;
      }
      case 19:
      {
              cout << "Please enter the exact status you want to remove: ";
              cin >> temp1;
              num1 = ListFlights.deleteFlightStatus(temp1);
              cout << "Deleted " << num1 << " flights with status " << temp1 << ".\n";
              break;
      }
      case 20:
      {
              ListFlights.updateFlights();
              cout << "Flights updated.\n";
              break;
      }
      case 21:
      {
        savedata(crewsList);
        break;
      }
      default:
              cout << "Incorrect input. Please input a valid number.\n";
    }
  }
}

void savedata(Crew crewsList) {
  ofstream output;
  output.open("data.txt");
  if (output.fail()) {
    cout << "Failed to open stream. Ending program.";
    exit(EXIT_FAILURE);
  }
  output << crewsList.crewList.size() << endl;
  for (int i = 0; i < crewsList.crewList.size(); ++i) {
    output << crewsList.crewList.at(i).getName() << endl;
    output << crewsList.crewList.at(i).getType() << endl;
    output << crewsList.crewList.at(i).getStatus() << endl;
    output << crewsList.crewList.at(i).getID() << endl;
  }
}
