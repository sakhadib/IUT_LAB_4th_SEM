//Adib Sakhawat - sakhadib
//IUT, 2024

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf = 1e9;
ll neg_inf = -1e9;

ll findPeak(vector<ll> arr){
    ll size = arr.size();
    ll left = 0, right = size - 1;
    while(left <= right){
        ll mid = (left + right) / 2;

        if(mid == 0){
            if(arr[mid] >= arr[mid + 1]){
                return arr[mid];
            }
        }
        else if(mid == size - 1){
            if(arr[mid] >= arr[mid - 1]){
                return arr[mid];
            }
        }
        else if(arr[mid] >= arr[mid + 1] && arr[mid] >= arr[mid - 1]){
            return arr[mid];
        }
        else if(arr[mid] < arr[mid - 1]){
            right = mid - 1;
        }
        else{
            left = mid + 1;
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

    vector<ll> arr;
    while(!cin.eof()){
        ll temp;
        cin >> temp;
        arr.push_back(temp);
    }

    cout << findPeak(arr);


    
    return 0;
}