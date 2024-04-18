//Adib Sakhawat - sakhadib
//IUT, 2024
typedef long long ll;
ll inf = 1e9;
int neg_inf = -1e9;
#define mod 1000000007

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Redirect input from input.txts
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());


    int k[4005];
    int n,a,i,j;
    fill(k+1, k+4005, neg_inf);
    cin >> n;

	for(;cin>>a;){
        for(i=a;i<=n;i++){
            k[i] = max(k[i],k[i-a]+1);
        }
    }

	cout << k[n];

    
    return 0;
}