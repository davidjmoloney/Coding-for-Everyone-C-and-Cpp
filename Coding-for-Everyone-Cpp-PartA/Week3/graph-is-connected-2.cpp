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




//travserse fuction is recursive function used to visit as many nodes as possible - check for connected graph
void traverse(bool* graph[], int u, bool visited[], int size)
{   
    //array for visited nodes keeps track of where we've been to already
    visited[u] = true; //mark v as visited

    //check what is connected to the current node and if we haven't already visited, move to said new node
    for (int v = 0; v < size; v++)
    {
        if (graph[u][v])
        {
            if (!visited[v]){
                traverse(graph, v, visited, size);
            }
        }
    }
}

bool is_connected(bool *graph[], int size)
{
    bool *vis = new bool[size];

    //for all vertex u as start point, check whether all nodes are visible or not
    
    for (int i = 0; i < size; i++)
        vis[i] = false; //initialize as no node is visited

    traverse(graph, 0, vis, size);  //call traverse function starting at node 0

    //if the "visited" array comes back with any emtpy items then we know we've been everywhere we can be
    for (int i = 0; i < size; i++)
    {   
        if (!vis[i]) //if there is a node, not visited by traversal, graph is not connected
            return false;
    }
    
    return true;
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
    const int size = 7;

    srand((unsigned)time(0));
    std::cout << "graph matrix is as follows" << std::endl;
    bool **graph = graph_gen(size);

    print_graph(graph, size);

    bool connected = is_connected(graph, size);
    std::cout << "Graph is connected: " << connected << std::endl;
}