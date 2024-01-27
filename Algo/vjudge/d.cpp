//Adib Sakhawat - sakhadib
//IUT, 2024

#include <bits/stdc++.h>
using namespace std;

int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    int count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] > arr[j]) {
            count += (mid - i + 1);
            temp[k++] = arr[j++];
        } else {
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int p = 0; p < k; ++p) {
        arr[left + p] = temp[p];
    }

    return count;
}

int mergeSortAndCount(vector<int>& arr, int left, int right) {
    int count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        count += mergeSortAndCount(arr, left, mid);
        count += mergeSortAndCount(arr, mid + 1, right);

        count += mergeAndCount(arr, left, mid, right);
    }
    return count;
}

int countSwapsBubbleSort(vector<int>& arr) {
    return mergeSortAndCount(arr, 0, arr.size() - 1);
}


int main() {

    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());

    while (true) {
        int N;
        cin >> N;

        if (N == 0)
            break;

        vector<int> P(N);
        for (int i = 0; i < N; i++)
            cin >> P[i];

        cout << countSwapsBubbleSort(P);
    }

    return 0;
}