//plane.h


#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

#define MAXPOINTS 200
struct point{
    float x;
    float y;
};

class plane{
    public:
        plane();
        ~plane();
        void printpoints();  //display the xy coordinates of all points in plane
        void findclosest(); //prints the xy coordinates of the 2 closest points 

    private:
        void mergesort (int n,struct point S[]);
        void merge(int h, int m, struct point U[],struct point V[], struct point S[]);
        //define any other private functions needed
        //the private data;
        struct point ThePlane[MAXPOINTS];
        int NoPoints; 
        int pass;   //pass =1 sort on x pass = 2 sort on y
        float min; //minimum distance so far
        point cp1; //closest points so far
        point cp2; //closest points so far
        float middleValue = 0.0;
        int calculationsDone = 0;
};



