//Adib Sakhawat - sakhadib
//IUT, 2024

#include <bits/stdc++.h>
using namespace std;

vector<int> removeDuplicatesAndZeros(vector<int>& arr) {
    int n = arr.size();
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            res.push_back(arr[i]);
        }
    }
    return res;
    
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

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    // for(int i=0; i<n; i++){
    //     cout << v[i] << " ";
    // }

    vector<int> res = removeDuplicatesAndZeros(v);

    int count = 0;

    for(int i=0; i<res.size(); i++){
        if(i+1 <= res[i]){
            count++;
        }
    }

    cout << count << endl;


    
    return 0;
}