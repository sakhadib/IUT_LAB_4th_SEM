//Adib Sakhawat - sakhadib
//IUT, 2024

#include <bits/stdc++.h>
using namespace std;

int inf = 1e9;
int neg_inf = -1e9;

int findPeak(vector<int> arr){
    int n = arr.size();
    for(int i=0; i<n-1; i++){
        if(i == 0){
            if(arr[i] > arr[i+1]){
                return arr[i];
            }
        }
        else if(i == n-1){
            if(arr[i] > arr[i-1]){
                return arr[i];
            }
        }
        else{
            if(arr[i] > arr[i+1] && arr[i] > arr[i-1]){
                return arr[i];
            }
        }
        
    }
}

int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());

    vector<int> arr;
    while(!cin.eof()){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    cout << findPeak(arr);


    
    return 0;
}