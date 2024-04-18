//Adib Sakhawat - sakhadib
//IUT, 2024
typedef long long ll;
ll inf = 1e9;
ll neg_inf = -1e9;
#define mod 1000000007

#include <bits/stdc++.h>
using namespace std;

vector<ll> dp;
ll a, b, c, d, e, f, n;

ll fn(ll n){
    if(n == 0) return a;
    if(n == 1) return b;
    if(n == 2) return c;
    if(n == 3) return d;
    if(n == 4) return e;
    if(n == 5) return f;

    if(dp[n] != inf){
        return dp[n];
    }

    dp[n] = (fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6))%10000007;
    return dp[n];
}

int main() {
    // // Redirect input from input.txt
    // ifstream in("../input.txt");
    // cin.rdbuf(in.rdbuf());

    // // Redirect output to output.txt
    // ofstream out("../output.txt");
    // cout.rdbuf(out.rdbuf());

    ll t, cas=1;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d >> e >> f >> n;
        dp.assign(n+2, inf);
        dp[0] = a; dp[1] = b; dp[2] = c; dp[3] = d; dp[4] = e; dp[5] = f;
        printf("Case %lld: %lld\n", cas, fn(n)%10000007);
        cas++;
    }
    
    return 0;
}