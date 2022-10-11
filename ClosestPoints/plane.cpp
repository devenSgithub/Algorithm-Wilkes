//plane.cpp

#include "plane.h"
#include <cassert>


plane::plane(){ 
    
    //ask for the file
    cout << "Enter a file name with the points to create the plane: " << endl;
    string file;

    // check for valid input have user reenter until a valid input is accepted
    while(true){
      
      cin >> file;
      if(cin.good()){
        break;
      }else{
        cout<<"You entered invalid input, reenter a file name \n";
        cin.clear();
        cin.ignore(120,'\n');
      }

    }
    //echo input
    cout << "You entered: " << file << endl;

    //set up to read in data from file
    float data;
    ifstream fin;
    fin.open(file.c_str());
    assert (fin.is_open());
    //vars set to count
    int count = 1;
    float tempx = 0.0;
    NoPoints = 0;

    //read until file empty (assume data is good)
    while (true){

        fin>>data;
            if (fin.eof()){
            break;
        }
           
        //count used to determine if x or y
        if(count == 1){
            //point set has been entered so increment NoPoints
            NoPoints++;
            //store x until y is read in
            tempx = data;
            //cout<<"enter X data   "<<tempx<<"   #of pts"<<NoPoints<<endl;//testing
            //count used to determine if x or y value
            count++;
        }else{
            //cout<<"enter Y data "<<data<<endl;
            //create a temp point to save x and y
            point temp;
                
            //set the temp x and y to the invalues from the file
            temp.x = tempx;
            temp.y = data;
            //cout<<"In temp: "<<temp.x << "  "<< temp.y<<endl;//testing

            //store temp to the correct position in the array
            ThePlane[NoPoints - 1] = temp;
            count--;
            //cout<<"point: "<< ThePlane[NoPoints - 1].x<<ThePlane[NoPoints - 1].y<<endl;//testing
        }//(if-else not necessary) (change if time later)
            
    }


}


plane::~plane(){



}

void plane::printpoints(){

    //loops through ThePlane printing each point until it reaches the end
    cout<<"Printing the points."<<endl;
    for (int i = 0; i < NoPoints; i++){
        
        cout <<"Point "<<i+1<<": X = "<<ThePlane[i].x<<", Y = "<<ThePlane[i].y<< endl;
        
    }
    

}//end printpoints






void plane::findclosest(){


    pass = 1;
    min = INFINITY;
    mergesort(NoPoints, ThePlane);
    cout<<"\nPrinting points sorted on the X: \n"<<endl;
    printpoints();
    //get a min from the two sets of points from the sorted x
    //preset point data
    cp1.x = INFINITY;
    cp2.x = INFINITY;
    cp1.y = INFINITY;
    cp2.y = INFINITY;
    calculationsDone = 0;

    //change pass and sort on y
    pass = 2;
    mergesort(NoPoints, ThePlane);
    cout<<"\nPrinting points sorted on the Y: \n"<<endl;
    printpoints();
    //print out min, closest pair, and calculations
    cout<<"\nminimun = "<< min <<endl;
    cout<<"closest pair is p1x: "<< cp1.x<<", p1y: "<<cp1.y <<" and p2x: " <<cp2.x<<", p2y: "<<cp2.y<<endl;
    cout<<"Distance calculations = "<< calculationsDone <<endl;


}





