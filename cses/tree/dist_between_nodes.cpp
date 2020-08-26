
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
int n,q;
vector<int>adj[mx];
vector<int>dp[mx];
int d[mx];
int l;
vi tin,tout;
int timer;
void dfs(int u=1,int p=1){
		d[u]=d[p]+1LL;
		tin[u]=++timer;
		dp[u][0]=p;
		for(int i=1;i<=l;i++)
			if(dp[u][i-1]!=-1LL)
				dp[u][i]=dp[dp[u][i-1]][i-1];
		
		for(int v:adj[u])
				if(v!=p)
					dfs(v,u);
					
		tout[u]=++timer;
			
}

bool is_ancestor(int u,int v){
	return tin[u]<=tin[v]&&tout[u]>=tout[v];
}

int lca(int u,int v){
	if(is_ancestor(u,v))
		return u;
	if(is_ancestor(v,u))
		return v;
	for(int i=l;i>=0;i--){
		if(dp[u][i]!=-1)
		if(!is_ancestor(dp[u][i],v))
			u=dp[u][i];
	}	
	return dp[u][0];
}


signed main(){
	cin>>n>>q;
	l=ceil(log2(n));
	

	timer=0;

	tin.resize(n+1);
	tout.resize(n+1);
	d[0]=-1;
	
	for(int i=1;i<=n;i++){
		dp[i].assign(l+1,-1);
	}

	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs();	
	//for(int i=l;i>=0;i--){
		//cout<<i<<" ";
		//for(int j=1;j<=n;j++)
			//cout<<dp[j][i]<<" ";
		//cout<<endl;
			
	//}
	
	while(q--){
		int a,b;
		cin>>a>>b;
		
		l=lca(a,b);
		//cout<<endl<<l;
		cout<<endl<<d[a]+d[b]-2LL*d[l];
	}

}
