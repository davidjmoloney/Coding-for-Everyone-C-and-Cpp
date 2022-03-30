/*

This code gives an overview example of the bubble sort technique used for putting an unordered list in order
DM - 28Mar22

*/

#include <stdio.h>



//function prototype
void swap(int *a, int *b);
void print_array(int data[], int nitems, char *str);
void bubble_sort(int data[], int nitems);


////////////////////////////// Main function ////////////////////////////////////////////
int main(void){
    int numbers[] = {4, 7, 1, 6, 2, 9};
    int size = sizeof(numbers)/sizeof(numbers[0]); //finds number of elements in an array
    printf("\n%d\n", size);

    print_array(numbers, size, "\ninitial array before sort\n");

    bubble_sort(numbers, size);

    print_array(numbers, size, "\nSorted array\n");

    return 0;
}



/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// Functions definitions ///////////////////////////////////
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int data[], int nitems, char str[]){

    printf("%s", str);

    for(int i = 0; i < nitems; i++){
        printf("%d\t", data[i]);
    }
    printf("\n");
}

/* Bubble sort
    in this case bubble sort works by pushing the smallest number to the bottom of the pile each time we pass through the list - can vary with required funcitonality
    first We compare the the last element and 2nd last elements of the list and we swap them if they need to be
    then we compare 2nd last and 3rd last elemetns and swap if required. Doing this for the entire list will place the smallest number 1st
    We run this operation again but for one less iteration than the previous run - this puts the second smallest number in the 2nd position of the list
    This is continued for nitems in the list

    Big O of bubble sort n
*/
void bubble_sort(int data[], int nitems){

    char msg[20];


    for(int i = 0; i < nitems; i++){


        sprintf(msg, "\niteration %d\n", i);  //sprintf lets you print to string variable (char[]) as if it is the console



        print_array(data, nitems, msg);

        for(int j = nitems - 1; j > i; j--){
            if(data[j] < data[j-1]){
                swap(&data[j - 1], &data[j]);
            }
        }
    }
}