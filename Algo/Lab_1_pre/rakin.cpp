//Adib Sakhawat - sakhadib
//IUT, 2024

#include <bits/stdc++.h>
using namespace std;

void randomWriter(int n){
    for(int i=0; i<n; i++){
        int x = rand() % n;
        cout << x << endl;
    }
}

int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());


    int n;
    cin >> n;

    randomWriter(n);

    
    return 0;
}