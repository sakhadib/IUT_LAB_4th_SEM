//Adib Sakhawat - sakhadib
//IUT, 2024
typedef long long ll;
ll inf = 1e9;
ll neg_inf = -1e9;

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());

    double Q;
    cin >> Q;

    double k1 = 151;
    double k2 = 37;
    double k3 = 337;
    double k4 = 173;
    double k5 = 17;
    double k6 = 211;
    double k7 = 2;
    double k8 = 53;

    double ans = (((((((Q + k1) * k2) / k3) + k4) * k5) / k6) - k7) * k8;

    cout << ans;


    
    return 0;
}