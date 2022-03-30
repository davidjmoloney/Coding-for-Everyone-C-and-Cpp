/*
Code used for calculate the average numbers in taken from a txt file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Function prototypes
int list_size(FILE * pfile);
void array_fill(int arr[], FILE * pfile);
double average(int arr[], int size);


///////////////////////////// Main program function ///////////////////////////////////////

int main(){

    // initialize a file pointer which is what will be used for opening & reading the file with weight data
    FILE * pfile;
    pfile = fopen("elephant_seal_data", "r");  //open file and set file pointer

    // if file can not be opened we will print an error message and finish the program
    if (pfile == NULL) {
        printf("file can't be opened \n");
        return 0;
    }

    // Find required size for weight array and initalize array
    int size = list_size(pfile);
    int weight_arr[size];


    // Fill the array with integers from the seal data file
    array_fill(weight_arr, pfile);

    // print data from file (weight array) to console
    printf("content of this file are \n");
    for(int i = 0; i < size; i++){
        printf("%d\t", weight_arr[i]);
    }
    printf("\n\n");


    // use the average function to find average weight and print number to console
    double avg_weight = average(weight_arr, size);
    printf("Average weight = %.3lf \n", avg_weight);


    fclose(pfile);

    return 0;

}




///////////////////////////// Function Definitions ///////////////////////////////////////

// Function used to find number of integers in text file
int list_size(FILE * pfile){

    int i = 0;
    int temp = 0;

    fseek(pfile, 0, SEEK_SET);          // Sets cursor in file to start

    while (!feof (pfile)){              // This will continue to run as long as we have not reached the End-of-file character
        fscanf (pfile, "%d", &temp);    // reads integer values from file - this is done to move cursor through file for each distinct integer
        i++;                            // increments counter
    }

    fseek(pfile, 0, SEEK_SET);          // Resets cursor in file to start

    return i;
}



// Function used to fill an array with integer values from a text file
void array_fill(int arr[], FILE * pfile){

    fseek(pfile, 0, SEEK_SET);              // Sets cursor in file to start
    int ind = 0;

    while (!feof (pfile)){
        fscanf (pfile, "%d", arr + ind);    // Reads integer values from file and saves into each location of array
        ind++;
    }

    fseek(pfile, 0, SEEK_SET);              // Resets cursor in file to start

}



// function used to calculate average of values in file
double average(int arr[], int size){
    double avg = 0;
    for(int i = 0; i < size; i++){
        avg = ((avg * i) + arr[i])/(i + 1.0);   // compute rolling average - used this method to prevent overflows if list got bigger
    }
    return avg;
}