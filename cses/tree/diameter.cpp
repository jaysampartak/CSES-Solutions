#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
#define vii vector<pair<int,int>>
#define vi  vector<int>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define tt int t; cin>>t;while(t--)
#define endl "\n"
#define pii pair<int,int>
#define pb push_back
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

const int sz=2e5+5;
int dp1[sz],dp2[sz];
vector<int>adj[sz];

pii bfs(int u){
	queue<int>q;
	int vis[sz]={0};
	q.push(u);
	int len=0;
	int tp=u;
	while(!q.empty()){
		for(int i=q.size()-1;i>=0;i--){
			tp=q.front();
			vis[tp]=true;
			// cout<<tp<<endl;
			q.pop();
			
			for(auto v:adj[tp]){
				if(!vis[v]){
					vis[v]=true;
					q.push(v);
				}
			}	
			
			
		}
		
		if(!q.empty())
			len++;
	}
	return {len,tp};
}

pii bfs1(int u){
	queue<int>q;
	int vis[sz]={0};
	q.push(u);
	int len=0;
	int tp=u;
	while(!q.empty()){
		for(int i=q.size()-1;i>=0;i--){
			tp=q.front();
			vis[tp]=true;
			// cout<<tp<<endl;
			q.pop();
			dp1[tp]=len;
			
			for(auto v:adj[tp]){
				if(!vis[v]){
					vis[v]=true;
					q.push(v);
				}
			}	
			
			
		}
		
		if(!q.empty())
			len++;
	}
	return {len,tp};
}

pii bfs2(int u){
	queue<int>q;
	int vis[sz]={0};
	q.push(u);
	int len=0;
	int tp=u;
	while(!q.empty()){
		for(int i=q.size()-1;i>=0;i--){
			tp=q.front();
			vis[tp]=true;
			// cout<<tp<<endl;
			q.pop();
			dp2[tp]=len;
			for(auto v:adj[tp]){
				if(!vis[v]){
					vis[v]=true;
					q.push(v);
				}
			}	
			
			
		}
		
		if(!q.empty())
			len++;
	}
	return {len,tp};
}


signed main(){
	int n,a,b;
	cin>>n;
	
	
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);

	}
		//cout<<"ho";
		pii v=bfs(1);
		
	    pii z=bfs1(v.second);
		pii c=bfs2(z.second);
		//cout<<z.first<<" "<<z.second<<endl;
		//cout<<c.fi<<" "<<c.se<<endl;
		
		//for(int i=1;i<n;i++)cout<<dp1[i]<<" "<<dp2[i]<<endl;
	for(int i=1;i<=n;i++){
		//if(dp1[i]<dp2[i])cout<<z.second;
		//else cout<< v.second;
		cout<<max(dp1[i],dp2[i]);
		cout<<" "; 
	}
}
