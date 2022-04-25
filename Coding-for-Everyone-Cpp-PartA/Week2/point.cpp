/*

DM - 11Apr2022
- Program to show the use of classes in C++

*/


#include <iostream>

using namespace std;

//class definition
class point{
public:             //access keywords: public means anyone can see it, private makes it part of the 'black box'
    double x, y;
};

point operator+(point& p1, point& p2){
    point sum = {p1.x + p2.x, p1.y + p2.y};
    return sum;
}

ostream& operator<< (ostream& out, const point& p){
    out << "(" << p.x << "," << p.y << ")";
    return out;
}


int main (void){
    point a = {3.4, 2.1}, b = {5.2, -6.6};
    cout << "a " << a << " + b " << b << " = " << a + b << endl;
}