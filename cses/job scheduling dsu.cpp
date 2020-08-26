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

struct job{
	int id,deadline,profit;
};

struct dsu{
	int *parent;
	
	dsu(int n){
		parent=new int[n+1];
		for(int i=0;i<=n;i++)
			parent[i]=i;
		
	}
	
	int find(int s){
		while(s==parent[s])
			return s;
		return parent[s]=find(parent[s]);
			
	}
	
	void merge(int u, int v){
		parent[v]=u;
	}
	
};

bool comp(job &a,job &b){
	return a.profit>b.profit;
}



signed main(){
	tt{
		int n;
		cin>>n;
		job task[n];
		int mxdead=INT_MIN;	
		for(int i=0;i<n;i++){
			cin>>task[i].id;
			cin>>task[i].deadline;
			mxdead=max(mxdead,task[i].deadline);
			cin>>task[i].profit;
		}
		sort(task,task+n,comp);
		
		dsu m(mxdead);
			int job=0;
			int profit=0;
		for(int i=0;i<n;i++){
			int available = m.find(task[i].deadline);
			
			if(available>0){
				job++;
				profit+=(task[i].profit);
				m.merge(m.find(available-1),available);
			}
		}
		cout<<job<<" "<<profit<<endl;
	}


}
