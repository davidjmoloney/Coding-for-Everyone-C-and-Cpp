/* 

DM 17Apr2022
- This program shows the method used to generate a randomly connected graph. 
- Also shows use of the is-connected algorithm for checking that any two nodes are connected

*/


#include <iostream>
#include <string>
#include <ctime>


  

bool** graph_gen(int size){
    bool **graph;                       //We pass a pointer to an array of pointers

    graph = new bool *[size];           //create an array of pointers each pointing to an array of bools
    for (int i = 0; i < size; i++){     //2D array is created
        graph[i] = new bool[size];      //NB: We use this method becuase we want to use dynamic memory allocation - heap memory
    }

    for (int i = 0; i < size; i++){

        for (int j = i; j < size; j++)
        {
            if(i == j)
                graph[i][j] = false;    //Ensure no loops - no node connected to itself
            else
                graph[i][j] = graph[j][i] = (rand() % 100) < 30; //we use this to generate rand bools with certain probability
                                                                 //there is 20% chance a rand int between 0-99 will be below 20
                                                                 //this is known as density - if 0 then no edges exist, if 1 then the graph is complete
        }

    }

    return graph;
}


//is-connected algorithm
bool is_connected(bool *graph[], int size){
    int old_size, c_size = 0;                   //set the closed set size
    bool *close = new bool[size];
    bool *open = new bool[size];
    for (int i = 0; i < size; i++)
        open[i] = close[i] = false;

    open[0] = true;                             //first node to add to open set is 0 - it will go straight into the open set

    while(c_size < size){
        old_size = c_size;

        for (int i = 0; i < size; i++){
            
            if(open[i] && (close[i] == false)){ //find the lowest node that is present in open set and not in closed
                close[i] = true;                //add said node to the closed set
                c_size++;
                
                for (int j = 0; j < size; j++)
                {                                       //check what new nodes can be added to the open set by seeing what edges are connected the node in question
                    open[j] = open[j] || graph[i][j];   //note that an existing nodes in open set will remain
                }
                i = 0;      //reset counter to 0 after a new node has been addded to closed set - find lowest node not checked yet in open set then
            }
        }

        //continue this until the closed set is full
        if(c_size == size)
            return true;

        //or until we can no longer add a node to the closed set - meaning we've check all available nodes
        if (old_size == c_size)
            return false;
        
        //NOTE: in this use of the algorithm we are not removing the nodes from the open set - 
        //we are only adding them in, and then adding them to the closed set if they are not already present (ie. havent been checked)
    }
    return false; //return required to compile but won't ever be reached
}

void print_graph(bool *graph[], int size){
    std::cout << "Graph Matrix\n\t";
    for (int i = 0; i < size; i++)
        std::cout << i << "\t";
    std::cout << "\n____";

    for (int i = 0; i < size; i++)
        std::cout << "________";
    std::cout << std::endl;

    for (int i = 0; i < size; i++){
        std::cout << i << "  |\t";
        for (int j = 0; j < size; j++){                             
            std::cout << graph[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

int main(void)
{
    const int size = 15;

    srand((unsigned)time(0));
    std::cout << "graph matrix is as follows" << std::endl;
    bool **graph = graph_gen(size);

    print_graph(graph, size);

    bool connected = is_connected(graph, size);
    std::cout << "Graph is connected: " << connected << std::endl;
}