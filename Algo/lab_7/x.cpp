//Adib Sakhawat - sakhadib
//IUT, 2024

// Including necessary header file for input-output operations
#include <iostream>
// Including fstream header file for file input-output operations
#include <fstream>
// Including bits/stdc++.h which includes most of the standard headers
#include <bits/stdc++.h>

// Namespace declaration to avoid repeatedly using std::
using namespace std;

// Defining a type alias for long long integer
typedef long long ll;

// Defining constants inf, neg_inf, and mod
ll inf = 1e9; // inf is initialized with 10^9
int neg_inf = -1e9; // neg_inf is initialized with -10^9
#define mod 1000000007 // mod is defined as 10^9 + 7

// main function
int main() {
    // Redirecting input from input.txt to cin
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirecting output from cout to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());

    // Declaring an array 'k' of size 4005
    int k[4005];
    // Declaring variables n, a, i, and j
    int n, a, i, j;

    // Filling elements of array k with neg_inf from index 1 to 4004
    fill(k + 1, k + 4005, neg_inf);
    // Reading input value 'n'
    cin >> n;

    // Loop for reading input 'a' until EOF (end of file) is reached
    for (; cin >> a;) {
        // Loop from 'a' to 'n'
        for (i = a; i <= n; i++) {
            // Updating value of k[i] by taking maximum of current value and k[i-a]+1
            k[i] = max(k[i], k[i - a] + 1);
        }
    }

    // Printing the maximum value in array k at index 'n'
    cout << k[n];

    // Returning 0 to indicate successful execution
    return 0;
}
