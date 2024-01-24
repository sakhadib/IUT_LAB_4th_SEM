//Adib Sakhawat - sakhadib
//IUT, 2024

#include <bits/stdc++.h>
using namespace std;

vector<int> randomGen(int len){
    vector<int> r;
    for(int i=0; i<len; i++){
        r.push_back(i);
    }

    return r;

}

bool linearSearch(vector<int> arr, int x){
    int len = arr.size();
    for(int i = 0; i < len; i++){
        if(arr[i] == x){
            return true;
        }
    }

    return false;
}

bool binarySearch(vector<int> arr, int x){
    int len = arr.size();
    int left = 0, right = len - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] == x){
            return true;
        }
        else if(arr[mid] < x){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    
    }

    return false;
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
        // bool x = linearSearch(arr, n+1);
        bool y = binarySearch(arr, n+1);
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