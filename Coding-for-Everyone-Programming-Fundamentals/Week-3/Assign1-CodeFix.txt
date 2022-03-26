#include<stdio.h>
#include<math.h> /* has  sin(), abs(), and fabs() */

int main(void){
    
double interval; 
double end_val = 10.0, calc_input = 0.0;    //Added and end value so user can decide what value ot finish checking sin calculation
int num_of_cycles = 30;                     //Improves readabilty and Can now decide the number of time the calculations will be carried out

interval = end_val/num_of_cycles;           //Calculates what the interval should be between each input value


for(int i = 0; i < num_of_cycles; i++){   //For loop runs until we get to the correct numebr of iterations
    
    printf("sin( %lf ) = %lf \t", calc_input, fabs(sin(calc_input)));
    calc_input += interval;   //Each time we carry out the calc, we add another interval amount
}


printf("\n+++++++\n");
return 0;
}