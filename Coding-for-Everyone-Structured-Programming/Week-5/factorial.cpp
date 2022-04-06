/* 

DM 06Apr2022
- calculates factorial values

*/


#include <iostream> //library used for printing to and from there terminal - no longer need to include the ".h" identifier

using namespace :: std; 


long long fact(int num){
    long long f = 1;    //We can now use 'long long' integer value - datatype of modern c larger than long int
    for(int i = 1; i <= num; i++)
        f *= i;
        
    return f;
}


int main(void){
    
    for(auto i = 0; i < 25; i++){
        
        cout << "Factorial of: " << i << " = " << fact(i) << endl;
    
        //Notice that when we get to 20! the output stops to make sense - long long can not hold values longer than this
    }
        
}