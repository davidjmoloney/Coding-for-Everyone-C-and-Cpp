// A short code used to explore the effects of different storage classes

#include <stdio.h>
#include <math.h> 



void testfunc(void);

int main(void){
    static int stat = 10;
    testfunc();
    testfunc();
    testfunc();
    printf("%d\n", stat); 
}


void testfunc(void){
     {
        /* While we define the value of this here, this only happens once. When function is called more than once the static
           storage classes says that the previous value held in this function should be used*/
        static int stat = 0;    
        stat++;
        printf("%d\n", stat);
       
    }
}
    
    