//Adib Sakhawat - sakhadib
//IUT, 2024
typedef long long ll;
ll inf = 1e9;
ll neg_inf = -1e9;
#define mod 1000000007

#include <bits/stdc++.h>
using namespace std;

void bucket_sort(vector<int>& arr){
    int n = arr.size();
    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());
    int bucket_size = (max_val - min_val) / n + 1;
    vector<vector<int> > buckets(n);
    for(int i=0; i<n; i++){
        int bi = (arr[i] - min_val) / bucket_size;
        buckets[bi].push_back(arr[i]);
    }
    for(int i=0; i<n; i++){
        sort(buckets[i].begin(), buckets[i].end());
    }
    int index = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<buckets[i].size(); j++){
            arr[index++] = buckets[i][j];
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

    bucket_sort(arr);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}