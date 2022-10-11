
//
//ss.cpp
// Deven Schwartz
// 11/9/2021
// Project 3: Sum-of-Subsets
// Assigment 3: Backtracking: Solve the Sum of Subsets Problem
// Description: takes a file with input to preform sumofsubsets algorithm.
// Flow: Program takes user input and preforms the sum of subsets algorithim on it.
// References: Book for algorithims: Foundations of Algorithms by Richard Neampolitan and Kumarss Naimipour
// Assistance: Dr. Bracken for problems/errors
//
//Testing: I have tested my code and have errors that I have not fixed.   
//1.) not sure if the output for 1-i loop is exactly what you wanted 
//2.) adding to the promising count is done inside the promising function call 
//(not sure if you wanted it there or outside of the call)

//Time: ~2 hours. Not sure on the exact time spent

//include files
#include<cassert>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//only global variable for counting number of promising calculations
int Global_Promising_Count = 0;


//promising function
bool promising(int i, int weight, int total, int W, int w[]){

    //increment count and return check value
    Global_Promising_Count++;
    return (weight + total >= W) && (weight == W || weight + w[i+1] <= W);
}


//sum of subsets function
void sum_of_subsets(int i, int weight, int total, int W, int include[] , int w[] ){

    //check if promising
    if(promising(i, weight, total, W, w)){
        //if valid check if a solution is found
        if(weight == W){
            //if found print out message 
            cout<<"Solution found. Include array:"<<endl;
            for(int j = 1; j<i+1; j++){
                cout<<include[j]<<endl;
                if(include[j] == 1){
                    cout<<"Value = "<<w[j]<<endl;
                }
            }
            
        }else{
            //otherwise check with and without next value
            include[i + 1] = 1;
            sum_of_subsets(i+1, weight+w[i+1], total - w[i+1], W, include, w);
            include[i+1] = 0;
            sum_of_subsets(i+1, weight, total - w[i+1], W, include, w);
        }
    }

}//sum of subsets function end



int main(){

    //common output
    cout<<"Deven Schwartz"<<endl;
    cout<<"Assignment 3: Sum-of-Subsets"<<endl;
    cout<<"Takes an input file and preforms the sum of subsets algorithm.\n"<<endl;
    //

    //get a file from user 
    string fn;
    cout<<"Enter the name of a file containing the data"<<endl;

    // check for valid input have user reenter until a valid input is accepted
    while(true){
        
        cin >> fn;
        if(cin.good()){
            break;
        }else{
            cout<<"You entered invalid input, reenter a file name \n";
            cin.clear();
            cin.ignore(120,'\n');
        }

    }

    cout << "You entered: " << fn << endl;

    //vars needed
    int data;
    int count = 1;
    int n = 0;
    int W = 0;
    //flag for empty file case
    bool emptycase = true;
    //open file and check to make sure opened correctly
    ifstream fin;
    fin.open(fn.c_str());
    assert (fin.is_open());

    // get n
    while (true){

        fin>>data;
        if (fin.eof() || !fin.good() || count == 2){
            if(count == 1){
                //set flag
                emptycase = true;
                cout<<"The file is empty."<<endl;
            }
            break;
        }
        if(count == 1){
            cout<<"Got n from the file: " << data <<endl;
            //set flag/n and inc cnt 
            emptycase = false;
            count++;
            n = data;
        }
    }

    //if empty file can exit here to avoid doing everthing else
    if(emptycase){
        exit(-1);
    }

    //create w and include 
        cout<<"Creating include and w array if file not enpty"<<endl;
        int include[n + 1];
        int w[n + 1];
    
    //get the rest of data from the file
    while (!emptycase){
        //gets next value from last loop if not an empty file 
        if(count == 2){
            cout<<"Got W from the file: " << data <<endl;
            W = data;
            count++;
        }

        fin>>data;
        //check for valid data and eof
        if (fin.eof() || !fin.good()){
            break;
        }

        //can assume this data is good
        cout<<"Got a number from the file: "<< data <<endl;
        w[count - 2] = data;
        count++;
    
    }
    //initilize total
    int total = 0;

    //testing
    //cout<<"n: "<<n<<"   W: "<<W <<"   Array w:"<<endl;
    //initilize include[n] and total
    for(int i = 1; i<n+1; i++){
        total = total + w[i];
        include[i] = 0;
        //test
        //cout<<w[i]<<endl;
    }

    //message parameters being used and call sum_of_subsets
    cout<<"Calling sum of subsets"<<endl;
    cout<<"Parameters i = "<<0<<" weight = "<<0<< " total = "<<total<<" W = "<<W<<" include: "<<endl;
    for(int i = 1; i<n+1; i++){
        cout<<include[i]<<endl;
    }
    cout<<"w: "<<endl;
    for(int i = 1; i<n+1; i++){
        cout<<w[i]<<endl;
    }
    cout<<"\n";
    sum_of_subsets(0,0,total,W,include,w);

    //print number of promising calculations
    cout<<"\nNumber of Promising calculations: "<< Global_Promising_Count <<endl;

}


