/*

DM - 30Mar2022

- Following code used to outline the use of the enum operator in c
- enum lets programmer assign names to integral constants in a local/global scope
- Here there is an example of value passing and reference passing using the enumerator

*/ 

#include <stdio.h>

//Enumerator definition
enum day {mon, tue, wed, thu, fri, sat, sun};


//function prototypes
enum day next_day(enum day d);
void print_day(enum day d);
void cycle_day(enum day * d);

int main(void){
    
    enum day today = mon;
    printf("Today is ");
    print_day(today);
    printf("\n\n");
    
    //To show how c in a "weak" language: We can pass an integer into function which uses the enumerator as an argument
    printf("Inputting 7 to function: ");
    print_day(7);
    printf("\n\n");
    
    //To show next day function
    printf("Next day is ");
    print_day(next_day(today));
    
    //Note that today remains as
    printf("\nThe value of 'today' is still: ");
    print_day(today);
    printf("\n\n");
    
    
    //if we use reference passing we can cycle day using the pointer 
    cycle_day(&today);
    printf("Cycle day is ");
    print_day(today);
    printf("\n'today' now has a value of: ");
    print_day(today);    
    printf("\n\n"); 
    
    
    return 0;
}


//Function definitions
enum day next_day(enum day d){
    return ((d + 1) % 7);           //modulo opertor used to prevent day from clocking above 7
}


void cycle_day(enum day * d){
    *d = (*d + 1) % 7;
}

void print_day(enum day d){
    switch(d){
        case mon: printf("Monday"); break;
        case tue: printf("Tuesday"); break;
        case wed: printf("Wednesday"); break;
        case thu: printf("Thursday"); break;
        case fri: printf("Friday"); break;
        case sat: printf("Saturday"); break;
        case sun: printf("Sunday"); break;
        default: printf("Error not a day");
    }
}