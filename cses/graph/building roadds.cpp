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
const int mxn=1e5+1;
bool vis[mxn];
int p[mxn];
vector<int>adj[mxn];

void dfs(int i){
	if(vis[i])return ;
	vis[i]=true;
	for(auto v:adj[i]){
		dfs(v);
	}
}
int bfs(){
	queue<int>q;
	q.push(1);
	int cnt=1;
	while(q.size()){
		int sz=q.size();
		for(int i=0;i<sz;i++){
			int tp=q.front();
			q.pop();
			if(tp==n)
				return cnt;
			else{
				for(auto v:adj[tp]){
					if(!vis[v]){
						p[v]=tp;
						q.push(v);
						vis[v]=true;
					}
						
				}
			} 	
				
		}
		cnt++;
	}
	return -1;
}
signed main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	p[1]=1;
	
	int x=bfs();
	if(x==-1)cout<<"IMPOSSIBLE\n";

	else {cout<<x<<endl;
		int s=n;
		vi v;
		while(true){
			v.pb(s);
			if(s==1)break;
			s=p[s];
			
		}
		reverse(all(v));
		for(auto po:v)cout<<po<<" ";
	}
}
