#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>


using namespace std;

bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

string findWinner(const vector<int>& arr) {
    int n = arr.size();
    vector<pair<int, int> > sortedOrder(n);

    for (int i = 0; i < n; i++) {
        sortedOrder[i] = make_pair(arr[i], i);
    }

    sort(sortedOrder.begin(), sortedOrder.end(), comparePairs);

    int misplaced = 0;
    for (int i = 0; i < n; i++) {
        if (sortedOrder[i].second != i) {
            misplaced++;
        }
    }

    return (misplaced % 2 == 1) ? "Marcelo" : "Carlos";
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

        cout << findWinner(P) << endl;
    }

    return 0;
}
