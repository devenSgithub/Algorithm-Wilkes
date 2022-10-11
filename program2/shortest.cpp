//shortest.cpp

#include "shortest.h"
#include <cassert>


shortest::shortest(){ 
    
    cout<<"creating graph"<<endl;

    int n;
      
    cout << "Enter the number of vertices: " << endl;
      
    // check for valid input have user reenter until a valid input is accepted
    while(true){
      
        cin >> n;
        if(cin.good() && n >= 0){
            break;
        }else{
            cout<<"You entered invalid input, reenter an integer \n";
            cin.clear();
            cin.ignore(120,'\n');
        }

    }

    cout << "You entered: " << n << endl;
    numberOfVertices = n;
    //set up arrays W, P, and D
    W = new int*[n];
    for(int i=1; i < n+1; i++){
        W[i]=new int[n];
    }

    P = new int*[n];
    for(int i=1; i < n+1; i++){
        P[i]=new int[n];
    }

    D = new int*[n];
    for(int i=1; i < n+1; i++){
        D[i]=new int[n];
    }
    
    //set values for the weights of W
    for(int i=1; i <= n; i++){
        for(int j=1; j <= n; j++){
            //all to infinty
            W[i][j] = INFINITYVALUE;
        }
        //diagonal are set to 0
        W[i][i] = 0;
    }

    char input;  
    //loop question until exited by user(checks for n y Y N)
    while(input != 'N' && input !='n'){

        cout << " Do you have an edge to enter? Enter: " << endl; 
        cout << "Y for yes. " << endl; 
        cout << "N for no. " << endl; 
           
        cin >> input;
        cout << "	\nYou entered: " << input << endl; 

        //switch to handle the input chocies 
        switch(input){
        
        case 'Y': 
            cout << "Adding an edge." << endl;
            //Prompt the user first for the first node in the edge, n1, and then the second node in the edge, n2.
            //Prompt user for the cost of the edge
            //Add weight to correct spot in W: W[n1][n2] = cost
            
            // get the first node
            cout << "Enter the first node in the edge (from 1 to "<< n << "): " << endl;
            int n1;

            // check for valid input have user reenter until a valid input is accepted
            while(true){
                cin >> n1;
                if(cin.good() && n1 < n+1){
                    break;
                }else{
                    cout<<"You entered invalid input, reenter an integer \n";
                    cin.clear();
                    cin.ignore(120,'\n');
                }
            }

            cout << "You entered: " << n1 << endl ;

            //get the second node
            cout << "Enter the second node in the edge (from 1 to "<< n << "): " << endl;
            int n2;

            // check for valid input have user reenter until a valid input is accepted
            while(true){
                cin >> n2;
                //weight to self is set at 0 so do not let user change
                if(cin.good() && n2 < n+1 && n2 !=n1){
                    break;
                }else{
                    cout<<"You entered invalid input, reenter an integer \n";
                    cin.clear();
                    cin.ignore(120,'\n');
                }
            }

            cout << "You entered: " << n2 << endl ;

            int cost;
            //get the cost of the edge
            cout << "Enter the cost of the edge: " << endl;

            // check for valid input have user reenter until a valid input is accepted
            while(true){
                cin >> cost;
                if(cin.good()){
                    break;
                }else{
                    cout<<"You entered invalid input, reenter an integer \n";
                    cin.clear();
                    cin.ignore(120,'\n');
                }
            }

            cout << "You entered: " << cost << endl ;
            //store in correct spot
            W[n1][n2] = cost;

            break; 

        case 'y': 
            cout << "Adding an edge." << endl;
            //Prompt the user first for the first node in the edge, n1, and then the second node in the edge, n2.
            //Prompt user for the cost of the edge
            //Add weight to correct spot in W: W[n1][n2] = cost
            
            // get the first node
            cout << "Enter the first node in the edge (from 1 to "<< n << "): " << endl;
            int n11;

            // check for valid input have user reenter until a valid input is accepted
            while(true){
                cin >> n11;
                if(cin.good() && n11 < n+1){
                    break;
                }else{
                    cout<<"You entered invalid input, reenter an integer \n";
                    cin.clear();
                    cin.ignore(120,'\n');
                }
            }

            cout << "You entered: " << n11 << endl ;

            //get the second node
            cout << "Enter the second node in the edge (from 1 to "<< n << "): " << endl;
            int n22;

            // check for valid input have user reenter until a valid input is accepted
            while(true){
                cin >> n22;
                //weight to self is set at 0 so do not let user change
                if(cin.good() && n22 < n+1 && n22 !=n11){
                    break;
                }else{
                    cout<<"You entered invalid input, reenter an integer \n";
                    cin.clear();
                    cin.ignore(120,'\n');
                }
            }

            cout << "You entered: " << n22 << endl ;

            int cost1;
            //get the cost of the edge
            cout << "Enter the cost of the edge: " << endl;

            // check for valid input have user reenter until a valid input is accepted
            while(true){
                cin >> cost1;
                if(cin.good()){
                    break;
                }else{
                    cout<<"You entered invalid input, reenter an integer \n";
                    cin.clear();
                    cin.ignore(120,'\n');
                }
            }

            cout << "You entered: " << cost1 << endl ;
            //store in correct spot
            W[n11][n22] = cost1;

            break; 





        
        case 'N': 
            cout << "No more edges to add." << endl;

            break;

        case 'n': 
            cout << "No more edges to add." << endl;

            break;
        
        default:
            cout << "Invalid Selection. Please Enter Again." << endl; 
        }//switch end


        cout << endl; 
    }//loop end

    cout<<"Printing W: "<<endl;
    for(int i=1; i <= n; i++){
        for(int j=1; j <= n; j++){
            cout<<W[i][j]<<"   ";
        }
        cout<<"\n";
        
    }

}//end of constructor


