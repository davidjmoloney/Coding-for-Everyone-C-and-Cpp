//Code used to cnt the digits and letters in a give piece of text

#include <stdio.h>

int main(void){
    int blanks = 0, digits = 0, letters = 0, count = 0, other = 0;
    int c;

    while((c = getchar()) != EOF){      // c is equated to value of next char from input file
                                        // while this is not equal to constant EOF (end of file) the code continues
        count++;

        if(c >= '0' && c <= '9'){
            digits++;
        }
        else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            letters++;
        }
        else if(c == ' '){
            blanks++;
        }
        else{
            other++;
        }
    }
    printf("Blanks: %d/%d \nDigits: %d/%d \nLetters: %d/%d \nOther: %d/%d \n ", blanks, count, digits, count, letters, count, other, count);
}