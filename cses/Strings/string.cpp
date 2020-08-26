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
int mod=1e9+7;


 int wordBreak(string s, vector<string>& wordDict) {
       
        vector<int>dp(s.size()+1,0);
        dp[0]=1;
        for(int i=0;i<s.size();i++){
            if(dp[i])
            for(auto p:wordDict){
				if(s[0]==p[0])
                if(s.substr(i,p.size())==p)
                    dp[i+p.size()]=(dp[i]+dp[i+p.size()])%mod;
            }
        }
       // for(auto p:dp)cout<<p<<" ";
        return dp[s.size()]%mod;
       
    }




signed main(){
	boost;
	string s,a;
	cin>>s;
	int k;
	cin>>k;
	vector<string>wordDict;
	while(k--){
		cin>>a;
		wordDict.pb(a);
	}
	
	cout<<wordBreak(s,wordDict);
	


}
