/*

DM - 11Apr2022
- Program to show the use of classes in C++

*/


#include <iostream>


//class definition
class point{
public:             //access keywords: public means anyone can see it, private makes it part of the 'black box'
    
    point() { x = y = 0.0; }                //Default contructor - what happens if nothing is initialized when object is created
    point(double x_init, double y_init) {   //Initialize Constructor - we set values when we created the onject
        x = x_init;                         //We can use this to set values of private variables
        y = y_init;                         //Here we are using function overloading for the constructor - different operation depenedent on the method signature
    }

    void print();

private:
    double x, y;                            //Note that if these were set to const values - we could not assign them as above and initializer list would be preferable

};

void point::print()                         //We can use the unary scope resolution operator to define methods outside of the scope of a class
{
    std::cout << "(" << x << "," << y << ")" << std::endl;
}

int main (void){
    point a = {3.4, 2.1}, b;
    a.print();
    b.print();
}