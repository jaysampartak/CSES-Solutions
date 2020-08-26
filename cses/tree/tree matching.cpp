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
// index cnt0 cnt1 edgetype
const int sz=2e5+5;
int dp0[sz],dp1[sz];
vector<int>adj[sz];

	void dfs(int u,int p){
		for(auto v:adj[u]){
			if(v==p)continue;
			dfs(v,u);
			dp1[u]=max(dp1[u]+max(dp0[v],dp1[v]),dp0[u]+dp0[v]+1 );
			dp0[u]+=max(dp0[v],dp1[v]);
		}
		
		
	}



signed main(){
	int n,a,b,st;
	cin>>n;
	
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		a--,b--;
		
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0,-1);
	cout<<max(dp0[0],dp1[0]);
	

}
