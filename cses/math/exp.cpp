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



long long power(long long a, long long b,int p) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%p;
        a = (a * a)%p;
        b >>= 1;
    }
    return res%p;
}
signed main(){
	const int p=1e9+7;
tt{
	cout<<endl;
	int a,b,c;
	cin>>a>>b>>c;
	if(a==0&&b==0&&c==0){cout<<0;continue;}
	
	if(a==0&&b==0){cout<<1;continue;}
	if(b==0&&c==0){cout<<a%p;continue;}
	
	if(a%p==0){cout<<0;continue;}
	int res=power(b,c,p-1);
	cout<<power(a,res,p);
	
}

}
