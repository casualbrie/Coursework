db: database.o bubble.o bSearch.o set.o stack.o parse.o db.o
	gcc -o db database.o bubble.o bSearch.o set.o stack.o parse.o db.o
db.o: db.h db.c defs.h
	gcc -c db.c
database.o: defs.h database.c parse.h
	gcc -c database.c
bubble.o: bubble.c defs.h 
	gcc -c bubble.c
bSearch.o: bSearch.c defs.h sortAndSearch.h 
	gcc -c bSearch.c
set.o: set.h set.c db.h
	gcc -c set.c
stack.o: stack.c stack.h
	gcc -c stack.c
parse.o: parse.c parse.h 
	gcc -c parse.c 
run:
	./db < data
clean:
	@rm -f *.o
