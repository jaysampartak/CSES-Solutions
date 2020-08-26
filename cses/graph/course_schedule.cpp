#include<bits/stdc++.h>
using namespace std;
#define ll long long


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


#define all(x) x.begin(),x.end()
#define ip vector<int,pair<int,int>>
#define vii vector<pair<int,int>>
#define vi  vector<int>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define tt int t; cin>>t;while(t--)
#define FOR(i,j,k) for(int i=0;i<j;i++)
#define endl "\n"
#define pb push_back
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);



vector<int>adj[100005],vis,p,ord;

bool DAG=true;

void dfs(int u,int pu=-1){
	//debug(u,pu,DAG);
	if(!DAG)return;
	vis[u]=1;
	p[u]=pu;
	for(int to:adj[u]){
		
		if(!vis[to])
			dfs(to,u);
		else if(vis[to]==1)	
			{DAG=false; 
				return;
				}
	}
	ord.pb(u);
	vis[u]=2;
}


signed main(){
	int n,m;
		cin>>n>>m;
		int u,v;
		p.assign(n,-1);
		vis.assign(n,0);
		for(int i=0;i<m;i++){
			cin>>u>>v,--u,--v;
			adj[u].pb(v);
		}
		for(int i=0;i<n;i++){
			if(!vis[i])dfs(i);
		}
		if(!DAG)
		{
			cout<<"IMPOSSIBLE\n";
			
		}else{
			
			
			reverse(all(ord));
			//cout<<ord.size();
			for(int i: ord)
				cout<<i+1<<" ";
			
		}
		

}
