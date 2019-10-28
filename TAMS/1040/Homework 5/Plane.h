#include <string>
using namespace std;

class Plane {
public:
  string getMake();
  string getTail();
  string getStatus();
  int getModel();
  int getSeats();
  int getRange();
  void setMake(string newMake);
  void setTail(string newTail);
  void setStatus(string newStatus);
  void setModel(int newModel);
  void setSeats(int newSeats);
  void setRange(int newRange);
  Plane();
private:
  string make, tail, status;
  int model, seats, range;
};
