
CFLAGS = -c -Wall -g
LFLAGS = -g -o driver

driver: driver.o plane.o
	g++ driver.o plane.o $(LFLAGS)

driver.o: driver.cpp plane.h
	g++ $(CFLAGS) driver.cpp

plane.o: plane.cpp plane.h
	g++ $(CFLAGS) plane.cpp

clean:
	rm -f driver *.o *~ *#
