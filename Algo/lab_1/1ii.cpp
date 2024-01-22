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

int findPeak(vector<int> arr){
    int len = arr.size();
    int left = 0, right = len - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1]){
            return arr[mid];
        }
        else if(arr[mid] < arr[mid - 1]){
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


    int n;
    cin >> n;
    vector<int> arr = randomGen(n);
    
    clock_t start = clock();
    int x = findPeak(arr);
    clock_t end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    // printf("for loop took %f seconds to execute \n", cpu_time_used);
    cout << "Duration - " << cpu_time_used << endl;

    cout << x << endl;

    return 0;
}