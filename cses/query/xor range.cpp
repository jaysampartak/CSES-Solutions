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


const int mxn=2e5+5;
int a[mxn];
int t[4*mxn];

void build(int v,int tl,int tr){
	if(tl==tr)
		t[v]=a[tl];
	else{
		int tm=(tl+tr)/2;
		build(2*v,tl,tm);
		build(2*v+1,tm+1,tr);
		t[v]=t[2*v]^t[2*v+1];
	}
		
}
int xori(int v,int tl ,int tr,int l,int r){
	if(l>r)
		return 0;
	if(tl>=l&&tr<=r)
		return t[v];
	int tm=(tl+tr)/2;
	return xori(2*v,tl,tm,l,min(tm,r))
			^xori(2*v+1,tm+1,tr,max(tm+1,l),r);	 
}


signed main(){
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>a[i];
	build(1,0,n-1);	
	
		while(q--){
		int a,b;
		cin>>a>>b,a--,b--;
		cout<<xori(1,0,n-1,a,b)<<endl;
		
	}	

}
