//driver.cpp


//
// driver.cpp
// Deven Schwartz
// 9/29/2021
// Project 1: Divide and Conquer
// Assigment 1: Find the closest pair of points in a plane in O(nlgn) time 	
// Description: Useses mergesort to find the closest pair of points from an array of points.
// Flow: Program prints the unsorted array of points then sorts on the x points, finds a min distance point then 
//sorts on the y and finds the correct min distance .
// References: Algorithms in C++, by Robert Sedgewick
// Assistance: Dr. Bracken for problems/errors
//
//Testing: I have tested my code and have errors that I have not fixed.   
//1.) Distance calculation are being done too many time but answers are almost always correct.


//Time: ~5 hours. Not sure on the exact time spent


#include "plane.h"
#include <iostream>
int main()
{


    //common output
    cout<<"Deven Schwartz"<<endl;
    cout<<"Assignment 1: Divide and Conquer"<<endl;
    cout<<"Takes points from a file and finds the closest pair.\n"<<endl;
    //

        
    plane myplane;
    myplane.printpoints();
    myplane.findclosest();
    cout<<"Exiting"<<endl;
}//end of main