//Adib Sakhawat - sakhadib
//IUT, 2024
typedef long long ll;
ll inf = 1e9;
ll neg_inf = -1e9;
#define mod 1000000007

#include <bits/stdc++.h>
using namespace std;

// 2D peak finding
// mri = max row index

void find_peek(vector<vector<int> > &mat){
    int row = mat.size();
    int col = mat[0].size();

    int low = 0, high = col-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        int mri = 0;
        for(int i=0; i<row; i++){
            if(mat[i][mid] > mat[mri][mid]){
                mri = i;
            }
        }
        if (mid == 0) {
            if (mat[mri][mid] >= mat[mri][mid - 1]) {
                if (mid == col - 1 || mat[mri][mid] >= mat[mri][mid + 1]) {
                    cout << mat[mri][mid] << " at index " << mri << " " << mid << endl;
                    return;
                }
            }
        } else if (mid == col - 1) {
            if (mat[mri][mid] >= mat[mri][mid + 1]) {
                if (mid == 0 || mat[mri][mid] >= mat[mri][mid - 1]) {
                    cout << mat[mri][mid] << " at index " << mri << " " << mid << endl;
                    return;
                }
            }
        } else {
            if (mat[mri][mid] >= mat[mri][mid - 1]) {
                if (mat[mri][mid] >= mat[mri][mid + 1]) {
                    cout << mat[mri][mid] << " at index " << mri << " " << mid << endl;
                    return;
                }
            }
        }
        if(mid > 0 && mat[mri][mid-1] > mat[mri][mid]){
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

    int row, col;
    cin >> row >> col;

    vector<vector<int> > arr(row, vector<int>(col));
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> arr[i][j];
        }
    }

    
    find_peek(arr);

    
    return 0;
}