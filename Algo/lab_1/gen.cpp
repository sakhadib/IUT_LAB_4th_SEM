//Adib Sakhawat - sakhadib
//IUT, 2024

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());

    int n = 70;
    cout << n << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << 4*i*i << endl;
        // cout << i*700 << endl;
    }
    


    
    return 0;
}