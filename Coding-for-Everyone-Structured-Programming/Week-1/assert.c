/*

DM - 30Mar2022

- This code is used to show how the assert.h file can be used to debug a program
- using the 'assert(exp)' function the program can be stopped if certain conditions are not met

*/ 


//#define NDEBUG //including NDEBUG will cause assert flags to be ignored in code

#include <assert.h>
#include <stdio.h>

//Enumerator definition
enum day_of_week {mon, tue, wed, thu, fri, sat, sun};
typedef enum day_of_week day;    

//function prototypes
void print_day(day d);

int main(void){
    
    day today = mon;
    
    //here we might include an assert flag
    assert(today == mon);
    
    printf("Today is ");
    print_day(today);
    printf("\n\n");
    
    
    today++;
    
    
    //include another assert flag
    assert(today == mon); 
    
    printf("Today is ");
    print_day(today);
    printf("\n\n");
    
    return 0;
}




//Function definitions
void print_day(day d){
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