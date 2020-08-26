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
const int mx=2e5+5;
int d[mx];
vector<vi>dp;
int s[mx];
vector<int>adj[mx];
int n;

int kpar(int x,int k){
	
	int ans=x;
	int mask;
	for(int i=0;i<=log2(k);i++){
		mask=1<<i;
		if((mask&k)>0){
			if(ans==-1)return -1;
			ans=dp[ans][i];
		}
	}
	return ans;
}

signed main(){
	int q;
	
	
		cin>>n>>q;
	
	
	dp.assign(n,vector<int>(log2(n)+1,-1));
	
	dp[0][0]=-1;
	for(int i=1;i<n;i++){
		cin>>dp[i][0];
		dp[i][0]--;
	}
		
		
	for(int h=1;h<=log2(n);h++){
		for(int i=0;i<n;i++){
			if(dp[i][h-1]!=-1)
				dp[i][h]=dp[dp[i][h-1]][h-1];
		}
	}

	
	while(q--){
		int x,k;
		cin>>x>>k;
		x--;
		int ans=kpar(x,k);
		
		cout<<endl<<(ans!=-1?ans+1:-1);
	}

	


}
