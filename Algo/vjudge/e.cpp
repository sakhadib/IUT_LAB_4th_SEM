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


    string s;
    cin >> s;
    vector<int> v;
    int n = s.size();
    for(int i=0; i<n; i++){
        if(s[i] == '1'){
            v.push_back(1);
        }
        else if(s[i] == '2'){
            v.push_back(2);
        }
        else if(s[i] == '3'){
            v.push_back(3);
        }
    }

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++){
        if(i == v.size()-1){
            cout << v[i] << endl;
        }
        else{
            cout << v[i] << "+";
        }
    }

    
    return 0;
}