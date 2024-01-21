//Adib Sakhawat - sakhadib
//IUT, 2024

#include <bits/stdc++.h>
using namespace std;

void insertionSort(int* arr, int len){
    for(int i = 1; i < len; i++){
        int j = i - 1;
        int temp = arr[i];
        while(j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());


    int arr[] = {5, 4, 3, 2, 1};
    insertionSort(arr, 5);
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }

    
    return 0;
}