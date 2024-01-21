//Adib Sakhawat - sakhadib
//IUT, 2023

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Redirect input from input.txt
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("output.txt");
    cout.rdbuf(out.rdbuf());


    for(int i=1; i<400; i++){
        cout<<"INSERT INTO COURSE VALUES("<< i <<", 'course"<<i<< "', 3, 1);"<<endl;
    }

    
    return 0;
}