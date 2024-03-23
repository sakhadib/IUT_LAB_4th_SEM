#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ii pair<ll,ll>
ll n,m,k,cnt=0;
ll N=1000000000007;
vector<ii> adj[100004];
vector<ll> dist(100004 ,N);
vector<bool> visited(100004);
void dijkstra(){
	set<ii > pq;
 
	for(int i=2;i<=n;i++){
		if(dist[i] != N){
			pq.insert({dist[i],i});
		}
	}
 
	pq.insert({(ll)0,(ll)1});
	dist[1] = (ll)0;
 
	while(! pq.empty()){
 
		ii front=*pq.begin(); pq.erase(pq.begin());
		ll d=front.first ,u=front.second;
		if(d > dist[u]){continue;}
		int size=adj[u].size();
 
		for(ll j=0;j<size;j++){
			ii v=adj[u][j];
 
			if(dist[v.first] >= dist[u] + v.second){
 
				if(visited[v.first]){
					cnt++;
					visited[v.first]=0;
				}
				dist[v.first] = (dist[u]+v.second);
				pq.insert({dist[v.first],v.first});
			}
		}
	}
}
int main(){
	cin>>n>>m>>k;
	ll u,v,w;
 
	for(ll i=0;i<m;i++){
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
 
	for(ll i=0;i<k;i++){
		cin>>v>>w;
		if(!visited[v]){
			visited[v]=1;
			dist[v]=w;
		}
		else{
			dist[v]=min(dist[v],w);
			cnt++;
		}
	}
 
	dijkstra();
 
	cout<<cnt<<endl;
}