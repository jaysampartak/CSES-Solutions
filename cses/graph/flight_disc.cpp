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

#define ar array


int n,m;
int a,b,c;
const int mxn=1e5+3;

vector<ar<ll,2>>adj1[mxn],adj2[mxn];
ll d1[mxn],d2[mxn];


void solve(int s,vector<ar<ll,2>> adj[mxn],ll d[mxn]){
	d[s]=0;
	priority_queue<ar<ll,2>,vector<ar<ll,2>>,greater<ar<ll,2>>>pq;
	
	pq.push({0,s});
	
	while(pq.size()){
		ar<ll,2>u=pq.top();
		pq.pop();
		if(u[0]>d[u[1]])
		continue;
		for(ar<ll,2> v: adj[u[1]]){
			
		if(d[v[0]]>u[0]+v[1]){
			d[v[0]]=u[0]+v[1];
			pq.push({d[v[0]],v[0]});
		}
			
		}
	}
	
}

signed main(){
	cin>>n>>m;
	memset(d1,0x3f,sizeof(d1));
	memset(d2,0x3f,sizeof(d2));
	for(int i=0;i<m;i++){
			cin>>a>>b>>c,--a,--b;
			adj1[a].pb({b,c});
			adj2[b].pb({a,c});
			
	}
	solve(0,adj1,d1);
	solve(n-1,adj2,d2);
	ll ans=1e18;
	
	for(int i=0;i<n;i++){
		for(ar<ll,2> v: adj1[i]){
			ans=min(ans,d1[i]+d2[v[0]]+v[1]/2);
		}
	}
	
	cout<<ans;
	

}