shortest::~shortest(){
    //delete w
    delete W;
    
     

}


// dijkstra function
void shortest::dijkstra(int V){

    //initilize all variables 
    int i;
    int vnear;
    int min = 1000000; //value being used for infinity
    int touch[numberOfVertices];
    int length[numberOfVertices];
    
    //initlize F
    edgenode *F;
    F = new edgenode;
    
    F = NULL;

    int startvalue;
    //set start value    
    startvalue = V;

    for(i = 1; i<= startvalue-1; i++){
        touch[i] = startvalue;
        length[i] = W[startvalue][i];
    }
    for(i = startvalue+1; i<= numberOfVertices; i++){
        touch[i] = startvalue;
        length[i] = W[startvalue][i];
    }

    
    
    
    
    
    
    //start to n-1
    for(int r = 1; r<=numberOfVertices-1; r++){




        min = 1000000;
        //1 to start
        for(i = 1; i<=startvalue-1; i++){
            if(0 < length[i] && length[i] < min){
                min = length[i];
                vnear = i;
            }
        }
        //start to end
        for(i = startvalue+1; i<=numberOfVertices; i++){
            if(0 < length[i] && length[i] < min){
                min = length[i];
                vnear = i;
            }
        }

        //if min not inf update f and touch


        if(min != 1000000){
            edgenode *e;
            e = new edgenode;

            e->e1 = touch[vnear];
            e->e2 = vnear;
            e->next = F;
            F = e;
        

            
           
            //1 to start
            for(i = 1; i<=startvalue-1; i++){
                if(length[vnear] + W[vnear][i]<length[i]){
                    length[i] = length[vnear] + W[vnear][i];
                    touch[i] = vnear;
                }
            }
             //start to end
            for(i = startvalue+1; i<=numberOfVertices; i++){
                if(length[vnear] + W[vnear][i]<length[i]){
                    length[i] = length[vnear] + W[vnear][i];
                    touch[i] = vnear;
                }
            }

        
        }
        length[vnear] = -1;
        //}
       

    
    }




 


    edgenode *temp;
    temp = new edgenode;
    temp = F;

    

    //print out F
    cout<<"Printing F"<<endl;

    //for(int c = 1; c<=numberOfVertices-1; c++){
      //  cout<<"V"<<temp->e1<<" V"<<temp->e2<<endl;
       // temp = temp->next;
   // }
   while(temp != NULL){
       cout<<"V"<<temp->e1<<"   V"<<temp->e2<<endl;
       temp = temp->next;
   }

    //print out touch
    cout<<"Printing touch"<<endl;
    for(i = 1; i<= startvalue-1; i++){
        cout<<i << " " << touch[i]<<endl;;
        
    }
    for(i = startvalue+1; i<= numberOfVertices; i++){
        cout<<i << " " << touch[i]<<endl;;
        
    }

//startvalue    

}//end of dijkstra





void shortest::floyd2(){
    int i;
    int j;
    int k;

    for(i = 1; i <= numberOfVertices; i++){
        for(j = 1; j <= numberOfVertices; j++){
            P[i][j] = 0;
        }
    }//end of for loop (sets all values in P to 0)

    D = W;
    //floyd algo
    for(k = 1; k <= numberOfVertices; k++){
        for(i = 1; i <= numberOfVertices; i++){
            for(j = 1; j<= numberOfVertices; j++){
                if(D[i][k] + D[k][j] < D[i][j]){
                    P[i][j] = k;
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
    //print out D
    cout<<"\nPrinting D: "<<endl;
    for(int i=1; i <= numberOfVertices; i++){
        for(int j=1; j <= numberOfVertices; j++){
            cout<<D[i][j]<<"   ";
        }
        cout<<"\n";
        
    }
    //testing code
    cout<<"\nPrinting P: "<<endl;
    for(int i=1; i <= numberOfVertices; i++){
        for(int j=1; j <= numberOfVertices; j++){
            cout<<P[i][j]<<"   ";
        }
        cout<<"\n";
        
    }



    //print the paths
    for(i = 1; i <= numberOfVertices; i++){
        for(j = 1; j <= numberOfVertices; j++){
            cout <<"calling path "<< i<<" "<<j<<endl;
            path(i, j);
        }
    }



}//end of floyd2



void shortest::path(int q, int r){

    if (P[q][r] != 0){
        path(q, P[q][r]);
        cout<<"v"<<P[q][r];
        path(P[q][r], r);
        cout<<"\n";
    }

}



