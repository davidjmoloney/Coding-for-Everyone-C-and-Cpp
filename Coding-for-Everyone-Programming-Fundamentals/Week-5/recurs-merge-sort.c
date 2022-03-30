/*
 This code gives an overview of the merge sorting algorithm
 this uses the merge function to sort a list of unordered entries

 Algorithm works by calling itself recusively so that each time it is called it is looking at smaller and smaller groups until it merges pairs of numbers
 It then merges groups of 4 numbers and so on until it finishes.
 Efficient code that works for any list input - can use dublicate numbers and can use an odd number of members in list


 big O: n*log(n)

 DM 29Mar2022

*/
#include <stdio.h>


void print_array(int data[], int nitems, char str[]);
void merge(int list1[], int list2[], int comb[], int nitem1, int nitem2);
void recurse_merge_sort(int arr[], int start_ind, int end_ind);

////////////////////////////// Main function ////////////////////////////////////////////
int main(void){
    int arr[] = {12, 3, 190, 176, 31, 45, 1, 67, 31, 53, 123, 65, 8, 74}; //Array to be ordered
    int size1 = sizeof(arr)/sizeof(arr[0]); //finds number of elements in an array


    print_array(arr, size1, "\nArray before order\n");

    recurse_merge_sort(arr, 0, size1 - 1);

    print_array(arr, size1, "\nArray after order\n");

    return 0;
}





/////////////////////////// Functions Definitions /////////////////////////////////////////

void print_array(int data[], int nitems, char str[]){

    printf("%s", str);

    for(int i = 0; i < nitems; i++){
        printf("%d\t", data[i]);
    }
    printf("\n");
}

//////////////////////////// RECURSIVE MERGE SORT FUNCTION ////////////////////////////////////////

void recurse_merge_sort(int arr[], int start_ind, int end_ind){     //This probably could have been achieved using length of array but using indexs was simpler
    if (start_ind < end_ind){
        // Finding mid element
        int mid_ind  = (start_ind + end_ind)/2;     //Carry out integer division to find approx mid point

        // Recursively sorting both the halves
        recurse_merge_sort(arr, start_ind, mid_ind);
        recurse_merge_sort(arr, mid_ind + 1, end_ind);

        // Merge the array
        int temp_arr[end_ind - start_ind + 1];  //temporary array used for merging function
        merge(arr + start_ind, arr + mid_ind + 1, temp_arr, mid_ind - start_ind + 1, end_ind - mid_ind);    //merge arrays as program comes out of the recursively called functions

        //Write to unordered array
        for(int i = start_ind; i < end_ind + 1; i++){
            arr[i] = temp_arr[i - start_ind];
        }
    }
}


////////////////////////////// MERGE FUNCTION ////////////////////////////////////////
void merge(int list1[], int list2[], int merge[], int nitem1, int nitem2){

    int i = 0, j = 0, k = 0; //ints to show what position of each array we are at

    while( i < nitem1 && j < nitem2){
        if(list1[i] < list2[j]){
            merge[k++] = list1[i++];     //This method will increment the array positions after the equate operation is performed
        }
        else{
            merge[k++] = list2[j++];
        }
    }

    while(i < nitem1){
        merge[k++] = list1[i++];     //Here we fill out the remainder of the combined array with the contents of whats left from list1 or list2
    }
    while(j < nitem2){
        merge[k++] = list2[j++];
    }
}