//Adib Sakhawat - sakhadib
//IUT, 2024
typedef long long ll;
ll inf = 1e9;
ll neg_inf = -1e9;

#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr) {
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> count(range), output(arr.size());
    for(int i = 0; i < arr.size(); i++)
        count[arr[i]-min]++;

    for(int i = 1; i < count.size(); i++)
        count[i] += count[i-1];

    for(int i = arr.size()-1; i >= 0; i--) {
        output[count[arr[i]-min]-1] = arr[i];
        count[arr[i]-min]--;
    }

    for(int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());

    vector<int> arr;
    arr.push_back(10);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);
    arr.push_back(1);
    arr.push_back(5);
    countingSort(arr);
    cout << "Sorted array: \n";
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}