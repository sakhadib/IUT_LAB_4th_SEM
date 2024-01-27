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

void Max_Heapify(vector<int> arr, int i){
    int heap_size = arr.size();
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;
    if(l < heap_size && arr[l] > arr[i]){
        largest = l;
    }
    if(r < heap_size && arr[r] > arr[largest]){
        largest = r;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        Max_Heapify(arr, largest);
    }
}

void Build_Max_Heap(vector<int> arr){
    int heap_size = arr.size();
    for(int i = heap_size/2; i >= 0; i--){
        Max_Heapify(arr, i);
    }
}

void Heap_Sort(vector<int> arr){
    Build_Max_Heap(arr);
    int heap_size = arr.size();
    for(int i = heap_size - 1; i >= 1; i--){
        swap(arr[0], arr[i]);
        heap_size--;
        Max_Heapify(arr, 0);
    }
}

int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());


    int n =28000;
    // cin >> n;

    vector<int> arr(n);
    arr = randomGen(n);

    clock_t start = clock();
    Heap_Sort(arr);
    clock_t end = clock();

    double cpu_time_used = ((double) (end - start));
    cout << "Time is : " << fixed << cpu_time_used << setprecision(5);


    
    return 0;
}