// Simple program showing the use of references and pointers in C++


#include <iostream>

using namespace std;

//Note: we dont need to dereference - we can say that we are passing in address using '&' and program will know to change values at location
//We are passing in "address of i", rather than "pointer called i"
inline void swap(int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;
}

//C++ has overloading - can now have more than one function of certain name
//discriminate by signature - types/number of arguments used by function
inline void swap(double &i, double &j)
{
    int temp = i;
    i = j;
    j = temp;
}



int main(void)
{
    int m = 5, n = 10;
    double x = 0.33, y = 1.75;

    cout << "int inputs: " << m << ", " << n << endl; //notice we dont need formatting rules
    swap(m, n); //still use variable names as normal even though we are editing the values stored in addresses
    cout << "int outputs: " << m << ", " << n << endl;


    cout << "double inputs " << x << ", " << y << endl;
    swap(x, y);
    cout << "double outputs " << x << ", " << y << endl;
}
