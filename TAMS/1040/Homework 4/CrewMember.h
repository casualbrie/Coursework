#include <string>
using namespace std;

class CrewMember {
public:
  string getName();
  string getType();
  string getStatus();
  int getID();
  void setName(string newName);
  void setType(string newType);
  void setStatus(string newStatus);
  void setID(int newID);
  CrewMember();
private:
  string name, type, status;
  int id;
};
