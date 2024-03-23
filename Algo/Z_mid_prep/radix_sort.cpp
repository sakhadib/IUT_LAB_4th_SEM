//Adib Sakhawat - sakhadib
//IUT, 2024
typedef long long ll;
ll inf = 1e9;
ll neg_inf = -1e9;
#define mod 1000000007

#include <bits/stdc++.h>
using namespace std;

void radixSort(vector<int>& arr){
    int n = arr.size();
    int max = *max_element(arr.begin(), arr.end());
    for(int exp = 1; max/exp > 0; exp *= 10){
        vector<int> output(n);
        vector<int> count(10, 0);

        for(int i=0; i<n; i++){
            count[(arr[i]/exp)%10]++;
        }

        for(int i=1; i<10; i++){
            count[i] += count[i-1];
        }

        for(int i=n-1; i>=0; i--){
            output[count[(arr[i]/exp)%10] - 1] = arr[i];
            count[(arr[i]/exp)%10]--;
        }

        for(int i=0; i<n; i++){
            arr[i] = output[i];
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

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    radixSort(arr);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}