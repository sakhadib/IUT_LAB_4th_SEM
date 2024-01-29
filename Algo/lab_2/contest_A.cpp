//Adib Sakhawat - sakhadib
//IUT, 2024

#include <bits/stdc++.h>
using namespace std;

int main() {
    // // Redirect input from input.txt
    // ifstream in("../input.txt");
    // cin.rdbuf(in.rdbuf());

    // // Redirect output to output.txt
    // ofstream out("../output.txt");
    // cout.rdbuf(out.rdbuf());

    vector<pair<int, int> > v;

    long long t;
    cin >> t;
    while(t--){
        long long price, quality;
        cin >> price >> quality;
        v.push_back(make_pair(price, quality));
    }

    sort(v.begin(), v.end());

    bool flag = false;

    for(long long i=0; i<v.size()-1; i++){
        if(v[i].second > v[i+1].second){
            flag = true;
            break;
        }
    }

    if(flag){
        cout << "Happy Alex";
    }
    else{
        cout << "Poor Alex";
    }



    
    return 0;
}