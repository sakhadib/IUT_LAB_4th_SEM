
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;
const ll llINF=1e18+10;
const ll mod=1e9+7;

vector<ll> extended_Cut_Rod(vector<ll>& p, ll n, vector<ll>& r) 
{
    vector<ll> s(n + 1, -1);
    r[0] = 0;
    return extended_Helper(p, n, r, s);
}

vector<ll> extended_Helper(vector<ll>& p, ll n, vector<ll>& r, vector<ll>& s) 
{
    if (s[n] >= 0) 
        return s;

    ll q = -llINF;
    for (ll j = 1; j <= n; j++) 
    {
        ll current_price = p[j] + extended_Helper(p, n - j, r, s)[n - j];
        if (q < current_price) 
        {
            q = current_price;
            s[n] = j;
        }
    }
    r[n] = q;
    return s;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> r(N,-llINF);
}
