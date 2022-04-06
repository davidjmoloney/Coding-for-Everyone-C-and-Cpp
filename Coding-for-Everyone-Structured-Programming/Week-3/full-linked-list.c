/*

DM 31Mar2022

- Following code outlines some of the key functions used in a linked lists data structure 
- Taken from: https://www.youtube.com/watch?v=VOpjAHCee7c&t=10s

*/


#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int value;
    struct node* next; //notice that we reference a structure of the same type within this structure
} node_t;


void print_list(node_t * head);
node_t* create_node(int value);
void insert_at_head(node_t **head, node_t *node_to_insert);
node_t* find_node(node_t * head, int val_to_find);
void insert_after(node_t *insert_after, node_t *new_node);
void concat(node_t * head1, node_t * head2);


  
int main(void){

    node_t * head1;
    node_t * temp1;

    //here we are creating a linked list in which every additional node is added to start - where the head is
    temp1 = create_node(45);
    head1 = temp1;
    temp1 = create_node(25);
    temp1->next = head1;    //The new node is given head as the next-address -- it is placed at the start
    head1 = temp1;
    temp1 = create_node(10);
    temp1->next = head1;
    head1 = temp1;

    //print list
    print_list(head1);


//  ^^ Basic Operation for creating a linked list ^^
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//      More Complex Functions Below     
    
    
    
    //We can also achieve this using a loop
    node_t * head2 = NULL;
    node_t * temp2;
    
    for(int i = 0; i < 20; i++){
        temp2 = create_node(i);
        insert_at_head(&head2, temp2);
    }
    
    print_list(head2);
    
    
    //Example of finding node
    printf("\n15 is at: %p \n", find_node(head2, 15));
    
    //insert a new node after a certain node
    node_t* new_node = create_node(75); 
    node_t* node_15 = find_node(head2, 15);
    insert_after(node_15, new_node);
    print_list(head2);
    
    
    
    //Example of concatination
    concat(head1, head2);
    print_list(head1);
    
    
    return 0;

}


//here we create a new node and assign the value to it - we return the pointer to this new node 
node_t* create_node(int value){
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}


//function to insert a given node at the head of a list
//here we pass in the pointer to the pointer of head so that we can make changes to the value of the pointer
void insert_at_head(node_t **head, node_t *node_to_insert){
    node_to_insert->next = *head;
    *head = node_to_insert;
    
}

//Function to insert a new node after a certain node
void insert_after(node_t *insert_after, node_t *new_node){
    new_node->next = insert_after->next;
    insert_after->next = new_node;
    
}


//function to find a node of interest - returns address of the node which holds value, otherwise returns NULL
node_t* find_node(node_t * head, int val_to_find){
    node_t * temp = head;
    
    while(temp != NULL){
        if(temp->value == val_to_find)
            return temp;
        
        temp = temp->next;
    }
    return NULL;
}

//Concatination function - uses recrusion to find the last element in list and make it point at head of another
void concat(node_t * head1, node_t * head2){
    if(head1->next == NULL)
        head1->next = head2;
    else
        concat(head1->next, head2);
}


void print_list(node_t * head){
    node_t * temp = head;
    
    printf("\n");
    while(temp != NULL){
        printf("%d - ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}