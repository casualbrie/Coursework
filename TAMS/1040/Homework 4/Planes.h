 #include <vector>
 #include <iostream>
 #include "Plane.h"
 using namespace std;

 class Planes {
 public:
   int searchPlane(string planeNum);
   bool addPlane(Plane newPlane);
   bool editPlane(Plane edited);
   bool deletePlane(string planeNum);
   void printPlanes();
   bool printEntry(string planeID);
   vector<Plane> planeList;
 };
