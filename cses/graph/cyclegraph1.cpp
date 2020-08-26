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
const int mxn=1e5+5;
int p[mxn];
bool vis[mxn];
vi ans;
vi adj[mxn];
int c=0;
int dfs(int u,int pu=-1){
	//debug(u);
	p[u]=pu;
	vis[u]=true;
	for(int v:adj[u]){
		
		if(v==pu)
			continue;
		
		if(vis[v]){
			int u2=u;
			while(v!=u){
				
				ans.pb(u);
				u=p[u];
			}
			ans.pb(v);
			ans.pb(u2);
			cout<<ans.size()<<endl;
			for(auto c:ans)
				cout<<c<<" ";
			exit(0);
		}else
			dfs(v,u);
		
	}
	return 0;
}


int n,m,a,b;;
signed main(){
cin>>n>>m;
for(int i=0;i<m;i++){
	cin>>a>>b;
	adj[a].pb(b);
	adj[b].pb(a);
}
for(int i=1;i<=n;i++){
	if(!vis[i])
		dfs(i);
}
cout<<"IMPOSSIBLE";

}