void plane::mergesort (int n,struct  point *S){

    //n is the number of elements in the array S

    if(n>1){
        int h = n/2;
        //cout<<"h var: "<<h<<endl;
        int m = n-h;
        //cout<<"m var: "<<m<<endl;

        //move 0 -> n/2 into array U
        point U[h];
        for (int i = 0; i < h; i++){    
            U[i] = S[i];     
        }

        if(pass == 2){
            //update the middle value
            middleValue = S[n/2].x;
        }

        //move n/2 -> n into V
        point V[m];
        for (int i = h; i < n; i++){
            V[i-h] = S[i];
        }

        mergesort(h,U);
        mergesort(m,V);
        merge(h,m,U,V,S);

        //for second pass
        if(pass == 2){
            //create 4 points and set to inifinity
            point p1;
            point p2;
            point p3;
            point p4;
            p1.x=p2.x=p3.x=p4.x=INFINITY;
            p1.y=p2.y=p3.y=p4.y=INFINITY;

            //cout<<"in pass 2"<<endl;
            
            //loop through the array 
            for (int i = 0; i < NoPoints; i++){
            
                //check if i is a viable point(less then min from midpoint) and run calculations 
                float distance = S[i].x - middleValue;
                if(abs(distance) < min){   
                    // calculate the distance between each point

                    //add 1 to keep track of number of times calculations are done
                    calculationsDone = calculationsDone + 1;

                    //calculation for p1
                    //only check values if p is not infinity
                    if(p1.x != INFINITY){
                        float dx = ThePlane[i].x - p1.x;
                        float dy = ThePlane[i].y - p1.y;
                        float tempmin = sqrt(dx*dx + dy*dy);
                        //cout<<"calculating"<<endl;
                        if (tempmin < min){
                            //change min if needed
                            min = tempmin;
                            cp1 = ThePlane[i];
                            cp2 = p1;
                        }
                    }

                    if(p2.x != INFINITY){
                        //calculation for p2
                        float dx = ThePlane[i].x - p2.x;
                        float dy = ThePlane[i].y - p2.y;
                        float tempmin = sqrt(dx*dx + dy*dy);
                        //cout<<"calculating"<<endl;
                        if (tempmin < min){
                            //change min if needed
                            min = tempmin;
                          
                            cp1 = ThePlane[i];
                            cp2 = p2;
                        }
                    }

                    if(p3.x != INFINITY){
                        //calculation for p3
                        float dx = ThePlane[i].x - p3.x;
                        float dy = ThePlane[i].y - p3.y;
                        float tempmin = sqrt(dx*dx + dy*dy);
                        if (tempmin < min){
                            //change min if needed
                            min = tempmin;
                        
                            cp1 = ThePlane[i];
                            cp2 = p3;
                        }
                    }

                    if(p4.x != INFINITY){
                        //calculation for p4
                        float dx = ThePlane[i].x - p4.x;
                        float dy = ThePlane[i].y - p4.y;
                        float tempmin = sqrt(dx*dx + dy*dy);
                        //cout<<"calculating"<<endl;
                        if (tempmin < min){
                            //change min if needed
                            //cout <<"new min has been found in p4"<<endl;
                            //cout<<tempmin<<endl;
                            min = tempmin;

                            cp1 = ThePlane[i];
                            cp2 = p4;
                        }
                    }

                    //set p to next p// p4 to next in array
                    //cout<<"p is less then min"<<endl;
                    p1 = p2;
                    p2 = p3;
                    p3 = p4;
                    p4 = ThePlane[i];
                }//end of if dis < min
                
                    
            
            }// end of loop
        }//end of if pass = 2


    }

}//end merge sort
 


void plane::merge(int h, int m, struct point *U, struct point *V, struct point *S){

    //cout<<"in here"<<endl;
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < h && j < m){
        if(pass == 1){
            //if pass is 1 then sort on the x 
            if(U[i].x < V[j].x){
                S[k] = U[i];
                //cout<<"INSIDE MERGE if less U: "<<U[i].x<<"         "<<U[i].y<<endl;
                i++;
            }else{
                S[k] = V[j];
                //cout<<"INSIDE MERGE if great U: "<<V[j].x<<"         "<<V[j].y<<endl;
                j++;
            }
            k++;
        }else{
            //otherwise do the same sort on the y
            if(U[i].y < V[j].y){
                S[k] = U[i];
                //cout<<"INSIDE MERGE if less U: "<<U[i].x<<"         "<<U[i].y<<endl;
                i++;
            }else{
                S[k] = V[j];
                //cout<<"INSIDE MERGE if great U: "<<V[j].x<<"         "<<V[j].y<<endl;
                j++;
            }
            k++;
        }
    }
    //clean up the array that is left with stuff in it
    if(i>=h){
        for (int x= j; x < m; x++){
            S[k] = V[x];
            //cout<<"INSIDE MERGE V elements left: "<<V[x].x<<"         "<<V[x].y<<endl;

            k++;
        
        }

    }else{
        for (int x = i; x < h; x++){
            S[k] = U[x];
            //cout<<"INSIDE MERGE U elements left: "<<U[x].x<<"         "<<U[x].y<<endl;
            k++;
        
        }
    }


  
}//end merge
