#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int mergeAndCount(vector<int>& arr, int l, int m, int r) {
    int invCount = 0;

    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            // Count inversions
            invCount += (n1 - i);
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    return invCount;
}

int mergeSortAndCount(vector<int>& arr, int l, int r) {
    int invCount = 0;
    if (l < r) {
        int m = l + (r - l) / 2;

        // Total inversion count is the sum of inversions in the left, right,
        // and merge steps
        invCount += mergeSortAndCount(arr, l, m);
        invCount += mergeSortAndCount(arr, m + 1, r);
        invCount += mergeAndCount(arr, l, m, r);
    }
    return invCount;
}

int inversion_Count(vector<int>& arr) {
    return mergeSortAndCount(arr, 0, arr.size() - 1);
}

int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Read the blank space after the array
        // string blankSpace;
        // cin >> blankSpace;

        cout << inversion_Count(arr) << endl;
    }

    return 0;
}
