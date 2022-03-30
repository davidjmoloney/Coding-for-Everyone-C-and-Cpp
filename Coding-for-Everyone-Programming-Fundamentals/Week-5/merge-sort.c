/*
 This code gives an overview of the merge sorting algorithm
 this uses the merge function to sort a list of unordered entries

 Algorithm works by rnnning the merge function with bigger and bigger groups of numbers
 First it looks at every pair of entries in a list and treats eac as its own list. Following this each pair is ordered.
 Treating each of these pairs as its own list it then orders groups of 4 and then 8 and so on.


 big O: n*log(n)
  
 DM 28Mar2022 

*/
#include <stdio.h>


void print_array(int data[], int nitems, char str[]);
void merge(int list1[], int list2[], int comb[], int nitem1, int nitem2);
void merge_sort(int list[], int nitems);

////////////////////////////// Main function ////////////////////////////////////////////
int main(void){
    int numbers1[] = {4, 2, 1, 8, 5, 10, 7};
    int size1 = sizeof(numbers1)/sizeof(numbers1[0]); //finds number of elements in an array


    print_array(numbers1, size1, "\nArray before order\n");

    merge_sort(numbers1, size1);

    print_array(numbers1, size1, "\nArray after order\n");

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

//////////////////////////// MERGE SORT FUNCTION ////////////////////////////////////////

// Note measures should be taken to ensure that segmentation fault does not occur if array is not 2^x long
void merge_sort(int list[], int nitems){
    int merge_pos, merge_size;
    int temp_array[nitems];
    
    for(merge_size = 1; merge_size < nitems; merge_size *= 2){   //Double the size of the sub-arrays each time
        for(merge_pos = 0; merge_pos < nitems - merge_size; merge_pos += 2*merge_size){     //locate the start point for every sub-merge function
            merge(list + merge_pos, list + merge_pos + merge_size, temp_array + merge_pos, merge_size, merge_size); //Carry out the sub-merges on sub-lists getting bigger in size
        }
        for(merge_pos = 0; merge_pos < nitems; merge_pos++){    
            list[merge_pos] = temp_array[merge_pos];            //update the unordered array with the temop array data 
                                                                // - this is will become more ordered with every iteration 
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