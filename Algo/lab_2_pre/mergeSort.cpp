//Adib Sakhawat - sakhadib
//IUT, 2024

#include <bits/stdc++.h>
using namespace std;

vector<int> randomGen(int len){
    vector<int> r;
    int x = len;
    for(int i=0; i<len; i++){
        r.push_back(x);
        x--;
    }
    return r;
}

void mergeSort(vector<int> arr, int left, int right){
    if(left >= right){
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    int temp[right - left + 1];
    int i = left, j = mid + 1, k = 0;
    while(i <= mid && j <= right){
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= right){
        temp[k++] = arr[j++];
    }
    for(int i = left; i <= right; i++){
        arr[i] = temp[i - left];
    }
}

int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());

    vector<int> X;
    vector<int> Y;

    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        vector<int> arr = randomGen(n);

        clock_t start = clock();
        // mergeSort(arr, 0, n-1);
        sort(arr.begin(), arr.end());
        clock_t end = clock();

        double cpu_time_used = ((double) (end - start));
        // printf("for loop took %f seconds to execute \n", cpu_time_used);
        X.push_back(n);
        Y.push_back(cpu_time_used);
        arr.clear();
    }

    for(int i=0; i<X.size(); i++){
        cout << X[i] << ", ";
    }

    cout << endl;

    for(int i=0; i<Y.size(); i++){
        cout << Y[i] << ", ";
    }



    
    return 0;
}