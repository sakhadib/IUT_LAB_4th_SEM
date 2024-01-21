//Adib Sakhawat - sakhadib
//IUT, 2024

#include <bits/stdc++.h>
using namespace std;

int findPeak(int* arr, int len){
    int left = 0, right = len - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1]){
            return arr[mid];
        }
        else if(arr[mid] < arr[mid - 1]){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    
    }

    return -1;

}

int main() {

    // Redirect input from input.txt
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("output.txt");
    cout.rdbuf(out.rdbuf());

    int arr[5];
    for(int i = 0; i < 5; i++){
        cin >> arr[i];
    }
    cout << findPeak(arr, 10) << endl;
    return 0;
}