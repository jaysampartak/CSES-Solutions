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
 
 
 
ll n,m,a,b,x;
const int mxn=1e5+5;
const ll INF=1e9;
 
ll d[mxn];
vector<array<ll,2>>adj[mxn];
 
signed main(){
	boost;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		cin>>x;			
		adj[a].pb({x,b});
		
	}
	
	priority_queue<array<ll,2>,vector<array<ll,2>>,greater<array<ll,2>>>pq;
	//dijkstras(1);
	pq.push({0,1});
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	
	while(pq.size()){
		array<ll,2>u =pq.top();
		pq.pop();
		if(u[0]>d[u[1]])
			continue;
		for(array<ll,2>v:adj[u[1]]){
			if(d[v[1]]>u[0]+v[0]){
				d[v[1]]=u[0]+v[0];
				pq.push({d[v[1]],v[1]});
			}
		}	
		
	}
	
	for(int i=1;i<=n;i++)
		cout<<d[i]<<" ";
}
