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
#define pb push_back
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

	int n;
	vector<bool>vis;
	vector<vi>child;
	vector<int> sub;
	
int calc(int i){
	
	if(vis[i])return sub[i];
	
	int ans=child[i].size();
	for(auto ch:child[i]){
		if(vis[ch])ans+=sub[ch];
		else {calc(ch);ans+=sub[ch];}
		
	}
	vis[i]=true;
	
	return sub[i]=ans;
	
}


signed main(){
	int a;
	
	cin>>n;
	vis.assign(n+1,false);
	child.assign(n+1,vi());
	sub.assign(n+1,0);
	
	
	for(int i=2;i<=n;i++){
		
		cin>>a;
		if(i==1)continue;
		child[a].pb(i);
		
	} 
	calc(1);
	for(int i=1;i<=n;i++)
		cout<<sub[i]<<" ";

}
