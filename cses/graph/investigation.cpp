#include<bits/stdc++.h>
using namespace std;
#define ll int
 
 
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
const int mod=1e9+7;
ll d[mxn];
vector<array<ll,2>>adj[mxn];

int minPaths[mxn],mnFlights[mxn],mxFlights[mxn],vis[mxn];
signed main(){
	boost;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		cin>>x;			
		adj[a].pb({x,b});
		
	}
	
	//priority_queue<array<ll,2>,vector<array<ll,2>>,greater<array<ll,2>>>pq;
	//dijkstras(1);
	set<array<ll,2> >pq;
	pq.insert({0,1});
	memset(d,0x3f,sizeof(d));
	memset(minPaths,0,sizeof minPaths);
	memset(mnFlights,0,sizeof mnFlights);
	memset(mxFlights,0 ,sizeof mxFlights);
	memset(vis,0,sizeof vis);
	d[1]=0;
	minPaths[1]=1;
	mnFlights[1]=0;
	mxFlights[1]=0;
	while(pq.size()){
		array<ll,2>curr =*pq.begin();
		pq.erase(pq.begin());
		//debug(curr);
		if(curr[0]>d[curr[1]])
			continue;
		//if(vis[x])
			//continue;
		//vis[x]=1;	
		for(array<ll,2>v:adj[curr[1]]){
			if(d[v[1]]==0x3f||d[v[1]]>curr[0]+v[0]){
				pq.erase({d[v[1]],v[1]});
				minPaths[v[1]]=minPaths[curr[1]];
				mnFlights[v[1]]=mnFlights[curr[1]]+1;
				mxFlights[v[1]]=mxFlights[curr[1]]+1;
				d[v[1]]=curr[0]+v[0];
				pq.insert({d[v[1]],v[1]});
			}else if(d[v[1]]==(curr[0]+v[0]) ){
				pq.erase({d[v[1]],v[1]});
				(minPaths[v[1]]+=minPaths[curr[1]])%=mod;
				mnFlights[v[1]]=min(mnFlights[v[1]],mnFlights[curr[1]]+1);
				mxFlights[v[1]]=max(mxFlights[v[1]],mxFlights[curr[1]]+1);
				pq.insert({d[v[1]],v[1]});
			}
		}	
		//cout<<d[curr[1]]<<" "<<minPaths[curr[1]]<<" "<<mnFlights[curr[1]]<<" "<<mxFlights[curr[1]]<<endl;
		
	}
	cout<<d[n]<<" "<<minPaths[n]<<" "<<mnFlights[n]<<" "<<mxFlights[n]<<endl;
	
}
