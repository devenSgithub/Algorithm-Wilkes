
//assign2.cpp
// Deven Schwartz
// 10//2021
// Project 2:Shortest Pair
// Assigment 2: Shortest Pair
// Description: user provide a graph and can then preform floyd or dijkstra until they exit
// Flow: Program creates a graph and preforms floyd and dijkstra on it
// References: Book for algorithims: Foundations of Algorithms by Richard Neampolitan and Kumarss Naimipour
// Assistance: Dr. Bracken for problems/errors
//
//Testing: I have tested my code and have errors that I have not fixed.   
//1.) incorrect dijkstra output for some cases 


//Time: ~4 hours. Not sure on the exact time spent


#include "shortest.h"
#include <iostream>
int main()
{


    //common output
    cout<<"Deven Schwartz"<<endl;
    cout<<"Assignment 2: Shortest Pair"<<endl;
    cout<<"Uses Dijkstra's and Floyd's algorithm to solve the shortest path problem.\n"<<endl;
    //

    shortest mygraph;


  char input;  
  //loop menu until exited by user
  while(input != '3'){

    cout << " \nEnter: " << endl; 
    cout << "   1 for Dijkstra. " << endl; 
    cout << "   2 for Floyd. " << endl;  
    cout << "   3 to exit the menu. " << endl; 
    
    cin >> input;

    cout << "	\nYou entered: " << input << endl; 

    //switch to handle the input chocies 
    switch(input)
    {
    
    case '1': 
      cout << "Dijkstra" << endl;

      cout << "Enter a starting vertex: " << endl;
      int infind;
      

      // check for valid input have user reenter until a valid input is accepted
      while(true){
      
        cin >> infind;
        if(cin.good()){
          break;
        }else{
          cout<<"You entered invalid input, reenter an integer \n";
          cin.clear();
          cin.ignore(120,'\n');
        }

      
      }

      cout << "You entered: " << infind << endl ;
      //call Dijkstra
      mygraph.dijkstra(infind);

      cout<<"\nReturning to menu selection"<<endl;
      break; 
    


    case '2': //Floyd
      cout << "Floyd" << endl;
      mygraph.floyd2();

      cout<<"\nReturning to menu selection"<<endl;
      break;
    


    case '3': //calls display siblings
      //exit case
      cout << "(Exiting the menu.)" << endl; 
      cout<<"-Goodbye-" << endl;
      break;
    
    
    default:
      cout << "Invalid Selection. Please Enter Again." << endl; 
    }//switch end

  }
    
    





    cout<<"Exiting"<<endl;
}//end of main