/*
DM 05Apr2022

File used to read integers from a file and store them in an array
First integer says how many integers are to be read

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


//Define the end of list value as the lowest possible integer
#define ENDOFLIST INT_MIN


//Function Prototypes
int* array_fill(FILE * pfile);
double array_average(int* arr);
double array_max(int* arr);

int main (void){

    //initialize file pointers and say what files they are
    FILE *ifp;
    FILE *ofp;

    //N.B. - When running this program ensure that the "read-file" is saved to the same directory and that it is a list of integer values
    ifp = fopen("read-file", "r+");
    ofp = fopen("answer-hw3", "w+");

    //initialize and fill array
    int* arr = array_fill(ifp);

    //calculate average
    double average = array_average(arr);
    int max = array_max(arr);


    //print to output file

    fprintf(ofp, "\nArray is: ");

    int ind = 0;
    while(*(arr+ind) != ENDOFLIST){
        fprintf(ofp, "%10d", *(arr+ind) );
        ind++;
    }

    fprintf(ofp, "\n\nAverage is: %.3lf\nMaximum is: %d\n", average, max);

    fclose(ifp);
    fclose(ofp);

}

//Function for filling an array of values from another file of integers - returns pointer to start of array
int* array_fill(FILE * pfile){

    // Sets cursor in file to start
    fseek(pfile, 0, SEEK_SET);
    int temp = 0, len = 0, ind = 0;

    //read first integer in file and create array
    if(fscanf (pfile, "%d", &temp) == 1)
        len =  temp;

    //initialize array to be one longer than required - this is to add ENDOFLIST value later
    int arr[len + 1];

    //Read values for required amount or until end of the file
    while ((ind < len) && (!feof (pfile))){
        fscanf (pfile, "%d", arr + ind);
        ind++;
    }


    //Add ENDOFLIST value to the end of the array
    arr[ind] = ENDOFLIST;

    // Resets cursor in file to start
    fseek(pfile, 0, SEEK_SET);

    int* ret = arr;
    return ret;
}




// function used to calculate average of values in file
double array_average(int* arr){
    double avg = 0.0;
    int ind = 0;

    while(arr[ind] != ENDOFLIST){
        avg = ((avg * ind) + arr[ind])/(ind + 1.0);   // compute rolling average - used this method to prevent overflows if list got bigger
        ind++;
    }

    return avg;
}


// function used to find maximum value
double array_max(int* arr){
    int max = 0;
    int ind = 0;

    while(arr[ind] != ENDOFLIST){
        max = (arr[ind] > max) ? arr[ind] : max;
        ind++;
    }

    return max;
}


