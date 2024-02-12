//Adib Sakhawat - sakhadib
//IUT, 2024

#include<bits/stdc++.h>
using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void dfs(int x,int y,vector<vector<char> >&graph,vector<vector<int> >&visited)
{
    visited[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int curr_X=x+dx[i];
        int curr_Y=y+dy[i];
        if(curr_X<0 || curr_X>=graph.size() || curr_Y<0 || curr_Y>=graph[0].size() || visited[curr_X][curr_Y] || graph[curr_X][curr_Y]=='#') 
        {
            continue;
        }
        dfs(curr_X,curr_Y,graph,visited);
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

    int n,m;
    cin>>n>>m;
    vector<vector<char> >graph(n,vector<char>(m));
    vector<vector<int> >visited(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>graph[i][j];

    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(graph[i][j]=='.'&&!visited[i][j])
            {
                dfs(i,j,graph,visited);
                ans++;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}