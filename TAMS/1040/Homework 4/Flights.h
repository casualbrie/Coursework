#include "Flight.h"
#include <ctime>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Flights {
public:
  int searchFlights(int flightID);
  void addFlight(Flight newFlight);
  bool editFlight(Flight edited);
  bool deleteFlight(int flightID);
  void printFlights();
  bool printEntry(int flightID);
  int printFlightsAssignment(string planeID);
  int printCrewAssignment(int crewID);
  int printFlightStatus(string compareStatus);
  int deleteFlightStatus(string conStatus);
  void updateFlights();
  vector<Flight> flightList;
};
