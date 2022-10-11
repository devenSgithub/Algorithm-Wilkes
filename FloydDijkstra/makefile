
CFLAGS = -c -Wall -g
LFLAGS = -g -o assign2

assign2: assign2.o shortest.o
	g++ assign2.o shortest.o $(LFLAGS)

assign2.o: assign2.cpp shortest.h
	g++ $(CFLAGS) assign2.cpp

shortest.o: shortest.cpp shortest.h
	g++ $(CFLAGS) shortest.cpp

clean:
	rm -f assign2 *.o *~ *#
