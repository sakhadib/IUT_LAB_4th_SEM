//Adib Sakhawat - sakhadib
//IUT, 2024

#include<bits/stdc++.h>
using namespace std;

vector<int> randomGen(int len){
    vector<int> r;
    for(int i=0; i<len; i++){
        r.push_back(i);
    }

    return r;

}

int findPeak(vector<int> arr){
    int len = arr.size();
    for(int i=0; i<len; i++){
        if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1]){
            return arr[i];
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

    vector<int> X;
    vector<int> Y;


    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        n*=10;
        vector<int> arr = randomGen(n);
        X.push_back(n);
        clock_t start = clock();
        int x = findPeak(arr);
        clock_t end = clock();

        double cpu_time_used = ((double) (end - start));
        // printf("for loop took %f seconds to execute \n", cpu_time_used);
        Y.push_back(cpu_time_used);
        arr.clear();

        n+=400;
    }

    for(int i=0; i<X.size(); i++){
        cout << X[i] << ", ";
    }

    cout << endl;

    for(int i=0; i<Y.size(); i++){
        cout << Y[i] << ", ";
    }

    // cout << x << endl;

    return 0;
}