// 08Apr2022
// code used to intrdouce some of the basic differencees between C and C++ coding


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIDES = 6;

inline int r_sides(){
    return rand() % SIDES + 1;
}

int main(void){
    const int n_dice = 2;
    int d1, d2;

    srand(clock());

    cout << "Enter number of trials: ";

    int trials;
    cin >> trials;

    int *outcomes = new int[(n_dice * SIDES) + 1]; //make an array 13 in length so that 13th position will be denoted as [12]

    for (int j; j < trials; j++){
        outcomes[(d1 = r_sides()) + (d2 = r_sides())]++; //increment the required position in the array by 1 - this counts the amount of time each number is seen
    }

    cout << "probabilites: \n";

    for (int j = 2; j < n_dice * SIDES + 1; j++){
        cout << "Dice Value = " << j << "\tProbability = " << static_cast<double>(outcomes[j]) / trials << "\t"; //we use static_cast to cast value here
        
        int i = (outcomes[j] * 1000) / trials;
            while(i > 0){
                cout << "-";
                i--;
            }

            cout << endl;
    }
}