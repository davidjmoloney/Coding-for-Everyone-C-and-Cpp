/*

DM 11Apr2022
- The following code shows the use of operator overloading - here we can add functionality to unary and binary operators which suit our our own type definitions

*/


#include <iostream>

using namespace std;

typedef enum days{SUN, MON, TUE, WED, THU, FRI, SAT} days_t;

//here we are overloading the autoincrement operator '++'
inline days operator++(days_t &d)
    { return d  = static_cast<days_t>(static_cast<int>(d) + 1 % 7); }


//We can do the same for the bitshift operator '<<' - which is also used for send information to the ostream
ostream& operator<<(ostream& out, const days_t& d){     //use const for nonmutable variable - use call by reference for complicated (not needed here)
    switch(d){
        case SUN: out << "Sunday"; break;
        case MON: out << "Monday"; break;
        case TUE: out << "Tuesday"; break;
        case WED: out << "Wednesday"; break;
        case THU: out << "Thursday"; break;
        case FRI: out << "Friday"; break;
        case SAT: out << "Saturday"; break;
        default: out << "Not a day";
    }
    return out;
}

int main(void){
    days_t d = MON, e;
    e = d;
    cout << d << "\t" << ++e << endl;
}
