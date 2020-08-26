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
const int BMAX=21;
vi adj[mx];
int tin[mx],tout[mx],bal[mx],k[mx],c[mx];
int anc[mx][BMAX];

int timer=0;

void pre(int u , int p){
	anc[u][0]=p;
	tin[u]=++timer;
	for(int i=1;i<BMAX;i++){
		anc[u][i]=anc[anc[u][i-1]][i-1];
	}
	for(auto v:adj[u]){
		if(v==p)
			continue;
		pre(v,u);
		
	}
	
	tout[u]=++timer;
}


bool is_anc(int u,int v){
	return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int lca(int u,int v){
	
	if(is_anc(u,v))return u;
	if(is_anc(v,u))return v;
	for(int i=BMAX-1;i>=0;i--){
		if(!is_anc(anc[u][i],v))u=anc[u][i];
	}
	return anc[u][0];
}
int dfs(int u,int p){
	c[u]=bal[u];
	for(int v:adj[u]){
		if(v==p)continue;
		c[u]+=dfs(v,u);
	}
	return c[u];
}
signed main(){
	int n,u,v,m;
	cin>>n>>m;
	for(int i=0;i<n-1;i++){
		cin>>u>>v;
		u--;v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	pre(0,0);
	for(int i=0;i<m;i++){
		cin>>u>>v;
		u--;v--;
		int l=lca(u,v);
		bal[u]++;
		bal[v]++;
		bal[l]-=2;
		k[l]++;
			}
	dfs(0,0);
	for(int i=0;i<n;i++){
		cout<<c[i]+k[i]<<" ";
	}


}
