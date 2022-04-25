


#include <iostream>
using namespace std;

template<class T1, class T2>
void copy(const T1 source[], T2 destination[], int size)
{
    for (int i = 0; i < size; i++){
        //static casting allows for safe casting of elements - program will online compile if two types that are castable are used
        destination[i] = static_cast<T2>(source[i]);
    }
}



int main (void)
{
    int n = 5;
    double src[] = {3.6, 7.2, 8.8, 10.4213, 4.20};
    int dest[n];

    copy(src, dest, n);

    for(int i = 0; i < n; i++){
        cout << dest[i] << "\t";
    }

    //Also works with chars
    char src2[] = "Hello";
    int dest2[n];

    copy(src2, dest2, n);

    for (int i = 0; i < n; i++)
    {
        cout << dest2[i] << "\t";
    }
}
