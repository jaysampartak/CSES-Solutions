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


const int mxn=1e3+3;
int dp[mxn][mxn],mat[mxn][mxn];


signed main(){
	int n,q;
	cin>>n>>q;
	char c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>c;
			dp[i][j]=((c=='.')?0:1);
			dp[i][j]+=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]);
		}
	}
	
		
	while(q--){
		int y1,x1,y2,x2;
		cin>>y1>>x1>>y2>>x2;
		cout<<dp[y2][x2]-dp[y2][x1-1]-dp[y1-1][x2]+dp[y1-1][x1-1]<<endl;
	}
	

}
