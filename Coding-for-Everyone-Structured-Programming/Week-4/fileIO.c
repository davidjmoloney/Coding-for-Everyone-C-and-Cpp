/*

DM 05Apr2022
File used to add a double line spacing any file of interest

*/



#include <stdio.h>
#include <stdlib.h>


void print_file(FILE * fp);
void double_space(FILE* ifp, FILE* ofp);



////////////////////////////////////////////////////////////////////////////////////////////////////

//here we are using the command line arguments in calling the main function of this program
//int argc - the number of arguments passed when calling the program
//argv - is a vector ie. an array of arrays of chars (a list of strings) input to the program when it is called
//We can use these two variables within the program
int main(int argc, char *argv[]){ 
    
    FILE *ifp;
    FILE *ofp;
    
    //Here we use argc to ensure we have the correct amount of characters at program call
    if(argc != 3){
        printf("need executable input-file outputfile");
        exit(1);
    }
    
    ifp = fopen(argv[1], "r+");
    ofp = fopen(argv[2], "w+");
    
    printf("\nSingle Spaced:\n");
    print_file(ifp);
    
    double_space(ifp, ofp);
    
    printf("\n\nDouble Spaced:\n");
    print_file(ofp);
    
    
    
}








////////////////////////////////////////////////////////////////////////////////////////////////////

void print_file(FILE * fp){
    int c;
    //rewind(fp);
    fseek(fp, 0, SEEK_SET);    //Can also use
    while((c = getc(fp)) != EOF){
        putc(c, stdout);            //prints each character of file to the stdout - terminal
    }
}


//With some adaption we could use this to replace any character or word in a file
void double_space(FILE* ifp, FILE* ofp){
    int c;
    rewind(ifp);
    //fseek(pfile, 0, SEEK_SET);    
    while((c = getc(ifp)) != EOF){
            putc(c, ofp);           //prints each character of file to the stdout - terminal
        if(c == '\n')
            putc('\n', ofp);        //Print an extra newline if a newline is read
    }
}