/*

DM 04Apr2022

- Following code is used to generate a linked list with 100 random numbers
- A bubble sort function is then used to swap the values assigned to each node until the list is ordered

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int value;
    struct node* next;
} node_t;

//Function Prototypes
void print_list(node_t * head);
node_t* create_node(int value);
void insert_at_head(node_t **head, node_t *node_to_insert);
int list_length(node_t* head);
void bubble_sort(node_t* head);
void swap_nodes(node_t* head, int len);


//////////////////////////////////////////// Main Function ////////////////////////////////////////////
int main(void){

    //We can also achieve this using a loop
    node_t * head1 = NULL;
    node_t * temp1 = NULL;

    //initialize random number generator
    srand(time(NULL));
    
    //loop to create 100 nodes each with a random number and place them at the head of the list
    //generated numbers less than 1000 for better readability
    for(int i = 0; i < 100; i++){
        temp1 = create_node(rand() % 1000); 
        insert_at_head(&head1, temp1);
    }

    printf("Unordered Linked List: \n");
    print_list(head1);

    bubble_sort(head1);
    
    printf("Ordered Linked List: \n"); 
    print_list(head1);


    return 0;

}


//////////////////////////////////////////// Function Definitions ////////////////////////////////////////////


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

//bubble sort function - used to call list length function and then call the swap nodes function iteratively 
void bubble_sort(node_t* head){
    int len = list_length(head);

    for(int i = len-1; i >= 0; i--){
        swap_nodes(head, i);
    }

    return;
}

//Function to swap the values assigned to two consecutive nodes
//Function only runs certain amount of times - means it doesnt have to check nodes which have already been ordered - better for bigger lists
void swap_nodes(node_t* head, int len){
    node_t* prev = head;
    node_t* current = head->next;
    int temp, i = 0;

    while(i < len){

        if(prev->value > current->value){
            temp = prev->value;
            prev->value = current->value;
            current->value = temp;
        }

        prev = current;
        current = current->next;

        i++;
    }

    return;
}



//Function used to calculate the length of a linked list - runs until it reachs the NULL reference
int list_length(node_t* head){
    node_t * temp = head;
    int i = 0;

    while(temp != NULL){
        i++;
        temp = temp->next;
    }
    return i;
}


//Print function will print every element in a linked list. After every 5th item a new line is started
void print_list(node_t * head){
    node_t * temp = head;
    int r = 0;
    
    while(temp != NULL){
        printf("%3d \t ", temp->value);
        temp = temp->next;

        r++;
        if((r % 5) == 0)
            printf("\n");

    }
    printf("\n\n");
}