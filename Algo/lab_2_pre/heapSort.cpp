//Adib Sakhawat - sakhadib
//IUT, 2024

#include <bits/stdc++.h>
using namespace std;

vector<int> randomGen(int len){
    vector<int> r(len);
    int x = len;
    for(int i=0; i<len; i++){
        r[i] = x;
        x--;
    }
    return r;
}


void heapify(vector<int> arr, int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && arr[l] > arr[largest]){
        largest = l;
    }

    if(r < n && arr[r] > arr[largest]){
        largest = r;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> arr){
    int n = arr.size();
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    for(int i = n-1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());

    vector<int> Y;

    int t;
    cin >> t;

    while(t--){
        int n; 
        cin >> n;
        cout << n << ", ";
        vector<int> arr = randomGen(n);

        clock_t start = clock();
        heapSort(arr);
        clock_t end = clock();

        double cpu_time_used = ((double) (end - start));
        // printf("for loop took %f seconds to execute \n", cpu_time_used);
        Y.push_back(cpu_time_used);
        arr.clear();
    }

    cout << endl;

    for(int i=0; i<Y.size(); i++){
        cout << Y[i] << ", ";
    }



    
    return 0;
}

/*


4
16
36
64
100
144
196
256
324
400
484
576
676
784
900
1024
1156
1296
1444
1600
1764
1936
2116
2304
2500
2704
2916
3136
3364
3600
3844
4096
4356
4624
4900
5184
5476
5776
6084
6400
6724
7056
7396
7744
8100
8464
8836
9216
9604
10000
10404
10816
11236
11664
12100
12544
12996
13456
13924
14400
14884
15376
15876
16384
16900
17424
17956
18496
19044
19600
20164
20736
21316
21904
22500
23104
23716
24336
24964
25600

*/