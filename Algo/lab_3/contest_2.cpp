//Adib Sakhawat - sakhadib
//IUT, 2024
typedef long long ll;
ll inf = 1e9;
ll neg_inf = -1e9;

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m = n*(n-1)/2, b[m];
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        sort(b,b+m);
        for(int i=0; i<m; i+=--n){
            cout<<b[i]<<' ';
        }
        cout<<"1000000000\n";
    }


    
    return 0;
}