#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
#define vii vector<pair<int,int>>
#define vi  vector<int>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define tt int t; cin>>t;while(t--)
#define endl "\n"
#define pb push_back
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
const int mx=2e5+5;
int d[mx];
int ans[mx],s[mx];
vector<int>adj[mx];
int n;

void dfs(int u=0,int p=-1){
	s[u]=1;
	for(int v:adj[u]){
		if(v==p)continue;
		d[v]=d[u]+1;
		dfs(v,u);
		s[u]+=s[v];
	}
}
void dfs2(int u, int pd, int p=-1){
	ans[u]=pd;
	for(int v:adj[u]){
		if(v==p)continue;
		dfs2(v,pd-s[v]+(n-s[v]),u);
	}
}


signed main(){

	cin>>n;
	for(int i=0;i<n-1;i++){
		int u ,v;
		cin>>u>>v,u--,v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfs();
	
	int sd=0;
	for(int i=0;i<n;i++)
		sd+=d[i];
		
	dfs2(0,sd);
	
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";

}
