 #include <vector>
 #include <iostream>
 #include <cstdlib>
 #include <fstream>
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
   void storePlanes();
   void loadPlanes();
   vector<Plane> planeList;
 };
