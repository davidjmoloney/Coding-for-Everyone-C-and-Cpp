// Simple program showing the use of references and pointers in C++


#include <iostream>
#include <complex>

using namespace std;

//We can make a general template function - this will be compiled for every instance with a different input type used
template <class T>
T add(T &i, T &j)
{
    return i + j;
}



int main(void)
{
    int m = 5, n = 10;
    double x = 0.33, y = 1.75;
    complex<double> r(2.6, 3.2), s(-1.5, 2.1); //This is how we generate complex numbers - using complex template with double input

    cout << "int inputs: " << m << ", " << n << endl; 
    int a = add(m, n);   //implicitly decide how they are added using add<int>
    cout << "added: " << a << endl << endl;

    cout << "double inputs " << x << ", " << y << endl;
    cout << "added: " << add(x, y) << endl << endl;

    cout << "complex inputs " << r << ", " << s << endl;
    cout << "added: " << add(r, s) << endl << endl;
    
}
