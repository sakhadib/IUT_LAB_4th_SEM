//Adib Sakhawat - sakhadib
//IUT, 2024

#include <bits/stdc++.h>
using namespace std;

int find2DPeak(int (*arr)[100], int row, int col){
    int left = 0, right = col - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        int maxIndex = 0;
        for(int i = 0; i < row; i++){
            if(arr[i][mid] > arr[maxIndex][mid]){
                maxIndex = i;
            }
        }
        if(arr[maxIndex][mid] >= arr[maxIndex][mid - 1] && arr[maxIndex][mid] >= arr[maxIndex][mid + 1]){
            return arr[maxIndex][mid];
        }
        else if(arr[maxIndex][mid] <= arr[maxIndex][mid - 1]){
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
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());
    
    int row, col;
    cin >> row >> col;

    int (*arr)[100] = new int[row][100];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }

    cout << find2DPeak(arr, row, col) << endl;

    return 0;
    
}