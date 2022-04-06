/*

DM 31Mar2022

- Following code outlines the basic opertaion of a linked list
- Taken from: https://www.youtube.com/watch?v=VOpjAHCee7c&t=10s

*/


#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int value;
    struct node* next; //notice that we reference a structure of the same type within this structure
} node_t;


void print_list(node_t * head);

int main(void){

    //make nodes
    node_t n1, n2, n3;
    //make pointer for the head of the list
    node_t * head;

    //define values and links in list
    n1.value = 45;
    n2.value = 13;
    n3.value = 99;

    head = &n1;
    n1.next = &n3;  //we point to the address of the next node
    n3.next = &n2;
    n2.next = NULL; //Final address in list


    //print list
    print_list(head);

    return 0;

}


void print_list(node_t * head){
    node_t * temp = head;

    while(temp != NULL){
        printf("%d - ", temp->value);
        temp = temp->next;
    }
}