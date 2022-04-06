
/*

DM 30Mar2022
- The following code is used to print the next date after dates of the year

*/


#include <stdio.h>

//defining enumerator for months and struct for date
typedef enum {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} month_t;
typedef struct  { month_t m; int d; } date_t;


//Function Prototypes
void print_date(date_t date);
date_t next_date(date_t date);




////////////////////////////////// Main Function ////////////////////////////////////////////////

int main(void){

    date_t day = {jan, 1};


    // Print Jan 1 and next day
    printf("\nThe day after ");
    print_date(day);
    printf(" is ");
    print_date(next_date(day));
    printf("\n\n");


    // Print Feb 28 and next day
    day.m = feb; day.d = 28;

    printf("\nThe day after ");
    print_date(day);
    printf(" is ");
    print_date(next_date(day));
    printf("\n\n");


    // Print mar 14 and next day
    day.m = mar; day.d = 14;

    printf("\nThe day after ");
    print_date(day);
    printf(" is ");
    print_date(next_date(day));
    printf("\n\n");


    // Print Oct 31 and next day
    day.m = oct; day.d = 31;

    printf("\nThe day after ");
    print_date(day);
    printf(" is ");
    print_date(next_date(day));
    printf("\n\n");


    // Print Dec 31 and next day
    day.m = dec; day.d = 31;

    printf("\nThe day after ");
    print_date(day);
    printf(" is ");
    print_date(next_date(day));
    printf("\n\n");


    return 0;
}





/////////////////////////////// Function Definitions /////////////////////////////////////////////

//Function for incrementing the date
date_t next_date(date_t date){

    //First initialise the return struct and set value to input date
    date_t next_date = date;

    //Cycling days will depend of month so a switch-case statement is used
    //the modulo operator '%' is used to check if it is last day of the month - will return 0 if it is and then we increment
    switch(next_date.m){
        case jan: next_date.d = (next_date.d % 31) + 1; break;
        case feb: next_date.d = (next_date.d % 28) + 1; break;
        case mar: next_date.d = (next_date.d % 31) + 1; break;
        case apr: next_date.d = (next_date.d % 30) + 1; break;
        case may: next_date.d = (next_date.d % 31) + 1; break;
        case jun: next_date.d = (next_date.d % 30) + 1; break;
        case jul: next_date.d = (next_date.d % 31) + 1; break;
        case aug: next_date.d = (next_date.d % 31) + 1; break;
        case sep: next_date.d = (next_date.d % 30) + 1; break;
        case oct: next_date.d = (next_date.d % 31) + 1; break;
        case nov: next_date.d = (next_date.d % 30) + 1; break;
        case dec: next_date.d = (next_date.d % 31) + 1; break;
        default: printf("Month input incorrect");               //prints error if month input is incorrect
    }

    //if day is now 1, it is the start of a new month so we increment that as well
    if(next_date.d == 1){
        next_date.m = (next_date.m + 1) % 12;
    }

    return next_date;

}



//Fucntion to print date of the year
void print_date(date_t date){

    //Switch statement used to print the correct month. An error message added if month is incorrect
    switch(date.m){
        case jan: printf("January"); break;
        case feb: printf("February"); break;
        case mar: printf("March"); break;
        case apr: printf("April"); break;
        case may: printf("May"); break;
        case jun: printf("June"); break;
        case jul: printf("July"); break;
        case aug: printf("August"); break;
        case sep: printf("September"); break;
        case oct: printf("October"); break;
        case nov: printf("Novemeber"); break;
        case dec: printf("December"); break;
        default: printf("Month input incorrect");
    }

    //print day
    printf(" %d", date.d);
}