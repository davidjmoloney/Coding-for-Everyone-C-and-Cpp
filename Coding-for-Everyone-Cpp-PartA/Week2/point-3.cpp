/*

DM - 11Apr2022
- Program to show the use of classes in C++

*/


#include <iostream>


//class definition
class point{
public:             
                   
    point(double x_init = 0.0, double y_init = 0.0): x(x_init), y(y_init){}     //here we use an initializer list - instead of assignment
                                                                                //With this we can initialize the const variables

    void print(){
        std::cout << "(" << x << "," << y << ")" << std::endl;
    }

private:
    const double x, y;

};



int main (void){
    point a = {3.4, 2.1}, b;
    a.print();
    b.print();
}