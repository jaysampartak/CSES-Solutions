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


const int mxn=2e5+5;
const int mod =1e9+7;

vector<int>adj[mxn];
ll child[mxn],d[mxn],vis[mxn];
int n;

int dfs(int u, int p=-1){
	if(u==n-1)return 1;
	vis[u]=1;
	for(int to:adj[u]){
		if(to==p)continue;
		if(vis[to]){
			
				//if(d[to]&&d[u]<d[to]+1){
					//d[u]=d[to]+1;
					//child[u]=to;
				//}
			
			if(d[to])(d[u]+=(d[to]))%=mod;
		}else{
			int x=dfs(to,u);
			if(x){
				(d[u]+=(x))%=mod;

			}
			
		}
		
	}
	return d[u];
}

signed main(){
	int m,a,b;
	cin>>n>>m;
	while(m--){
		cin>>a>>b,--a,--b;
		adj[a].pb(b);
	}
	memset(child,-1,sizeof(child));
	memset(d,0,sizeof(d));
	memset(vis,0,sizeof(vis));
	
	dfs(0);
	
	
		cout<<d[0]%mod<<endl;
		
	
	
	
}
