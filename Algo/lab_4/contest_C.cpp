//Adib Sakhawat - sakhadib
//IUT, 2024
typedef long long ll;
ll inf = 1e9;
ll neg_inf = -1e9;

#include <bits/stdc++.h>
using namespace std;

vector<int> X;
vector<int> Y;


void dfs(int cur,vector<vector<int> >&graph,vector<int>&visited)
{
    visited[cur]=1;
    for(int i = 0; i < graph[cur].size(); i++){
        int nxt = graph[cur][i];
        if(visited[nxt]) 
            continue;
        else{
            X.push_back(cur);
            Y.push_back(nxt);
        }
        dfs(nxt,graph,visited);
    }
}


int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());

    int n, m;
    cin >> n >> m;

    vector<vector<int> > graph(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> visited(n+1);
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i, graph, visited);
        }
    }

    for(int i=0; i<X.size(); i++){
        cout << X[i] << " " << Y[i] << endl;
    }

    
    return 0;
}