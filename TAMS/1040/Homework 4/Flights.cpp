#include "Flights.h"
using namespace std;

int Flights::searchFlights(int flightID) {
  for(int i = 0; i < flightList.size(); ++i){
    if(flightList.at(i).getFlightID() == flightID) {
      return i;
    }
  }
  return -1;
}
void Flights::addFlight(Flight newFlight) {
  updateFlights(); //just in case the loop didn't get one in time
  flightList.push_back(newFlight);
}
bool Flights::editFlight(Flight edited) {
  string planeID, startPort, endPort, status, startTime, endTime;
  int pilot, copilot, cabin1, cabin2, cabin3, numPass, flightID;
  int flightIterator = searchFlights(edited.getFlightID());
  if (flightIterator == -1) {
    return false;
  }
  else {
    if (edited.getPlaneID() != " ") {
      flightList.at(flightIterator).setPlaneID(edited.getPlaneID());
    }
    if (edited.getStartPort() != " ") {
      flightList.at(flightIterator).setStartPort(edited.getStartPort());
    }
    if (edited.getEndPort() != " ") {
      flightList.at(flightIterator).setEndPort(edited.getEndPort());
    }
    if (edited.getStatus() != " ") {
      flightList.at(flightIterator).setStatus(edited.getStatus());
    }
    if (edited.getStartTime() != " ") {
      flightList.at(flightIterator).setStartTime(edited.getStartTime());
    }
    if (edited.getEndTime() != " ") {
      flightList.at(flightIterator).setEndTime(edited.getEndTime());
    }
    if (edited.getPilot() != 0) {
      flightList.at(flightIterator).setPilot(edited.getPilot());
    }
    if (edited.getCopilot() != 0) {
      flightList.at(flightIterator).setCopilot(edited.getCopilot());
    }
    if (edited.getCabin1() != 0) {
      flightList.at(flightIterator).setCabin1(edited.getCabin1());
    }
    if (edited.getCabin2() != 0) {
      flightList.at(flightIterator).setCabin2(edited.getCabin2());
    }
    if (edited.getCabin3() != 0) {
      flightList.at(flightIterator).setCabin3(edited.getCabin3());
    }
    if (edited.getNumPass() != 0) {
      flightList.at(flightIterator).setNumPass(edited.getNumPass());
    }
  }
}
bool Flights::deleteFlight(int flightID) {
  int flightIterator = searchFlights(flightID);
  if (flightIterator == -1) {
    return false;
  }
  else {
    flightList.erase(flightList.begin() + flightIterator);
    return true;
  }
}
void Flights::printFlights() {
  for (int i = 0; i < flightList.size(); ++i) {
    cout << flightList.at(i).getFlightID() << endl;
  }
}
bool Flights::printEntry(int flightID) {
  int flightIterator = searchFlights(flightID);
  if (flightIterator == -1) {
    return false;
  }
  else {
    cout << flightList.at(flightIterator).getPlaneID() << endl;
    cout << flightList.at(flightIterator).getStartPort() << endl;
    cout << flightList.at(flightIterator).getEndPort() << endl;
    cout << flightList.at(flightIterator).getStatus() << endl;
    cout << flightList.at(flightIterator).getStartTime() << endl;
    cout << flightList.at(flightIterator).getEndTime() << endl;
    cout << flightList.at(flightIterator).getPilot() << endl;
    cout << flightList.at(flightIterator).getCopilot() << endl;
    cout << flightList.at(flightIterator).getCabin1() << endl;
    cout << flightList.at(flightIterator).getCabin2() << endl;
    cout << flightList.at(flightIterator).getCabin3() << endl;
    cout << flightList.at(flightIterator).getNumPass() << endl;
    cout << flightList.at(flightIterator).getFlightID() << endl;
    return true;
  }
}
int Flights::printFlightsAssignment(string planeID) {
  int check = 0;
  for (int i = 0; i < flightList.size(); ++i) {
    if (flightList.at(i).getPlaneID() == planeID) {
      if (flightList.at(i).getStatus() == "Active") {
        cout << "Leaving " << flightList.at(i).getStartPort() << " at " << flightList.at(i).getStartTime() << endl;
        cout << "Arriving at " << flightList.at(i).getEndPort() << " at " << flightList.at(i).getEndTime() << endl << endl;
        ++check; //will print out how many assignments were printed using check
      }
    }
  }
  return check;
}
int Flights::printCrewAssignment(int crewID) {
  int check = 0;
  for (int i = 0; i < flightList.size(); ++i) {
    if (flightList.at(i).getPilot() == crewID) {
      if (flightList.at(i).getStatus() == "Active") {
        cout << "Crew member is leaving " << flightList.at(i).getStartPort() << " at " << flightList.at(i).getStartTime() << endl;
        cout << "Arriving at " << flightList.at(i).getEndPort() << " at " << flightList.at(i).getEndTime() << endl << endl;
        ++check; //will print out how many assignments were printed using check
      }
    }
    if (flightList.at(i).getCopilot() == crewID) {
      if (flightList.at(i).getStatus() == "Active") {
        cout << "Crew member is leaving " << flightList.at(i).getStartPort() << " at " << flightList.at(i).getStartTime() << endl;
        cout << "Arriving at " << flightList.at(i).getEndPort() << " at " << flightList.at(i).getEndTime() << endl << endl;
        ++check; //will print out how many assignments were printed using check
      }
    }
    if (flightList.at(i).getCabin1() == crewID) {
      if (flightList.at(i).getStatus() == "Active") {
        cout << "Crew member is leaving " << flightList.at(i).getStartPort() << " at " << flightList.at(i).getStartTime() << endl;
        cout << "Arriving at " << flightList.at(i).getEndPort() << " at " << flightList.at(i).getEndTime() << endl << endl;
        ++check; //will print out how many assignments were printed using check
      }
    }
    if (flightList.at(i).getCabin2() == crewID) {
      if (flightList.at(i).getStatus() == "Active") {
        cout << "Crew member is leaving " << flightList.at(i).getStartPort() << " at " << flightList.at(i).getStartTime() << endl;
        cout << "Arriving at " << flightList.at(i).getEndPort() << " at " << flightList.at(i).getEndTime() << endl << endl;
        ++check; //will print out how many assignments were printed using check
      }
    }
    if (flightList.at(i).getCabin3() == crewID) {
      if (flightList.at(i).getStatus() == "Active") {
        cout << "Crew member is leaving " << flightList.at(i).getStartPort() << " at " << flightList.at(i).getStartTime() << endl;
        cout << "Arriving at " << flightList.at(i).getEndPort() << " at " << flightList.at(i).getEndTime() << endl << endl;
        ++check; //will print out how many assignments were printed using check
      }
    }
  }
  return check;
}
int Flights::printFlightStatus(string compareStatus) {
  int check = 0;
  for (int i = 0; i < flightList.size(); ++i) {
    if (flightList.at(i).getStatus() == compareStatus) {
      cout << flightList.at(i).getFlightID() << endl;
      ++check;
    }
  }
  return check;
}
int Flights::deleteFlightStatus(string conStatus) {
  int check = 0;
  int newSize = flightList.size();
  //something that can be adjusted in the middle of the loop
  //loop might automatically do this but using new variable for insurance
  for (int i = 0; i < newSize; ++i) {
    if (flightList.at(i).getStatus() == conStatus) {
      flightList.erase(flightList.begin() + i);
      i--;
      /*cancel iterator to make sure that the flight that fills in the hole
      is checked too*/
      ++check;
    }
  }
  return check;
}
void Flights::updateFlights() {
  unsigned long int now = time(0);

  tm flightTime;
  time_t compareFlight;
  memset(&flightTime, 0, sizeof(tm));
  for (int i = 0; i < flightList.size(); ++i) {
    strptime(flightList.at(i).getEndTime().c_str(), "%d %b %Y %H:%M:%S", &flightTime);
    compareFlight = mktime(&flightTime);
    if ((compareFlight <= now) && (flightList.at(i).getStatus() == "Active")) {
      flightList.at(i).setStatus("Completed");
    }
  }
}
