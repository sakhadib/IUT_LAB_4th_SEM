//Adib Sakhawat - sakhadib
//IUT, 2024
typedef long long ll;
ll inf = 1e9;
ll neg_inf = -1e9;
#define mod 1000000007

#include <bits/stdc++.h>
using namespace std;

// 1D peak finding
void find_peek_naive(vector<int>& arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        if(i == 0 && arr[i] >= arr[i+1]){
            cout << arr[i] <<" at index " << i << endl;
            return;
        }
        else if(i == n-1 && arr[i] >= arr[i-1]){
            cout << arr[i] <<" at index " << i  << endl;
            return;
        }
        else if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1]){
            cout << arr[i] <<" at index " << i  << endl;
            return;
        }
    }
}

void find_peek_binary(vector<int>& arr){
    int n = arr.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if (mid == 0 || arr[mid] >= arr[mid - 1]) {
            if (mid == n - 1 || arr[mid] >= arr[mid + 1]) {
                cout << arr[mid] << " at index " << mid << endl;
                return;
            }
        }
        if(mid > 0 && arr[mid-1] > arr[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
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

    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Naive: ";
    find_peek_naive(arr);
    cout << "Binary: ";
    find_peek_binary(arr);


    
    return 0;
}