//Adib Sakhawat - sakhadib
//IUT, 2024
typedef long long ll;
ll inf = 1e9;
ll neg_inf = -1e9;
#define mod 1000000007

#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int>& arr){
    int n = arr.size();
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> count(range), output(n);
    for(int i=0; i<n; i++){
        count[arr[i] - min]++;
    }

    for(int i=1; i<count.size(); i++){
        count[i] += count[i-1];
    }

    for(int i=n-1; i>=0; i--){
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for(int i=0; i<n; i++){
        arr[i] = output[i];
    }
}



void cs(vector<int>& arr){
    int n = arr.size();
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());

    int range = max - min + 1;

    vector<int> count(range, 0), output(n);

    for(int i=0; i<n; i++){
        count[arr[i] - min]++;
    }

    for(int i=1; i<range; i++){
        count[i] += count[i-1];
    }

    for(int i=n-1; i>=0; i--){
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for(int i=0; i<n; i++){
        arr[i] = output[i];
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

    counting_sort(arr);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    


    
    return 0;
}