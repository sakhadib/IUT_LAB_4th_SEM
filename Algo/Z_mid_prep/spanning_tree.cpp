//Adib Sakhawat - sakhadib
//IUT, 2024
typedef long long ll;
ll inf = 1e9;
ll neg_inf = -1e9;
#define mod 1000000007
const ll N = 1e5;

#include <bits/stdc++.h>
using namespace std;

ll parent[N];

void make(ll v){
    parent[v]=v;
}

ll find(ll v){
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]); //PATH COMPRESSION OPERATION
}

void s_Union(ll a,ll b){
    a=find(a);
    b=find(b);

    if(a!=b){
        parent[b]=a;
    }
}

struct edge{
    int parent;
    int weight;
    bool operator<(const edge &e) const{
        return weight > e.weight;
    }
    edge(int p, int w) : parent(p), weight(w) {}
};

vector<bool> visited;


void Prim(){
    int n, m;
    cin >> n >> m;

    vector<edge> adj[n];
    visited.resize(n, false);

    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(edge(v, w));
        adj[v].push_back(edge(u, w));
    }

    priority_queue<edge> pq;
    pq.push(edge(0, 0));

    int mst = 0;

    while(!pq.empty()){
        edge u = pq.top();
        pq.pop();

        if(visited[u.parent]) continue;

        visited[u.parent] = true;
        mst += u.weight;

        for(int i=0; i<adj[u.parent].size(); i++){
            if(!visited[adj[u.parent][i].parent]){
                pq.push(adj[u.parent][i]);
            }
        }
    }

    cout << mst << endl;
}


void kruskal(){
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, pair<ll,ll> > >edges;

    while(m--){
        ll u,v,wt;
        cin >> u >> v >> wt;
        edges.push_back(make_pair(wt,make_pair(u,v)));
    }

    std::sort(edges.begin(),edges.end()); //SORTING THE EDGES

    ll total_cost=0;
    for(ll i = 1; i <= n; i++){
        make(i);
    }

    for(int i=0; i<edges.size(); i++){
        ll wt = edges[i].first;
        ll u = edges[i].second.first;
        ll v = edges[i].second.second;

        if(find(u) == find(v)) continue;

        s_Union(u, v);
        total_cost += wt;
    }


    cout << total_cost << endl;

    

}


int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());


    // Prim();
    kruskal();

    
    return 0;
}