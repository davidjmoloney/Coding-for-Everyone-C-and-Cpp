/* 

DM 06Apr2022
-This code is a first example of C++ program. 

*/


#include <iostream> //library used for printing to and from there terminal - no longer need to include the ".h" identifier

using namespace :: std; 

const double m_to_k = 1.609;


//call functions as the same but now we can use the 'inline' keyword
//this tells compiler that instead of calling fucntion - just insert the function into main code whenever it is required during compile
//- can be more efficient if function is small
inline double convert(int mi){
    return mi * m_to_k;
}


int main(void){
    int miles = 1;
    
    
    cout << "Input distance to convert: ";
    cin >> miles;
    cout << "\nDistance in km is: " << convert(miles) << " km" << endl << endl;
    
}