/*

DM 04Apr2022
- Program used to generate a doubly linked list and removed any repeated nodes from the list

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//node definition - contains two pointers for previous and next node in list
typedef struct node {
    int value;
    struct node* next;
    struct node* prev;
} node_t;

//Function Protoype
void print_list_head(node_t * head);
void print_list_tail(node_t * tail);
node_t* create_node(int value);
void insert_at_head(node_t **head, node_t *node_to_insert);
node_t* find_node(node_t * head, int val_to_find);
void remove_node(node_t* to_remove);
void remove_repeats(node_t * head);


int main(void){



    //We can also achieve this using a loop
    node_t * head1 = NULL;
    node_t * temp1 = NULL;
    node_t * tail1 = NULL;

    head1 = create_node(rand() % 50);
    tail1 = head1;

    //initialize random number generator
    srand(time(NULL));


    //loop to create 100 nodes each with a random number and place them at the head of the list
    //generated numbers less than 1000 for better readability
    for(int i = 0; i < 200; i++){
        temp1 = create_node(rand() % 50);
        insert_at_head(&head1, temp1);
    }

    
    
    
    printf("List of 200 random values up to 49:\n");
    print_list_head(head1);

    //Call function to remove any repeats in the list
    remove_repeats(head1);


    printf("\n\nAny repeated values in list removed: \n");
    print_list_head(head1);



    return 0;

}


//here we create a new node and assign the value to it - we return the pointer to this new node
node_t* create_node(int value){
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    result->prev = NULL;
    return result;
}


//function to insert a given node at the head of a list
//here we pass in the pointer to the pointer of head so that we can make changes to the value of the pointer
void insert_at_head(node_t **head, node_t *node_to_insert){
    node_to_insert->next = *head;
    node_to_insert->next->prev = node_to_insert;
    *head = node_to_insert;
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

//Function for removing a node from the linked list
//Set prev and next pointers on adjacent nodes - check in case it is at either end of the list
void remove_node(node_t* to_remove){
    if(to_remove->prev != NULL)
        to_remove->prev->next = to_remove->next;

    if(to_remove->next != NULL)
        to_remove->next->prev = to_remove->prev;

    //free the allocated memory that was used with the node
    free(to_remove); 
}


//Function used to remove repeats - takes each item in list and 
//checks remaining portion of list to see if it is repeated
void remove_repeats(node_t * head){

    node_t * temp = head;
    int repeat = 1;
    node_t * repeat_node = NULL;

    while(temp != NULL){

        repeat = 1;
        while(repeat == 1){
            repeat = 0;
            
            //Continues to search until it reaches the last item in the list
            if(temp->next != NULL)
                repeat_node = find_node(temp->next, temp->value); 
            
            //If a repeated value is found the repeated value is removed
            if(repeat_node != NULL){
                repeat = 1;
                remove_node(repeat_node);
                repeat_node = NULL;     //Set repeat_node back to NULL to prevent as segmentation fault
            }
        }
        
        //Increment position in list
        temp = temp->next;
    }


}

//Print list starting at the head
void print_list_head(node_t * head){
    node_t * temp = head;
    while(temp != NULL){
        printf("%d - ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

//Print list starting at the tail
void print_list_tail(node_t * tail){
    node_t * temp = tail;
    while(temp != NULL){
        printf("%d - ", temp->value);
        temp = temp->prev;
    }
    printf("\n");
}