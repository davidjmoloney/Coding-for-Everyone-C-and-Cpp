
/*
DM 24Mar2021
- The following code was written to compute the output of the sin(x) function
- The input x must be between 0 and 1
- If the value input is not between 0 and 1, the code will return an error and ask again. 
- Otherwise it will return the output of sin(x)
*/


#include <stdio.h>	//stdio.h included to use print and scan function
#include <math.h>	//math.h included to use sin function

int main(void) {
	double x = 0;	//initialise input x as a double data type


	//'do-while' loop used to continue running program until input is correct
	do{		

		//Ask user for input value by printing first and then scsanning
		printf("Please input a value: ");
		scanf("%lf", &x);

		//if x is not correct we print an error
		if (x < 0 || x > 1) {
			printf("Error: invalid input. Must be between 0 and 1\n\n");
		}
	} while (x < 0 || x > 1);



	//Use 'if' statement to ensure value lies between correct interval
	if (x >= 1 || x <= 1) {

		//print function with its output
		printf("sin(%.2lf) = %.2lf\nThank you\n\n", x, sin(x));		

	}
}