#include <iostream>
using namespace std;

/*******************************************************************
* getInfo *
* Gets and validates lottery info from the user and places it in   *
* reference parameters referencing variables in the main function. *
*******************************************************************/
void getInfo(int & pickFrom, int & numPicks) {
    do {
        cout << "How many balls (1-12) are in the pool to pick from? ";
        cin >> pickFrom;
        if(pickFrom < 1 || pickFrom > 12){
            cout << "Input Error! There must be between 1 and 12 balls." << endl;




        }
    }while (pickFrom < 1 || pickFrom > 12);

    do{
        cout << "How many balls (1-7) will be drawn? ";
        cin >> numPicks;
        if(numPicks < 1 || numPicks > 7){
            cout << "Input Error!" << endl;




        }
    }while (numPicks < 1 || numPicks > 7);

}



/******************************************************************
* computeWays                                                     *
* Computes and returns the number of different possible sets      *
* of k numbers that can be chosen from a set of n numbers.        *
* The formula for this is     k!(n- k)!                           *
*                             --------                            *
*                                 n!                              *
*******************************************************************/
// Note that the computation is done in a way that does not require
// multiplying two factorials together. This is done to prevent any
// intermediate result becoming so large that it causes overflow.
double computeWays(int n, int k){
    double num = 1.0;
    double den = 1.0;

    for(int i=2; i<=n; ++i){
        num *= i;
    }

    for(int i=2; i <= k; ++i){
        den *= i;
    }

    for(int i=2; i<=(n-k); ++i){
        den *= i;
    }
    return 1/ (num/den);
}

// This function computes factorials recursively. It is called by computeWays.
double factorial(int n){
    if(n == 0 and n == 1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }

}
