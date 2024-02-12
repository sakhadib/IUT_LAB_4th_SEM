//Adib Sakhawat - sakhadib
//IUT, 2024

#include<bits/stdc++.h>
using namespace std;

vector<vector<int> >conn_comp;
vector<int>current_conn_comp;

void dfs(int cur,vector<vector<int> >&graph,vector<int>&visited)
{
    current_conn_comp.push_back(cur);
    visited[cur]=1;
    for(int i = 0; i < graph[cur].size(); i++){
        int nxt = graph[cur][i];
        if(visited[nxt]) 
            continue;
        dfs(nxt,graph,visited);
    }
}

int main()
{
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());

    int n,m,i;
    cin >> n >> m;

    vector<vector<int> > graph(n+1);
    vector<int> visited(n+1);

    while(m--)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ct=0;
    for(i=1;i<=n;i++)
    {
        if(visited[i]) 
            continue;
        current_conn_comp.clear();
        dfs(i,graph,visited);
        conn_comp.push_back(current_conn_comp);
        ct++;
    }
    

    if(ct>1)
    {
        cout<<ct-1<<"\n";
        for(i=1;i<ct;i++)
            cout<<conn_comp[i-1][0]<<" "<<conn_comp[i][0]<<"\n";
    }
    else cout<<0;
}
