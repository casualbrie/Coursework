MGA: main.o Crew.o CrewMember.o Flight.o Flights.o Plane.o Planes.o
	g++ -o MGA main.o Crew.o CrewMember.o Flight.o Flights.o Plane.o Planes.o
main.o: main.cpp Crew.h Planes.h Flights.h
	g++ -c main.cpp
Crew.o: Crew.cpp Crew.h
	g++ -c Crew.cpp
CrewMember.o: CrewMember.cpp CrewMember.h
	g++ -c CrewMember.cpp
Planes.o: Planes.h Planes.cpp
	g++ -c Planes.cpp
Plane.o: Plane.h Plane.cpp
	g++ -c Plane.cpp
Flights.o: Flights.h Flights.cpp
	g++ -c Flights.cpp
Flight.o: Flight.h Flight.cpp
	g++ -c Flight.cpp
clean: 
	rm *.o
	rm MGA
