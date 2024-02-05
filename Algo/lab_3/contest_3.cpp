//Adib Sakhawat - sakhadib
//IUT, 2024
typedef long long ll;
ll inf = 1e9;
ll neg_inf = -1e9;

#include <bits/stdc++.h>
using namespace std;

int a[300005],n;

int main() {
    // // Redirect input from input.txt
    // ifstream in("../input.txt");
    // cin.rdbuf(in.rdbuf());

    // // Redirect output to output.txt
    // ofstream out("../output.txt");
    // cout.rdbuf(out.rdbuf());

    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i];  
    }

    sort(a+1,a+n+1);

    cout<<a[(n+1)/2];


    
    return 0;
}