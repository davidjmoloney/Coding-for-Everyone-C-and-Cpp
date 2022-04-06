/*

DM 01Apr2022

- Code shows the use and creation of a binary tree data structure
- Some code from coursera "C for Everyone" and some from "https://www.youtube.com/watch?v=UbhlOk7vjVY"

*/


#include <stdio.h>
#include <stdlib.h>

typedef int DATA; //using this typedef means we can change the data used in the binary tree

typedef struct node{
    DATA val;
    struct node* left;
    struct node* right;
} node_t;





// Prototype
node_t* create_node(DATA value);
node_t* create_tree(DATA val[], int i, int size);
void print_tree(node_t* root);
void print_tree_rec(node_t* root, int level);





////////////////////////////////// Main Function ////////////////////////////////////////////

int main(void){
    DATA value[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(value)/sizeof(value[0]);

    node_t* root = create_tree(value, 0, size);
    print_tree(root);
}






////////////////////////////////// Functions ////////////////////////////////////////////

//Create a node, which holds a value and has two empty branches
node_t* create_node(DATA val){
    node_t* new_node = malloc(sizeof(node_t));
    if(new_node != NULL){
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->val = val;
    }
    return new_node;
}


// Function used to create a binary tree and return the root address
// Takes an array input and fills its contents into tree level by level
node_t* create_tree(DATA val[], int i, int size){

    node_t* temp;

    if(i >= size)
        return NULL;
    else {
        temp = create_node(val[i]);
        temp->left = create_tree(val, 2*i + 1, size);
        temp->right = create_tree(val, 2*i + 2, size);
        return temp;
    }

}


/////////////// Print Function for Binary tree /////////////////
/*  Note that this is a recursive function
    Each print function will call another function if there are still branches to move to on the tree
    This is post order processing of the data - we first use the parent node and then the two child nodes - (along with each further child nodes)
    Unlike more common method inorder processing where we print child1 (+further branches), then parent, then child2. This is better for the normally ordered data
*/
void print_tree_rec(node_t* root, int level){

    node_t* temp = root;

    if(temp == NULL){
        printf("< EMPTY >\n");
        return;
    }


    else{

        printf("Value = %d\n", temp->val);
        level++;

        print_tabs(level);
        printf("Left: ");
        print_tree_rec(temp->left, level);

        print_tabs(level);
        printf("Right: ");
        print_tree_rec(temp->right, level);

        return;
    }

}

//This function will initiate the recursive print function - more user friendly
void print_tree(node_t * root){
    print_tree_rec(root, 0);
}

void print_tabs(int tabs){
    for(int i = 0; i < tabs; i++){
        printf("\t");
    }
}
