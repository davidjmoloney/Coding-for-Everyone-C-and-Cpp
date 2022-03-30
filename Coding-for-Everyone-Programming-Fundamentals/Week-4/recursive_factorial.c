#include <stdio.h>


long factorial(int n);


int main(void){
    long n_fact;
    int n;

    printf("Factorial of: ");
    scanf("%d", &n);

    n_fact = factorial(n);
    printf("%d! = %ld\n", n, n_fact);
}

long factorial(int n){
    if(n == 1){
        return 1;
    }
    else{
        return(factorial(n - 1) * n);
    }
}
