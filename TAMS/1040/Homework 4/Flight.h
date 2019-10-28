#include <string>
using namespace std;

class Flight {
public:
  string getPlaneID();
  string getStartPort();
  string getEndPort();
  string getStatus();
  string getStartTime();
  string getEndTime();
  int getPilot();
  int getCopilot();
  int getCabin1();
  int getCabin2();
  int getCabin3();
  int getNumPass();
  int getFlightID();
  void setPlaneID(string newID);
  void setStartPort(string newStart);
  void setEndPort(string newEnd);
  void setStatus(string newStatus);
  void setStartTime(string newStart);
  void setEndTime(string newEnd);
  void setPilot(int newPilot);
  void setCopilot(int newCopilot);
  void setCabin1(int newCabin1);
  void setCabin2(int newCabin2);
  void setCabin3(int newCabin3);
  void setNumPass(int newNum);
  void setFlightID(int newID);
  Flight();
private:
  string planeID, startPort, endPort, status, startTime, endTime;
  int pilot, copilot, cabin1, cabin2, cabin3, numPass, flightID;
};
