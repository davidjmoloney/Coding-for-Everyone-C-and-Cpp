/*

DM 30Mar2022
- The following code is an overview of how a stack data structure is generated using the C language
- https://www.youtube.com/watch?v=A4sRhuGkRb0

- A stack is a basic structure which uses a 'last-in-first-out' mechanism
- we have two main operations with the stack; push to add an element to the top; pop to remove an element from the top

*/



#include <stdio.h>
#include <limits.h>      //header file including macros for limits of datatypes
#include <stdbool.h>    //library used for basic bool operations in c

#define STACK_LEN 10
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

//define struct for stack
typedef struct{
    char stack[STACK_LEN];
    int top;
} stack_t;


//prototypes
void reset(stack_t * stk);
bool push(stack_t * stk, char c);
char pop(stack_t * stk);
bool is_empty(const stack_t * stk);
bool is_full(const stack_t * stk);




//main function
int main(void){
    stack_t word_stk;
    reset(&word_stk);
    
    char *word = "0123456789ABCDE";
    char reverse[20]= {0};
    
    int i = 0;
    
    printf("Original string: %s\n\n", word);
    
    while((!is_full(&word_stk)) && (word[i] != '\0')){
        
        push(&word_stk, word[i]);
        printf("%c\n", word[i]);
        i++;  
    }
    
    i = 0;
    while((!is_empty(&word_stk)) && (i < 20)){
        reverse[i] = pop(&word_stk);
        i++;
    }
    printf("reverse string: %s\n\n", reverse);
    
    
    return 0;
    
}







// stack reset function - settings cursor (top) to EMPTY (-1)
void reset(stack_t * stk){
    stk->top = EMPTY; 
}





//functions to check if stack is full or empty
bool is_empty(const stack_t * stk){
    return (stk->top == EMPTY);
}

bool is_full(const stack_t * stk){
    return (stk->top == STACK_LEN - 1);
}





//push function - used to add elements to the top of the stack
bool push(stack_t * stk, char c){
    
    //Ensure that the top of the stack has not surpassed the size of the stack
    if(stk->top >= STACK_LEN - 1)
        return false;
    
    stk->top++;
    stk->stack[stk->top] = c;
    return true;
}






// Pop function will read an element off if the stack and set the top index one lower (effectively removing an element)
char pop(stack_t * stk){
    if(stk->top ==  EMPTY)
        return 0;
    
    return stk->stack[stk->top--];
    //Note we use top-- (postfix decrement) so that top will lower 1 after return operation has been carried out
}