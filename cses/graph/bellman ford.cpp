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


const int mxn=2500;
int n,m;
int a,b,c;
ll d[mxn];
vector<array<ll,2>>adj[mxn];
ll ans[mxn];
vector<int> adj1[mxn];
bool vis[mxn],vis1[mxn];

void dfs(int u){
	vis[u]=true;
	for(array<ll,2> v: adj[u]){
		if(!vis[v[0]])
			dfs(v[0]);
	}
}
void dfs1(int u){
	vis1[u]=true;
	for(int v:adj1[u]){
		if(!vis1[v])
			dfs1(v);
	}
}
signed main(){

cin>>n>>m;
memset(d,0xc0,sizeof(d));
for(int i=0;i<m;i++){
	cin>>a>>b>>c,--a,--b;
	adj[a].pb({b,c});
	adj1[b].pb(a);

}
d[0]=0;
dfs(0);
dfs1(n-1);

for(int i=0;i<n;i++){
	bool ch=0;
	for(int j=0;j<n;j++){
		
		for(array<ll,2> a:adj[j]){
			if(d[a[0]]<d[j]+a[1]){
				if(vis[a[0]]&&vis1[a[0]])
					ch=1;				
				d[a[0]]=d[j]+a[1];
				
			}
				
				
		}
		
		
	}

	if(i>=n-1&&ch){
			
			cout<<-1;
			return 0;
		}
	
	
}	
	
		cout<<d[n-1];
}
