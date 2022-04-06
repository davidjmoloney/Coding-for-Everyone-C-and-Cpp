/*

DM - 30Mar2022

- This code is used to show how typedef can be used to simplify code 
- we can define the 'enum day' type to something else using typedef

*/ 

#include <stdio.h>

//Enumerator definition
enum day_of_week {mon, tue, wed, thu, fri, sat, sun};

//Typedef usage
typedef enum day_of_week day_t;      // now the word day can be used instead of day_of_week
                                     // use the _t to denote that it is a typedef

//function prototypes
void print_day(day_t d);


int main(void){
    
    day_t today = mon;
    printf("Today is ");
    print_day(today);
    printf("\n\n");
    
    
    return 0;
}


//Function definitions
void print_day(day_t d){
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