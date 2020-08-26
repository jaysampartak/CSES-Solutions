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





int n,m,a,b;
const int mxn=1e5+5;
vi adj[mxn];
vi side(mxn,-1);

bool bipartite(){
	bool is_bipartite=true;
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(side[i]==-1){
			side[i]=0;
			
			q.push(i);
			while(q.size()){
				int tp=q.front();
				q.pop();
				for(int v:adj[tp]){
					if(side[v]==-1)
						{	q.push(v);
							side[v]=!side[tp];
						}
					else{
						is_bipartite &=(side[tp]!=side[v]);
					}	
				}
			}
			
		}
	}
	return is_bipartite;
}


signed main(){
cin>>n>>m;	
	for(int i=0;i<m;i++){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
		
	}
	if(bipartite()){
		for(int i=1;i<=n;i++)cout<<side[i]+1<<" ";
	}else
		cout<<"IMPOSSIBLE";
	cout<<endl;


}
