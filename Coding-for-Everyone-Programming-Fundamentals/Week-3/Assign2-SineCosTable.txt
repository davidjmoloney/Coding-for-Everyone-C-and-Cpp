#include<stdio.h>
#include<math.h> 

int main(void){

double interval;
double end_val = 1, calc_input = 0, sin_out = 0, cos_out = 0;   //Added and end value so user can decide what value ot finish checking sin calculation
int num_of_cycles = 30;                                         //Improves readabilty and Can now decide the number of time the calculations will be carried out

interval = end_val/num_of_cycles;                               //Calculates what the interval should be between each input value

printf("\tInput\t|\tSine\t|\tCosine\t|\n");
printf("----------------|---------------|---------------|\n"); 

for(int i = 0; i < num_of_cycles; i++){                         //For loop runs until we get to the correct numebr of iterations
    
    printf("\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|\n", calc_input, sin(calc_input), cos(calc_input));   //Prints out cosine and sine functions in table fomrat
    calc_input += interval;   //Each time we carry out the calc, we add another interval amount
}



return 0;
}