//Adib Sakhawat - sakhadib
//IUT, 2024
typedef long long ll;
ll inf = 1e9;
ll neg_inf = -1e9;

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int v, int s){
    bool visited[v];
    for(int i=0; i<v; i++){
        visited[i] = false;
    }

    stack<int> st;
    st.push(s);

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

    dfs(adj, n, 1);

    
    return 0;
}