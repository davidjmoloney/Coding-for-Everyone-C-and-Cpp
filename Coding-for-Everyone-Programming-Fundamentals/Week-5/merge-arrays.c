/*
 This code gives an overview of the merge function
 this is used to combine two lists of ordered items into one list of ordered items

 Algorithm works by comparing 0th items first. If one is smaller, it is placed at 0th position of the combined list
 it then looks at the next 2 lowest items not sorted from both lists (0th item & 1st item). it places lower of the 2 into the 1st position of combined list
 it continues this until no more comparisons can be made and then it adds the remaining items into the combined list
 --- a diagram will help explain this better - look it up


 
DM 28Mar2022 

*/
#include <stdio.h>


void print_array(int data[], int nitems, char str[]);
void merge(int list1[], int list2[], int comb[], int nitem1, int nitem2);


////////////////////////////// Main function ////////////////////////////////////////////
int main(void){
    int numbers1[] = {1, 2, 6, 13, 34, 100};
    int size1 = sizeof(numbers1)/sizeof(numbers1[0]); //finds number of elements in an array

    int numbers2[] = {3, 5, 8, 10, 11, 15, 24, 89};
    int size2 = sizeof(numbers2)/sizeof(numbers2[0]);

    int num_merge[size1 + size2];

    print_array(numbers1, size1, "\nArray 1\n");
    print_array(numbers2, size2, "\nArray 2\n");

    merge(numbers1, numbers2, num_merge, size1, size2);

    print_array(num_merge, size1 + size2, "\nMerged array\n");

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