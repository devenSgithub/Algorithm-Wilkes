//shortest.h

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

#define INFINITYVALUE 1000000

struct edgenode {
    int e1;
    int e2;
    edgenode *next;
}; 

class shortest{
    public:
        shortest();
        ~shortest();
        void dijkstra(int V);
        void floyd2();

        //void printpoints();  //display the xy coordinates of all points in plane
        //void findclosest(); //prints the xy coordinates of the 2 closest points 

    private:
        int **W;
        int **P;
        int **D;
        int numberOfVertices;
        void path (int q, int r);
        //void merge(int h, int m, struct point U[],struct point V[], struct point S[]);
        //define any other private functions needed
        //the private data;
        //struct point ThePlane[MAXPOINTS];
        //int NoPoints; 
        //int pass;   //pass =1 sort on x pass = 2 sort on y
        //float min; //minimum distance so far
        //point cp1; //closest points so far
        //point cp2; //closest points so far
        //float middleValue = 0.0;
        //int calculationsDone = 0;
};


