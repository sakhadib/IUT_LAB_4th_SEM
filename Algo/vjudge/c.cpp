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


    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        if(i%2==0){
            ans += v[i+1] - v[i];
        }
    }

    cout << ans << endl;

    
    return 0;
}