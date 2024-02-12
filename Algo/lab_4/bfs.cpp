//Adib Sakhawat - sakhadib
//IUT, 2024
typedef long long ll;
ll inf = 1e9;
ll neg_inf = -1e9;

#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], int v, int s){
    bool visited[v];
    for(int i=0; i<v; i++){
        visited[i] = false;
    }

    queue<int> q;
    visited[s] = true;
    q.push(s);

    cout << "\nBFS:____\n";

    while(!q.empty()){
        int u = q.front();
        cout << u << " ";
        q.pop();

        for(int i=0; i<adj[u].size(); i++){
            if(!visited[adj[u][i]]){
                visited[adj[u][i]] = true;
                q.push(adj[u][i]);
            }
        }
    }
}

void dfs(vector<int> adj[], int v, int s){
    bool visited[v];
    for(int i=0; i<v; i++){
        visited[i] = false;
    }

    stack<int> st;
    st.push(s);

    cout << "\nDFS:____\n";

    while(!st.empty()){
        int u = st.top();
        st.pop();

        if(!visited[u]){
            cout << u << " ";
            visited[u] = true;
        }

        for(int i=0; i<adj[u].size(); i++){
            if(!visited[adj[u][i]]){
                st.push(adj[u][i]);
            }
        }
    }
}


int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());


    int n;
    cin >> n;
    vector<int> adj[n+1];
    int u, v;
    while(cin >> u >> v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(adj, n, 1);
    // dfs(adj, n, 1);

    
    return 0;
}