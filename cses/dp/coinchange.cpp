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



const int mod=1e9+7;
signed main(){
	int n,x;
	cin>>n>>x;
	int dp[x+1];
	int c[n];
	for(int i=0;i<n;i++)cin>>c[i];
	
	for(int i=0;i<=x;i++){
		dp[i]=INT_MAX-32;
	}
	dp[0]=0;
	for(int i=0;i<=x-1;i++){
		for(int w=0;w<n;w++){
			if(i+c[w]<=n&&dp[i]!=INT_MAX-32)
				dp[i+c[w]]=min(dp[i]+1ll,dp[i+c[w]]);
		}
	}
	for(int j:dp)cout<<j<<" ";
	cout<<(dp[x]==INT_MAX?-1:dp[x]);

}
