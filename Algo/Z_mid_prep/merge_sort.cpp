//Adib Sakhawat - sakhadib
//IUT, 2024
typedef long long ll;
ll inf = 1e9;
ll neg_inf = -1e9;
#define mod 1000000007

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);
    for(int i=0; i<n1; i++){
        L[i] = arr[l+i];
    }
    for(int i=0; i<n2; i++){
        R[i] = arr[m+1+i];
    }

    int i = 0, j = 0, k = l;
    if (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            merge(arr, l+1, m, r);
        }
        else {
            arr[k] = R[j];
            merge(arr, l, m, r+1);
        }
    }
    else if (i < n1) {
        arr[k] = L[i];
        merge(arr, l+1, m, r);
    }
    else if (j < n2) {
        arr[k] = R[j];
        merge(arr, l, m, r+1);
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());




    
    return 0;
}