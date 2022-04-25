//  Convert this program to C++
//  change to C++ io
//  change to one line comments
//  change defines of constants to const
//  change array to vector<>
//  inline any short function



#include <iostream>
#include <vector>


const int N = 40;
using namespace std;

//define inline function for summing numbers in an array - could add template definition but no need as function is only used once 
inline void sum(int& p, int n, vector<int>& data){
    int i;
    p = 0;

    //sum up the numbers in the array iteratively
    for (i = 0; i < n; ++i)
        p = p + data[i];

}

int main(){
    int i;
    int accum = 0;
    vector<int> data(N);

    for (i = 0; i < N; ++i){
        //Add consecutive numbers into the array
        data[i] = i; 
    }

    //call function for summing values in the array
    sum(accum, N, data);

    cout << "sum is " << accum << endl;

    return 0;
}