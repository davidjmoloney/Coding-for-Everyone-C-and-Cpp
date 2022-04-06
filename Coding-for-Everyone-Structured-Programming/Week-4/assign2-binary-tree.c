/*

DM 01Apr2022

- Code shows the use and creation of a binary tree data structure

*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ENDOFLIST INT_MIN

typedef int DATA; //using this typedef means we can change the data used in the binary tree



typedef struct node{
    DATA value;
    struct node* left;
    struct node* right;
} node_t;



// Function Prototypes
node_t* create_node(DATA value);
node_t* create_tree(DATA * values);
void print_tree(node_t* root);
void print_tree_rec(node_t* root, int level);
void print_tabs(int tabs);
int array_mid(int* arr);
void insert_num(node_t** rootptr, DATA value);
int* array_fill(FILE * pfile);






////////////////////////////////// Main Function ////////////////////////////////////////////

int main(void){
    //int size = sizeof(value)/sizeof(value[0]);
    //initialize file pointers and say what files they are
    FILE *ifp;

    //N.B. - When running this program ensure that the "read-file" is saved to the same directory and that it is a list of integer values
    ifp = fopen("read-file", "r+");

    //initialize and fill array
    int* values = array_fill(ifp);

    fclose(ifp);

    node_t* root = create_tree(values);
    
    //print binary tree inorder 
    print_tree(root);

}






////////////////////////////////// Functions ////////////////////////////////////////////

//Create a node, which holds a value and has two empty branches
node_t* create_node(DATA val){
    node_t* new_node = malloc(sizeof(node_t));
    if(new_node != NULL){
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->value = val;
    }
    return new_node;
}


// Function used to create a binary tree and return the root address
// Takes an array input and fills a binary tree inorder
node_t* create_tree(DATA values[]){

    node_t* root = NULL;

    int ind = 0;
    
    //Find the closest value to the average and start the binary tree here
    int mid = array_mid(values);
    insert_num(&root, mid);

    while(values[ind] != ENDOFLIST){
        insert_num(&root, values[ind]);
        ind++;
    }

    return root;
}


//Function for adding elements to binary tree
void insert_num(node_t** rootptr, DATA value){
    node_t* root = *rootptr; //this is to improve readability

    if(root == NULL){
        //tree is empty - new node required
        (*rootptr) = create_node(value);
        return;
    }

    //This should be removed if tree requires repeated values
    if(value == root->value){
        //do nothing
        return;
    }

    if(value < root->value){
        insert_num(&(root->left), value);
    }
    else{
        insert_num(&(root->right), value);
    }
}





//fucntion for finding the mid point of binary tree - Not required but useful for creating a balanced tree
int array_mid(int* arr){
    double  avg = 0.0;
    int diff = 0, mid = 0,  ind = 0, avg_int = 0;


    while(arr[ind] != ENDOFLIST){
        avg = ((avg * ind) + arr[ind])/(ind + 1.0);   // compute rolling average - used this method to prevent overflows if list got bigger
        ind++;
    }

    ind = 0;
    avg_int = (int)avg;
    diff = abs(arr[0] - avg_int);


    while(arr[ind] != ENDOFLIST){
        if(abs(arr[ind] - avg_int) <= diff){
            mid = arr[ind];
            diff = abs(arr[ind] - avg_int);
        }
        ind++;

    }

    return mid;
}




/////////////// Print Function for Binary tree /////////////////

/*  Note that this is a recursive function
    Each print function will call another function if there are still branches to move to on the tree
    This is "inorder" processing of the data - we first print the left most branches first and then move to parent and then to the right
*/
void print_tree_rec(node_t* root, int level){

    node_t* temp = root;

    if(temp == NULL){
        return;
    }


    else{

        print_tree_rec(temp->left, level);

        printf("\t %d", temp->value);

        print_tree_rec(temp->right, level);

        return;
    }

}

//This function will initiate the recursive print function - more user friendly
void print_tree(node_t * root){
    print_tree_rec(root, 0);
}


//Function for filling an array of values from another file of integers - returns pointer to start of array
int* array_fill(FILE * pfile){

    // Sets cursor in file to start
    fseek(pfile, 0, SEEK_SET);
    int temp = 0, len = 1, ind = 0;
    
    //read first integer in file and create array
    if(fscanf (pfile, "%d", &temp) == 1)
        len =  temp;


    //initialize array to be one longer than required - this is to add ENDOFLIST value later
    int* arr = calloc(len + 1, sizeof(int));
    

    //Read values for required amount or until end of the file
    while ((ind < len) && (!feof (pfile))){
        fscanf (pfile, "%d", arr + ind);
        ind++;
    }


    //Add ENDOFLIST value to the end of the array
    arr[ind] = ENDOFLIST;

    // Resets cursor in file to start
    fseek(pfile, 0, SEEK_SET);

    return arr;
}


