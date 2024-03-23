//Adib Sakhawat - sakhadib
//IUT, 2024
typedef long long ll;
ll inf = 1e9;
ll neg_inf = -1e9;
#define mod 1000000007

#include <bits/stdc++.h>
#include "weightedgraph.h"
using namespace std;

void dijkastra(weightedGraph g, int source){
    int distance[100];
    init(distance, 100, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    pq.push(make_pair(0, source));
    distance[source] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(int i=0; i<g.adj[u].size(); i++){
            int v = g.adj[u][i].first;
            int w = g.adj[u][i].second;

            if(distance[v] > distance[u] + w){
                distance[v] = distance[u] + w;
                pq.push(make_pair(distance[v], v));
            }
        }
    }
    for(int i=0; i<g.n; i++){
        cout << i << " " << distance[i] << endl;
    }
}

int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());

    weightedGraph g(10);
    readGraph(g, false);
    dijkastra(g, 1);
    
    return 0;
}