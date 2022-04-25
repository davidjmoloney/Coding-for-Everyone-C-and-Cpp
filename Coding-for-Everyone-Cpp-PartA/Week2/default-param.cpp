/*
DM 09Apr2022
- File to show the use of default parameters in function calls

*/

#include <iostream>
using namespace std;


template <class summable>
summable sum(const summable data[], int size, summable start = 0, bool print = 1)   //Here we use default values with the function
{
    if(print == 1) 
        cout << "Start: " << start << endl;

    for (int i = 0; i < size; i++)
    {
        start += data[i];
        if (print == 1)
            cout << "Sum" << i + 1 << ": " << start << endl;
    }
    if (print == 1)
        cout << "Finish: " << start << endl;

    return start;
}

int main(void){

    int a[] = {33, 76, 41, 10, 34, 23, 34, 13, 50};
    double b[] = {1.43, 5.1, 8.88, 3.9, 4.7, 7.1, 5.55, 10.21};

    //See how we can call the function not using all of the required inputs - this is because we are using default parameters
    int s = sum(a, 9);
    sum(a, 9, s);
    //We can also call function without writing it to a value



    //We can use the same function but now with double inputs - note that print is still defaulting to 1 so values will print
    double t = sum(b, 8, -100.0);

    //Now we use function but set print to 0 as well
    //Note that we have to define the start value here as well as otherwise the 0 will be taken as start and not print
    bool print = false;
    cout << "t = " << t << "(100 less than: " << sum(b, 8, 0.0, print) << ")" << endl;


}