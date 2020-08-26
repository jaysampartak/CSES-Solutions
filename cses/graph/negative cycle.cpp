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



struct edge{
	int a,b;
	ll c;
};
vector<edge> edges;
vector<ll>p,d;
signed main(){
	int n,m,a,b,c;
	cin>>n>>m;
	p.assign(n,-1);
	d.assign(n,1000000000);
	for(int i=0;i<m;i++){
			cin>>a>>b>>c;
			edges.pb({--a,--b,c});
	}
	int x;
	
	for(int i=0;i<n;i++){
		x=-1;
		for(auto e: edges){
			//debug(d);
			if(d[e.b]>d[e.a]+e.c){
				d[e.b]=d[e.a]+e.c;
				p[e.b]=e.a;
				x=e.b;
				
			}
		}
	}
	
	if(x==-1)cout<<"NO\n";
	else{
		//for(int i=0;i<n;i++)x=p[x];
		vi cycle;
		for(int v=x;;v=p[v]){
			//cout<<v;
			cycle.pb(v);
			if(v==x&&cycle.size()>1)
				break;
		}
		cout<<"YES\n";
				reverse(all(cycle));
			for(int v:cycle)
			cout<<v+1<<" ";
		
	}
	
	
	
}
