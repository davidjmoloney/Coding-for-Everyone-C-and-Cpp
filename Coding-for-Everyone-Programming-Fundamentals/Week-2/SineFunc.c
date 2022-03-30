#pragma warning(disable:4996)

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

	double in_val = 0, out_val = 0;	//initialise input and output variables as double data types


	//'do-while' loop used to continue running program until input is correct
	do {
		//Ask user for input value by printing first and then scsanning
		printf("Please input a value: ");
		scanf("%lf", &in_val);

		//if in_val is not correct we print an error
		if (in_val < 0 || in_val > 1) {
			printf("Error: invalid input. Must be between 0 and 1\n\n");
		}

	} while (in_val < 0 || in_val > 1);



	//Use 'if' statement to ensure value lies between correct interval
	if (in_val >= 1 || in_val <= 1) {
		out_val = sin(in_val);
		//print function with its output
		printf("sin(%.2lf) = %.2lf\nThank you\n\n", in_val, out_val);
	}

	return 0;
}