//Adib Sakhawat - sakhadib
//IUT, 2024
typedef long long ll;
ll inf = 1e9;
ll neg_inf = -1e9;
#define mod 1000000007

#include <bits/stdc++.h>
using namespace std;
const ll N = 1e5;

ll parent[N];
ll size_g[N];

void make(ll v){
    parent[v]=v;
    size_g[v]=1;
}

ll find(ll v){
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]); //PATH COMPRESSION OPERATION
}

void Union(ll a,ll b){
    a=find(a);
    b=find(b);

    if(a!=b){
        if(size_g[a]<size_g[b]) {swap(a,b);}
        parent[b]=a;
        size_g[a]+=size_g[b];
    }
}

bool is_conn(ll nodes){
    ll root=find(1);
    for(ll i=2;i<=nodes;i++){
        if(find(i)!=root) return false;
    }
    return true;
}


int main() {
    // // Redirect input from input.txt
    // ifstream in("../input.txt");
    // cin.rdbuf(in.rdbuf());

    // // Redirect output to output.txt
    // ofstream out("../output.txt");
    // cout.rdbuf(out.rdbuf());

    ll n,e;
    cin>>n>>e;

    vector<pair<ll, pair<ll,ll> > >edges;

    while(e--){
        ll u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(make_pair(wt,make_pair(u,v)));
    }

    std::sort(edges.begin(),edges.end()); //SORTING THE EDGES

    for(ll i=1;i<=n;i++){
        make(i);
    }

    ll total_cost=0;
    for(ll i = 0; i < edges.size(); i++){
        ll wt = edges[i].first;
        ll u = edges[i].second.first;
        ll v = edges[i].second.second;

        if(find(u) == find(v)) continue;
        Union(u, v);
        total_cost += wt;
    }

    
    if(is_conn(n)){
        cout<< total_cost <<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }


    
    return 0;
}